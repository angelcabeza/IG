#include "luzdireccional.h"


LuzDireccional::LuzDireccional( const Tupla2f & orientacion,GLenum idLuzOpenGl, Tupla4f colorAmbiente, Tupla4f colorEspecular, Tupla4f colorDifuso){
    id = idLuzOpenGl; // es una luz direccional

    posicion = {1,1,1,0};
    // w = 0 porque es direccional
    this->colorAmbiente = colorAmbiente;
    this->colorDifuso = colorDifuso;
    this->colorEspecular = colorEspecular;

    alpha = orientacion(0);
    beta = orientacion(1);

}

void LuzDireccional::variarAnguloAlpha (float incremento){
    alpha += incremento;
}

void LuzDireccional::variarAnguloBeta (float incremento){
    beta += incremento;
}
void LuzDireccional::activar(){
   glEnable(this->id);

   //Le indico la posicion de la luz (infinito en este caso)
   glLightfv(this->id,)
}

// Esto no se si está bien porque no se como se inicializa la posicion :(
void LuzDireccional::actualizarPosicion(){
    float x;
    float y;
    float z;

    x = sin(beta*(M_PI/180.0));
    y = sin(alpha*(M_PI/180.0));
    z = sin(beta*(M_PI/180.0)) + cos(alpha*(M_PI/180.0));
}