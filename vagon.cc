#include "vagon.h"

Vagon::Vagon(){
    prisma = new Prisma();
    ruedasdelanteras = new RuedasDelanteras();
    ruedastraseras = new RuedasTraseras();
    bisagra = new Esfera(100,100,10);
    grados_libertad_vagon = 0;
    maximo_giro = false;
    minimo_giro = true;

    Material material = Material ({0.633, 0.727811,0.633, 1}, {0.633, 0.727811,0.633, 1},{0.0215, 0.1745, 0.0215, 1}, 64.0);
    prisma->setMaterial(material);
}

void Vagon::draw(modo_dibujado modo, bool ajedrez, bool tapas){
    glPushMatrix();
        glTranslatef(-45,10,20);
        prisma->draw(modo,ajedrez);
    glPopMatrix();

    glPushMatrix();
        ruedasdelanteras->draw(modo,ajedrez,tapas);
    glPopMatrix();

    glPushMatrix();
        ruedastraseras->draw(modo,ajedrez,tapas);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0,20,0);
        glScalef(1,0.75,1);
        bisagra->draw(modo,ajedrez,tapas);
    glPopMatrix();
}

void Vagon::modificarGradosLibertadRuedasManual(float valor){
    ruedasdelanteras->modificarGradosLibertadRuedasManual(valor);
    ruedastraseras->modificarGradosLibertadRuedasManual(valor);
}

void Vagon::modificarGradosLibertadVagon(float valor){
    if ( (maximo_giro && valor > 0) || (minimo_giro && valor < 0))
        valor = -valor;

    grados_libertad_vagon += valor;

    if (grados_libertad_vagon >= 15){
        maximo_giro = true;
        minimo_giro = false;
    }

    if (grados_libertad_vagon <= -15){
        maximo_giro = false;
        minimo_giro = true;
    }
}