#ifndef CAMARA_H_INCLUDED
#define CAMARA_H_INCLUDED

#include "aux.h"
class Camara{
    private:
        Tupla3f eye;
        Tupla3f at;
        Tupla3f up;

        int tipo;
        float left,right,near,far,bottom,top;
    public:
        Camara( Tupla3f eye, Tupla3f at,Tupla3f up,
                int tipo, float near,  float far,float left, float top);
        void rotarXExaminar(float angle);
        void rotarYExaminar(float angle);
        void rotarZExaminar(float angle);
        void rotarXFirstPerson(float angle);
        void rotarYFirstPerson(float angle);
        void rotarZFirstPerson(float angle);
        void mover(float x, float y, float z);
        void zoom(float factor);
        void setObserver();
        void setProyeccion();
        void girar(int x, int y);
        void girarEx(int x, int y);
        void setAt(Tupla3f nuevoAt);
        Tupla3f getAt();
        Tupla3f getEye();
        Tupla3f getUp();
};

#endif