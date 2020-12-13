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
    bisagra = new Esfera(100,100,10);
}

void CabezaConRuedas::draw(modo_dibujado modo, bool ajedrez, bool tapas){

    glPushMatrix();
        glRotatef(grados_libertad_vagon,0,1,0);
        cabeza->draw(modo,ajedrez,tapas);
    glPopMatrix();

    glPushMatrix();
        ruedasdelanteras->draw(modo,ajedrez,tapas);
    glPopMatrix();

    glPushMatrix();
        ruedastraseras->draw(modo,ajedrez,tapas);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0,20,0);
        glScalef(1,0.755,1);
        bisagra->draw(modo,ajedrez,tapas);
    glPopMatrix();
}

void CabezaConRuedas::modificarGradosLibertadHumo(float valor){
    cabeza->modificarGradosLibertadHumo(valor);
}

void CabezaConRuedas::modificarGradosLibertadRuedasManual(float valor){
    ruedasdelanteras->modificarGradosLibertadRuedasManual(valor);
    ruedastraseras->modificarGradosLibertadRuedasManual(valor)
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