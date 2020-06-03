//puerta.cpp
//definicion de las funciones mienbro de la clase puerta.
#include <iostream>
using namespace std;
#include "puerta.h"
#include "persona.h"
#include "piso.h"
#include "elevador.h"

//constructor
Puerta::Puerta()
	:abierta(false) //inicializa abierto en falso
{
	cout<<"puerta construida"<<endl;
}

//destructor
Puerta::~Puerta()
{
	cout<<"puerta destruida"<<endl;
}

//abre la puerta 
void Puerta::abrePuerta(Persona * const ptrPasajero,
Persona * const ptrSiguientePasajero, Piso &pisoActual,
Elevador &elevador)
{
	if(!abierta){   //si la puerta no esta abierta abre la puerta
		abierta=true;
		cout<<"el elevador abre su puerta en el piso "
		<<pisoActual.obtieneNumero()<<endl;
		
		//si el pasajero esta en el elevador le indica que salga
		if(ptrPasajero !=0){
			ptrPasajero->saleElevador (pisoActual, elevador);
			delete ptrPasajero; //el pasajero abandona el elevador
		}
		//si el pasajero esta esperando el elevador le indica que entre
		if(ptrSiguientePasajero != 0)
		ptrSiguientePasajero->entraElevador(
		elevador, pisoActual);
	}
}

//cierra la puerta 
void Puerta::cierraPuerta(const Piso &pisoActual)
{
	if(abierta){   //si la puerta esta abierta la cierra
	abierta=false;
	cout<<"el elevador cierra sus puertas en el piso "
	<<pisoActual.obtieneNumero()<<endl;
	}
}
