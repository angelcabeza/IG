#ifndef LUZDIRECCIONAL_H_INCLUDED
#define LUZDIRECCIONAL_H_INCLUDED

#include "aux.h"
#include "luz.h"

class LuzDireccional : public Luz{

    protected:
        float alpha;
        float beta;

    public:
        //inicializar fuente de luz
        LuzDireccional(const Tupla2f & orientacion,GLenum idLuzOpenGl, Tupla4f colorAmbiente, Tupla4f colorEspecular, Tupla4f colorDifuso);

        //Cambiar angulo
        void variarAnguloAlpha( float incremento );
        void variarAnguloBeta ( float incremento );
        void actualizarPosicion();
};
#endif