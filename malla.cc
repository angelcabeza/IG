#include "aux.h"
#include "malla.h"

// *****************************************************************************
//
// Clase Malla3D
//
// *****************************************************************************

// Creación de un VBO
GLuint Malla3D::CrearVBO (GLuint tipo_vbo, GLuint tamanio_bytes, GLvoid * puntero_ram){

   GLuint id_vbo;                   // resultado identificador de VBO
   glGenBuffers(1,&id_vbo);         // crear nuevo VBO, obtener identificador (nunca 0)
   glBindBuffer(tipo_vbo,id_vbo);   //activar el VBO usando su identificador


   // esta instrucción hace la transferencia de datos desde RAM hacia GPU
   glBufferData(tipo_vbo,tamanio_bytes,puntero_ram,GL_STATIC_DRAW);

   glBindBuffer(tipo_vbo,0);        // desactivación del VBO (activar 0)
   return id_vbo;                   // devolver el identificador resultado
}

// Visualización en modo inmediato con 'glDrawElements'

void Malla3D::draw_ModoInmediato(bool ajedrez)
{

   // visualizar la malla usando glDrawElements,
   // habilitar uso de un array de vértices
   glEnableClientState( GL_VERTEX_ARRAY );

   // indicar eel formato y la direccion de memoria del array de vértices
   // (son tuplas de 3 valores float, sin espacio entre ellas)

   glVertexPointer( 3, GL_FLOAT, 0, v.data() );

   // habilitar uso de un array de colores
   glEnableClientState ( GL_COLOR_ARRAY);

   if (ajedrez){
      glColorPointer(3,GL_FLOAT,0,color_ajedrez_pares.data());
      glDrawElements(GL_TRIANGLES,caras_pares.size()*3, GL_UNSIGNED_INT,caras_pares.data());

      glColorPointer(3,GL_FLOAT,0,color_ajedrez_impares.data());
      glDrawElements(GL_TRIANGLES,caras_impares.size()*3, GL_UNSIGNED_INT,caras_impares.data());
   }
   else{
      glColorPointer(3,GL_FLOAT,0,color.data());
      // visualizar, indicando tipo de primitiva, número de índices,
      // tipo de los índices y dirección de la tabla de índices

      glDrawElements (GL_TRIANGLES, f.size()*3, GL_UNSIGNED_INT, f.data());
   }

   //deshabilitar array de vértices
   glDisableClientState ( GL_VERTEX_ARRAY);
   glDisableClientState ( GL_COLOR_ARRAY);

}

// -----------------------------------------------------------------------------
// Visualización en modo diferido con 'glDrawElements' (usando VBOs)

void Malla3D::draw_ModoDiferido()
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

   glBindBuffer ( GL_ARRAY_BUFFER, id_vbo_ver);    //activar VBO de vértices
   glVertexPointer (3, GL_FLOAT,0,0);              // especifica formato y off-set (=0)
   glBindBuffer ( GL_ARRAY_BUFFER,0);              // desactivar VBO de vértices.
   glEnableClientState( GL_VERTEX_ARRAY );         // habilitar tabla de vértices

   glBindBuffer (GL_ARRAY_BUFFER,id_vbo_col);
   glColorPointer (3,GL_FLOAT,0,0);
   glBindBuffer ( GL_ARRAY_BUFFER,0);
   glEnableClientState(GL_COLOR_ARRAY);


   // visualizar triángulos con glDrawElements(puntero a tabla == 0)
   glBindBuffer (GL_ELEMENT_ARRAY_BUFFER, id_vbo_tri);                  // activar VBO de triángulos
   glDrawElements (GL_TRIANGLES, 3*f.size(), GL_UNSIGNED_INT, 0);
   glBindBuffer( GL_ELEMENT_ARRAY_BUFFER,0);                            // desactivar VBO de triángulos


   // desactivar uso de array de vértices y de colores
   glDisableClientState( GL_VERTEX_ARRAY);
   glDisableClientState( GL_COLOR_ARRAY);

}

void Malla3D::draw_Suavizado(bool ajedrez){
   //acitva el modo de sombreado suave
   glShadeModel(GL_SMOOTH);

   // visualizar la malla usando glDrawElements,
   // habilitar uso de un array de vértices
   glEnableClientState( GL_VERTEX_ARRAY );

   // indicar eel formato y la direccion de memoria del array de vértices
   // (son tuplas de 3 valores float, sin espacio entre ellas)

   glVertexPointer( 3, GL_FLOAT, 0, v.data() );


   if (ajedrez){
      glDrawElements(GL_TRIANGLES,caras_pares.size()*3, GL_UNSIGNED_INT,caras_pares.data());
      glDrawElements(GL_TRIANGLES,caras_impares.size()*3, GL_UNSIGNED_INT,caras_impares.data());
   }
   else{
      // visualizar, indicando tipo de primitiva, número de índices,
      // tipo de los índices y dirección de la tabla de índices

      glDrawElements (GL_TRIANGLES, f.size()*3, GL_UNSIGNED_INT, f.data());
   }

   //deshabilitar array de vértices
   glDisableClientState ( GL_VERTEX_ARRAY);
   glDisableClientState ( GL_COLOR_ARRAY);
}

void Malla3D::draw_Plano(bool ajedrez){
   //acitva el modo de sombreado suave
   glShadeModel(GL_FLAT);

   // visualizar la malla usando glDrawElements,
   // habilitar uso de un array de vértices
   glEnableClientState( GL_VERTEX_ARRAY );

   // indicar eel formato y la direccion de memoria del array de vértices
   // (son tuplas de 3 valores float, sin espacio entre ellas)

   glVertexPointer( 3, GL_FLOAT, 0, v.data() );


   if (ajedrez){
      glDrawElements(GL_TRIANGLES,caras_pares.size()*3, GL_UNSIGNED_INT,caras_pares.data());
      glDrawElements(GL_TRIANGLES,caras_impares.size()*3, GL_UNSIGNED_INT,caras_impares.data());
   }
   else{
      // visualizar, indicando tipo de primitiva, número de índices,
      // tipo de los índices y dirección de la tabla de índices

      glDrawElements (GL_TRIANGLES, f.size()*3, GL_UNSIGNED_INT, f.data());
   }

   //deshabilitar array de vértices
   glDisableClientState ( GL_VERTEX_ARRAY);
   glDisableClientState ( GL_COLOR_ARRAY);
}


// -----------------------------------------------------------------------------
// Función de visualización de la malla,
// puede llamar a  draw_ModoInmediato o bien a draw_ModoDiferido

void Malla3D::draw(modo_dibujado modo, bool ajedrez)
{
   if (modo == DIFERIDO && !ajedrez){
      draw_ModoDiferido();
   }
   else{

      if (modo == DIFERIDO && ajedrez){
         std::cout << "El modo ajedrez solo se puede pintar en modo inmediato, ha sido redirigido al modo inmediato" << std::endl;
      }
      
      draw_ModoInmediato(ajedrez);
      
   }
   
}