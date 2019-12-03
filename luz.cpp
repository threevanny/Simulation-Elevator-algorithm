//luz.cpp
//definicion de las funciones mienbro de la clase luz.
#include <iostream>
using namespace std;
#include "luz.h"

//constructor
Luz::Luz(int numero)
	:encendida(false),
	numeroPiso(numero)
	{
		cout<<"piso "<<numeroPiso<<" luz construida"<<endl;
	}
	
//destructor
Luz:: ~Luz() 
{
	cout<<"piso "<<numeroPiso<<" luz destruida"<<endl;
}

//enciende la luz
void Luz::enciende()
{
	if(!encendida){ //si la luz no esta encendida, la enciende
	encendida = true;
	cout<<"piso "<<numeroPiso<<" se enciende la luz"<<endl;
	}
}

//apaga la luz
void Luz::apaga()
{
	if(encendida){ //si la luz no esta encendida, la apaga
	encendida = false;
	cout<<"piso "<<numeroPiso<<" se apaga la luz"<<endl;
	}
}
