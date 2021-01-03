#ifndef PRISMA_H_INCLUDED
#define PRISMA_H_INCLUDED

#include "aux.h"

class Prisma : public Malla3D
{
    private:
        void inicializarVertices(float lado,float ancho);
        void inicializarCaras();

    public:
        Prisma(float lado=40, float ancho=80);
};

#endif