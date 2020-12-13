#include "ruedastraseras.h"

RuedasTraseras::RuedasTraseras(){
    rueda1 = new Esfera (100,100,10);
    rueda2 = new Esfera (100,10,10);
    grados_rotacion = 0;
}

void RuedasTraseras::draw(modo_dibujado modo, bool ajedrez, bool tapas){
    glPushMatrix();
        glTranslatef(-25,0,5);
        glRotatef(grados_rotacion,0,0,1);
        rueda1->draw(modo,ajedrez,tapas);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-25,0,15);
        glRotatef(grados_rotacion,0,0,1);
        rueda2->draw(modo,ajedrez,tapas);
    glPopMatrix();
}

void RuedasTraseras::modificarGradosLibertadRuedasManual(float valor){
    grados_rotacion += valor;
}