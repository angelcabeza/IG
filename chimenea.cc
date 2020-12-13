#include "chimenea.h"

Chimenea::Chimenea(){
    humo = new Humo();
    base_chimenea = new Cilindro(100,100,20,10);

    Material material = Material({0.3,0.3,0.3,1.0},{0.3,0.3,0.3,1.0},{0.3,0.3,0.3,1.0},128);

    base_chimenea->setMaterial(material);
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