#include "aux.h"
#include "malla.h"
#include "cubo.h"

void Cubo::inicializarVertices(float lado){
   // inicializar la tabla de vértices
   Tupla3f v0 = {-lado/2,-lado/2,lado/2};
   Tupla3f v1 = {lado/2,-lado/2,lado/2};
   Tupla3f v2 = {lado/2, lado/2,lado/2};
   Tupla3f v3 = {-lado/2,lado/2,lado/2};
   Tupla3f v4 = {-lado/2,lado/2,-lado/2};
   Tupla3f v5 = {lado/2,lado/2,-lado/2};
   Tupla3f v6 = {-lado/2,-lado/2,-lado/2};
   Tupla3f v7 = {lado/2,-lado/2,-lado/2};

   v.push_back(v0);
   v.push_back(v1);
   v.push_back(v2);
   v.push_back(v3);
   v.push_back(v4);
   v.push_back(v5);
   v.push_back(v6);
   v.push_back(v7);
}

void Cubo::inicializarCaras(){
   //Primera cara
   Tupla3i c0 = {0,1,2};
   Tupla3i c1 = {0,2,3};
   //Segunda cara
   Tupla3i c2 = {1,7,5};
   Tupla3i c3 = {1,5,2};
   //Tercera cara
   Tupla3i c4 = {3,2,5};
   Tupla3i c5 = {5,4,3};
   //Cuarta cara
   Tupla3i c6 = {0,7,1};
   Tupla3i c7 = {0,6,7};
   //Quinta cara
   Tupla3i c8 = {6,5,7};
   Tupla3i c9 = {6,4,5};
   //Sexta cara
   Tupla3i c10 = {6,0,3};
   Tupla3i c11 = {6,3,4};

   f.push_back(c0);
   f.push_back(c1);
   f.push_back(c2);
   f.push_back(c3);
   f.push_back(c4);
   f.push_back(c5);
   f.push_back(c6);
   f.push_back(c7);
   f.push_back(c8);
   f.push_back(c9);
   f.push_back(c10);
   f.push_back(c11);
 
   // DIVIDO LAS CARAS EN PARES E IMPARES PARA PODER DIBUJARLAS EN MODO AJEDREZ
   for (int i = 0; i < f.size(); i++){
      if ( i%2 == 0)
         caras_pares.push_back(f[i]);
      else
         caras_impares.push_back(f[i]);
   }
}


void Cubo::inicializarColores(){
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
Cubo::Cubo(float lado)
{

   // inicializar la tabla de vértices
   inicializarVertices(lado);

   // inicializar la tabla de caras o triángulos:
   // (es importante en cada cara ordenar los vértices en sentido contrario
   //  de las agujas del reloj, cuando esa cara se observa desde el exterior del cubo)
   inicializarCaras();
   inicializarColores();
   inicializarNormalesCaras();
   inicializarNormalesVertices();
}

Tupla4f Cubo::getMaterial(){
   return m.getDifuso();
}
