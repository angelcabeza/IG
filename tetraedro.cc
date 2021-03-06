#include "aux.h"
#include "malla.h"
#include "tetraedro.h"


void Tetraedro::inicializarVertices(){
    // inicializar la tabla de vértices
   Tupla3f v0 = {50.0,0.0,0.0};
   Tupla3f v1 = {0.0,0.0,50.0};
   Tupla3f v2 = {-50.0,0.0,0.0};
   Tupla3f v3 = {0.0,100.0,0.0};

   v.push_back(v0);
   v.push_back(v1);
   v.push_back(v2);
   v.push_back(v3);
}

void Tetraedro::inicializarCaras(){
   // inicializar la tabla de caras o triángulos:
   // (es importante en cada cara ordenar los vértices en sentido contrario
   //  de las agujas del reloj, cuando esa cara se observa desde el exterior del cubo)

   Tupla3i c0 = {1,0,3};
   Tupla3i c1 = {2,1,3};
   Tupla3i c2 = {1,2,0};
   Tupla3i c3 = {0,2,3};

   f.push_back(c0);
   f.push_back(c1);
   f.push_back(c2);
   f.push_back(c3);

   // DIVIDO LAS CARAS EN PARES E IMPARES PARA PODER DIBUJARLAS EN MODO AJEDREZ
   for (int i = 0; i < f.size(); i++){
      if ( i%2 == 0)
         caras_pares.push_back(f[i]);
      else
         caras_impares.push_back(f[i]);
   }
}

Tetraedro::Tetraedro()
{

   // inicializar la tabla de vértices
   inicializarVertices();
    
   // inicializar la tabla de caras o triángulos:
   // (es importante en cada cara ordenar los vértices en sentido contrario
   //  de las agujas del reloj, cuando esa cara se observa desde el exterior del cubo)
   inicializarCaras();

   inicializarNormalesCaras();
   inicializarNormalesVertices();

}

