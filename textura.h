#ifndef TEXTURA_H_INCLUDED
#define TEXTURA_H_INCLUDED

#include "aux.h"

class Textura{
    private:
        GLuint textura_id = 0;
        unsigned char * texels;
        int width,height;
        std::vector<unsigned char> data;

    public:
        Textura();
        Textura(const std::string & archivo);
        Textura (const Textura & t);
        void activar();
        Textura & operator = (const Textura & otro);


};

#endif