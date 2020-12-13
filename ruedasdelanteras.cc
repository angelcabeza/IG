#include "ruedasdelanteras.h"

RuedasDelanteras::RuedasDelanteras(){
    rueda1 = new Cilindro(100,100,20,10);
    rueda2 = new Cilindro(100,100,20,10);
    grados_rotacion = 0;
}

void RuedasDelanteras::draw(modo_dibujado modo, bool ajedrez, bool tapas){
    glPushMatrix();
        glTranslatef(-70,0,-15);
        glRotatef(grados_rotacion,0,0,90);
        glRotatef(90,1,0,0);
        glScalef(1,0.5,1);
        rueda1->draw(modo,ajedrez,tapas);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-70,0,5);
        glRotatef(grados_rotacion,0,0,90);
        glRotatef(90,1,0,0);
        glScalef(1,0.5,1);
        rueda2->draw(modo,ajedrez,tapas);
    glPopMatrix();
}

void RuedasDelanteras::modificarGradosLibertadRuedasManual(float valor){
    grados_rotacion += valor;
}