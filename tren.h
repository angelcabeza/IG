#ifndef TREN_H_INCLUDED
#define TREN_H_INCLUDED

#include "malla.h"
#include "vagonestraserosconectados.h"
#include "cabezavagonconectados.h"
#include "conectorvagones.h"

class Tren : public Malla3D
{
    private:
        VagonesTraserosConectados * vagonestraseros = nullptr;
        CabezaVagonConectados * vagonesdelanteros = nullptr;
        ConectorVagones * conector = nullptr;

    public:
        Tren();
        void draw (modo_dibujado modo, bool ajedrez, bool tapas);
        void modificarGradosLibertadHumo(float valor);
        void modificarGradosLibertadRuedas(float valor);
        void modificarGradosLibertadConectores(float valor);
        void modificarGradosLibertadVagones(float valor);
        void modificarGradosLibertadHumoManual(float valor);
        void modificarGradosLibertadRuedasManual(float valor);
        void modificarGradosLibertadConectoresManual(float valor);
        void modificarGradosLibertadVagonesManual(float valor);
};

#endif