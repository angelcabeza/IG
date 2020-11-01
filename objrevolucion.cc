#include "aux.h"
#include "objrevolucion.h"
#include "ply_reader.h"




// *****************************************************************************
//
// Clase ObjRevolucion (práctica 2)
//
// *****************************************************************************


// *****************************************************************************
// objeto de revolución obtenido a partir de un perfil (en un PLY)

ObjRevolucion::ObjRevolucion() {}

ObjRevolucion::ObjRevolucion(const std::string & archivo, int num_instancias, bool tapa_sup, bool tapa_inf){

   std::vector<Tupla3f> perfil_original;
   ply::read_vertices(archivo,perfil_original);
   crearMalla(perfil_original,num_instancias);
}

// *****************************************************************************
// objeto de revolución obtenido a partir de un perfil (en un vector de puntos)

 
ObjRevolucion::ObjRevolucion(std::vector<Tupla3f> archivo, int num_instancias, bool tapa_sup, bool tapa_inf) {
}

void ObjRevolucion::crearMalla(std::vector<Tupla3f> perfil_original, int num_instancias) {


   //Extraigo los polos del perfil y los almaceno aparte ¡¡CON UN PERFIL EN ORDEN ASSCENDENTE!!
   Tupla3f polo_sup, polo_inf;

   if (ordenDescendente(perfil_original)){
      std::cout << "El orden es descendente" << std::endl;
      cambiarOrden(perfil_original);
   }

   std::cout << "Primer punto ply: " << perfil_original[0] << std::endl;
   if(perfil_original[0](0) == 0.0){
      std::cout << "HE ENTRADO TAPA INFERIOR" << std::endl;
      polo_inf = perfil_original[perfil_original.size()-1];
      perfil_original.erase(perfil_original.begin());
   }
   else{
      polo_inf = {0.0,perfil_original[0](1),0.0};
      std::cout << "Polo sur: " << polo_inf << std::endl;
   }

   if (perfil_original[perfil_original.size()-1](0) == 0.0){
      std::cout << "HE ENTRADO TAPA SUPERIOR" << std::endl;
      polo_sup = perfil_original[0];
      perfil_original.pop_back();
   }
   else{
      polo_sup = {0.0,perfil_original[perfil_original.size()-1](1),0.0};
      std::cout << "Polo norte: " << polo_sup << std::endl;
   }

   // INSTRUCCIONES PARA RELLENAR LA TABLA DE VÉRTICES
   v.clear();

   for (int i = 0; i < num_instancias; i++){
      for (int j = 0; j < perfil_original.size(); j++){
         Tupla3f v_aux;
         v_aux(0) = cos((2*M_PI*i)/num_instancias) * perfil_original[j][0] + sin((2*M_PI*i)/num_instancias) * perfil_original[j][2];
         v_aux(1) = perfil_original[j][1];
         v_aux(2) = -sin((2*M_PI*i)/num_instancias) * perfil_original[j][0] + cos((2*M_PI*i)/num_instancias) * perfil_original[j][2];
         v.push_back(v_aux);
      }
   }

   // INSTRUCCIONES PARA RELLENAR LA TABLA DE CARAS (TRIANGULOS)
   f.clear();

   int a,b;
   Tupla3i cara1,cara2;

   for (int i = 0; i < num_instancias;i++){
      for (int j = 0; j < perfil_original.size()-1;j++){
         a = perfil_original.size() * i + j;
         b = perfil_original.size() * ((i+1)%num_instancias) +j;

         cara1 = {a,b,b+1};
         cara2 = {a,b+1,a+1};

         f.push_back(cara1);
         f.push_back(cara2);
      }
   }

   std::cout << "NUMERO DE VERTICES: " << v.size() << std::endl;

   v.push_back(polo_inf);
   v.push_back(polo_sup);

   const int M = perfil_original.size();

   std::cout << "PERFIL ORIGINAL SIZE: " << perfil_original.size() << std::endl;
   std::cout << "NUMERO DE VERTICES: " << v.size() << std::endl;

   std::cout << "Polo Sur: " << v[M*num_instancias] << std::endl;

   // Genero los triangulos de las tapa inferior
   for(int i=0; i < num_instancias; i++){
      Tupla3i caraInf = {M*num_instancias, (M * i), (M * (i+1))};
      f.push_back(caraInf);
   }

   // Genero los triangulos de la tapa superior
   for(int i=0; i < num_instancias; i++){
      Tupla3i caraSup = {M * num_instancias + 1, ((M * (i+1)) -1), (M * (((i+1)%num_instancias)+1)-1)};
      f.push_back(caraSup);
   }

}

bool ObjRevolucion::ordenDescendente(std::vector<Tupla3f> perfil_original){
   return (perfil_original[0](1) > perfil_original[perfil_original.size()-1](1));
}

void ObjRevolucion::cambiarOrden(std::vector<Tupla3f> perfil_original){
   std::vector<Tupla3f>::reverse_iterator it = perfil_original.rbegin();

   std::vector<Tupla3f> tmp;

   for (it; it != perfil_original.rend();it++){
      tmp.push_back(*(it));
   }

   perfil_original = tmp;
}

