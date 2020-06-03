//botonElevador.cpp
//definicion de las funciones de la clase Botonelevador
#include <iostream>
using namespace std;
#include "botonElevador.h"
#include "elevador.h"

//constructor
BotonElevador::BotonElevador(Elevador &manipulaElevador)
	:presionado(false),
	refElevador(manipulaElevador)
	{
		cout<<"boton del elevador construido"<<endl;
	}
//destructor
BotonElevador::~BotonElevador()
{
	cout<<"boton del elevador destruido"<<endl;
}

//presiona el boton e indica al elevador que se prepare para abandonar el piso
void BotonElevador::presionaBoton()
{
	presionado = true;
	cout<<"el boton del elevador le indica al elevador que se prepare para partir"<<endl;
	refElevador.preparaParaPartir(true);
}

//restablece boton
void BotonElevador::restableceBoton()
{
	presionado=false;
}
