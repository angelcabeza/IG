#include "camara.h"

Camara::Camara( Tupla3f  ey, Tupla3f  at,  Tupla3f  up,
                 int  tipo,  float near,  float far,float left,float top){

    this->eye = ey;
    this->at = at;
    this->up = up;
    this->tipo = tipo;
    this->near = near;
    this->far = far;
    this->left = left;
    this->top = top;
}

void Camara::setObserver(){
    gluLookAt(this->eye(0),this->eye(1),this->eye(2),
              this->at(0),this->at(1),this->at(2),
              this->up(0),this->up(1),this->up(2));
}

void Camara::setProyeccion(){
    if (tipo == 0){                 // Es una cámara perspectiva
        glFrustum(-left,left,-top,top,near,far);
    }
    else{                           // Es una cámara ortográfica
        glOrtho(-left,left,-top,top,near,far);
    }
}

void Camara::rotarXExaminar(float angle){

    Tupla3f n = eye - at;

    float modulo = sqrt(n.lengthSq());

    //Vamos a rotar este vector ya que es la x
    n(1) = cos(angle) * n(1) - sin(angle) * n(2);
    n(2) = sin(angle) * n(1) + cos(angle) * n(2);

    eye = n + at;
}

void Camara::rotarYExaminar(float angle){
    // Esto es el vector VPN
    Tupla3f n = eye - at;

    float modulo = sqrt(n.lengthSq());

    //Vamos a rotar este vector ya que es la x
    n(0) = cos(angle) * n(0) + sin(angle) * n(2);
    n(2) = -sin(angle) * n(0) + cos(angle) * n(2);

    n = n.normalized() * modulo;

    eye = n + at;
}

void Camara::rotarZExaminar(float angle){
    // Esto es el vector VPN
    Tupla3f n = eye - at;

    float modulo = sqrt(n.lengthSq());

    //Vamos a rotar este vector ya que es la x
    n(0) = cos(angle) * n(0) - sin(angle) * n(1);
    n(1) = sin(angle) * n(0) + cos(angle) * n(1);

    n = n.normalized() * modulo;

    eye = n + at;
}

void Camara::rotarXFirstPerson(float angle){

	Tupla3f n = at - eye;

    float modulo = sqrt(n.lengthSq());

	n(1) = cos(angle) * n(1) - sin(angle) * n(2);
    n(2) = sin(angle) * n(1) + cos(angle) * n(2);

    n = n.normalized() * modulo;

	at = n + eye;
}

void Camara::rotarYFirstPerson(float angle){
    Tupla3f n = at - eye;

    float modulo = sqrt(n.lengthSq());

    n(0) = cos(angle)*n(0) + sin(angle)*n(2);
    n(2) = -sin(angle)*n(0) + cos(angle)*n(2);

    n = n.normalized() * modulo;

    at = n + eye;
}

void Camara::rotarZFirstPerson(float angle){
    Tupla3f n = at - eye;

    n(0) = cos(angle) * n(0) - sin(angle) * n(1);
    n(1) = sin(angle) * n(0) + cos(angle) * n(1);

    at = n + eye;
}

void Camara::mover(float x,float y,float z){
    at(0) += x;
    at(1) += y;
    at(2) += z;

    eye(0) += x;
    eye(1) += y;
    eye(2) += z;
}

void Camara::zoom(float factor){
    this->left -= factor;
    this->top -= factor;
}

void Camara::girar(int x, int y){
    rotarXFirstPerson( -y * M_PI/180.0 );
    rotarYFirstPerson( -x * M_PI/180.0 );
}

void Camara::girarEx(int x, int y){
    rotarXExaminar( y * M_PI/180.0 );
    rotarYExaminar( x * M_PI/180.0 );
}

void Camara::setAt(Tupla3f nuevoat){
    at = nuevoat;
}