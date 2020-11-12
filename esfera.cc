#include "aux.h"
#include "esfera.h"

Esfera::Esfera(const int num_vert_perfil,const int num_instancias_perf, const float radio){
    this->num_instancias = num_instancias_perf;
    std::vector<Tupla3f> perfil;

    Tupla3f vert_sup_esfera = {0,radio,0};
    Tupla3f vertice;

    float n_x;
    float n_y;
    float n_z;

    float angulo = M_PI / num_vert_perfil;

    for (int i = 0; i < num_vert_perfil; i++){
        n_x = vert_sup_esfera(0) * cos(angulo * i) - vert_sup_esfera(1) * sin(angulo *i);
        n_y = vert_sup_esfera(0) * sin(angulo * i) + vert_sup_esfera(1) * cos(angulo *i);
        n_z = vert_sup_esfera(2);

        perfil.push_back({n_x,n_y,n_z});
    }

    Tupla3f vert_inf_esfera = {0.0,-radio,0.0};
    perfil.push_back(vert_inf_esfera);
    crearMalla(perfil,num_instancias_perf,true,true);

    inicializarColores();
}

void Esfera::inicializarColores(){
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