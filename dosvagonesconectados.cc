#include "dosvagonesconectados.h"

DosVagonesConectados::DosVagonesConectados(){
    vagon1 = new Vagon();
    vagon2 = new Vagon();
    conectorvagones = new ConectorVagones();
    grados_libertad = 0;
}

void DosVagonesConectados::draw(modo_dibujado modo, bool ajedrez, bool tapas){
    glPushMatrix();
        glTranslatef(270,0,0);
        glRotatef(grados_libertad,0,1,0);
        vagon1->draw(modo,ajedrez,tapas);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(175,20,0);
        conectorvagones->draw(modo,ajedrez,tapas);
    glPopMatrix();

    glPushMatrix();
        vagon->draw(modo,ajedrez,tapas);
    glPopMatrix();
}

void DosVagonesConectados::modificarGradosLibertadVagonesManual(float valor){
    grados_libertad+= valor;
}