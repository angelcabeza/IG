#ifndef RUEDA_H_INCLUDED
#define RUEDA_H_INCLUDED

#include "malla.h"
#include "cilindro.h"

class Rueda : public Malla3D{

    private:
        bool maximo_giro;
        bool minimo_giro;
        float grados_libertad_ruedas;
        Cilindro * cilindro = nullptr;

    public:
        Rueda();
        void draw(modo_dibujado modo, bool ajedrez,bool tapas);
        void modificarGradosLibertadRuedas(float valor);
};

#endif