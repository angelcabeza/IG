#ifndef HUMO_H_INCLUDED
#define HUMO_H_INCLUDED

#include "malla.h"
#include "esfera.h"

class Humo : public Malla3D{
    private:
        bool maxima_altura;
        bool minima_altura;
        float grados_libertad_humo;
        Esfera * esfera = nullptr;

    public:
        Humo();

        void draw(modo_dibujado modo, bool ajedrez,bool tapas);
        void modificarGradosLibertadHumo(float valor);
        void modificarGradosLibertadHumoManual(float valor);
};

#endif