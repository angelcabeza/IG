#include "luzposicional.h"

LuzPosicional::LuzPosicional( const Tupla3f & posicion,GLenum idLuzOpenGL,Tupla4f colorAmbiente, Tupla4f colorEspecular, Tupla4f colorDifuso){
    limite_dch_x = false;
    limite_izq_x = false;
    limite_abajo_y = false;
    limite_arriba_y = false;
    limite_z_neg = false;
    limite_z_pos = false;
    
    Tupla4f posicion_4D = {posicion(0),posicion(1),posicion(2),1};
    this->id = idLuzOpenGL;
    this->posicion = posicion_4D;

    this->colorAmbiente = colorAmbiente;
    this->colorEspecular = colorEspecular;
    this->colorDifuso = colorDifuso;
}

void LuzPosicional::cambiarPosicion(float x, float y, float z){
    if (posicion[0] >= 500){
        limite_dch_x = true;
        limite_izq_x = false;
    }
    if (posicion[1] >= 500){
        limite_abajo_y = false;
        limite_arriba_y = true;
    }
    if (posicion[2] >= 500){
        limite_z_neg = false;
        limite_z_pos = true;
    }
    if (posicion[0] <= -500){
        limite_izq_x = true;
        limite_dch_x = false;
    }
    if (posicion[1] <= 0){
        limite_abajo_y = true;
        limite_arriba_y = false;
    }
    if (posicion[2] <= 0){
        limite_z_neg = true;
        limite_z_pos = false;
    }

    if (limite_dch_x && x > 0)
        x = -x;
    else if (limite_izq_x && x < 0)
        x = -x;
    
    if (limite_arriba_y && y > 0)
        y = -y;
    else if (limite_abajo_y && y < 0)
        y = -y;

    if (limite_z_pos && z > 0)
        z = -z;
    else if (limite_z_neg && z < 0)
        z = -z;   

    posicion[0] += x;
    posicion[1] += y;
    posicion[2] += z;
}