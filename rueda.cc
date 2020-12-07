#include "rueda.h"

Rueda::Rueda(){
    grados_libertad_ruedas = 0;
    cilindro = new Cilindro(100,100,20,10);
    maximo_giro = false;
    minimo_giro = false;
    Material material = Material({0.5,0.5,0.5,1.0},{0.5,0.5,0.5,1.0},{0.5,0.5,0.5,1.0},128);

    cilindro->setMaterial(material);
}

void Rueda::draw(modo_dibujado modo, bool ajedrez,bool tapas){

    glPushMatrix();
        glRotatef(grados_libertad_ruedas,0,1,0);
        glRotatef(90,1,0,0);
        glScalef(1,0.5,1);
        cilindro->draw(modo,ajedrez,tapas);
    glPopMatrix();
}

void Rueda::modificarGradosLibertadRuedas(float valor){

    if ( (maximo_giro && valor > 0) || (minimo_giro && valor < 0))
        valor = -valor;

    grados_libertad_ruedas += valor;

    if (grados_libertad_ruedas >= 15){
        maximo_giro = true;
        minimo_giro = false;
    }

    if (grados_libertad_ruedas <= -15){
        maximo_giro = false;
        minimo_giro = true;
    }
}