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
}

void Tetraedro::inicializarColores(){
   Tupla3f c_rojo = {1.0,0.0,0.0};
   Tupla3f c_verde = {0.0,1.0,0.0};
   Tupla3f c_naranja = {0.9,0.2,0.07};

   for (int i = 0; i < 3*f.size()/2; i++){
         color_ajedrez_pares.push_back(c_rojo);
         color_ajedrez_impares.push_back(c_verde);
   }

   for (int i = 0; i < v.size(); i++){
       color.push_back(c_naranja);
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

   //inicializar los distintos vectores de colores
   inicializarColores();

}

