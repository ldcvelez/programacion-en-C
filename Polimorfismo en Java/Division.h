/**//* 38.670.422-CESPEDES,Leonel-(06-2965) *//**/

#ifndef DIVISION_H_INCLUDED
#define DIVISION_H_INCLUDED

#include "Operador.h"
#include "DivisionPorCeroException.h"


class Division : public Operador
{
public:
    Division(const float a,const float b);
    //~Division();
    float calcular()const;
};

#endif // DIVISION_H_INCLUDED

