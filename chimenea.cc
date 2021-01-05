#include "chimenea.h"

Chimenea::Chimenea(){
    humo = new Humo();
    base_chimenea = new Cilindro(100,100,20,10,false);

    Material silver = Material({0.50754,0.50754,0.50754,1.0}, {0.508273,0.508273,0.508273,1.0}, {0.19225,0.19225,0.19225,1.0}, 51.2);

    base_chimenea->setMaterial(silver);
    base_chimenea->setColor({0.5,0.5,0.5});
}

void Chimenea::draw(modo_dibujado modo, bool ajedrez,bool tapas){
    glPushMatrix();
        glTranslatef(0,30,0);
        humo->draw(modo,ajedrez,tapas);
    glPopMatrix();

    glPushMatrix();
        base_chimenea->draw(modo,ajedrez,tapas);
    glPopMatrix();
}

void Chimenea::modificarGradosLibertadHumoAutomatico(float valor){
    humo->modificarGradosLibertadHumoAutomatico(valor);
}

void Chimenea::modificarGradosLibertadHumoManual(float valor){
    humo->modificarGradosLibertadHumoManual(valor);
}

void Chimenea::setColorSeleccion(Tupla3f color){
    humo->setColorSeleccion(color);
    base_chimenea->setColorSeleccion(color);
    base_chimenea->setColor(color);
}

void Chimenea::restaurarColorConectoresChimenea(){
    base_chimenea->setColor({0.5,0.5,0.5});
}

void Chimenea::restaurarColorRuedasHumo(){
    humo->restaurarColorRuedasHumo();
}