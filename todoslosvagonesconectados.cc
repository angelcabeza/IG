#include "todoslosvagonesconectados.h"

TodosLosVagonesConectados::TodosLosVagonesConectados(){
    tresvagones = new TresVagonesConectados();
    conector = new ConectorVagones();
    cabeza = new CabezaConRuedas();
    grados_libertad = 0;
    maximo_giro = false;
    minimo_giro = false;

    conector->setColor({0.0,1.0,0.0});
}

void TodosLosVagonesConectados::draw(modo_dibujado modo, bool ajedrez, bool tapas){
    glPushMatrix();
        glTranslatef(90,0,0);
        glRotatef(grados_libertad,0,1,0);
        tresvagones->draw(modo,ajedrez,tapas);
    glPopMatrix();

    glPushMatrix();
        cabeza->draw(modo,ajedrez,tapas);
    glPopMatrix();
}

void TodosLosVagonesConectados::modificarGradosLibertadVagon2Manual(float valor){
    grados_libertad += valor;
}

void TodosLosVagonesConectados::modificarGradosLibertadVagon3Manual(float valor){
    tresvagones->modificarGradosLibertadVagon3Manual(valor);
}

void TodosLosVagonesConectados::modificarGradosLibertadVagon4Manual(float valor){
    tresvagones->modificarGradosLibertadVagon4Manual(valor);
}

void TodosLosVagonesConectados::modificarGradosLibertadHumoManual(float valor){
    cabeza->modificarGradosLibertadHumoManual(valor);
}

void TodosLosVagonesConectados::modificarGradosLibertadRuedasManual(float valor){
    cabeza->modificarGradosLibertadRuedasManual(valor);
    tresvagones->modificarGradosLibertadRuedasManual(valor);
}

void TodosLosVagonesConectados::modificarGradosLibertadHumoAutomatico(float valor){
    cabeza->modificarGradosLibertadHumoAutomatico(valor);
}

void TodosLosVagonesConectados::modificarGradosLibertadRuedasAutomatico(float valor){
    cabeza->modificarGradosLibertadRuedasAutomatico(valor);
    tresvagones->modificarGradosLibertadRuedasAutomatico(valor);
}

void TodosLosVagonesConectados::modificarGradosLibertadVagon2Automatico(float valor){
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

void TodosLosVagonesConectados::modificarGradosLibertadVagon3Automatico(float valor){
    tresvagones->modificarGradosLibertadVagon3Automatico(valor);
}

void TodosLosVagonesConectados::modificarGradosLibertadVagon4Automatico(float valor){
    tresvagones->modificarGradosLibertadVagon4Automatico(valor);
}