#include "ruedastraseras.h"

RuedasTraseras::RuedasTraseras(){
    rueda1 = new Cilindro (100,100,20,10);
    rueda2 = new Cilindro (100,100,20,10);
    grados_rotacion = 0;

    Material black_plastic = Material({0.01, 0.01 ,0.01, 1}, {0.5, 0.5, 0.5, 1}, {0.0 ,0.0 ,0.0, 1.0}, 32);

    rueda1->setMaterial(black_plastic);
    rueda2->setMaterial(black_plastic);
}

void RuedasTraseras::draw(modo_dibujado modo, bool ajedrez, bool tapas){
    glPushMatrix();
        glTranslatef(105,0,5);
        glRotatef(grados_rotacion,0,0,1);
        glRotatef(90,1,0,0);
        glScalef(1,0.5,1);
        rueda1->draw(modo,ajedrez,tapas);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(105,0,-15);
        glRotatef(grados_rotacion,0,0,1);
        glRotatef(90,1,0,0);
        glScalef(1,0.5,1);
        rueda2->draw(modo,ajedrez,tapas);
    glPopMatrix();
}

void RuedasTraseras::modificarGradosLibertadRuedasManual(float valor){
    grados_rotacion += valor;
}