#ifndef CONECTORVAGONES_H_INCLUDED
#define CONECTORVAGONES_H_INCLUDED

#include "malla.h"
#include "cilindro.h"

class ConectorVagones : public Malla3D
{
    private:
        bool maximo_giro;
        bool minimo_giro;
        float grados_libertad_conector;
        Cilindro * cilindro = nullptr;

    public:
        ConectorVagones();
        void draw (modo_dibujado modo, bool ajedrez, bool tapas);
        void modificarGradosLibertadConectores(float valor);
        float getGradosLibertad();
};

#endif