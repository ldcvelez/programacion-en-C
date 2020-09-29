/**//* 38.670.422-CESPEDES,Leonel-(06-2965) *//**/

#ifndef FIGURA_H_
#define FIGURA_H_

#include "FiguraInvalidaException.h"
#include <string>

using namespace std;


class Figura
{
private:
        string nombre;


public:
        Figura(string nombre);
        virtual ~Figura();

        virtual double area() const = 0;
};



#endif // FIGURA_H_
