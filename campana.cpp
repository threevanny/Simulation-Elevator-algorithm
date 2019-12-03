//campana.cpp
//definicion de las funciones miembro de la clase campana.
#include <iostream>

using namespace std;

#include"campana.h"

//constructor
Campana::Campana()
{
	cout<<"campana construida"<<endl;
}
//destructor
Campana::~Campana()
{
	cout<<"campana destruida"<<endl;
}
//suena campana
void Campana::suenaCampana()const
{
	cout<<"el elevador suena la campana"<<endl;
}
