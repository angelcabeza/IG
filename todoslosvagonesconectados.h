#ifndef TODOSLOSVAGONESCONECTADOS_H_INCLUDED
#define TODOSLOSVAGONESCONECTADOS_H_INCLUDED

#include "malla.h"
#include "tresvagonesconectados.h"
#include "cabezaconruedas.h"

class TodosLosVagonesConectados : public Malla3D{
    private:
        TresVagonesConectados * tresvagones = nullptr;
        ConectorVagones * conector = nullptr;
        CabezaConRuedas * cabeza = nullptr;
        float grados_libertad;
        bool maximo_giro;
        bool minimo_giro;

    public:
        TodosLosVagonesConectados();
        void draw(modo_dibujado modo, bool ajedrez, bool tapas);
        void modificarGradosLibertadVagon2Manual(float valor);
        void modificarGradosLibertadVagon3Manual(float valor);
        void modificarGradosLibertadVagon4Manual(float valor);
        void modificarGradosLibertadHumoManual(float valor);
        void modificarGradosLibertadRuedasManual(float valor);
        void modificarGradosLibertadVagon2Automatico(float valor);
        void modificarGradosLibertadVagon3Automatico(float valor);
        void modificarGradosLibertadVagon4Automatico(float valor);
        void modificarGradosLibertadHumoAutomatico(float valor);
        void modificarGradosLibertadRuedasAutomatico(float valor);
};

#endif