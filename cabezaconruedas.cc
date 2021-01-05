#include "cabezaconruedas.h"

CabezaConRuedas::CabezaConRuedas(){
    cabeza = new CabezaSinRuedas();
    ruedasdelanteras = new RuedasDelanteras();
    ruedastraseras = new RuedasTraseras();
    maximo_giro = false;
    minimo_giro = false;
    grados_libertad_vagon = 0;
}

void CabezaConRuedas::draw(modo_dibujado modo, bool ajedrez, bool tapas){

    glPushMatrix();
        cabeza->draw(modo,ajedrez,tapas);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-45,0,0);
        ruedasdelanteras->draw(modo,ajedrez,tapas);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-45,0,0);
        ruedastraseras->draw(modo,ajedrez,tapas);
    glPopMatrix();
}

void CabezaConRuedas::modificarGradosLibertadHumoAutomatico(float valor){
    cabeza->modificarGradosLibertadHumoAutomatico(valor);
}

void CabezaConRuedas::modificarGradosLibertadRuedasManual(float valor){
    ruedasdelanteras->modificarGradosLibertadRuedasManual(valor);
    ruedastraseras->modificarGradosLibertadRuedasManual(valor);
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

void CabezaConRuedas::modificarGradosLibertadHumoManual(float valor){
    cabeza->modificarGradosLibertadHumoManual(valor);
}

void CabezaConRuedas::modificarGradosLibertadRuedasAutomatico(float valor){
    ruedasdelanteras->modificarGradosLibertadRuedasManual(valor);
    ruedastraseras->modificarGradosLibertadRuedasManual(valor);
}

void CabezaConRuedas::setColorSeleccion(Tupla3f color){
    ruedasdelanteras->setColorSeleccion(color);
    ruedastraseras->setColorSeleccion(color);
    cabeza->setColorSeleccion(color);
}

void CabezaConRuedas::restaurarColorVagones(){
    cabeza->restaurarColorVagones();
}

void CabezaConRuedas::restaurarColorConectoresChimenea(){
    cabeza->restaurarColorConectoresChimenea();
}

void CabezaConRuedas::restaurarColorRuedasHumo(){
    cabeza->restaurarColorRuedasHumo();
    ruedasdelanteras->restaurarColorRuedasHumo();
    ruedastraseras->restaurarColorRuedasHumo();
}