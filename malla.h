// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: Malla3D.h
// -- declaraciones de clase Malla3D (mallas indexadas) y derivados
//
// #############################################################################

#ifndef MALLA3D_H_INCLUDED
#define MALLA3D_H_INCLUDED

#include "aux.h"
#include "material.h"
#include "textura.h"

// *****************************************************************************
//
// clase para objetos 3D (mallas indexadas)
//
// *****************************************************************************

typedef enum {DIFERIDO,INMEDIATO,DEFAULT} modo_dibujado;

class Malla3D
{
   public:

   // dibuja el objeto en modo inmediato
   void draw_ModoInmediato(bool ajedrez);

   // dibuja el objeto en modo diferido (usando VBOs)
   void draw_ModoDiferido();

   void setMaterial (const Material & mat);
   void setTextura(const Textura & text);
   void setColor (Tupla3f color_solido);
   Tupla3f getColor ();
   Tupla3f getCentro();
   void calcularCentro();
   Tupla3f getPosicion();
   void setPosicion(Tupla3f pos);
   Tupla3f posicion;

   GLuint CrearVBO (GLuint tipo_vbo, GLuint tamanio_bytes, GLvoid * puntero_ram);

   // función que redibuja el objeto
   // está función llama a 'draw_ModoInmediato' (modo inmediato)
   // o bien a 'draw_ModoDiferido' (modo diferido, VBOs)
   void draw(modo_dibujado modo,bool ajedrez) ;


   protected:

   void inicializarNormalesVertices();
   void inicializarNormalesCaras();
   void inicializarColores();

   Tupla3f centro = {0,0,0};

   Material  m;
   Textura * textura = nullptr;
         
   GLuint id_vbo_ver = 0;
   GLuint id_vbo_tri = 0;
   GLuint id_vbo_col = 0;
   GLuint id_vbo_normal_vertex = 0;
   GLuint id_vbo_normal_faces = 0;

   std::vector<Tupla3f> v ;   // tabla de coordenadas de vértices (una tupla por vértice, con tres floats)
   std::vector<Tupla3i> f ; // una terna de 3 enteros por cada cara o triángulo
   std::vector<Tupla3f> nv ; // tabla de coordenadas de normales de vértices y caras (uuna tupla por vértice y cara, con tres floats)
   std::vector<Tupla3f> nf ; // tabla de coordenadas de normales de las caras
   std::vector<Tupla3i> caras_pares,caras_impares; // tabla de triángulos necesarias para pintar en modo ajedrez
   std::vector<Tupla3f> color_ajedrez_pares,color_ajedrez_impares;          // tabla de colores para el ajedrez
   std::vector<Tupla3f> color;                                              // tabla de colores para la figura
   std::vector<Tupla2f> ct;                                                 // tabla de coordenadas de textura
   Tupla3f colorSolido;

   // completar: tabla de colores, tabla de normales de vértices
} ;


#endif
