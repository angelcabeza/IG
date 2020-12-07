#include "cabezaconruedas.h"

CabezaConRuedas::CabezaConRuedas(){
    cabeza = new CabezaSinRuedas();
    rueda_delantera1 = new Rueda();
    rueda_delantera2 = new Rueda();
    rueda_trasera1 = new Rueda();
    rueda_trasera2 = new Rueda();
    maximo_giro = false;
    minimo_giro = false;
    grados_libertad_vagon = 0;
}

void CabezaConRuedas::draw(modo_dibujado modo, bool ajedrez, bool tapas){

    glPushMatrix();
        glRotatef(grados_libertad_vagon,0,1,0);
        cabeza->draw(modo,ajedrez,tapas);
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

void CabezaConRuedas::modificarGradosLibertadHumo(float valor){
    cabeza->modificarGradosLibertadHumo(valor);
}

void CabezaConRuedas::modificarGradosLibertadRuedas(float valor){
    rueda_delantera1->modificarGradosLibertadRuedas(valor);
    rueda_delantera2->modificarGradosLibertadRuedas(valor);
    rueda_trasera1->modificarGradosLibertadRuedas(valor);
    rueda_trasera2->modificarGradosLibertadRuedas(valor);
}

void CabezaConRuedas::modificarGradosLibertadVagon(float valor){
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