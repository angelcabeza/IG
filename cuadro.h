#ifndef CUADRO_H_INCLUDED
#define CUADRO_H_INCLUDED

#include "malla.h"

class Cuadro : public Malla3D {
    private:
        void inicializarVertices();
        void inicializarCaras();
        void inicializarColores();
        void inicializarTexturas();
   public:
        Cuadro() ;
};

#endif