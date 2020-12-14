#include "vagon.h"

Vagon::Vagon(){
    prisma = new Prisma();
    ruedasdelanteras = new RuedasDelanteras();
    ruedastraseras = new RuedasTraseras();
    bisagra = new Esfera(100,100,10);
    grados_libertad_vagon = 0;
    maximo_giro = false;
    minimo_giro = true;

    Material bronce = Material ({0.7038, 0.27048,0.0828, 1}, {0.256777, 0.137622,0.086014, 1},{0.019125, 0.0735, 0.0225, 1}, 12.8);
    Material silver = Material({0.50754,0.50754,0.50754,1.0}, {0.508273,0.508273,0.508273,1.0}, {0.19225,0.19225,0.19225,1.0}, 51.2);
    prisma->setMaterial(bronce);
    bisagra->setMaterial(silver);
}

void Vagon::draw(modo_dibujado modo, bool ajedrez, bool tapas){
    glPushMatrix();
        glTranslatef(-45,10,20);
        prisma->draw(modo,ajedrez);
    glPopMatrix();

    glPushMatrix();
        ruedasdelanteras->draw(modo,ajedrez,tapas);
    glPopMatrix();

    glPushMatrix();
        ruedastraseras->draw(modo,ajedrez,tapas);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0,20,0);
        glScalef(1,0.75,1);
        bisagra->draw(modo,ajedrez,tapas);
    glPopMatrix();
}

void Vagon::modificarGradosLibertadRuedasManual(float valor){
    ruedasdelanteras->modificarGradosLibertadRuedasManual(valor);
    ruedastraseras->modificarGradosLibertadRuedasManual(valor);
}

void Vagon::modificarGradosLibertadVagon(float valor){
    if ( (maximo_giro && valor > 0) || (minimo_giro && valor < 0))
        valor = -valor;

    grados_libertad_vagon += valor;

    if (grados_libertad_vagon >= 15){
        maximo_giro = true;
        minimo_giro = false;
    }

    if (grados_libertad_vagon <= -15){
        maximo_giro = false;
        minimo_giro = true;
    }
}

void Vagon::modificarGradosLibertadRuedasAutomatico(float valor){
    ruedasdelanteras->modificarGradosLibertadRuedasManual(valor);
    ruedastraseras->modificarGradosLibertadRuedasManual(valor);
}