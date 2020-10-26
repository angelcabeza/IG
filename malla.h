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

   GLuint CrearVBO (GLuint tipo_vbo, GLuint tamanio_bytes, GLvoid * puntero_ram);

   // función que redibuja el objeto
   // está función llama a 'draw_ModoInmediato' (modo inmediato)
   // o bien a 'draw_ModoDiferido' (modo diferido, VBOs)
   void draw(modo_dibujado modo,bool ajedrez) ;

   protected:

   GLuint id_vbo_ver = 0;
   GLuint id_vbo_tri = 0;
   GLuint id_vbo_col = 0;

   void calcular_normales() ; // calcula tabla de normales de vértices (práctica 3)

   std::vector<Tupla3f> v ;   // tabla de coordenadas de vértices (una tupla por vértice, con tres floats)
   std::vector<Tupla3i> f ; // una terna de 3 enteros por cada cara o triángulo
   std::vector<Tupla3f> color_ajedrez_pares,color_ajedrez_impares;          // tabla de colores para el ajedrez
   std::vector<Tupla3f> color;                                              // tabla de colores para la figura

   // completar: tabla de colores, tabla de normales de vértices
} ;


#endif
