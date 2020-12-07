#ifndef VAGONESTRASEROSCONECTADOS_H_INCLUDED
#define VAGONESTRASEROSCONECTADOS_H_INCLUDED

#include "malla.h"
#include "vagon.h"
#include "conectorvagones.h"

class VagonesTraserosConectados : public Malla3D
{

    private:
        Vagon * vagon1 = nullptr;
        Vagon * vagon2 = nullptr;
        ConectorVagones * conector = nullptr;

    public:

        VagonesTraserosConectados();
        void draw(modo_dibujado modo, bool ajedrez, bool tapas);
        void modificarGradosLibertadRuedas(float valor);
        void modificarGradosLibertadConectores(float valor);
        void modificarGradosLibertadVagones(float valor);
};

#endif