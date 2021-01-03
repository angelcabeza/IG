#ifndef CUADRO_H_INCLUDED
#define CUADRO_H_INCLUDED

#include "malla.h"

class Cuadro : public Malla3D {
    private:
        void inicializarVertices(float lado);
        void inicializarCaras();
        void inicializarTexturas();
   public:
        Cuadro(float lado=50.0) ;
};

#endif