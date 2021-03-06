// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: tetraedro.h

//
// #############################################################################

#ifndef TETRAEDRO_H_INCLUDED
#define TETRAEDRO_H_INCLUDED

#include "aux.h"

// *****************************************************************************
//
// clases derivadas de Malla3D (definen constructores específicos)
//
// *****************************************************************************

// *****************************************************************************
// Tetraedro con centro en el origen 

class Tetraedro: public Malla3D
{
   private:
      void inicializarVertices();
      void inicializarCaras();
   public:
      Tetraedro();

} ;




#endif
