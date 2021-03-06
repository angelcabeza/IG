#include "conectorvagones.h"

ConectorVagones::ConectorVagones(){
    grados_libertad_conector = 0;
    cilindro = new Cilindro (100,100,20,10,false);
    esferaExtDcha = new Esfera (10,100,10,false);
    esferaExtrIzq = new Esfera (10,100,10,false);
    minimo_giro = false;
    maximo_giro = false;

    Material silver = Material({0.50754,0.50754,0.50754,1.0}, {0.508273,0.508273,0.508273,1.0}, {0.19225,0.19225,0.19225,1.0}, 51.2);
    cilindro->setMaterial(silver);
    esferaExtDcha->setMaterial(silver);
    esferaExtrIzq->setMaterial(silver);
    cilindro->setColor({0.5,0.5,0.5});
    esferaExtDcha->setColor({0.5,0.5,0.5});
    esferaExtrIzq->setColor({0.5,0.5,0.5});
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

    glPushMatrix();
        glTranslatef(-45,0,0);
        glScalef(1,0.75,1);
        esferaExtrIzq->draw(modo,ajedrez,tapas);
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

void ConectorVagones::setColorSeleccion(Tupla3f color){
    cilindro->setColorSeleccion(color);
    esferaExtDcha->setColorSeleccion(color);
    esferaExtrIzq->setColorSeleccion(color);
    cilindro->setColor(color);
    esferaExtDcha->setColor(color);
    esferaExtrIzq->setColor(color);
}

void ConectorVagones::restaurarColorConectoresChimenea(){
    cilindro->setColor({0.5,0.5,0.5});
    esferaExtDcha->setColor({0.5,0.5,0.5});
    esferaExtrIzq->setColor({0.5,0.5,0.5});
}