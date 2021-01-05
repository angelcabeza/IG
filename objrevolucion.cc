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

ObjRevolucion::ObjRevolucion(){}

ObjRevolucion::ObjRevolucion(const std::string & archivo, int num_instancias, bool textura,bool tapa_sup, bool tapa_inf, int eje_rotacion){
   this->con_textura = textura;
   this->num_instancias = num_instancias;
   ply::read_vertices(archivo,perfil);
   crearMalla(perfil,num_instancias,tapa_sup,tapa_inf,eje_rotacion);
   inicializarNormalesCaras();
   inicializarNormalesVertices();
   calcularCoordTexturas();
}

// *****************************************************************************
// objeto de revolución obtenido a partir de un perfil (en un vector de puntos)

 
ObjRevolucion::ObjRevolucion(std::vector<Tupla3f> archivo, int num_instancias, bool textura,bool tapa_sup, bool tapa_inf,int eje_rotacion) {
   this->con_textura = textura;
   this->num_instancias = num_instancias;
   perfil = archivo;
   crearMalla(archivo,num_instancias,tapa_sup,tapa_inf,eje_rotacion);
   inicializarNormalesCaras();
   inicializarNormalesVertices();
   calcularCoordTexturas();
}

void ObjRevolucion::crearMalla(std::vector<Tupla3f> perfil_original, int num_instancias,bool tapa_sup, bool tapa_inf, int eje_rotacion) {

   // Si el perfil viene dado een orden descendente lo pongo en orden ascendente
   if (ordenDescendente(perfil_original)){
      cambiarOrden(perfil_original);
   }

   //Extraigo los polos del perfil y los almaceno aparte ¡¡CON UN PERFIL EN ORDEN ASSCENDENTE!!
   Tupla3f polo_sup, polo_inf;

   const float EPSILON = 0.0000001;
   if((fabs(0.0 - perfil_original[0](0)) < EPSILON) && (fabs(0.0 - perfil_original[0](2) < EPSILON))){
      polo_inf = perfil_original[0];
      perfil_original.erase(perfil_original.begin());
   }
   else{
      polo_inf = {0.0,perfil_original[0](1),0.0};

   }

   if ((fabs(0.0 - perfil_original[perfil_original.size()-1](0)) < EPSILON) && (fabs(0.0 - perfil_original[perfil_original.size()-1](2)) < EPSILON)){
      polo_sup = perfil_original[perfil_original.size()-1];
      perfil_original.pop_back();
   }
   else{
      polo_sup = {0.0,perfil_original[perfil_original.size()-1](1),0.0};
   }


   if (con_textura && !esfera){
      num_instancias++;
   }

   // INSTRUCCIONES PARA RELLENAR LA TABLA DE VÉRTICES
   inicializarVertices(num_instancias,perfil_original,eje_rotacion);

   // INSTRUCCIONES PARA RELLENAR LA TABLA DE CARAS (TRIANGULOS)
   inicializarCaras(num_instancias,perfil_original);

   const int M = perfil_original.size();

   if (tapa_inf){
      v.push_back(polo_inf);
      // Genero los triangulos de las tapa inferior
      for(int i=0; i < num_instancias; i++){
         Tupla3i caraInf = {(M*(i+1))%(M*num_instancias),(M * i),M*num_instancias};
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

// Visualización en modo inmediato con 'glDrawElements' para OBJETOS DE REVOLUCION
void ObjRevolucion::draw_ModoInmediato(bool ajedrez,bool tapas)
{

   // visualizar la malla usando glDrawElements,
   // habilitar uso de un array de vértices
   glEnableClientState( GL_VERTEX_ARRAY );

   // indicar eel formato y la direccion de memoria del array de vértices
   // (son tuplas de 3 valores float, sin espacio entre ellas)

   glVertexPointer( 3, GL_FLOAT, 0, v.data() );

     // habilitar uso de un array de colores
   if (!glIsEnabled(GL_LIGHTING)){
      glEnableClientState ( GL_COLOR_ARRAY);
   }
   else{
      glEnableClientState( GL_NORMAL_ARRAY);
      glNormalPointer(GL_FLOAT,0,nv.data());

      m.aplicar();
   }

   if (!ct.empty() && glIsEnabled(GL_TEXTURE_2D)){
      glEnableClientState ( GL_TEXTURE_COORD_ARRAY);
      glTexCoordPointer ( 2, GL_FLOAT, 0, ct.data());
      textura->activar();
   }

   if (ajedrez){
      if (!glIsEnabled(GL_LIGHTING))
         glColorPointer(3,GL_FLOAT,0,color_ajedrez_pares.data());

      glDrawElements(GL_TRIANGLES,caras_pares.size()*3, GL_UNSIGNED_INT,caras_pares.data());

      if (!glIsEnabled(GL_LIGHTING))
         glColorPointer(3,GL_FLOAT,0,color_ajedrez_impares.data());

      glDrawElements(GL_TRIANGLES,caras_impares.size()*3, GL_UNSIGNED_INT,caras_impares.data());
   }
   else{
      if (!glIsEnabled(GL_LIGHTING)){
         glColorPointer(3,GL_FLOAT,0,color.data());
      }
      // visualizar, indicando tipo de primitiva, número de índices,
      // tipo de los índices y dirección de la tabla de índices

      if (tapas){
         glDrawElements (GL_TRIANGLES, f.size()*3, GL_UNSIGNED_INT, f.data());
      }else{
         glDrawElements (GL_TRIANGLES, (f.size()-2*num_instancias)*3, GL_UNSIGNED_INT, f.data());
      }

   }

   //deshabilitar array de vértices
   glDisableClientState ( GL_VERTEX_ARRAY);
   glDisableClientState ( GL_COLOR_ARRAY);

   if (!glIsEnabled(GL_LIGHTING))
      glDisableClientState ( GL_NORMAL_ARRAY);

   if(!ct.empty()){
      glDisableClientState ( GL_TEXTURE_COORD_ARRAY);
      //glDisable(GL_TEXTURE_2D);
   }

}

void ObjRevolucion::draw_ModoDiferido(bool tapas)
{
   // (la primera vez, se deben crear los VBOs y guardar sus identificadores en el objeto)
   // completar (práctica 1)
   // .....

   if (id_vbo_ver == 0){
      id_vbo_ver = CrearVBO( GL_ARRAY_BUFFER, 3*sizeof(float)*v.size(), v.data() );
   }

   if (id_vbo_col == 0){
      id_vbo_col = CrearVBO( GL_ARRAY_BUFFER, 3*sizeof(float)*color.size(),color.data());
   }

   if (id_vbo_tri == 0){
      id_vbo_tri = CrearVBO( GL_ELEMENT_ARRAY_BUFFER, 3*sizeof(int)*f.size() ,f.data() );
   }

   if (id_vbo_normal_vertex == 0){
      id_vbo_normal_vertex = CrearVBO( GL_ARRAY_BUFFER, 3*sizeof(float) * nv.size(), nv.data());
   }
   if (id_vbo_coord == 0){
      id_vbo_coord = CrearVBO( GL_ARRAY_BUFFER, 2*sizeof(float)*ct.size(), ct.data());
   }

   glBindBuffer ( GL_ARRAY_BUFFER, id_vbo_ver);    //activar VBO de vértices
   glVertexPointer (3, GL_FLOAT,0,0);              // especifica formato y off-set (=0)
   glBindBuffer ( GL_ARRAY_BUFFER,0);              // desactivar VBO de vértices.
   glEnableClientState( GL_VERTEX_ARRAY );         // habilitar tabla de vértices

   if (!glIsEnabled(GL_LIGHTING)){
      glBindBuffer (GL_ARRAY_BUFFER,id_vbo_col);
      glColorPointer (3,GL_FLOAT,0,0);
      glBindBuffer ( GL_ARRAY_BUFFER,0);
      glEnableClientState(GL_COLOR_ARRAY);
   }
   else{
      glEnableClientState(GL_NORMAL_ARRAY);
      glBindBuffer(GL_ARRAY_BUFFER,id_vbo_normal_vertex);
      glNormalPointer(GL_FLOAT,0,0);
      glBindBuffer(GL_ARRAY_BUFFER,0);
      m.aplicar();
   }

   if (!ct.empty() && glIsEnabled(GL_TEXTURE_2D)){
      textura->activar();
      glEnableClientState(GL_TEXTURE_COORD_ARRAY);
      glBindBuffer(GL_ARRAY_BUFFER,id_vbo_coord);
      glTexCoordPointer(2,GL_FLOAT,0,0);
      glBindBuffer(GL_ARRAY_BUFFER,0);
   }

   // visualizar triángulos con glDrawElements(puntero a tabla == 0)
   glBindBuffer (GL_ELEMENT_ARRAY_BUFFER, id_vbo_tri);                  // activar VBO de triángulos
   
   if (tapas)
      glDrawElements (GL_TRIANGLES, 3*f.size(), GL_UNSIGNED_INT, 0);
   else
      glDrawElements (GL_TRIANGLES, 3*(f.size()-2*num_instancias), GL_UNSIGNED_INT, 0);

   glBindBuffer( GL_ELEMENT_ARRAY_BUFFER,0);                            // desactivar VBO de triángulos


   // desactivar uso de array de vértices y de colores
   glDisableClientState( GL_VERTEX_ARRAY);
   glDisableClientState( GL_COLOR_ARRAY);

   if (glIsEnabled(GL_LIGHTING)){
      glDisableClientState( GL_NORMAL_ARRAY);
   }

}

void ObjRevolucion::draw(modo_dibujado modo, bool ajedrez,bool tapas)
{
   if (modo == DIFERIDO && !ajedrez){
      draw_ModoDiferido(tapas);
   }
   else{

      if (modo == DIFERIDO && ajedrez){
         std::cout << "El modo ajedrez solo se puede pintar en modo inmediato, ha sido redirigido al modo inmediato" << std::endl;
      }
      
      draw_ModoInmediato(ajedrez,tapas);
      
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




/*void ObjRevolucion::inicializarColores(){
   Tupla3f c_rojo = {1.0,0.0,0.0};
   Tupla3f c_verde = {0.0,1.0,0.0};
   Tupla3f c_naranja = {1.0,1.0,1.0};

   for (int i = 0; i < 3*f.size()/2; i++){
         color_ajedrez_pares.push_back(c_rojo);
         color_ajedrez_impares.push_back(c_verde);
   }

   for (int i = 0; i < v.size(); i++){
      color.push_back(c_naranja);
   }
}*/



void ObjRevolucion::inicializarVertices(int num_instancias_perfil, std::vector<Tupla3f> & perfil,int eje_rotacion){
   v.clear();
   Tupla3f v_aux;
   int contador = 0;
   
   for (int i = 0; i < num_instancias_perfil; i++){
      for (int j = 0; j < perfil.size(); j++){
            if (i == num_instancias_perfil-1 && con_textura){
               v.push_back(v[contador]);
               contador++;
            }
            else{
               if (eje_rotacion == 0){                                                     // ROTAMOS EJE X
                  v_aux = RotarEjeX(v_aux,num_instancias_perfil,perfil,i,j);
               }
               else if (eje_rotacion == 1)                                                // ROTAMOS EJE Y
                  v_aux = RotarEjeY(v_aux,num_instancias_perfil,perfil,i,j);
               else                                                                       // ROTAMOS EJE Z
                  v_aux = RotarEjeZ(v_aux,num_instancias_perfil,perfil,i,j);
               v.push_back(v_aux);
            }
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

int ObjRevolucion::getNumInstancias(){
   return this->num_instancias;
}

Tupla4f ObjRevolucion::getMaterial(){
   return m.getDifuso();
}

void ObjRevolucion::calcularCoordTexturas(){
   ct.resize(v.size());


   if (!esfera){
      std::cout << "Calculando coords textura cilidro " << std::endl;
      float alpha, beta, h;

      float s, t;
      std::vector<float> distancias;
      std::vector<Tupla2f> aux;
      distancias.resize(perfil.size());
      distancias[0] = 0.0;

      //M = num_vertices_perfil
      // N = num_instancias
      for (float i = 1; i < perfil.size(); i++){
         distancias[i] = distancias[i-1] - distanciasEntrePuntos(perfil[i], perfil[i-1]);
      }

      float i = 0;
      float j = perfil.size()-1;
      int contador = 0;

      ct.resize(v.size());

      for (int k = 0; k < ct.size()-2 ; k++){
         s = i / (num_instancias + 1);
         t = distancias[j] / distancias[perfil.size()-1];

         ct[k] = {s,t};

         if (j == 0){
            i++;
            j = perfil.size()-1;
         } else{
            j--;
         }

      }
   }
   else{
      float alpha;
      float beta;
      float aux;
      float t;
      float s;
      float x;
      float y;
      float z;

      for (int i = 0; i < ct.size(); i++){
         x = v[i](0);
         y = v[i](1);
         z = v[i](2);

         alpha = atan2(z,x);

         aux = sqrt(pow(x,2)+pow(z,2));
         beta = atan2(y,aux);

         s = 1- (0.5 + (alpha/(2*M_PI)));
         s+= 0.5;
         s= fmod(s,1.0);
         t = 0.5 + (beta/M_PI);

         ct[i] = {s,t};
      }
   }

}


float ObjRevolucion::distanciasEntrePuntos(Tupla3f anterior, Tupla3f actual){
   float x = pow(anterior(0)-actual(0),2);
   float y = pow(anterior(1)-actual(1),2);
   float z = pow(anterior(2)-actual(2),2);

   return sqrt(x+y+z);
}

void ObjRevolucion::setTextura(const Textura & text){
   this->textura = new Textura(text);
   calcularCoordTexturas();
}