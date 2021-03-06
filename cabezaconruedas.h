#ifndef CABEZACONRUEDAS_H_INCLUDED
#define CABEZACONRUEDAS_H_INCLUDED

#include "malla.h"
#include "cabezasinruedas.h"
#include "ruedasdelanteras.h"
#include "ruedastraseras.h"
#include "esfera.h"

class CabezaConRuedas : public Malla3D{
    private:
        bool maximo_giro;
        bool minimo_giro;
        RuedasDelanteras * ruedasdelanteras = nullptr;
        RuedasTraseras * ruedastraseras = nullptr;
        float grados_libertad_vagon;
        CabezaSinRuedas * cabeza = nullptr;
        
        Esfera * bisagra = nullptr;

    public:
        CabezaConRuedas();
        void draw(modo_dibujado modo, bool ajedrez,bool tapas);
        void modificarGradosLibertadHumoAutomatico(float valor);
        void modificarGradosLibertadRuedasManual(float valor);
        void modificarGradosLibertadVagon(float valor);
        void modificarGradosLibertadHumoManual(float valor);
        void modificarGradosLibertadRuedasAutomatico(float valor);
        void setColorSeleccion(Tupla3f color);
        void restaurarColorVagones();
        void restaurarColorConectoresChimenea();
        void restaurarColorRuedasHumo();

};

#endif