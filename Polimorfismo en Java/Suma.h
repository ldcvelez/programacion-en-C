/**//* 38.670.422-CESPEDES,Leonel-(06-2965) *//**/

#ifndef SUMA_H_INCLUDED
#define SUMA_H_INCLUDED

#include <string>
#include "Operador.h"

class Suma : public Operador
{
public:
    Suma(const float a,const float b);
    //~Suma();
    float calcular()const;
};
#endif // SUMA_H_INCLUDED

