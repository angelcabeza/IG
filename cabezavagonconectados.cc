#include "cabezavagonconectados.h"

CabezaVagonConectados::CabezaVagonConectados(){
    cabeza = new CabezaConRuedas();
    vagon = new Vagon();
    conector = new ConectorVagones();
}

void CabezaVagonConectados::draw(modo_dibujado modo, bool ajedrez, bool tapas){
    glPushMatrix();
        glTranslatef(-70,0,0);
        vagon->draw(modo,ajedrez,tapas);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-180,0,0);
        cabeza->draw(modo,ajedrez,tapas);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-105,20,-20);
        conector->draw(modo,ajedrez,tapas);
    glPopMatrix();
}

void CabezaVagonConectados::modificarGradosLibertadHumo(float valor){
    cabeza->modificarGradosLibertadHumo(valor);
}

void CabezaVagonConectados::modificarGradosLibertadRuedas(float valor){
    cabeza->modificarGradosLibertadRuedas( valor);
    vagon->modificarGradosLibertadRuedas(valor);
}

void CabezaVagonConectados::modificarGradosLibertadConectores(float valor){
    conector->modificarGradosLibertadConectores(valor);
}

void CabezaVagonConectados::modificarGradosLibertadVagon(float valor){
    vagon->modificarGradosLibertadVagon(valor);
    cabeza->modificarGradosLibertadVagon(valor);
}