#include "cuadro.h"

Cuadro::Cuadro(float lado){
    // inicializar la tabla de vértices
   inicializarVertices(lado);

   // inicializar la tabla de caras o triángulos:
   // (es importante en cada cara ordenar los vértices en sentido contrario
   //  de las agujas del reloj, cuando esa cara se observa desde el exterior del cubo)
   inicializarCaras();
   inicializarNormalesCaras();
   inicializarNormalesVertices();
   inicializarTexturas();
}

void Cuadro::inicializarVertices(float lado){
    v.push_back({0,0,0});
    v.push_back({0,lado/2,0});
    v.push_back({lado,0,0});
    v.push_back({lado,lado/2,0});
}

void Cuadro::inicializarCaras(){
    f.push_back({0,3,1});
    f.push_back({0,2,3});
}


void Cuadro::inicializarTexturas(){
    
    textura = new Textura("texturas/text-madera.jpg");
    
    ct.push_back({0,1});
    ct.push_back({0,0});
    ct.push_back({1,1});
    ct.push_back({1,0});
}