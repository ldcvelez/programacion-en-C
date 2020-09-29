/**//* 38.670.422-CESPEDES,Leonel-(06-2965) *//**/

#ifndef RESTA_H_INCLUDED
#define RESTA_H_INCLUDED

#include "Operador.h"

class Resta : public Operador
{
public:
    Resta(const float a,const float b);
    //~Resta();
    float calcular()const;

};
#endif // RESTA_H_INCLUDED

