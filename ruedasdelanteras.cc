#include "ruedasdelanteras.h"

RuedasDelanteras::RuedasDelanteras(){
    rueda1 = new Esfera(100,100,10);
    rueda2 = new Esfera(100,100,10);
    grados_rotacion = 0;
}

void RuedasDelanteras::draw(modo_dibujado modo, bool ajedrez, bool tapas){
    glPushMatrix();
        glTranslatf(-70,0,5);
        glRotatef(grados_rotacion,0,0,90);
        rueda1->draw(modo,ajedrez,tapas);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-10,0,15);
        glRotatef(grados_rotacion,0,0,90);
        rueda2->draw(modo,ajedrez,tapas);
    glPopMatrix();
}

void RuedasDelanteras::modificarGradosLibertadRuedasManual(float valor){
    grados_rotacion += valor;
}