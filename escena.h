#ifndef _ESCENA_H
#define _ESCENA_H

#include "ejes.h"
#include "malla.h"
#include "cubo.h"
#include "objply.h"
#include "tetraedro.h"
#include "objrevolucion.h"
#include "cilindro.h"
#include "cono.h"
#include "esfera.h"
#include "luz.h"
#include "luzdireccional.h"
#include "luzposicional.h"
#include "material.h"
#include "prisma.h"
#include "tren.h"
#include "cuadro.h"




typedef enum {NADA, SELOBJETO,SELVISUALIZACION,SELDIBUJADO,ANIMACIONMANUAL,ANIMACIONAUTOMATICA} menu;
typedef enum {CUBO,TETRAEDRO,ESFERA,CILINDRO,CONO,PLY,NINGUNO} objeto_seleccionado;
typedef enum {PUNTOS,LINEAS,SOLIDO,AJEDREZ,SINTAPAS,ILUMINACION} modo_visualizacion;
typedef enum {ALPHA,BETA} variacion_luz_direccional;
typedef enum {SUAVE,PLANO} modo_sombreado;
typedef enum {HUMO,RUEDAS,VAGON1,VAGON2,VAGON3,VAGON4} objeto_a_animar;

class Escena
{

   private:

   

 // ** PARÁMETROS DE LA CÁMARA (PROVISIONAL)
       
       // variables que definen la posicion de la camara en coordenadas polares
   GLfloat Observer_distance;
   GLfloat Observer_angle_x;
   GLfloat Observer_angle_y;

   // variables que controlan la ventana y la transformacion de perspectiva
   GLfloat Width, Height, Front_plane, Back_plane;

    // Transformación de cámara
	void change_projection( const float ratio_xy );
	void change_observer();
    


   void clear_window();

   // DECLARACION DE LOS DISTINTOS ENUMS NECESARIOS PARA EL MENU
   menu modoMenu=NADA;
   objeto_seleccionado objeto_a_pintar = NINGUNO;
   modo_dibujado modo_dibujado_escogido = DEFAULT;
   modo_visualizacion modo_visualizacion_escogido = SOLIDO;
   variacion_luz_direccional variacion_direccional;
   modo_sombreado modo_sombreado_escogido;
   objeto_a_animar objeto;
   ////////////////////////////////////////////////////////////////

   // DECLARACION DE VARIABLES BOOLEANAS NECESARIAS PARA LUCES
   bool iluminacion;
   bool activar_luz0;
   bool activar_luz1;
   bool activar_luz2;
   //////////////////////////////////////////////////////////////

   // Objetos de la escena
   Ejes ejes;
   Cubo * cubo = nullptr ; // es importante inicializarlo a 'nullptr'
   Tetraedro * tetraedro= nullptr ; // es importante inicializarlo a 'nullptr'
   Prisma * prisma = nullptr;
   ObjPLY * ply = nullptr;
   ObjRevolucion * peon_negro = nullptr;
   ObjRevolucion * peon_blanco = nullptr;
   Cilindro * cilindro = nullptr;
   Cilindro * cilindro_tumbado = nullptr;
   Cono * cono = nullptr;
   Esfera * esfera = nullptr;
   Esfera * esfera_luz2 = nullptr;
   LuzPosicional * luz1 = nullptr;
   LuzDireccional * luz0 = nullptr;
   LuzPosicional * luz2 = nullptr;
   Tren * tren = nullptr;
   Cuadro * cuadro = nullptr;
   
   public:

    Escena();
	void inicializar( int UI_window_width, int UI_window_height );
	void redimensionar( int newWidth, int newHeight ) ;

	// Dibujar
	void dibujar() ;

	// Interacción con la escena
	bool teclaPulsada( unsigned char Tecla1, int x, int y ) ;
	void teclaEspecial( int Tecla1, int x, int y );
    void animar();

};
#endif
