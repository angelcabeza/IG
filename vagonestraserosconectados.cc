#include "vagonestraserosconectados.h"

VagonesTraserosConectados::VagonesTraserosConectados(){
    vagon1 = new Vagon();
    vagon2 = new Vagon();
    conector = new ConectorVagones();
}

void VagonesTraserosConectados::draw(modo_dibujado modo, bool ajedrez, bool tapas){
    glPushMatrix();
        glTranslatef(40,0,0);
        vagon1->draw(modo,ajedrez,tapas);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(115,20,-20);
        conector->draw(modo,ajedrez,tapas);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(150,0,0);
        vagon2->draw(modo,ajedrez,tapas);
    glPopMatrix();
}

void VagonesTraserosConectados::modificarGradosLibertadRuedas(float valor){
    vagon1->modificarGradosLibertadRuedas(valor);
    vagon2->modificarGradosLibertadRuedas(valor);
}

void VagonesTraserosConectados::modificarGradosLibertadConectores(float valor){
    conector->modificarGradosLibertadConectores(valor);
}

void VagonesTraserosConectados::modificarGradosLibertadVagones(float valor){
    vagon1->modificarGradosLibertadVagon(valor);
    vagon2->modificarGradosLibertadVagon(valor);
}