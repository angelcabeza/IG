#ifndef VAGON_H_INCLUDED
#define VAGON_H_INCLUDED

#include "malla.h"
#include "prisma.h"
#include "ruedasdelanteras.h"
#include "ruedastraseras.h"
#include "esfera.h"
#include "conectorvagones.h"

class Vagon : public Malla3D
{
    private:
        bool maximo_giro;
        bool minimo_giro;
        Prisma * prisma = nullptr;
        RuedasDelanteras * ruedasdelanteras = nullptr;
        RuedasTraseras * ruedastraseras = nullptr;
        float grados_libertad_vagon;
        Esfera * bisagra = nullptr;
        ConectorVagones * conector = nullptr;

    public:
        Vagon();
        void draw(modo_dibujado modo, bool ajedrez, bool tapas);
        void modificarGradosLibertadRuedasManual(float valor);
        void modificarGradosLibertadVagon(float valor);
        void modificarGradosLibertadRuedasAutomatico(float valor);
};

#endif