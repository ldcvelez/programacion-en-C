/**//* 38.670.422-CESPEDES,Leonel-(06-2965) *//**/

#include "Figura.h"


////////////////////// Metodos Figura


Figura::Figura(string nombre):nombre(nombre)
{
    this->nombre = nombre;
}


Figura::~Figura()
{}


// Implemento en este archivo lso metodos exception
/////////////////////// METODOS  EXCEPTION


FiguraInvalidaException::FiguraInvalidaException(const string& mensaje)
{
    this->mensaje = mensaje;
}


const string& FiguraInvalidaException::what()const
{
    return this->mensaje;
}
