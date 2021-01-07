#include "aux.h"
#include "cono.h"

Cono::Cono(const int num_vert_perfil,const int num_instancias_perf, const float altura, const float radio,bool textura, bool tapa_inf, bool tapa_sup){ 

    this->num_instancias = num_instancias_perf;
    this->con_textura = textura;
    std::vector<Tupla3f> perfil;

    Tupla3f vertice;
    float contador = 0;
    const float NUM_DECRECER_RADIO = radio/num_vert_perfil;

    for (int i = 0; i < num_vert_perfil;i++){
        vertice = {radio-contador,i*(altura/num_vert_perfil),0};

        contador += NUM_DECRECER_RADIO;
        perfil.push_back(vertice);
    }

    crearMalla(perfil,num_instancias_perf,tapa_inf,tapa_sup);

    inicializarNormalesCaras();
    inicializarNormalesVertices();
}