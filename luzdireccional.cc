#include "luzdireccional.h"


LuzDireccional::LuzDireccional( const Tupla2f & orientacion,GLenum idLuzOpenGl, Tupla4f colorAmbiente, Tupla4f colorEspecular, Tupla4f colorDifuso){
    id = idLuzOpenGl; // es una luz direccional

    // w = 0 porque es direccional
    this->colorAmbiente = colorAmbiente;
    this->colorDifuso = colorDifuso;
    this->colorEspecular = colorEspecular;

    alpha = orientacion(0);
    beta = orientacion(1);

    actualizarPosicion();
}

void LuzDireccional::variarAnguloAlpha (float incremento){
    alpha += incremento;
    actualizarPosicion();
}

void LuzDireccional::variarAnguloBeta (float incremento){
    beta += incremento;
    actualizarPosicion();
}

void LuzDireccional::actualizarPosicion(){
    float x;
    float y;
    float z;

    // con radio 1
    x = sin(alpha) * cos(beta);
    y = sin(alpha) * sin(beta);
    z = cos(alpha);

    posicion = {x,y,z,0.0}; // w = 0 porque es direccional, tiene que estar en el infinito
}