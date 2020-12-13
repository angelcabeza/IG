#ifndef RUEDASDELANTERAS_H_INCLUDED
#define RUEDASDELANTERAS_H_INCLUDED


#include "malla.h"
#include "esfera.h"

class RuedasDelanteras : public Malla3D{
    private:
        Esfera * rueda1 = nullptr;
        Esfera * rueda2 = nullptr;
        float grados_rotacion;

    public:
        RuedasDelanteras();
        void draw(modo_dibujado modo, bool ajedrez, bool tapas);
        void modificarGradosLibertadRuedasManual(float valor);
};

#endif