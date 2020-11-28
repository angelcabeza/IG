#ifndef LUZ_H_INCLUDED
#define LUZ_H_INCLUDED

#include "aux.h"

class Luz{

    private:
        bool activada;
    protected:
        Tupla4f posicion;
        GLenum id;
        Tupla4f colorAmbiente;
        Tupla4f colorDifuso;
        Tupla4f colorEspecular;

    public:
        void activar();
        void desactivar();
        bool estaActivada();
};

#endif