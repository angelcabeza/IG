#include "cuadro.h"

Cuadro::Cuadro(){
    // inicializar la tabla de vértices
   inicializarVertices();

   // inicializar la tabla de caras o triángulos:
   // (es importante en cada cara ordenar los vértices en sentido contrario
   //  de las agujas del reloj, cuando esa cara se observa desde el exterior del cubo)
   inicializarCaras();
   inicializarColores();
   inicializarNormalesCaras();
   inicializarNormalesVertices();
   inicializarTexturas();
}

void Cuadro::inicializarVertices(){
    v.push_back({0,0,0});
    v.push_back({0,50,0});
    v.push_back({50,0,0});
    v.push_back({50,50,0});
}

void Cuadro::inicializarCaras(){
    f.push_back({0,3,1});
    f.push_back({0,2,3});
}

void Cuadro::inicializarColores(){
    Tupla3f c_rojo = {1.0,0.0,0.0};
   Tupla3f c_verde = {0.0,1.0,0.0};
   Tupla3f c_naranja = {1,1,1};

   for (int i = 0; i < 3*f.size()/2; i++){
         color_ajedrez_pares.push_back(c_rojo);
         color_ajedrez_impares.push_back(c_verde);
   }

   for (int i = 0; i < v.size(); i++){
      color.push_back(c_naranja);
   }
}

void Cuadro::inicializarTexturas(){
    
    textura = new Textura("texturas/text-madera.jpg");
    
    ct.push_back({0,1});
    ct.push_back({0,0});
    ct.push_back({1,1});
    ct.push_back({1,0});
}