/**//* 38.670.422-CESPEDES,Leonel-(06-2965) *//**/

#include "Resta.h"

Resta::Resta(const float a,const float b):Operador(a,b,"RESTA"){}

//Resta::~Resta()
//{
//
//}

float Resta::calcular()const
{
    return _operA-_operB;
}
