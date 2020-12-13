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

    public:
        TodosLosVagonesConectados();
        void draw(modo_dibujado modo, bool ajedrez, bool tapas);
        void modificarGradosLibertadManual(float valor);
};

#endif