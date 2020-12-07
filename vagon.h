#ifndef VAGON_H_INCLUDED
#define VAGON_H_INCLUDED

#include "malla.h"
#include "prisma.h"
#include "rueda.h"

class Vagon : public Malla3D
{
    private:
        bool maximo_giro;
        bool minimo_giro;
        Prisma * prisma = nullptr;
        Rueda * rueda_delantera1 = nullptr;
        Rueda * rueda_delantera2 = nullptr;
        Rueda * rueda_trasera1 = nullptr;
        Rueda * rueda_trasera2 = nullptr;
        float grados_libertad_vagon;

    public:
        Vagon();
        void draw(modo_dibujado modo, bool ajedrez, bool tapas);
        void modificarGradosLibertadRuedas(float valor);
        void modificarGradosLibertadVagon(float valor);
};

#endif