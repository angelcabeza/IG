#include "material.h"

Material::Material( Tupla4f mdifuso, Tupla4f mespecular, Tupla4f mambiente, float brillo){
    ambiente = mambiente;
    difuso = mdifuso;
    especular = mespecular;
    this->brillo = brillo;
}

Material::Material(){}

void Material::aplicar(){
    glMaterialfv(GL_FRONT, GL_AMBIENT, this->ambiente);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, this->difuso);
    glMaterialfv(GL_FRONT, GL_SPECULAR, this->especular);
    glMaterialf(GL_FRONT, GL_SHININESS, this->brillo);
}

void Material::operator = (const Material & otro){
    this->ambiente = otro.ambiente;
    this->difuso = otro.difuso;
    this->especular = otro.especular;
    this->brillo = otro.brillo;

    std::cout << "Aplico operator = " << std::endl;
}

Tupla4f Material::getDifuso(){
    return difuso;
}