#include "vagon.h"

Vagon::Vagon(){
    prisma = new Prisma();
    rueda_delantera1 = new Rueda();
    rueda_delantera2 = new Rueda();
    rueda_trasera1 = new Rueda();
    rueda_trasera2 = new Rueda();
    grados_libertad_vagon = 0;
    maximo_giro = false;
    minimo_giro = true;

    Material material = Material ({0.633, 0.727811,0.633, 1}, {0.633, 0.727811,0.633, 1},{0.0215, 0.1745, 0.0215, 1}, 64.0);
    prisma->setMaterial(material);
}

void Vagon::draw(modo_dibujado modo, bool ajedrez, bool tapas){
    glPushMatrix();
        glRotatef(grados_libertad_vagon,0,1,0);
        glTranslatef(0,10,0);
        prisma->draw(modo,ajedrez);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-20,0,-10);
        rueda_delantera1->draw(modo,ajedrez,tapas);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-20,0,-30);
        rueda_delantera2->draw(modo,ajedrez,tapas);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(20,0,-10);
        rueda_trasera1->draw(modo,ajedrez,tapas);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(20,0,-30);
        rueda_trasera2->draw(modo,ajedrez,tapas);
    glPopMatrix();
}

void Vagon::modificarGradosLibertadRuedas(float valor){
    rueda_delantera1->modificarGradosLibertadRuedas(valor);
    rueda_delantera2->modificarGradosLibertadRuedas(valor);
    rueda_trasera1->modificarGradosLibertadRuedas(valor);
    rueda_trasera2->modificarGradosLibertadRuedas(valor);
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