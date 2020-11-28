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

void Tetraedro::inicializarNormalesCaras(){
   Tupla3f p;
   Tupla3f q;
   Tupla3f r;
   Tupla3f vector_a;
   Tupla3f vector_b;
   Tupla3f vector_perpendicular;
   Tupla3f vector_normal;

   for (int i = 0; i < f.size(); i++){
      p = v[f[i](0)];
      q = v[f[i](1)];
      r = v[f[i](2)];

      //std::cout << "p = " << p[0] << "," << p[1] << "," << p[2] << std::endl;
      //std::cout << "q = " << q[0] << "," << q[1] << "," << q[2] << std::endl;
      //std::cout << "r = " << r[0] << "," << r[1] << "," << r[2] << std::endl;

      vector_a = q - p;
      vector_b = r - p;

      //std::cout << "vector_a = " << vector_a[0] << "," << vector_a[1] << "," << vector_a[2] << std::endl;
      //std::cout << "vector_b = " << vector_b[0] << "," << vector_b[1] << "," << vector_b[2] << std::endl;
      

      vector_perpendicular = vector_a.cross(vector_b);

      //std::cout << "Llamo a nomralized en normalesCaras" << std::endl;
      //std::cout << "x: " << vector_perpendicular[0] << "\ny: " << vector_perpendicular[1] << "\nz: " << vector_perpendicular[2] << std::endl << std::endl;
      //std::cout << "ERROR OCURRE EN LA CARA: " << i << std::endl;
      vector_normal = vector_perpendicular.normalized();

      nf.push_back(vector_normal);
   }
}

void Tetraedro::inicializarNormalesVertices(){

   nv.resize(v.size());
   for (int i = 0; i < f.size(); i++){
      nv[f[i](0)] = (nv[f[i](0)] + nf[i]).normalized();
      nv[f[i](1)] = (nv[f[i](1)] + nf[i]).normalized();
      nv[f[i](2)] = (nv[f[i](2)] + nf[i]).normalized();
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

   inicializarNormalesCaras();
   inicializarNormalesVertices();

   std::cout << "NORMALES CARAS" << std::endl;
   for (int i = 0; i < nf.size(); i++){
      std::cout << nf[i](0) << " , " << nf[i](1) << " , " << nf[i](2) << std::endl;
   }

   std::cout << "NOMRALES VERTICES" << std::endl;
    for (int i = 0; i < nv.size(); i++){
      std::cout << nv[i](0) << " , " << nv[i](1) << " , " << nv[i](2) << std::endl;
   }

}

