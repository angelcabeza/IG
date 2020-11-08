

#include "aux.h"     // includes de OpenGL/glut/glew, windows, y librería std de C++
#include "escena.h"
#include "malla.h" // objetos: Cubo y otros....

//**************************************************************************
// constructor de la escena (no puede usar ordenes de OpenGL)
//**************************************************************************

Escena::Escena()
{
    Front_plane       = 50.0;
    Back_plane        = 2000.0;
    Observer_distance = 4*Front_plane;
    Observer_angle_x  = 0.0 ;
    Observer_angle_y  = 0.0 ;

    ejes.changeAxisSize( 5000 );
    

    // crear los objetos de la escena....
    // .......completar: ...
    // .....

    tetraedro = new Tetraedro();
    cubo = new Cubo (50.0);
    ply = new ObjPLY("plys/beethoven.ply");
    objrevolucion = new ObjRevolucion("plys/peon.ply",10,1);
    cilindro = new Cilindro(100,100,100,50);
    cono = new Cono(100,100,100,50);
    esfera = new Esfera(100,100,10);


}

//**************************************************************************
// inicialización de la escena (se ejecuta cuando ya se ha creado la ventana, por
// tanto sí puede ejecutar ordenes de OpenGL)
// Principalmemnte, inicializa OpenGL y la transf. de vista y proyección
//**************************************************************************

void Escena::inicializar( int UI_window_width, int UI_window_height )
{
	glClearColor( 1.0, 1.0, 1.0, 1.0 );// se indica cual sera el color para limpiar la ventana	(r,v,a,al)

	glEnable( GL_DEPTH_TEST );	// se habilita el z-bufer
   glEnable(GL_CULL_FACE);

	Width  = UI_window_width/10;
	Height = UI_window_height/10;

   change_projection( float(UI_window_width)/float(UI_window_height) );
	glViewport( 0, 0, UI_window_width, UI_window_height );
}



// **************************************************************************
//
// función de dibujo de la escena: limpia ventana, fija cámara, dibuja ejes,
// y dibuja los objetos
//
// **************************************************************************

void Escena::dibujar()
{
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); // Limpiar la pantalla
	change_observer();
   ejes.draw();
   bool ajedrez = false;
   bool tapas = true;

   switch (modo_visualizacion_escogido)
   {
      case PUNTOS:
         glPointSize(7);
         glPolygonMode(GL_FRONT,GL_POINT);
      break;

      case LINEAS:
         glPolygonMode(GL_FRONT,GL_LINE);
      break;

      case SOLIDO:
         glPolygonMode(GL_FRONT,GL_FILL);
      break;

      case AJEDREZ:
         ajedrez = true;
      break;

      case SINTAPAS:
         tapas = false;
      break;

      default:
         break;
   }


   glPushMatrix();
      glTranslatef(50,50,0);
      glScalef(5,5,5);

      ply->draw(modo_dibujado_escogido,ajedrez);
   glPopMatrix();

   glPushMatrix();
      glTranslatef(-50,50,0);
      glScalef(4,4,4);

      esfera->draw(modo_dibujado_escogido,ajedrez,tapas);
   glPopMatrix();

   glPushMatrix();
      glTranslatef(-90,-110,0);

      cono->draw(modo_dibujado_escogido,ajedrez,tapas);
   glPopMatrix();

   glPushMatrix();
      glTranslatef(90,-120,0);

      cilindro->draw(modo_dibujado_escogido,ajedrez,tapas);
   glPopMatrix();




   /*
   switch (objeto_a_pintar)
   {
      case CUBO:
         cubo->draw(modo_dibujado_escogido,ajedrez);
      break;

      case TETRAEDRO:
         tetraedro->draw(modo_dibujado_escogido,ajedrez);
      break;

      case ESFERA:
         esfera->draw(modo_dibujado_escogido,ajedrez,tapas);
      break;

      case CILINDRO:
         cilindro->draw(modo_dibujado_escogido,ajedrez,tapas);
      break;

      case CONO:
         cono->draw(modo_dibujado_escogido,ajedrez,tapas);
      break;

      case PLY:
         ply->draw(modo_dibujado_escogido,ajedrez);
      break;
   }*/
    
}

//**************************************************************************
//
// función que se invoca cuando se pulsa una tecla
// Devuelve true si se ha pulsado la tecla para terminar el programa (Q),
// devuelve false en otro caso.
//
//**************************************************************************

bool Escena::teclaPulsada( unsigned char tecla, int x, int y )
{
   using namespace std ;
   cout << "Tecla pulsada: '" << tecla << "'" << endl;
   bool salir=false;
   switch( toupper(tecla) )
   {
      case 'Q' :
         if (modoMenu!=NADA)
            modoMenu=NADA;            
         else {
            salir=true ;
         }
         break ;
      case 'O' :
         modoMenu=SELOBJETO;

         cout << "Ha entrado en el modo selección de objeto" << endl;
         cout << "Presione 'C' para dibujar un cubo" << endl;
         cout << "Presione 'T' para visualizar un tetraedro" << endl;
         cout << "Presione 'H' para visualizar la esfera" << endl;
         cout << "Presione 'E' para visualizar el cono" << endl;
         cout << "Presione 'R' para visualizar el cilindro" << endl;
         cout << "Presione 'F' para visualizar un ply" << endl;
         cout << "Presione 'Q' para salir de este modo" << endl;

         break ;
        case 'V' :
         // ESTAMOS EN MODO SELECCION DE MODO DE VISUALIZACION
         modoMenu=SELVISUALIZACION;

         cout << "Ha entrado en el modo de visualizacion" << endl;
         cout << "Presione 'P' para la visualización modo puntos" << endl;
         cout << "Presione 'L' para la visualización modo líneas" << endl;
         cout << "Presione 'S' para la visualización modo sólido" << endl;
         cout << "Presione 'A' para la visualización modo ajedrez" << endl;
         cout << "Presione 'Q' para salir de este modo" << endl;
         break ;
       case 'D' :
         // ESTAMOS EN MODO SELECCION DE DIBUJADO
         modoMenu=SELDIBUJADO;

         cout << "Ha entrado en el modo de dibujado" << endl;
         cout << "Presione '1' para la visualización con glDraElements" << endl;
         cout << "Presione '2' para la visualización con Vertex Buffer Objetcts (VBOs)" << endl;
         cout << "Presione 'Q' para salir de este modo" << endl;
         break ;

       case 'X' :
         cout << "Has entrado en el menú de selección de tapas" << endl;
         cout << "Si quiere dibujar el objeto de revolución con tapas pulse Y" << endl;
         cout << "Si quiere dibujar el objeto de revolución sin tapas pulse N" << endl;
         break;
         // COMPLETAR con los diferentes opciones de teclado
         case 'C' :
          if (objeto_a_pintar != CUBO){
            objeto_a_pintar=CUBO;
          }
          else{
             objeto_a_pintar=NINGUNO;
          }

          break;

         case 'T' :

          if (objeto_a_pintar != TETRAEDRO)
            objeto_a_pintar=TETRAEDRO;
          else
            objeto_a_pintar=NINGUNO;

          break;

         case 'H' :
          if ( objeto_a_pintar != ESFERA)
            objeto_a_pintar=ESFERA;
          else
            objeto_a_pintar=NINGUNO;
          
         break;

         case 'E' :
          if ( objeto_a_pintar != CONO)
            objeto_a_pintar=CONO;
          else
            objeto_a_pintar=NINGUNO;
          
         break;

         case 'R' :
          if ( objeto_a_pintar != CILINDRO)
            objeto_a_pintar=CILINDRO;
          else
            objeto_a_pintar=NINGUNO;
          
         break;

         case 'F' :
          if ( objeto_a_pintar != PLY)
            objeto_a_pintar=PLY;
          else
            objeto_a_pintar=NINGUNO;
          
         break;

         case '1'  :
            cout << "Ha escogido pintar en modo inmediato" << endl;
            modo_dibujado_escogido = INMEDIATO;
          break;
         
         case '2'  :
            cout << "Ha escogido pintar en modo diferido" << endl;
            modo_dibujado_escogido = DIFERIDO;
          break; 

         case 'P'  :
            cout << "Ha escogido pintar en modo puntos" << endl;
            if (modo_visualizacion_escogido != PUNTOS)
               modo_visualizacion_escogido = PUNTOS;

          break;

         case 'L'  :
            cout << "Ha escogido pintar en modo lineas" << endl;
            if (modo_visualizacion_escogido != LINEAS)
               modo_visualizacion_escogido = LINEAS;
          break;

         case 'S'  :
            cout << "Ha escogido pintar en modo solido" << endl;
            if (modo_visualizacion_escogido != SOLIDO)
               modo_visualizacion_escogido = SOLIDO;

          break;

         case 'A'  :
            cout << "Ha escogido pintar en modo ajedrez" << endl;
            if (modo_visualizacion_escogido != AJEDREZ)
               modo_visualizacion_escogido = AJEDREZ;
          break;

         case 'Y' :
            modo_visualizacion_escogido = SOLIDO;
         break;

         case 'N' :
            modo_visualizacion_escogido = SINTAPAS;
         break;
   }
   return salir;
}
//**************************************************************************

void Escena::teclaEspecial( int Tecla1, int x, int y )
{
   switch ( Tecla1 )
   {
	   case GLUT_KEY_LEFT:
         Observer_angle_y-- ;
         break;
	   case GLUT_KEY_RIGHT:
         Observer_angle_y++ ;
         break;
	   case GLUT_KEY_UP:
         Observer_angle_x-- ;
         break;
	   case GLUT_KEY_DOWN:
         Observer_angle_x++ ;
         break;
	   case GLUT_KEY_PAGE_UP:
         Observer_distance *=1.2 ;
         break;
	   case GLUT_KEY_PAGE_DOWN:
         Observer_distance /= 1.2 ;
         break;
	}

	//std::cout << Observer_distance << std::endl;
}

//**************************************************************************
// Funcion para definir la transformación de proyeccion
//
// ratio_xy : relacción de aspecto del viewport ( == ancho(X) / alto(Y) )
//
//***************************************************************************

void Escena::change_projection( const float ratio_xy )
{
   glMatrixMode( GL_PROJECTION );
   glLoadIdentity();
   const float wx = float(Height)*ratio_xy ;
   glFrustum( -wx, wx, -Height, Height, Front_plane, Back_plane );
}
//**************************************************************************
// Funcion que se invoca cuando cambia el tamaño de la ventana
//***************************************************************************

void Escena::redimensionar( int newWidth, int newHeight )
{
   Width  = newWidth/10;
   Height = newHeight/10;
   change_projection( float(newHeight)/float(newWidth) );
   glViewport( 0, 0, newWidth, newHeight );
}

//**************************************************************************
// Funcion para definir la transformación de vista (posicionar la camara)
//***************************************************************************

void Escena::change_observer()
{
   // posicion del observador
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glTranslatef( 0.0, 0.0, -Observer_distance );
   glRotatef( Observer_angle_y, 0.0 ,1.0, 0.0 );
   glRotatef( Observer_angle_x, 1.0, 0.0, 0.0 );
}
