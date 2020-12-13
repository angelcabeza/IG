#ifndef TREN_H_INCLUDED
#define TREN_H_INCLUDED

#include "malla.h"
#include "todoslosvagonesconectados.h"

class Tren : public Malla3D
{
    private:
        TodosLosVagonesConectados * tren = nullptr;
        float grados_libertad;
        bool maximo_giro;
        bool minimo_giro;
    public:
        Tren();
        void draw (modo_dibujado modo, bool ajedrez, bool tapas);
        void modificarGradosLibertadVagon1Manual(float valor);
        void modificarGradosLibertadVagon2Manual(float valor);
        void modificarGradosLibertadVagon3Manual(float valor);
        void modificarGradosLibertadVagon4Manual(float valor);
        void modificarGradosLibertadHumoManual(float valor);
        void modificarGradosLibertadRuedasManual(float valor);
        void modificarGradosLibertadVagon1Automatico(float valor);
        void modificarGradosLibertadVagon2Automatico(float valor);
        void modificarGradosLibertadVagon3Automatico(float valor);
        void modificarGradosLibertadVagon4Automatico(float valor);
        void modificarGradosLibertadHumoAutomatico(float valor);
        void modificarGradosLibertadRuedasAutomatico(float valor);
};

#endif