#include "cabezasinruedas.h"

CabezaSinRuedas::CabezaSinRuedas(){
    chimenea = new Chimenea ();
    prisma = new Prisma();
    grado_libertad_vagon = 0;
    maximo_giro = false;
    minimo_giro = false;

    Material bronce = Material ({0.7038, 0.27048,0.0828, 1}, {0.256777, 0.137622,0.086014, 1},{0.019125, 0.0735, 0.0225, 1}, 12.8);
    prisma->setMaterial(bronce);
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

void CabezaSinRuedas::modificarGradosLibertadHumoAutomatico(float valor){
    chimenea->modificarGradosLibertadHumoAutomatico(valor);
}

void CabezaSinRuedas::modificarGradosLibertadHumoManual(float valor){
    chimenea->modificarGradosLibertadHumoManual(valor);
}