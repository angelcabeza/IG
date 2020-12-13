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
        bool maximo_giro;
        bool minimo_giro;

    public:
        TresVagonesConectados();
        void draw(modo_dibujado modo,bool ajedrez,bool tapas);
        void modificarGradosLibertadVagon3Manual(float valor);
        void modificarGradosLibertadVagon4Manual(float valor);
        void modificarGradosLibertadRuedasManual(float valor);
        void modificarGradosLibertadRuedasAutomatico(float valor);
        void modificarGradosLibertadVagon3Automatico(float valor);
        void modificarGradosLibertadVagon4Automatico(float valor);
};

#endif