// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: Cubo.h

//
// #############################################################################

#ifndef OBJREVOLUCION_H_INCLUDED
#define OBJREVOLUCION_H_INCLUDED

#include "aux.h"
#include "malla.h"

// *****************************************************************************
//
// clases derivadas de Malla3D (definen constructores específicos)
//
// *****************************************************************************

// *****************************************************************************
// Cubo con centro en el origen y lado unidad por defecto
// (tiene 9 vertices y 6 caras)

class ObjRevolucion : public Malla3D
{

public:
    ObjRevolucion();
    ObjRevolucion(const std::string & archivo, int num_instancias, bool tapa_sup=true, bool tapa_inf=true,int eje_rotacion=1) ;
    ObjRevolucion(std::vector<Tupla3f> archivo, int num_instancias, bool tapa_sup=true, bool tapa_inf=true,int eje_rotacion=1) ;
private:
    const double CONSTANTE_ROTACION = 2*M_PI;
    bool ordenDescendente(std::vector<Tupla3f> perfil_original);
    void cambiarOrden(std::vector<Tupla3f> & perfil_original);
    Tupla3f RotarEjeY(Tupla3f vector, int num_instancias, std::vector<Tupla3f> perfil_original, int instancia_actual,int vertice_actual);
    Tupla3f RotarEjeX(Tupla3f vector, int num_instancias, std::vector<Tupla3f> perfil_original, int instancia_actual,int vertice_actual);
    Tupla3f RotarEjeZ(Tupla3f vector, int num_instancias, std::vector<Tupla3f> perfil_original, int instancia_actual,int vertice_actual);
    void inicializarColores();
    void inicializarVertices(int num_instancias_perfil, std::vector<Tupla3f> & perfil, int eje_rotacion=1);
    void inicializarCaras(int num_instancias_perfil, std::vector<Tupla3f> & perfil);
    void inicializarNormalesCaras();
    void inicializarNormalesVertices();

protected:
    int num_instancias;
    void crearMalla(std::vector<Tupla3f> perfil_original, int num_instancias,bool tapa_inf, bool tapa_sup,int eje_rotacion=1);
public:
    int getNumInstancias();
    void draw(modo_dibujado modo,bool ajedrez, bool tapas);
    // metodo dibujar para objetos de revolucion
   void draw_ModoInmediato(bool ajedrez,bool tapas);
   // dibuja objetos de revolucion en modo diferido
   void draw_ModoDiferido(bool tapas);

} ;




#endif
