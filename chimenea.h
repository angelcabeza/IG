#ifndef CHIMENEA_H_INCLUDED
#define CHIMENEA_H_INCLUDED

#include "malla.h"
#include "cilindro.h"
#include "humo.h"

class Chimenea : public Malla3D{

    private:
        Cilindro * base_chimenea = nullptr;
        Humo * humo = nullptr;

    public:
        Chimenea();
        void draw(modo_dibujado modo, bool ajedrez,bool tapas);
        void modificarGradosLibertadHumoAutomatico(float valor);
        void modificarGradosLibertadHumoManual(float valor);
        void setColorSeleccion(Tupla3f color);
        void restaurarColorConectoresChimenea();
        void restaurarColorRuedasHumo();
};

#endif