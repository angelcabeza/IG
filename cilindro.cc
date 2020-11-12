#include "aux.h"
#include "cilindro.h"

Cilindro::Cilindro(const int num_vert_perfil,const int num_instancias_perf,const float altura, const float radio){
   this->num_instancias = num_instancias_perf;
   std::vector<Tupla3f> perfil;

   Tupla3f vertice;

   for (int i = 1; i <= num_vert_perfil;i++){
        vertice = {radio,i*(altura/num_vert_perfil),0};

        perfil.push_back(vertice);
   }

   crearMalla(perfil,num_instancias_perf,true);

   inicializarColores();
}

void Cilindro::inicializarColores(){
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