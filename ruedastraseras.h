#ifndef RUEDASTRASERAS_H_INLCUDED
#define RUEDASTRASERAS_H_INCLUDED

#include "malla.h"
#include "esfera.h"

class RuedasTraseras : public Malla3D{
    private:
        Esfera * rueda1 = nullptr;
        Esfera * rueda2 = nullptr;
        float grados_rotacion;
    public:
        RuedasTraseras();
        void draw(modo_dibujado modo, bool ajedrez, bool tapas);
        void modificarGradosLibertadRuedasManual(float valor);
};

#endif