#include "tresvagonesconectados.h"

TresVagonesConectados::TresVagonesConectados(){
    dosvagones = new DosVagonesConectados();
    conector = new ConectorVagones();
    vagon = new Vagon();
    grados_libertad = 0;
}

void TresVagonesConectados::draw(modo_dibujado modo, bool ajedrez, bool tapas){
    glPushMatrix();
        glRotatef(grados_libertad,0,1,0);
        dosvagones->draw(modo,ajedrez,tapas);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(25,0,0);
        conector->draw(modo,ajedrez,tapas);
    glPopMatrix();

    glPushMatrix();
        vagon->draw(modo,ajedrez,tapas);
    glPopMatrix();
}

void TresVagonesConectados::modificarGradosLibertadVagonesManual(float valor){
    grados_libertad += valor;
}