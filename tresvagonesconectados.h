#ifndef TRESVAGONESCONECTADOS_H_INCLUDED
#define TRESVAGONESCONECTADOS_H_INCLUDED

#include "malla.h"
#include "dosvagonesconectados.h"

class TresVagonesConectados : public Malla3D{
    private:
        DosVagonesConectados * dosvagones = nullptr;
        ConectorVagones * conector = nullptr;
        Vagon * vagon = nullptr;
        float grados_libertad = 0;

    public:
        TresVagonesConectados();
        void draw(modo_dibujado modo,bool ajedrez,bool tapas);
        void modificarGradosLibertadVagonesManual(float valor);
};

#endif