#include "tresvagonesconectados.h"

TresVagonesConectados::TresVagonesConectados(){
    dosvagones = new DosVagonesConectados();
    conector = new ConectorVagones();
    vagon = new Vagon();
    grados_libertad = 0;
    maximo_giro = false;
    minimo_giro = true;
}

void TresVagonesConectados::draw(modo_dibujado modo, bool ajedrez, bool tapas){
    glPushMatrix();
        glTranslatef(145,0,0);
        glRotatef(grados_libertad,0,1,0);
        dosvagones->draw(modo,ajedrez,tapas);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(55,20,0);
        conector->draw(modo,ajedrez,tapas);
    glPopMatrix();

    glPushMatrix();
        vagon->draw(modo,ajedrez,tapas);
    glPopMatrix();
}

void TresVagonesConectados::modificarGradosLibertadVagon3Manual(float valor){
    grados_libertad += valor;
}

void TresVagonesConectados::modificarGradosLibertadVagon4Manual(float valor){
    dosvagones->modificarGradosLibertadVagon4Manual(valor);
}

void TresVagonesConectados::modificarGradosLibertadRuedasManual(float valor){
    vagon->modificarGradosLibertadRuedasManual(valor);
    dosvagones->modificarGradosLibertadRuedasManual(valor);
}

void TresVagonesConectados::modificarGradosLibertadRuedasAutomatico(float valor){
    vagon->modificarGradosLibertadRuedasAutomatico(valor);
    dosvagones->modificarGradosLibertadRuedasAutomatico(valor);
}

void TresVagonesConectados::modificarGradosLibertadVagon3Automatico(float valor){
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

void TresVagonesConectados::modificarGradosLibertadVagon4Automatico(float valor){
    dosvagones->modificarGradosLibertadVagon4Automatico(valor);
}