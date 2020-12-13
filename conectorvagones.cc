#include "conectorvagones.h"

ConectorVagones::ConectorVagones(){
    grados_libertad_conector = 0;
    cilindro = new Cilindro (100,100,20,10);
    esferaExtDcha = new Esfera (100,100,10);
    minimo_giro = false;
    maximo_giro = false;

    Material material = Material ({1.0,1.0,1.0,1.0},{1.0,1.0,1.0,1.0},{1.0,1.0,1.0,1.0},128);
    cilindro->setMaterial(material);
}

void ConectorVagones::draw(modo_dibujado modo, bool ajedrez, bool tapas){
    glPushMatrix();
        glTranslatef(-9,0,0);
        glScalef(2,0.5,1);
        glRotatef(90,0,0,1);
        cilindro->draw(modo,ajedrez,tapas);
    glPopMatrix();
    
    glPushMatrix();
        glScalef(1,0.75,1);
        esferaExtDcha->draw(modo,ajedrez,tapas);
    glPopMatrix();
}

void ConectorVagones::modificarGradosLibertadConectores(float valor){

    if ( (maximo_giro && valor > 0) || (minimo_giro && valor < 0))
        valor = -valor;

    grados_libertad_conector += valor;

    if (grados_libertad_conector >= 15){
        maximo_giro = true;
        minimo_giro = false;
    }

    if (grados_libertad_conector <= -15){
        maximo_giro = false;
        minimo_giro = true;
    }
}

float ConectorVagones::getGradosLibertad(){
    return grados_libertad_conector;
}