#ifndef TREN_H_INCLUDED
#define TREN_H_INCLUDED

#include "malla.h"
#include "todoslosvagonesconectados.h"

class Tren : public Malla3D
{
    private:
        TodosLosVagonesConectados * tren = nullptr;
        float grados_libertad;
    public:
        Tren();
        void draw (modo_dibujado modo, bool ajedrez, bool tapas);
};

#endif