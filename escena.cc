

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

    //INICIALIZAR SUELO
    suelo = new Cuadro(800);
    suelo->setColor({1,1,1});
    Textura text2 = Textura("texturas/text-madera.jpg");
    suelo->setTextura(text2);
    pared = new Cuadro(800);
    pared->setColor({1,1,1});
    pared->setTextura(text2);
   //////////////////////////////////////////////////////

   //INICIALIZAR LATA
    Textura text = Textura("texturas/text-lata-1.jpg");
    peon_negro = new ObjRevolucion("plys/lata-pcue.ply",50,true);
    peon_negro->setColor({1,1,1});
    peon_negro->setTextura(text);
    /////////////////////////////////////////////////////////////////////

    ///INICIALIZAR BALONFUTBOL
    balonfutbol = new Esfera(100,100,20,true);
    balonfutbol->setColor({1,1,1});
    Textura text3 = Textura("texturas/text-balonfutbol.jpg");
    balonfutbol->setTextura(text3);
    ////////////////////////////////////////////////////////////////////

    // INICIALIZAR TREN
    tren = new Tren();
   /////////////////////////////////////////////////////////////////////

   //INICIALIZAR CAMA
    pata1 = new Prisma(10,50);
    pata1->setColor({0.9,0.65,0.4});
    pata2 = new Prisma(10,50);
    pata2->setColor({0.9,0.65,0.4});
    pata3 = new Prisma(10,50);
    pata3->setColor({0.9,0.65,0.4});
    pata4 = new Prisma(10,50);
    pata4->setColor({0.9,0.65,0.4});
    somier = new Prisma(100,200);
    somier->setColor({0.9,0.65,0.4});
    reposacabezas = new Prisma(100,10);
    reposacabezas->setColor({0.9,0.65,0.4});
    colchon = new Prisma(100,200);
    colchon->setColor({1,0,0});
    ///////////////////////////////////////////////////////////////////

   // INICIALIZAR POSTER
    poster = new Cuadro(20);
    poster->setColor({1,1,1});
    Textura text_cuadro = Textura("texturas/text-cuadro.jpg");
    poster->setTextura(text_cuadro);
   ////////////////////////////////////////////////////////////////////

   //INICIALIZAR MESA
    pataMesa1 = new Prisma (10,80);
    pataMesa2 = new Prisma (10,80);
    pataMesa3 = new Prisma (10,80);
    pataMesa4 = new Prisma (10,80);
    tablaMesa = new Prisma (10,80);
    tablaMesa = new Prisma (100,200);
    pataMesa1->setColor({0.9,0.65,0.4});
    pataMesa2->setColor({0.9,0.65,0.4});
    pataMesa3->setColor({0.9,0.65,0.4});
    pataMesa4->setColor({0.9,0.65,0.4});
    tablaMesa->setColor({0.9,0.65,0.4});
   ////////////////////////////////////////////////////////////////////

   // INICIALIZAR SILLA
    pataSilla1 = new Prisma (10,80);
    pataSilla2 = new Prisma (10,80);
    pataSilla3 = new Prisma (10,80);
    pataSilla4 = new Prisma (10,80);
    baseSilla = new Prisma (40,50);
    reposaEspaldas = new Prisma (60,30);
    pataSilla1->setColor({0.9,0.65,0.4});
    pataSilla2->setColor({0.9,0.65,0.4});
    pataSilla3->setColor({0.9,0.65,0.4});
    pataSilla4->setColor({0.9,0.65,0.4});
    baseSilla->setColor({0.9,0.65,0.4});
    reposaEspaldas->setColor({0.9,0.65,0.4});
   ////////////////////////////////////////////////////////////////////

   // INICIALIZAR LAMPARA
    baseLampara = new Esfera(100,100,20,false);
    baseLampara->setColor({0.6,0.6,0.5});
    cono = new Cono(10,100,20,20,false,false,false);
    cono->setColor({0.6,0.6,0.5});

   /////////////////////////////////////////////////////////////////////
    //Declaro y aplico materiales            DIFUSO               ESPECULAR        AMBIENTE     BRILLO
    Material material_difuso = Material( {1.0,1.0,1.0,1.0} , {0.0,0.0,0.0,1.0} , {0.0,0,0,1.0} , 128.0);
    Material material_especular = Material ( {0.0,0.0,0.0,1.0} , {0.0,0.0,0.0,1.0} , {0.0,0.0,0.0,1.0} , 128.0);
    Material material_esmeralda = Material ({0.9,0.2,0.07,1.0}, {0.9,0.2,0.07, 1}, {0.0, 0.0,0.0, 1}, 64.0);
    Material material_anaranjado = Material ({0.633, 0.727811,0.633, 1}, {0.633, 0.727811,0.633, 1},{0.0215, 0.1745, 0.0215, 1}, 64.0);
    Material white_plastic = Material ({0.55,0.55,0.55,1}, {0.7,0.7,0.7,1}, {0.0,0.0,0.0,1}, 0.25*128);
    Material red_plastic = Material ({0.5,0.0,0.0,1}, {0.7,0.6,0.6,1}, {0,0,0,1}, 0.25*128);
    Material bronce = Material ({0.7038, 0.27048,0.0828, 1}, {0.256777, 0.137622,0.086014, 1},{0.019125, 0.0735, 0.0225, 1}, 12.8);
    Material plata = Material ({0.50754,0.50754,0.50754,1},{0.508273,0.508273,0.508273,1},{0.19225,0.19225,0.19225,1},0.4*128);
    
    //ASIGNACION DE MATERIALES PARA CAMA
    pata1->setMaterial(bronce);
    pata2->setMaterial(bronce);
    pata3->setMaterial(bronce);
    pata4->setMaterial(bronce);
    somier->setMaterial(bronce);
    colchon->setMaterial(red_plastic);
    reposacabezas->setMaterial(bronce);
    ///////////////////////////////////////////////////

    // ASIGNACION DE MATERIALES PARA MESA
    pataMesa1->setMaterial(bronce);
    pataMesa2->setMaterial(bronce);
    pataMesa3->setMaterial(bronce);
    pataMesa4->setMaterial(bronce);
    tablaMesa->setMaterial(bronce);
    //////////////////////////////////////////////////

    // ASGINACION DE MATERIALES PARA SILLA
    pataSilla1->setMaterial(bronce);
    pataSilla2->setMaterial(bronce);
    pataSilla3->setMaterial(bronce);
    pataSilla4->setMaterial(bronce);
    baseSilla->setMaterial(bronce);
    reposaEspaldas->setMaterial(bronce);

    // ASIGNACION DE MATERIALES PARA LAMPARA
    cono->setMaterial(plata);
    baseLampara->setMaterial(plata);
    //////////////////////////////////////////////////

    // ASIGNACION DE MATERIALES PARA POSTER, BALON DE FUTBOL, PARED, SUELO Y LATA
    poster->setMaterial(white_plastic);
    suelo->setMaterial(white_plastic);
    pared->setMaterial(white_plastic);
    peon_negro->setMaterial(white_plastic);
    balonfutbol->setMaterial(white_plastic);
   ///////////////////////////////////////////////////

   // CREO LAS LUCES DE LA ESCENA
    luz0 = new LuzDireccional({0,10},GL_LIGHT0,{1.0,1.0,1.0,1.0}, {1.0,1.0,1.0,1.0}, {1.0,1.0,1.0,1.0});
    luz1 = new LuzPosicional({20, 200, 50},GL_LIGHT1,  {0.239,0.239,0.239,1.0}, {1.0,1.0,1.0,1}, {1.0,1.0,1.0,1.0});
    luz2 = new LuzPosicional({0, 200, 900},GL_LIGHT2,  {0.239,0.169,0.074,1.0}, {1.0,1.0,1.0,1}, {1.0,1.0,1.0,1.0});
    luz3 = new LuzPosicional({118, 110, 120},GL_LIGHT3,  {0.239,0.169,0.074,1.0}, {1.0,1.0,1.0,1}, {1.0,1.0,1.0,1.0});
   /////////////////////////////////////////////////////////////////////////////////////////////////////////////////

   // DECLARO LAS CAMARAS DE LA ESCENA
   Tupla3f eye = {500,100,500};
   Tupla3f at = {0 ,0 ,0};
   Tupla3f up = {0,1,0};

   camaras.push_back(Camara(eye,at,up,0,50.0,20000.0,100,100));

   eye = {0,100,700};
   at = {0,60,-115};

   camaras.push_back(Camara(eye,at,up,0,50.0,20000.0,100,100));

   eye = {-500,100,500};
   at = {0,0,0};

   camaras.push_back(Camara(eye,at,up,1,50.0,20000.0,50,100));

   camaraActiva = 1;

   ///////////////////////////////////////////////////////
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

   // TROZO PARA LA ACTIVACION DE LUCES
   //////////////////////////////////////////////////////////////////////////////
   if (iluminacion){
      glEnable(GL_NORMALIZE);
      glEnable(GL_LIGHTING);

      if (modo_sombreado_escogido == SUAVE)
         glShadeModel(GL_SMOOTH);
      else
         glShadeModel (GL_FLAT);
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

   if (activar_luz3){
      glPushMatrix();
         luz3->activar();
      glPopMatrix();
   }
   else{
      if(luz3->estaActivada())
         luz3->desactivar();
   }
   ////////////////////////////////////////////////////////////////////////////

   glEnable(GL_TEXTURE_2D);

   // DIBUJANDO OBJETOS CON TEXTURA
   ////////////////////////////////////////////////////////////////////////////
   glPushMatrix();
      glTranslatef(220,75,100);
      peon_negro->setPosicion({220,75,100});
      glScalef(30,30,30);
      glRotatef(90,0,1,0);
      peon_negro->draw(modo_dibujado_escogido,ajedrez,tapas);
   glPopMatrix();
   
   glPushMatrix();
      glTranslatef(-400,0,400);
      glRotatef(-90,1,0,0);
      suelo->draw(modo_dibujado_escogido,ajedrez);
   glPopMatrix();

   glPushMatrix();
      glTranslatef(-200,20,200);
      balonfutbol->setPosicion({-200,20,200});
      balonfutbol->draw(modo_dibujado_escogido,ajedrez,tapas);
   glPopMatrix();

   glPushMatrix();
      glTranslatef(-400,0,0);
      pared->draw(modo_dibujado_escogido,ajedrez);
   glPopMatrix();

   glPushMatrix();
      glTranslatef(-200,200,10);
      glScalef(10,10,10);
      poster->setPosicion({-200,200,10});
      poster->draw(modo_dibujado_escogido,ajedrez);
   glPopMatrix();

   glDisable(GL_TEXTURE_2D);

   // DIBUJANDO TREN
   /////////////////////////////////////////////////////////////////////////////////////////////
   glPushMatrix();
      glTranslatef(-200,10,300);
      glScalef(0.5,0.5,0.5);
      tren->setPosicion({-200,10,300});
      tren->draw(modo_dibujado_escogido,ajedrez,tapas);
   glPopMatrix();
   //////////////////////////////////////////////////////////////////////////////////////////////


   // Dibujando CAMA
   ////////////////////////////////////////////////////////////////////////////////////////////
   glPushMatrix();
      glTranslatef(-300,20,50);
      glRotatef(90,0,0,1);
      pata1->draw(modo_dibujado_escogido,ajedrez);
   glPopMatrix();

   glPushMatrix();
      glTranslatef(-230,20,50);
      glRotatef(90,0,0,1);
      pata2->draw(modo_dibujado_escogido,ajedrez);
   glPopMatrix();

   glPushMatrix();
      glTranslatef(-300,20,160);
      glRotatef(90,0,0,1);
      pata3->draw(modo_dibujado_escogido,ajedrez);
   glPopMatrix();

   glPushMatrix();
      glTranslatef(-230,20,160);
      glRotatef(90,0,0,1);
      pata4->draw(modo_dibujado_escogido,ajedrez);
   glPopMatrix();

   glPushMatrix();
      glTranslatef (-230,40,100);
      glRotatef(90,0,1,0);
      glScalef(0.75,0.055,1);
      somier->setPosicion({-230,40,100});
      somier->draw(modo_dibujado_escogido,ajedrez);
   glPopMatrix();

   glPushMatrix();
      glTranslatef(-230,40,30);
      glRotatef(90,0,1,0);
      glScalef(1,0.75,1);
      reposacabezas->draw(modo_dibujado_escogido,ajedrez);
   glPopMatrix();

   glPushMatrix();
      glTranslatef(-230,49,105);
      glRotatef(90,0,1,0);
      glScalef(0.68,0.3,1);
      colchon->draw(modo_dibujado_escogido,ajedrez);
   glPopMatrix();
   //////////////////////////////////////////////////////////////////////////

   ////////////////////////////////////////////////////////////////////////////
   // DIBUJANDO MESA
   glPushMatrix();
      glTranslatef(250,30,110);
      glRotatef(90,0,0,1);
      pataMesa1->draw(modo_dibujado_escogido,ajedrez);
   glPopMatrix();

   glPushMatrix();
      glTranslatef(250,30,160);
      glRotatef(90,0,0,1);
      pataMesa2->draw(modo_dibujado_escogido,ajedrez);
   glPopMatrix();

   glPushMatrix();
      glTranslatef(130,30,160);
      glRotatef(90,0,0,1);
      pataMesa3->draw(modo_dibujado_escogido,ajedrez);
   glPopMatrix();

   glPushMatrix();
      glTranslatef(130,30,110);
      glRotatef(90,0,0,1);
      pataMesa4->draw(modo_dibujado_escogido,ajedrez);
   glPopMatrix();

   glPushMatrix();
      glTranslatef(180,60,180);
      glScalef(1,0.15,1);
      tablaMesa->setPosicion({180,60,180});
      tablaMesa->draw(modo_dibujado_escogido,ajedrez);
   glPopMatrix();
   /////////////////////////////////////////////////////////////////////////

   /////////////////////////////////////////////////////////////////////////
   // DIBUJANDO SILLA
   glPushMatrix();
      glTranslatef(200,30,210);
      glRotatef(90,0,0,1);
      glScalef(0.5,1,1);
      pataSilla1->draw(modo_dibujado_escogido,ajedrez);
   glPopMatrix();

   glPushMatrix();
      glTranslatef(200,30,240);
      glRotatef(90,0,0,1);
      glScalef(0.5,1,1);
      pataSilla2->draw(modo_dibujado_escogido,ajedrez);
   glPopMatrix();

   glPushMatrix();
      glTranslatef(170,30,210);
      glRotatef(90,0,0,1);
      glScalef(0.5,1,1);
      pataSilla3->draw(modo_dibujado_escogido,ajedrez);
   glPopMatrix();

   glPushMatrix();
      glTranslatef(170,30,240);
      glRotatef(90,0,0,1);
      glScalef(0.5,1,1);
      pataSilla4->draw(modo_dibujado_escogido,ajedrez);
   glPopMatrix();

   glPushMatrix();
      glTranslatef(180,50,240);
      glScalef(1,0.25,1);
      baseSilla->setPosicion({180,50,240});
      baseSilla->draw(modo_dibujado_escogido,ajedrez);
   glPopMatrix();

   glPushMatrix();
      glTranslatef(200,60,240);
      glScalef(0.25,1,0.67);
      reposaEspaldas->draw(modo_dibujado_escogido,ajedrez);
   glPopMatrix();
   /////////////////////////////////////////////////////////////////////////

   ////////////////////////////////////////////////////////////////////////
   // DIBUJANDO LAMPARA
   glPushMatrix();
      glTranslatef(118,110,120);
      cono->setPosicion({128,128,200});
      cono->draw(modo_dibujado_escogido,ajedrez,tapas);
   glPopMatrix();

   glPushMatrix();
      glTranslatef(118,95,120);
      baseLampara->setPosicion({118,95,120});
      baseLampara->draw(modo_dibujado_escogido,ajedrez,tapas);
   glPopMatrix();
   //////////////////////////////////////////////////////////////////////////7
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
            if (modoMenu == SELOBJETO){
               if (objeto_a_pintar != CUBO){
                  objeto_a_pintar=CUBO;
               }
               else{
                  objeto_a_pintar=NINGUNO;
               }
            }
            else {
               cout << "MODO MENU = SELCAM";
               modoMenu = SELCAM;
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
            if (iluminacion && modoMenu == SELVISUALIZACION){
               if (activar_luz0)
                  activar_luz0 = false;
               else
                  activar_luz0 = true;
            }

            if (modoMenu==ANIMACIONMANUAL){
               objeto=HUMO;
            }

            if (modoMenu == SELCAM){
               cout << "Camara activa = 0" << endl;
               camaraActiva = 0;
               change_projection(1);
            }

         break;

         case '1'  :

            if (modoMenu == SELDIBUJADO){
               cout << "Ha escogido pintar en modo inmediato" << endl;
               modo_dibujado_escogido = INMEDIATO;
            }

            if (iluminacion && modoMenu == SELVISUALIZACION){
               if (activar_luz1)
                  activar_luz1 = false;
               else
                  activar_luz1 = true;
            }

            if (modoMenu == SELCAM){
               cout << "Camara activa = 1" << endl;
               camaraActiva = 1;
               change_projection(1);
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
            
            if (iluminacion && modoMenu == SELVISUALIZACION){
               if (activar_luz2)
                  activar_luz2 = false;
               else
                  activar_luz2 = true;
            }

            if (modoMenu == SELCAM){
               cout << "Camara activa = 2" << endl;
               camaraActiva = 2;
               change_projection(1);
            }

            if (modoMenu == ANIMACIONMANUAL){
               objeto=VAGON2;
            }
         break;

         case '3' :
            if (modoMenu == ANIMACIONMANUAL){
               objeto=VAGON3;
            }

            if (iluminacion && modoMenu == SELVISUALIZACION){
               if (activar_luz3)
                  activar_luz3 = false;
               else
                  activar_luz3 = true;
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
         camaras[camaraActiva].rotarYExaminar(-1*M_PI/180.0);
         break;
	   case GLUT_KEY_RIGHT:
         camaras[camaraActiva].rotarYExaminar(1*M_PI/180.0);
         break;
	   case GLUT_KEY_UP:
         camaras[camaraActiva].rotarXExaminar(-1*M_PI/180.0);
         break;
	   case GLUT_KEY_DOWN:
         camaras[camaraActiva].rotarXExaminar(1*M_PI/180.0);
         break;
	   case GLUT_KEY_PAGE_UP:
         camaras[camaraActiva].zoom(10.8);
         break;
	   case GLUT_KEY_PAGE_DOWN:
         camaras[camaraActiva].zoom(-10.8);
         break;
	}

   change_projection(1);
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
   //glFrustum( -wx, wx, -Height, Height, Front_plane, Back_plane );
   camaras[camaraActiva].setProyeccion();

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
   camaras[camaraActiva].setObserver();
}

void Escena::animar(){
   if (modoMenu == ANIMACIONAUTOMATICA){
      tren->modificarGradosLibertadVagon4Automatico(0.3);
      tren->modificarGradosLibertadVagon3Automatico(0.3);
      tren->modificarGradosLibertadVagon2Automatico(0.3);
      tren->modificarGradosLibertadHumoAutomatico(0.3);
      tren->modificarGradosLibertadRuedasAutomatico(0.3);
   }

   if (iluminacion){
      if (luz1->estaActivada()){
         luz1->cambiarPosicion(10,0,0);
         std::cout << "Cambiando pos" << std::endl;
      }
      if (luz2->estaActivada())
         luz2->cambiarPosicion(10,0,0);
   }
}

void Escena::clickRaton(int boton, int estado, int x, int y){
   xant = x;
   yant = y;

   if (boton == GLUT_RIGHT_BUTTON){
      if (estado == GLUT_DOWN){
         if (!objetoSeleccionado)
            estadoRaton = MOVIENDO_CAMARA_FIRSTPERSON;
         else{
            estadoRaton = MOVIENDO_CAMARA_EXAMINAR;
            std::cout << "Moviendo camara examinar" << std::endl;
         }
      }
      else{
         estadoRaton = DESACTIVADO;
      }

   }
   else if (boton == 3){
      camaras[camaraActiva].zoom(10.8);
   }
   else if (boton == 4){
      camaras[camaraActiva].zoom(-10.8);
   }
   else if(boton == GLUT_LEFT_BUTTON){
      std::cout << "Has pulsado el boton izquierdo del raton" << std::endl;
      if (estado == GLUT_DOWN){
         std::cout << "Llamo a dibujaSeleccion" << std::endl;
         dibujaSeleccion();
         procesarPick(x,y);
      }
   }

   change_projection(1);
} 

void Escena::ratonMovido(int x, int y){

   if (estadoRaton == MOVIENDO_CAMARA_FIRSTPERSON){
      camaras[camaraActiva].girar(x-xant, y-yant);
   }
   else if (estadoRaton == MOVIENDO_CAMARA_EXAMINAR){
      camaras[camaraActiva].girarEx(x-xant,y-yant);
   }

   xant = x;
   yant = y;
}

void Escena::dibujaSeleccion(){
   Tupla3f color_antes;
   glDisable(GL_DITHER);
   glDisable(GL_LIGHTING);
   glDisable(GL_TEXTURE_2D);

   glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   change_observer();
   // DIBUJANDO OBJETOS CON TEXTURA
   ////////////////////////////////////////////////////////////////////////////
   peon_negro->setColorSeleccion({1,0,0});
   color_antes = peon_negro->getColor();
   peon_negro->setColor({1,0,0});
   glPushMatrix();
      glTranslatef(220,75,100);
      glScalef(30,30,30);
      glRotatef(90,0,1,0);
      peon_negro->draw(modo_dibujado_escogido,false,false);
   glPopMatrix();
   peon_negro->setColor(color_antes);

   balonfutbol->setColorSeleccion({0,1,0});
   color_antes = balonfutbol->getColor();
   balonfutbol->setColor({0,1,0});
   glPushMatrix();
      glTranslatef(-200,20,200);
      balonfutbol->draw(modo_dibujado_escogido,false,false);
   glPopMatrix();
   balonfutbol->setColor(color_antes);

   poster->setColorSeleccion({0,0,1});
   color_antes = poster->getColor();
   poster->setColor({0,0,1});
   glPushMatrix();
      glTranslatef(-200,200,10);
      glScalef(10,10,10);
      poster->draw(modo_dibujado_escogido,false);
   glPopMatrix();
   poster->setColor(color_antes);

   glDisable(GL_TEXTURE_2D);

   // DIBUJANDO TREN
   /////////////////////////////////////////////////////////////////////////////////////////////
   tren->setColorSeleccion({1,1,0});
   color_antes = tren->getColor();
   tren->setColor({1,1,0});
   glPushMatrix();
      glTranslatef(-200,10,300);
      glScalef(0.5,0.5,0.5);
      tren->setPosicion({-200,10,300});
      tren->draw(modo_dibujado_escogido,false,false);
   glPopMatrix();
   tren->restaurarColorConectoresChimenea();
   tren->restaurarColorRuedasHumo();
   tren->restaurarColorVagones();
   //////////////////////////////////////////////////////////////////////////////////////////////


   // Dibujando CAMA
   ////////////////////////////////////////////////////////////////////////////////////////////
   somier->setColorSeleccion({0,1,1});
   color_antes = somier->getColor();
   somier->setColor({0,1,1});
   pata1->setColor({0,1,1});
   pata2->setColor({0,1,1});
   pata3->setColor({0,1,1});
   pata4->setColor({0,1,1});
   colchon->setColor({0,1,1});
   reposacabezas->setColor({0,1,1});
   glPushMatrix();
      glTranslatef(-300,20,50);
      glRotatef(90,0,0,1);
      pata1->draw(modo_dibujado_escogido,false);
   glPopMatrix();

   glPushMatrix();
      glTranslatef(-230,20,50);
      glRotatef(90,0,0,1);
      pata2->draw(modo_dibujado_escogido,false);
   glPopMatrix();

   glPushMatrix();
      glTranslatef(-300,20,160);
      glRotatef(90,0,0,1);
      pata3->draw(modo_dibujado_escogido,false);
   glPopMatrix();

   glPushMatrix();
      glTranslatef(-230,20,160);
      glRotatef(90,0,0,1);
      pata4->draw(modo_dibujado_escogido,false);
   glPopMatrix();

   glPushMatrix();
      glTranslatef (-230,40,100);
      glRotatef(90,0,1,0);
      glScalef(0.75,0.055,1);
      somier->draw(modo_dibujado_escogido,false);
   glPopMatrix();

   glPushMatrix();
      glTranslatef(-230,40,30);
      glRotatef(90,0,1,0);
      glScalef(1,0.75,1);
      reposacabezas->draw(modo_dibujado_escogido,false);
   glPopMatrix();

   glPushMatrix();
      glTranslatef(-230,49,105);
      glRotatef(90,0,1,0);
      glScalef(0.68,0.3,1);
      colchon->draw(modo_dibujado_escogido,false);
   glPopMatrix();
   somier->setColor(color_antes);
   pata1->setColor(color_antes);
   pata2->setColor(color_antes);
   pata3->setColor(color_antes);
   pata4->setColor(color_antes);
   colchon->setColor({1,0,0});
   reposacabezas->setColor(color_antes);
   //////////////////////////////////////////////////////////////////////////

   ////////////////////////////////////////////////////////////////////////////
   // DIBUJANDO MESA
   tablaMesa->setColorSeleccion({1,0,1});
   color_antes = tablaMesa->getColor();
   tablaMesa->setColor({1,0,1});
   pataMesa1->setColor({1,0,1});
   pataMesa2->setColor({1,0,1});
   pataMesa3->setColor({1,0,1});
   pataMesa4->setColor({1,0,1});

   glPushMatrix();
      glTranslatef(250,30,110);
      glRotatef(90,0,0,1);
      pataMesa1->draw(modo_dibujado_escogido,false);
   glPopMatrix();

   glPushMatrix();
      glTranslatef(250,30,160);
      glRotatef(90,0,0,1);
      pataMesa2->draw(modo_dibujado_escogido,false);
   glPopMatrix();

   glPushMatrix();
      glTranslatef(130,30,160);
      glRotatef(90,0,0,1);
      pataMesa3->draw(modo_dibujado_escogido,false);
   glPopMatrix();

   glPushMatrix();
      glTranslatef(130,30,110);
      glRotatef(90,0,0,1);
      pataMesa4->draw(modo_dibujado_escogido,false);
   glPopMatrix();

   glPushMatrix();
      glTranslatef(180,60,180);
      glScalef(1,0.15,1);
      tablaMesa->draw(modo_dibujado_escogido,false);
   glPopMatrix();

   tablaMesa->setColor(color_antes);
   pataMesa1->setColor(color_antes);
   pataMesa2->setColor(color_antes);
   pataMesa3->setColor(color_antes);
   pataMesa4->setColor(color_antes);
   /////////////////////////////////////////////////////////////////////////

   /////////////////////////////////////////////////////////////////////////
   // DIBUJANDO SILLA
   baseSilla->setColorSeleccion({1,0.5,1});
   color_antes = baseSilla->getColor();
   baseSilla->setColor({1,0.5,1});
   pataSilla1->setColor({1,0.5,1});
   pataSilla2->setColor({1,0.5,1});
   pataSilla3->setColor({1,0.5,1});
   pataSilla4->setColor({1,0.5,1});
   reposaEspaldas->setColor({1,0.5,1});
   glPushMatrix();
      glTranslatef(200,30,210);
      glRotatef(90,0,0,1);
      glScalef(0.5,1,1);
      pataSilla1->draw(modo_dibujado_escogido,false);
   glPopMatrix();

   glPushMatrix();
      glTranslatef(200,30,240);
      glRotatef(90,0,0,1);
      glScalef(0.5,1,1);
      pataSilla2->draw(modo_dibujado_escogido,false);
   glPopMatrix();

   glPushMatrix();
      glTranslatef(170,30,210);
      glRotatef(90,0,0,1);
      glScalef(0.5,1,1);
      pataSilla3->draw(modo_dibujado_escogido,false);
   glPopMatrix();

   glPushMatrix();
      glTranslatef(170,30,240);
      glRotatef(90,0,0,1);
      glScalef(0.5,1,1);
      pataSilla4->draw(modo_dibujado_escogido,false);
   glPopMatrix();

   glPushMatrix();
      glTranslatef(180,50,240);
      glScalef(1,0.25,1);
      baseSilla->draw(modo_dibujado_escogido,false);
   glPopMatrix();

   glPushMatrix();
      glTranslatef(200,60,240);
      glScalef(0.25,1,0.67);
      reposaEspaldas->draw(modo_dibujado_escogido,false);
   glPopMatrix();

   baseSilla->setColor(color_antes);
   pataSilla1->setColor(color_antes);
   pataSilla2->setColor(color_antes);
   pataSilla3->setColor(color_antes);
   pataSilla4->setColor(color_antes);
   reposaEspaldas->setColor(color_antes);
   /////////////////////////////////////////////////////////////////////////

   ////////////////////////////////////////////////////////////////////////
   // DIBUJANDO LAMPARA
   cono->setColorSeleccion({0.2,0.2,0.2});
   baseLampara->setColorSeleccion({0.2,0.2,0.2});
   color_antes = cono->getColor();
   cono->setColor({0.2,0.2,0.2});
   baseLampara->setColor({0.2,0.2,0.2});

   glPushMatrix();
      glTranslatef(118,110,120);
      cono->setPosicion({128,128,200});
      cono->draw(modo_dibujado_escogido,false,false);
   glPopMatrix();

   glPushMatrix();
      glTranslatef(118,95,120);
      baseLampara->draw(modo_dibujado_escogido,false,false);
   glPopMatrix();

   cono->setColor(color_antes);
   baseLampara->setColor(color_antes);
   //////////////////////////////////////////////////////////////////////////7
   

   glEnable(GL_DITHER);
	glEnable(GL_LIGHTING);
	glEnable(GL_TEXTURE);
}

void Escena::procesarPick(int x, int y){
   glDisable(GL_DITHER);
	glDisable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

   GLint viewport[4];
   glGetIntegerv(GL_VIEWPORT,viewport);
   GLfloat pixel[3];

   glReadPixels(x,viewport[3]-y,1,1,GL_RGB,GL_FLOAT, (void *) pixel);

   Tupla3f pixel_leido = {pixel[0],pixel[1],pixel[2]};

   //Truncamos a un decimal todas las componentes del pixel
   int valor_truncado = pixel_leido[0] * 10;
   pixel_leido[0] = valor_truncado / 10.0;
   valor_truncado = pixel_leido[1] * 10;
   pixel_leido[1] = valor_truncado / 10.0;
   valor_truncado = pixel_leido[2] * 10;
   pixel_leido[2] = valor_truncado / 10.0;

   if (pixel_leido[0] == peon_negro->getColorSeleccion()[0] && pixel_leido[1] == peon_negro->getColorSeleccion()[1] && pixel_leido[2] == peon_negro->getColorSeleccion()[2]){
      std::cout << "Has seleccionado la lata" << std::endl;

      peon_negro->calcularCentro();

      Tupla3f centro = peon_negro->getCentro();

      centro = centro + peon_negro->getPosicion();

      camaras[camaraActiva].setAt(centro);
      objetoSeleccionado = true;
   }
   else if (pixel_leido[0] == balonfutbol->getColorSeleccion()[0] && pixel_leido[1] == balonfutbol->getColorSeleccion()[1] && pixel_leido[2] == balonfutbol->getColorSeleccion()[2]){
      std::cout << "Has seleccionado el balon de futbol" << std::endl;

      balonfutbol->calcularCentro();

      Tupla3f centro = balonfutbol->getCentro() + balonfutbol->getPosicion();

      camaras[camaraActiva].setAt(centro);
      objetoSeleccionado = true;
   }
   else if (pixel_leido[0] == poster->getColorSeleccion()[0] && pixel_leido[1] == poster->getColorSeleccion()[1] && pixel_leido[2] == poster->getColorSeleccion()[2]){
      std::cout << "Has seleccionado el poster" << std::endl;

      poster->calcularCentro();

      Tupla3f centro = poster->getCentro() + poster->getPosicion();

      camaras[camaraActiva].setAt(centro);
      objetoSeleccionado = true;
   }
   else if (pixel_leido[0] == tren->getColorSeleccion()[0] && pixel_leido[1] == tren->getColorSeleccion()[1] && pixel_leido[2] == tren->getColorSeleccion()[2]){
      std::cout << "Has seleccionado el tren" << std::endl;

      Tupla3f centro = tren->getPosicion();

      camaras[camaraActiva].setAt(centro);
      objetoSeleccionado = true;
   }
   else if (pixel_leido[0] == somier->getColorSeleccion()[0] && pixel_leido[1] == somier->getColorSeleccion()[1] && pixel_leido[2] == somier->getColorSeleccion()[2]){
      std::cout << "Has seleccionado la cama " << std::endl;

      somier->calcularCentro();

      Tupla3f centro = somier->getCentro()+ somier->getPosicion();

      camaras[camaraActiva].setAt(centro);
      objetoSeleccionado = true;
   }
   else if (pixel_leido[0] == tablaMesa->getColorSeleccion()[0] && pixel_leido[1] == tablaMesa->getColorSeleccion()[1] && pixel_leido[2] == tablaMesa->getColorSeleccion()[2]){
      std::cout << "Has seleccionado la mesa " << std::endl;

      tablaMesa->calcularCentro();

      Tupla3f centro = tablaMesa->getCentro() + tablaMesa->getPosicion();

      camaras[camaraActiva].setAt(centro);
      objetoSeleccionado = true;
   }
   else if (pixel_leido[0] == baseSilla->getColorSeleccion()[0] && pixel_leido[1] == baseSilla->getColorSeleccion()[1] && pixel_leido[2] == baseSilla->getColorSeleccion()[2]){
      std::cout << "Has seleccionado la silla" << std::endl;

      baseSilla->calcularCentro();

      Tupla3f centro = baseSilla->getCentro() + baseSilla->getPosicion();
      camaras[camaraActiva].setAt(centro);
      objetoSeleccionado = true;
   }
   else if (pixel_leido[0] == baseLampara->getColorSeleccion()[0] && pixel_leido[1] == baseLampara->getColorSeleccion()[1] && pixel_leido[2] == baseLampara->getColorSeleccion()[2]){
      std::cout << "Has seleccionado la lampara" << std::endl;

      baseLampara->getCentro();

      Tupla3f centro = baseLampara->getCentro() + baseLampara->getPosicion();
      camaras[camaraActiva].setAt(centro);
      objetoSeleccionado = true;
   }
   else{
      std::cout << "No hay ningun objeto seleccionado" << std::endl;
      objetoSeleccionado = false;
   }
}