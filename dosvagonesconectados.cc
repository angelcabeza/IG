#include "dosvagonesconectados.h"

DosVagonesConectados::DosVagonesConectados(){
    vagon1 = new Vagon();
    vagon2 = new Vagon();
    grados_libertad = 0;
    maximo_giro = false;
    minimo_giro = false;
}

void DosVagonesConectados::draw(modo_dibujado modo, bool ajedrez, bool tapas){
    glPushMatrix();
        glTranslatef(135,0,0);
        glRotatef(grados_libertad,0,1,0);
        vagon1->draw(modo,ajedrez,tapas);
    glPopMatrix();

    glPushMatrix();
        vagon2->draw(modo,ajedrez,tapas);
    glPopMatrix();
}

void DosVagonesConectados::modificarGradosLibertadVagon4Manual(float valor){
    grados_libertad+= valor;
}

void DosVagonesConectados::modificarGradosLibertadRuedasManual(float valor){
    vagon1->modificarGradosLibertadRuedasManual(valor);
    vagon2->modificarGradosLibertadRuedasManual(valor);
}

void DosVagonesConectados::modificarGradosLibertadRuedasAutomatico(float valor){
    vagon1->modificarGradosLibertadRuedasAutomatico(valor);
    vagon2->modificarGradosLibertadRuedasAutomatico(valor);
}


void DosVagonesConectados::modificarGradosLibertadVagon4Automatico(float valor){
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