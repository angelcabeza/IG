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
        bool maximo_giro;
        bool minimo_giro;
    public:
        DosVagonesConectados();
        void draw (modo_dibujado modo, bool ajedrez, bool tapas);
        void modificarGradosLibertadVagon4Manual(float valor);
        void modificarGradosLibertadRuedasManual(float valor);
        void modificarGradosLibertadRuedasAutomatico(float valor);
        void modificarGradosLibertadVagon4Automatico(float valor);
};

#endif