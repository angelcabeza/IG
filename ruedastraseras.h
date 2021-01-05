#ifndef RUEDASTRASERAS_H_INCLUDED
#define RUEDASTRASERAS_H_INCLUDED

#include "malla.h"
#include "cilindro.h"

class RuedasTraseras : public Malla3D {
    private:
        Cilindro * rueda1 = nullptr;
        Cilindro * rueda2 = nullptr;
        float grados_rotacion;
    public:
        RuedasTraseras();
        void draw(modo_dibujado modo, bool ajedrez, bool tapas);
        void modificarGradosLibertadRuedasManual(float valor);
        void setColorSeleccion(Tupla3f color);
        void restaurarColorRuedasHumo();
};

#endif