#include "cabezasinruedas.h"

CabezaSinRuedas::CabezaSinRuedas(){
    chimenea = new Chimenea ();
    prisma = new Prisma();
    grado_libertad_vagon = 0;
    maximo_giro = false;
    minimo_giro = false;

    Material material = Material ({0.633, 0.727811,0.633, 1}, {0.633, 0.727811,0.633, 1},{0.0215, 0.1745, 0.0215, 1}, 64.0);
    prisma->setMaterial(material);
}

void CabezaSinRuedas::draw(modo_dibujado modo, bool ajedrez,bool tapas){
    glPushMatrix();
        glTranslatef(-60,50,5);
        chimenea->draw(modo,ajedrez,tapas);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-45,10,20);
        prisma->draw(modo,ajedrez);
    glPopMatrix();
}

void CabezaSinRuedas::modificarGradosLibertadHumo(float valor){
    chimenea->modificarGradosLibertadHumo(valor);
}
