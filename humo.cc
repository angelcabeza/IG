#include "humo.h"

Humo::Humo(){
    grados_libertad_humo = 0;
    esfera = new Esfera(100,100,10,false);
    maxima_altura = false;
    minima_altura = true;

    Material material = Material ({0.0,0.0,0.0,1.0},{0.0,0.0,0.0,1.0},{0.0,0.0,0.0,1.0},128);

    esfera->setMaterial(material);
    esfera->setColor({0.0,0.0,0.0});
}

void Humo::draw(modo_dibujado modo, bool ajedrez,bool tapas){

    glPushMatrix();
        glTranslatef(0,grados_libertad_humo,0);
        esfera->draw(modo,ajedrez,tapas);
    glPopMatrix();
}

void Humo::modificarGradosLibertadHumoAutomatico(float valor){

    if ( (maxima_altura && valor > 0) || (minima_altura && valor < 0)){
        valor = -valor;
    }

    grados_libertad_humo += valor;

    if (grados_libertad_humo <= 0){
        maxima_altura = false;
        minima_altura = true;
    }

    if (grados_libertad_humo >= 50){
        maxima_altura = true;
        minima_altura = false;
    }
}

void Humo::modificarGradosLibertadHumoManual(float valor){
    grados_libertad_humo += valor;
}

void Humo::setColorSeleccion(Tupla3f color){
    esfera->setColorSeleccion(color);
    esfera->setColor(color);
}

void Humo::restaurarColorRuedasHumo(){
    esfera->setColor({0,0,0});
}