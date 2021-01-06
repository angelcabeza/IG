#ifndef LUZPOSICIONAL_H_INCLUDED
#define LUZPOSICIONAL_H_INCLUDED

#include "aux.h"
#include "luz.h"

class LuzPosicional : public Luz{
    private:
        bool limite_izq_x;
        bool limite_dch_x;
        bool limite_arriba_y;
        bool limite_abajo_y;
        bool limite_z_pos;
        bool limite_z_neg;
    public:
        LuzPosicional( const Tupla3f & posicion,GLenum idLuzOpenGL,Tupla4f colorAmbiente, Tupla4f colorEspecular, Tupla4f colorDifuso);
        void cambiarPosicion(float x, float y, float z);
};
#endif