/**//* 38.670.422-CESPEDES,Leonel-(06-2965) *//**/

#include "Suma.h"

Suma::Suma(const float a,const float b):Operador(a,b,"SUMA"){}

//Suma::~Suma()
//{
//
//}

float Suma::calcular()const
{
    return _operA+_operB;
}

