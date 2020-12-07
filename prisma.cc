#include "aux.h"
#include "malla.h"
#include "prisma.h"


Prisma::Prisma(float lado,float ancho){
    inicializarVertices(lado,ancho);
    inicializarCaras();
    inicializarColores();
    inicializarNormalesCaras();
    inicializarNormalesVertices();
}

void Prisma::inicializarVertices(float lado,float ancho){

    Tupla3f v0 = {-(ancho/2),0,0};
    Tupla3f v1 = {-(ancho/2), lado,0};
    Tupla3f v2 = {ancho/2,lado,0};
    Tupla3f v3 = {ancho/2,0,0};

    Tupla3f v4 = {-(ancho/2),lado,-lado};
    Tupla3f v5 = {-(ancho/2),0,-lado};
    Tupla3f v6 = {ancho/2,lado,-lado};
    Tupla3f v7 = {ancho/2,0,-lado};

    v.push_back(v0);
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);
    v.push_back(v5);
    v.push_back(v6);
    v.push_back(v7);
}

void Prisma::inicializarCaras(){

    //Cara delantera
    Tupla3i c0 = {0,2,1};
    Tupla3i c1 = {0,3,2};

    //Cara Superior
    Tupla3i c2 = {1,6,4};
    Tupla3i c3 = {1,2,6};

    //Cara inferior
    Tupla3i c4 = {5,7,3};
    Tupla3i c5 = {5,3,0};

    //Cara lateral derecha
    Tupla3i c6 = {3,6,2};
    Tupla3i c7 = {3,7,6};

    //Cara lateral izquierda
    Tupla3i c8 = {5,0,1};
    Tupla3i c9 = {5,1,4};

    //Cara Trasera
    Tupla3i c10 = {7,5,4};
    Tupla3i c11 = {7,4,6};

    f.push_back(c0);
    f.push_back(c1);
    f.push_back(c2);
    f.push_back(c3);
    f.push_back(c4);
    f.push_back(c5);
    f.push_back(c6);
    f.push_back(c7);
    f.push_back(c8);
    f.push_back(c9);
    f.push_back(c10);
    f.push_back(c11);

    // DIVIDO LAS CARAS EN PARES E IMPARES PARA PODER DIBUJARLAS EN MODO AJEDREZ
    for (int i = 0; i < f.size(); i++){
        if ( i%2 == 0)
            caras_pares.push_back(f[i]);
        else
            caras_impares.push_back(f[i]);
    }
}

void Prisma::inicializarColores(){
    Tupla3f c_rojo = {1.0,0.0,0.0};
    Tupla3f c_verde = {0.0,1.0,0.0};
    Tupla3f c_naranja = {0.9,0.2,0.07};

    for (int i = 0; i < 3*f.size()/2; i++){
            color_ajedrez_pares.push_back(c_rojo);
            color_ajedrez_impares.push_back(c_verde);
    }

    for (int i = 0; i < v.size(); i++){
        color.push_back(c_naranja);
    }
}