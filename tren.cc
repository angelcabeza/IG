#include "tren.h"

Tren::Tren(){
    tren = new TodosLosVagonesConectados();
    grados_libertad = 0;
}

void Tren::draw(modo_dibujado modo, bool ajedrez, bool tapas){
    
    glPushMatrix();
        glRotatef(grados_libertad,0,1,0);
        tren->draw(modo,ajedrez,tapas);
    glPopMatrix();
}