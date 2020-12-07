#include "tren.h"

Tren::Tren(){
    vagonestraseros = new VagonesTraserosConectados();
    vagonesdelanteros = new CabezaVagonConectados();
    conector = new ConectorVagones();
}

void Tren::draw(modo_dibujado modo, bool ajedrez, bool tapas){
    
    glPushMatrix();
        vagonesdelanteros->draw(modo,ajedrez,tapas);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(5,20,-20);
        conector->draw(modo,ajedrez,tapas);
    glPopMatrix();

    glPushMatrix();
        vagonestraseros->draw(modo,ajedrez,tapas);
    glPopMatrix();
}

void Tren::modificarGradosLibertadHumo(float valor){
    vagonesdelanteros->modificarGradosLibertadHumo(valor);
}

void Tren::modificarGradosLibertadRuedas(float valor){
    vagonesdelanteros->modificarGradosLibertadRuedas(valor);
    vagonestraseros->modificarGradosLibertadRuedas(valor);
}

void Tren::modificarGradosLibertadConectores(float valor){
    vagonestraseros->modificarGradosLibertadConectores(valor);
    vagonesdelanteros->modificarGradosLibertadConectores(valor);
    conector->modificarGradosLibertadConectores(valor);
}

void Tren::modificarGradosLibertadVagones(float valor){
    vagonestraseros->modificarGradosLibertadVagones(valor);
    vagonesdelanteros->modificarGradosLibertadVagon(valor);
}

void Tren::modificarGradosLibertadHumoManual(float valor){
    vagonesdelanteros->modificarGradosLibertadHumo(valor);
}

void Tren::modificarGradosLibertadRuedasManual(float valor){
    vagonesdelanteros->modificarGradosLibertadRuedas(valor);
    vagonestraseros->modificarGradosLibertadRuedas(valor);
}

void Tren::modificarGradosLibertadConectoresManual(float valor){
    vagonestraseros->modificarGradosLibertadConectores(valor);
    vagonesdelanteros->modificarGradosLibertadConectores(valor);
    conector->modificarGradosLibertadConectores(valor);
}

void Tren::modificarGradosLibertadVagonesManual(float valor){
    vagonestraseros->modificarGradosLibertadVagones(valor);
    vagonesdelanteros->modificarGradosLibertadVagon(valor);
}