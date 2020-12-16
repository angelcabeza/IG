

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


   // OBJETOS EN LA ESCENA
    iluminacion = false;
    /*peon_blanco = new ObjRevolucion("plys/peon.ply",100,true,true);
    esfera = new Esfera(100,100,1);
    esfera_luz2 = new Esfera(100,100,1);
    cubo = new Cubo(100);
    cono = new Cono (100,100,40,40);*/
    //cilindro = new Cilindro(100,100,50,50);
    peon_negro= new ObjRevolucion("plys/lata-pcue.ply",100,true,true);
    Textura tex("texturas/text-lata-1.jpg");
    peon_negro->setTextura(tex);
   /////////////////////////////////////////////////////////////////////

    //Declaro y aplico materiales
    /*Material material_difuso = Material( {1.0,1.0,1.0,1.0} , {0.0,0.0,0.0,1.0} , {0.0,0,0,1.0} , 128.0);
    Material material_especular = Material ( {0.0,0.0,0.0,1.0} , {0.0,0.0,0.0,1.0} , {0.0,0.0,0.0,1.0} , 128.0);
    Material material_esmeralda = Material ({0.9,0.2,0.07,1.0}, {0.9,0.2,0.07, 1}, {0.0, 0.0,0.0, 1}, 64.0);
    Material material_anaranjado = Material ({0.633, 0.727811,0.633, 1}, {0.633, 0.727811,0.633, 1},{0.0215, 0.1745, 0.0215, 1}, 64.0);

    peon_blanco->setMaterial(material_difuso);
    peon_negro->setMaterial(material_especular);
    cono->setMaterial(material_esmeralda);
    cilindro->setMaterial(material_anaranjado);
    prisma->setMaterial(material_anaranjado);*/
   //////////////////////////////////////////////////////////////////////////////////////////////////////

   // CREO LAS LUCES DE LA ESCENA
    luz0 = new LuzDireccional({0,10},GL_LIGHT0,{1.0,1.0,1.0,1.0}, {1.0,1.0,1.0,1.0}, {1.0,1.0,1.0,1.0});
    luz1 = new LuzPosicional({20, 100, -300},GL_LIGHT1,  {0.239,0.239,0.239,1.0}, {1.0,1.0,1.0,1}, {1.0,1.0,1.0,1.0});
    luz2 = new LuzPosicional({30, 30, 70},GL_LIGHT2,  {0.239,0.169,0.074,1.0}, {1.0,1.0,1.0,1}, {1.0,1.0,1.0,1.0});
   /////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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


   //PROTEJO A LOS EJES DE LA ILUMINACIÓN PARA QUE SE DIBUJEN SIEMPRE DEL MISMO COLOR
   if (iluminacion){
      glDisable(GL_LIGHTING);
      ejes.draw();
      glEnable(GL_LIGHTING);
   }
   else{
      ejes.draw();
   }
   
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
   
   glEnable(GL_TEXTURE_2D);

   if (iluminacion){
      glEnable(GL_NORMALIZE);
      glEnable(GL_LIGHTING);

      if (modo_sombreado_escogido == SUAVE)
         glShadeModel(GL_SMOOTH);
      else
         glShadeModel (GL_FLAT);
   }

      if(activar_luz1){
      glPushMatrix();
         glTranslatef(20,100,-300);
         glScalef(4,4,4);
         esfera->draw(modo_dibujado_escogido,ajedrez,true);
      glPopMatrix();
   }

   if (activar_luz2){
      glPushMatrix();
         glTranslatef(30,30,70);
         glScalef(4,4,4);
         esfera_luz2->draw(modo_dibujado_escogido,ajedrez,true);
      glPopMatrix();
   }

   if(activar_luz0){
      glPushMatrix();
         luz0->activar();
      glPopMatrix();
   }
   else{
      if(luz0->estaActivada()){
         luz0->desactivar();
      }
   }

   if (activar_luz1){
      glPushMatrix();
         luz1->activar();
      glPopMatrix();
   }
   else{
      if(luz1->estaActivada()){
         luz1->desactivar();
      }
   }

   if (activar_luz2){
      glPushMatrix();
         luz2->activar();
      glPopMatrix();
   }
   else{
      if(luz2->estaActivada())
         luz2->desactivar();
   }

   // ESTO ES EL ESCENARIO PARA LA P3
   /*glPushMatrix();
     glTranslatef(-100,1,1);
      glScalef(50,50,50);

      peon_negro->draw(modo_dibujado_escogido,ajedrez,tapas);
   glPopMatrix();

   glPushMatrix();
      glTranslatef(100,1,1);
      glScalef(50,50,50);

      peon_blanco->draw(modo_dibujado_escogido,ajedrez,tapas);
   glPopMatrix();

   glPushMatrix();
      glTranslatef(0,0,-100);
      cilindro->draw(modo_dibujado_escogido,ajedrez,tapas);
   glPopMatrix();

   glPushMatrix();
      glTranslatef (150 ,0,-50);
      cono->draw(modo_dibujado_escogido,ajedrez,tapas);
   glPopMatrix();*/

   //std::cout << "voy a dibujar" << std::endl;
   glScalef(100,100,100);
   peon_negro->draw(modo_dibujado_escogido,ajedrez,tapas);
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
         cout << "Presione 'T' para la visualizaicón con ilumnación" << endl;
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

       case 'M' :
         modoMenu=ANIMACIONMANUAL;

         cout << "Ha entrado en el modo de animacion manual" << endl;
         cout << "Presione '+' para aumentar el valor del grado de libertad seleccionado" << endl;
         cout << "Presione '-' para disminuir el valor del grado de libertad seleccionado" << endl;
         cout << "Presione 0 para modificar el humo del tren" << endl;
         cout << "Presione 1 para modificar el primer vagon del tren" << endl;
         cout << "Presione 2 para modificar el segundo vagon del tren" << endl;
         cout << "Presione 3 para modificar el tercer vagon del tren" << endl;
         cout << "Presione 4 para modificar el cuarto vagon del tren" << endl;
         cout << "Presione 5 para modificar las ruedas del tren" << endl;
       break;

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
          if (modoMenu ==SELVISUALIZACION){
            iluminacion = true;
            modo_visualizacion_escogido = ILUMINACION;
          }

          if (modoMenu == SELOBJETO){
            if (objeto_a_pintar != TETRAEDRO)
               objeto_a_pintar=TETRAEDRO;
            else
               objeto_a_pintar=NINGUNO;
          }

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

         case '0' :
            if (iluminacion){
               if (activar_luz0)
                  activar_luz0 = false;
               else
                  activar_luz0 = true;
            }

            if (modoMenu==ANIMACIONMANUAL){
               objeto=HUMO;
            }

         break;

         case '1'  :

            if (modoMenu == SELDIBUJADO){
               cout << "Ha escogido pintar en modo inmediato" << endl;
               modo_dibujado_escogido = INMEDIATO;
            }

            if (iluminacion){
               if (activar_luz1)
                  activar_luz1 = false;
               else
                  activar_luz1 = true;
            }

            if (modoMenu == ANIMACIONMANUAL){
               objeto=VAGON1;
            }

          break;
         
         case '2'  :

            if (modoMenu == SELDIBUJADO){
               cout << "Ha escogido pintar en modo diferido" << endl;
               modo_dibujado_escogido = DIFERIDO;
            }
            
            if (iluminacion){
               if (activar_luz2)
                  activar_luz2 = false;
               else
                  activar_luz2 = true;
            }

            if (modoMenu == ANIMACIONMANUAL){
               objeto=VAGON2;
            }
         break;

         case '3' :
            if (modoMenu == ANIMACIONMANUAL){
               objeto=VAGON3;
            }
         break;

         case '4' :
            if (modoMenu == ANIMACIONMANUAL){
               objeto=VAGON4;
            }
         break;

         case '5' :
            if (modoMenu == ANIMACIONMANUAL){
               objeto=RUEDAS;
            }
         break;

         case 'P'  :
            if (modo_visualizacion_escogido != PUNTOS && modo_visualizacion_escogido != ILUMINACION){
               cout << "Ha escogido pintar en modo puntos" << endl;
               modo_visualizacion_escogido = PUNTOS;
               iluminacion = false;
            }

            if (modo_visualizacion_escogido == ILUMINACION){
               cout << "Ha escogido pintar con sombreado plano (GL_PLANE)" << endl;
               modo_sombreado_escogido = PLANO;
            }

          break;

         case 'L'  :
            cout << "Ha escogido pintar en modo lineas" << endl;
            if (modo_visualizacion_escogido != LINEAS)
               modo_visualizacion_escogido = LINEAS;
          break;

         case 'S'  :
            if (modo_visualizacion_escogido != SOLIDO && modo_visualizacion_escogido != ILUMINACION){
               cout << "Ha escogido pintar en modo solido" << endl;
               modo_visualizacion_escogido = SOLIDO;
               iluminacion = false;
            }

            if (modo_visualizacion_escogido == ILUMINACION){
               cout << "Ha escogido pintar con sombreado suave (GL_SMOOTH)" << endl;
               modo_sombreado_escogido = SUAVE;
            }
            
          break;

         case 'A'  :

            if (modoMenu != SELVISUALIZACION)
               modoMenu = ANIMACIONAUTOMATICA;

            if (modoMenu == SELVISUALIZACION){
               if (modo_visualizacion_escogido != AJEDREZ && modo_visualizacion_escogido != ILUMINACION){
                  cout << "Ha escogido pintar en modo ajedrez" << endl;
                  modo_visualizacion_escogido = AJEDREZ;
                  iluminacion = false;
               }
            }

            if(modo_visualizacion_escogido == ILUMINACION){
               variacion_direccional = ALPHA;
               cout << "Ha escogido variar la componente alpha de la luz direccional" << endl;
            }

          break;

         case 'Y' :
            modo_visualizacion_escogido = SOLIDO;
         break;

         case 'N' :
            modo_visualizacion_escogido = SINTAPAS;
         break;

         case 'B' :
            if (modo_visualizacion_escogido == ILUMINACION){
               variacion_direccional = BETA;
               cout << "Va a variar la componente beta de la luz direccional" << endl;
            }
         break;

         case '<' :

            if (modo_visualizacion_escogido == ILUMINACION){

               if (variacion_direccional == ALPHA){
                  luz0->variarAnguloAlpha(-20.0);                  
               }

               if (variacion_direccional == BETA){
                  luz0->variarAnguloBeta(-20);
               }
            }

         break;

         case '>' :

            if (modo_visualizacion_escogido == ILUMINACION){

               if (variacion_direccional == ALPHA){
                  luz0->variarAnguloAlpha(20.0);                  
               }

               if (variacion_direccional == BETA){
                  luz0->variarAnguloBeta(20.0);
               }
            }

         break;

         case '+' :
            if (modoMenu == ANIMACIONMANUAL){
               if (objeto == HUMO)
                  tren->modificarGradosLibertadHumoManual(10);
               else if (objeto == VAGON1)
                  tren->modificarGradosLibertadVagon1Manual(10);
               else if (objeto == VAGON2)
                  tren->modificarGradosLibertadVagon2Manual(10);
               else if (objeto == VAGON3)
                  tren->modificarGradosLibertadVagon3Manual(10);
               else if (objeto == VAGON4)
                  tren->modificarGradosLibertadVagon4Manual(10);
               else if (objeto == RUEDAS)
                  tren->modificarGradosLibertadRuedasManual(10);
            }

         break;

         case '-' :

            if (modoMenu == ANIMACIONMANUAL){
               if (objeto == HUMO)
                  tren->modificarGradosLibertadHumoManual(-10);
               else if (objeto == VAGON1)
                  tren->modificarGradosLibertadVagon1Manual(-10);
               else if (objeto == VAGON2)
                  tren->modificarGradosLibertadVagon2Manual(-10);
               else if (objeto == VAGON3)
                  tren->modificarGradosLibertadVagon3Manual(-10);
               else if (objeto == VAGON4)
                  tren->modificarGradosLibertadVagon4Manual(-10);
               else if (objeto == RUEDAS)
                  tren->modificarGradosLibertadRuedasManual(10);
            }
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

void Escena::animar(){
   if (modoMenu == ANIMACIONAUTOMATICA){
      tren->modificarGradosLibertadVagon4Automatico(0.3);
      tren->modificarGradosLibertadVagon3Automatico(0.3);
      tren->modificarGradosLibertadVagon2Automatico(0.3);
      tren->modificarGradosLibertadHumoAutomatico(0.3);
   }
}
