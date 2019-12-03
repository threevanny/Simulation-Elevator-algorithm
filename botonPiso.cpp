//botonPiso.cpp
//definicion de las funciones miembro de la clase BotonPiso.
#include <iostream>
using namespace std;
#include "botonPiso.h"
#include "elevador.h"

//constructor
BotonPiso::BotonPiso(int piso, Elevador &manipulaElevador)
	:numeroPiso(piso),
	presionado(false),
	refElevador(manipulaElevador)
{
	cout<<"boton del piso "<<numeroPiso<<" construido"<<endl;
}

//destructor
BotonPiso::~BotonPiso()
{
	cout<<"boton del piso "<<numeroPiso<<" destruido"<<endl;
}

//presiona el boton
void BotonPiso::presionaBoton()
{
	presionado=true;
	cout<<"boton del piso "<<numeroPiso<<" llama al elevador"<<endl;

//llama la elevador a este piso
refElevador.llamaElevador(numeroPiso);
}

//restablece boton
void BotonPiso::restableceBoton()
{
	presionado=false;
}
