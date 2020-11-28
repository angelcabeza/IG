#include "luzposicional.h"

LuzPosicional::LuzPosicional( const Tupla3f & posicion,GLenum idLuzOpenGL,Tupla4f colorAmbiente, Tupla4f colorEspecular, Tupla4f colorDifuso){

    Tupla4f posicion_4D = {posicion(0),posicion(1),posicion(2),1};
    this->id = idLuzOpenGL;
    this->posicion = posicion_4D;

    this->colorAmbiente = colorAmbiente;
    this->colorEspecular = colorEspecular;
    this->colorDifuso = colorDifuso;
}