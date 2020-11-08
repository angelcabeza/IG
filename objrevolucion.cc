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

ObjRevolucion::ObjRevolucion(const std::string & archivo, int num_instancias, bool tapa_sup, bool tapa_inf, int eje_rotacion){

   std::vector<Tupla3f> perfil_original;
   ply::read_vertices(archivo,perfil_original);

   if (tapa_sup && tapa_inf ){
      crearMalla(perfil_original,num_instancias,true);
   }
   else{
      crearMalla(perfil_original,num_instancias,tapa_sup,tapa_inf,eje_rotacion);
   }

   inicializarColores();
}

// *****************************************************************************
// objeto de revolución obtenido a partir de un perfil (en un vector de puntos)

 
ObjRevolucion::ObjRevolucion(std::vector<Tupla3f> archivo, int num_instancias, bool tapa_sup, bool tapa_inf,int eje_rotacion) {
   crearMalla(archivo,num_instancias,tapa_sup,tapa_inf,eje_rotacion);
   inicializarColores();
}

void ObjRevolucion::crearMalla(const std::vector<Tupla3f> & perfil_original, const int num_instancias_perfil, const bool conTapas,int eje_rotacion){

   std::vector<Tupla3f> perfil = perfil_original;

   // Si el perfil viene dado een orden descendente lo pongo en orden ascendente
   if (ordenDescendente(perfil)){
      cambiarOrden(perfil);
   }

   //Extraigo los polos del perfil y los almaceno aparte ¡¡CON UN PERFIL EN ORDEN ASSCENDENTE!!
   Tupla3f polo_sup, polo_inf;

   if(perfil[0](0) == 0.0){
      polo_inf = perfil[0];
      perfil.erase(perfil.begin());
   }
   else{
      polo_inf = {0.0,perfil[0](1),0.0};

   }

   if (perfil[perfil.size()-1](0) == 0.0){
      polo_sup = perfil[perfil.size()-1];
      perfil.pop_back();
   }
   else{
      polo_sup = {0.0,perfil[perfil.size()-1](1),0.0};
   }

   // RELLENAR LA TABLA DE VÉRTICES
   inicializarVertices(num_instancias_perfil,perfil);

   // RELLENAR LA TABLA DE CARAS (TRIANGULOS)

   inicializarCaras(num_instancias_perfil,perfil);

   // Si hay quee añadirle las tapas
   if (conTapas){
      v.push_back(polo_inf);
      v.push_back(polo_sup);

      const int M = perfil.size();

      // Genero los triangulos de las tapa inferior
      for(int i=0; i < num_instancias_perfil; i++){
         Tupla3i caraInf = {M*num_instancias_perfil, (M * (i+1)) % (M*num_instancias_perfil),(M * i)};

         //std::cout << "He insertado el triángulo: " << caraInf(0) << " " << caraInf(1) << " " << caraInf(2) << " " << "como tapa inferior" << std::endl;
         f.push_back(caraInf);
      }


      // Genero los triangulos de la tapa superior
      for(int i=0; i < num_instancias_perfil; i++){
         Tupla3i caraSup = {M * num_instancias_perfil + 1, ((M * (i+1)) -1), (M * (((i+1)%num_instancias_perfil)+1)-1) % (M*num_instancias_perfil)};

         //std::cout << "He insertado el triángulo: " << caraSup(0) << " " << caraSup(1) << " " << caraSup(2) << " " << "como tapa superior" << std::endl;
         f.push_back(caraSup);
      }
   }

   // DIVIDO LAS CARAS EN PARES E IMPARES PARA PODER DIBUJARLAS EN MODO AJEDREZ
   for (int i = 0; i < f.size(); i++){
      if ( i%2 == 0)
         caras_pares.push_back(f[i]);
      else
         caras_impares.push_back(f[i]);
   }
}

void ObjRevolucion::crearMalla(std::vector<Tupla3f> perfil_original, int num_instancias,bool tapa_sup, bool tapa_inf, int eje_rotacion) {


   // Si el perfil viene dado een orden descendente lo pongo en orden ascendente
   if (ordenDescendente(perfil_original)){
      cambiarOrden(perfil_original);
   }

   //Extraigo los polos del perfil y los almaceno aparte ¡¡CON UN PERFIL EN ORDEN ASSCENDENTE!!
   Tupla3f polo_sup, polo_inf;

   if(perfil_original[0](0) == 0.0){
      polo_inf = perfil_original[perfil_original.size()-1];
      perfil_original.erase(perfil_original.begin());
   }
   else{
      polo_inf = {0.0,perfil_original[0](1),0.0};
   }

   if (perfil_original[perfil_original.size()-1](0) == 0.0){
      polo_sup = perfil_original[0];
      perfil_original.pop_back();
   }
   else{
      polo_sup = {0.0,perfil_original[perfil_original.size()-1](1),0.0};
   }

   // INSTRUCCIONES PARA RELLENAR LA TABLA DE VÉRTICES
   inicializarVertices(num_instancias,perfil_original);

   // INSTRUCCIONES PARA RELLENAR LA TABLA DE CARAS (TRIANGULOS)
   inicializarCaras(num_instancias,perfil_original);
   
   const int M = perfil_original.size();

   if (tapa_inf){
      v.push_back(polo_inf);

      // Genero los triangulos de las tapa inferior
      for(int i=0; i < num_instancias; i++){
         Tupla3i caraInf = {M*num_instancias, (M * i), (M * (i+1))};
         f.push_back(caraInf);
      }
   }

   if (tapa_sup){
      v.push_back(polo_sup);

      // Genero los triangulos de la tapa superior
      for(int i=0; i < num_instancias; i++){
         Tupla3i caraSup = {M * num_instancias + 1, ((M * (i+1)) -1), (M * (((i+1)%num_instancias)+1)-1)};
         f.push_back(caraSup);
      }
   }

   // DIVIDO LAS CARAS EN PARES E IMPARES PARA PODER DIBUJARLAS EN MODO AJEDREZ
   for (int i = 0; i < f.size(); i++){
      if ( i%2 == 0)
         caras_pares.push_back(f[i]);
      else
         caras_impares.push_back(f[i]);
   }

}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//                  FUNCIONES PRIVATE QUE HE USADO PARA MEJORAR LA LEGIBILIDAD DEL CÓDIGO
//
//
////////////////////////////////////////////////////////////////////////////////////////////////////////


bool ObjRevolucion::ordenDescendente(std::vector<Tupla3f> perfil_original){
   return (perfil_original[0](1) > perfil_original[perfil_original.size()-1](1));
}



void ObjRevolucion::cambiarOrden(std::vector<Tupla3f> & perfil_original){
   std::vector<Tupla3f>::reverse_iterator it = perfil_original.rbegin();

   std::vector<Tupla3f> tmp;

   for (it; it != perfil_original.rend();it++){
      tmp.push_back(*(it));
   }

   perfil_original = tmp;
}



Tupla3f ObjRevolucion::RotarEjeY(Tupla3f vector, int num_instancias, std::vector<Tupla3f> perfil_original, int instancia_actual,int vertice_actual){
   vector(0) = cos((CONSTANTE_ROTACION*instancia_actual)/num_instancias) * perfil_original[vertice_actual][0] + sin((CONSTANTE_ROTACION*instancia_actual)/num_instancias) * perfil_original[vertice_actual][2];
   vector(1) = perfil_original[vertice_actual][1];
   vector(2) = -sin((CONSTANTE_ROTACION*instancia_actual)/num_instancias) * perfil_original[vertice_actual][0] + cos((CONSTANTE_ROTACION*instancia_actual)/num_instancias) * perfil_original[vertice_actual][2];

   return vector;
}

Tupla3f ObjRevolucion::RotarEjeX(Tupla3f vector, int num_instancias, std::vector<Tupla3f> perfil_original, int instancia_actual,int vertice_actual){
   vector(0) = perfil_original[vertice_actual][0];
   vector(1) = cos((CONSTANTE_ROTACION*instancia_actual)/num_instancias) * perfil_original[vertice_actual][1] - sin((CONSTANTE_ROTACION*instancia_actual)/num_instancias) * perfil_original[vertice_actual][2];
   vector(2) = sin((CONSTANTE_ROTACION*instancia_actual)/num_instancias) * perfil_original[vertice_actual][1] + cos((CONSTANTE_ROTACION*instancia_actual)/num_instancias) * perfil_original[vertice_actual][2];

   return vector;
}

Tupla3f ObjRevolucion::RotarEjeZ(Tupla3f vector, int num_instancias, std::vector<Tupla3f> perfil_original, int instancia_actual,int vertice_actual){
   vector(0) = cos((CONSTANTE_ROTACION*instancia_actual)/num_instancias) * perfil_original[vertice_actual][0] - sin((CONSTANTE_ROTACION*instancia_actual)/num_instancias) * perfil_original[vertice_actual][1];
   vector(1) = sin((CONSTANTE_ROTACION*instancia_actual)/num_instancias) * perfil_original[vertice_actual][0] + cos((CONSTANTE_ROTACION*instancia_actual)/num_instancias) * perfil_original[vertice_actual][1];
   vector(2) = perfil_original[vertice_actual][2];

   return vector;
}




void ObjRevolucion::inicializarColores(){
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



void ObjRevolucion::inicializarVertices(int num_instancias_perfil, std::vector<Tupla3f> & perfil,int eje_rotacion){
   v.clear();
   Tupla3f v_aux;
   
   for (int i = 0; i < num_instancias_perfil; i++){
      for (int j = 0; j < perfil.size(); j++){

         if (eje_rotacion == 0)                                                     // ROTAMOS EJE X
            v_aux = RotarEjeX(v_aux,num_instancias_perfil,perfil,i,j);
         else if (eje_rotacion == 1)                                                // ROTAMOS EJE Y
            v_aux = RotarEjeY(v_aux,num_instancias_perfil,perfil,i,j);
         else                                                                       // ROTAMOS EJE Z
            v_aux = RotarEjeZ(v_aux,num_instancias_perfil,perfil,i,j);

         v.push_back(v_aux);
      }
   }
}



void ObjRevolucion::inicializarCaras(int num_instancias_perfil, std::vector<Tupla3f> & perfil){
   f.clear();

   int a,b;
   Tupla3i cara1,cara2;

   for (int i = 0; i < num_instancias_perfil;i++){
      for (int j = 0; j < perfil.size()-1;j++){
         a = perfil.size() * i + j;
         b = perfil.size() * ((i+1)%num_instancias_perfil) +j;

         cara1 = {a,b,b+1};
         cara2 = {a,b+1,a+1};

         f.push_back(cara1);
         f.push_back(cara2);
      }
   }
}