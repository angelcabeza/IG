#include "todoslosvagonesconectados.h"

TodosLosVagonesConectados::TodosLosVagonesConectados(){
    tresvagones = new TresVagonesConectados();
    conector = new ConectorVagones();
    cabeza = new CabezaConRuedas();
    grados_libertad = 0;
}

void TodosLosVagonesConectados::draw(modo_dibujado modo, bool ajedrez, bool tapas){
    glPushMatrix();
        glRotatef(grados_libertad,0,1,0);
        glTranslatef(115,0,0);
        tresvagones->draw(modo,ajedrez,tapas);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(25,0,0);
        conector->draw(modo,ajedrez,tapas);
    glPopMatrix();

    glPushMatrix();
        cabeza->draw(modo,ajedrez,tapas);
    glPopMatrix();
}

void TodosLosVagonesConectados::modificarGradosLibertadManual(float valor){
    grados_libertad += valor;
}