#include "tren.h"

Tren::Tren(){
    tren = new TodosLosVagonesConectados();
    grados_libertad = 0;
    maximo_giro = false;
    minimo_giro = false;
}

void Tren::draw(modo_dibujado modo, bool ajedrez, bool tapas){
    
    glPushMatrix();
        glTranslatef(-160,0,0);
        glRotatef(grados_libertad,0,1,0);
        tren->draw(modo,ajedrez,tapas);
    glPopMatrix();
}

void Tren::modificarGradosLibertadVagon1Manual(float valor){
    grados_libertad+=valor;
}

void Tren::modificarGradosLibertadVagon2Manual(float valor){
    tren->modificarGradosLibertadVagon2Manual(valor);
}

void Tren::modificarGradosLibertadVagon3Manual(float valor){
    tren->modificarGradosLibertadVagon3Manual(valor);
}

void Tren::modificarGradosLibertadVagon4Manual(float valor){
    tren->modificarGradosLibertadVagon4Manual(valor);
}

void Tren::modificarGradosLibertadHumoManual(float valor){
    tren->modificarGradosLibertadHumoManual(valor);
}

void Tren::modificarGradosLibertadRuedasManual(float valor){
    tren->modificarGradosLibertadRuedasManual(valor);
}

void Tren::modificarGradosLibertadHumoAutomatico(float valor){
    tren->modificarGradosLibertadHumoAutomatico(valor);
}

void Tren::modificarGradosLibertadRuedasAutomatico(float valor){
    tren->modificarGradosLibertadRuedasAutomatico(valor);
}

void Tren::modificarGradosLibertadVagon1Automatico(float valor){
    if ( (maximo_giro && valor > 0) || (minimo_giro && valor < 0))
        valor = -valor;

    grados_libertad += valor;

    if (grados_libertad >= 15){
        maximo_giro = true;
        minimo_giro = false;
    }

    if (grados_libertad <= -15){
        maximo_giro = false;
        minimo_giro = true;
    }
}

void Tren::modificarGradosLibertadVagon2Automatico(float valor){
    tren->modificarGradosLibertadVagon2Automatico(valor);
}

void Tren::modificarGradosLibertadVagon3Automatico(float valor){
    tren->modificarGradosLibertadVagon3Automatico(valor);
}

void Tren::modificarGradosLibertadVagon4Automatico(float valor){
    tren->modificarGradosLibertadVagon4Automatico(valor);
}

void Tren::setColorSeleccion(Tupla3f color){
    tren->setColorSeleccion(color);
    colorSeleccion = color;
}

Tupla3f Tren::getColorSeleccion(){
    return colorSeleccion;
}

void Tren::restaurarColorVagones(){
    tren->restaurarColorVagones();
}

void Tren::restaurarColorConectoresChimenea(){
    tren->restaurarColorConectoresChimenea();
}

void Tren::restaurarColorRuedasHumo(){
    tren->restaurarColorRuedasHumo();
}