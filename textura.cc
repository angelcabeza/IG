#include "textura.h"
#include "jpg_imagen.hpp"

Textura::Textura(){}

Textura::Textura(const std::string & archivo){
    jpg::Imagen * pimg = new jpg::Imagen(archivo);
    width = pimg->tamX();
    height = pimg->tamY();
	texels = pimg->leerPixels();
}

Textura::Textura(const Textura & t){
	*this = t;
}

void Textura::activar(){
	glEnable(GL_TEXTURE_2D);

	if (textura_id == 0) {
		glGenTextures( 1, &textura_id ); // idTex almacena el nuevo identificador

		//Cambiar el identificador de textura activa
		glBindTexture(GL_TEXTURE_2D,textura_id);

		gluBuild2DMipmaps( GL_TEXTURE_2D ,GL_RGB ,// formato interno
							width ,// núm. de columnas (arbitrario)
							height ,// núm de filas (arbitrario)
							GL_RGB ,// formato y orden de los texels en RAM
							GL_UNSIGNED_BYTE ,// tipo de cada te-xel
							texels// puntero a los bytes con texels(void *)
						 );
 	} else {
      //Cambiar el identificador de textura activa
      glBindTexture(GL_TEXTURE_2D,textura_id);
	}

	//std::cout << "ME SALGO DEL METODO" << std::endl;
}

Textura & Textura::operator = (const Textura & otro){
	this->texels = otro.texels;
	this->width = otro.width;
	this->height = otro.height;
	this->textura_id = otro.textura_id;

	return *this;
}