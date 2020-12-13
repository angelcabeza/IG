#ifndef DOSVAGONESCONECTADOS_H_INCLUDED
#define DOSVAGONESCONECTADOS_H_INLCUDED

#include "vagon.h"
#include "malla.h"
#include "conectorvagones.h"

class DosVagonesConectados : public Malla3D{
    private:
        Vagon * vagon1 = nullptr;
        Vagon * vagon2 = nullptr;
        ConectorVagones * conectorvagones = nullptr;
        float grados_libertad;
    public:
        DosVagonesConectados();
        void draw (modo_dibujado modo, bool ajedrez, bool tapas);
        void modificarGradosLibertadVagonesManual(float valor);
};

#endif