#ifndef CABEZACONRUEDAS_H_INCLUDED
#define CABEZACONRUEDAS_H_INCLUDED

#include "malla.h"
#include "cabezasinruedas.h"
#include "rueda.h"

class CabezaConRuedas : public Malla3D{
    private:
        bool maximo_giro;
        bool minimo_giro;
        float grados_libertad_vagon;
        CabezaSinRuedas * cabeza = nullptr;
        Rueda * rueda_delantera1 = nullptr;
        Rueda * rueda_delantera2 = nullptr;
        Rueda * rueda_trasera1 = nullptr;
        Rueda * rueda_trasera2 = nullptr;

    public:
        CabezaConRuedas();
        void draw(modo_dibujado modo, bool ajedrez,bool tapas);
        void modificarGradosLibertadHumo(float valor);
        void modificarGradosLibertadRuedas(float valor);
        void modificarGradosLibertadVagon(float valor);
};

#endif