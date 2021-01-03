#include "aux.h"
#include "cilindro.h"

Cilindro::Cilindro(const int num_vert_perfil,const int num_instancias_perf,const float altura, const float radio,bool textura){
   this->num_instancias = num_instancias_perf;
   this->con_textura = textura;

   Tupla3f vert_sup = {0,altura,0};

   Tupla3f vertice;

   for (int i = 1; i <= num_vert_perfil;i++){
        vertice = {radio,i*(altura/num_vert_perfil),0};

        perfil.push_back(vertice);
   }
   
   crearMalla(perfil,num_instancias_perf,true,true,1);
   
   inicializarNormalesCaras();
   inicializarNormalesVertices();
}