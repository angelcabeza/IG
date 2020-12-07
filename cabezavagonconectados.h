#ifndef CABEZAVAGONCONECTADOS_H_INCLUDED
#define CABEZAVAGONCONECTADOS_H_INCLUDED

#include "malla.h"
#include "vagon.h"
#include "cabezaconruedas.h"
#include "conectorvagones.h"


class CabezaVagonConectados : public Malla3D
{
    private:
        CabezaConRuedas * cabeza = nullptr;
        Vagon * vagon = nullptr;
        ConectorVagones * conector = nullptr;

    public:
        CabezaVagonConectados();
        void draw(modo_dibujado modo, bool ajedrez, bool tapas);
        void modificarGradosLibertadHumo(float valor);
        void modificarGradosLibertadRuedas(float valor);
        void modificarGradosLibertadConectores(float valor);
        void modificarGradosLibertadVagon(float valor);

};

#endif