/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* 38.670.422-CESPEDES,Leonel-(06-2965) *//**/
/**//**   DEBE MODIFICAR LA LÍNEA DE COMENTARIO ANTERIOR CON SUS DATOS   **//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//**   DESARROOLLE LAS "FUNCIONES MIEMBRO" DE LA CLASE    **//**//**//**/

#include "Prisma.h"


///////////////////    Métodos Constructores


Prisma::Prisma(string color, int alto, int ancho, int profundidad)
{
 if(alto <= 0 || ancho <= 0 || profundidad <= 0)   // Si se quiere crear un objeto con atributos <=0 , crea un objeto con valores 1 en c/u de ellos
 {
        this->color = "Incoloro";
        this->alto = 1;
        this->ancho = 1;
        this->profundidad = 1;
 }
  else
     {
        this->color = color;
        this->alto = alto;
        this->ancho = ancho;
        this->profundidad = profundidad;
      }
}


Prisma::Prisma(const Prisma& pris)
{
    this->color = pris.color;
    this->alto = pris.alto;
    this->ancho = pris.ancho;
    this->profundidad = pris.profundidad;
}


////////////////////////////////// Sobrecarga de Operadores


void Prisma::imprimirPrisma(ostream& out)const
{
    out << alto << "x" << ancho << "x" << profundidad << "-" << color;
}



ostream& operator<<(ostream& out, const Prisma& p)
{
    p.imprimirPrisma(out);
    return out;
}



Prisma operator*(int numero, const Prisma& obj)
{
    Prisma aux;
    aux.alto = numero * obj.alto;
    aux.ancho = numero * obj.ancho;
    aux.profundidad = numero * obj.profundidad;
    aux.color = obj.color;
    return aux;
}



Prisma Prisma::operator++(int num)
{
    Prisma aux(this->color, this->alto, this->ancho, this->profundidad);
    this->alto++;
    this->ancho++;
    this->profundidad++;
    return aux;
}


Prisma& Prisma::operator--()
{
  if(this->alto > 1)
    this->alto--;
  if(this->ancho > 1)
    this->ancho--;
  if(this->profundidad > 1)
    this->profundidad--;
    return *this;
}




Prisma& Prisma::operator=(const Prisma& obj)
{
    this->alto = obj.alto;
    this->ancho = obj.ancho;
    this->profundidad = obj.profundidad;
    this->color = obj.color;
    return *this;
}
