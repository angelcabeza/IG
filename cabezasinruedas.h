#ifndef CABEZASINRUEDAS_H_INCLUDED
#define CABEZASINRUEDAS_H_INCLUDED

#include "malla.h"
#include "chimenea.h"
#include "prisma.h"

class CabezaSinRuedas : public Malla3D{
    private:
        bool maximo_giro;
        bool minimo_giro;
        float grado_libertad_vagon;
        Chimenea * chimenea = nullptr;
        Prisma * prisma = nullptr;

    public:
        CabezaSinRuedas();
        void draw(modo_dibujado modo, bool ajedrez,bool tapas);
        void modificarGradosLibertadHumoAutomatico(float valor);
        void modificarGradosLibertadVagon(float valor);
        void modificarGradosLibertadHumoManual(float valor);
        void setColorSeleccion(Tupla3f color);
        void restaurarColorVagones();
        void restaurarColorConectoresChimenea();
        void restaurarColorRuedasHumo();
};

#endif