//piso.cpp
//definicion de las funciones miembro para la clase Piso.
#include <iostream>
using namespace std;
#include "piso.h"
#include "persona.h"
#include "elevador.h"
#include "puerta.h"

//constantes estaticas que reprensentan los numeros de los pisos
const int Piso::PISO1=1;
const int Piso::PISO2=2;

//constructor
Piso::Piso(int numero, Elevador &manipulaElevador)	
	:botonPiso(numero, manipulaElevador),
	numeroPiso(numero),
	refElevador(manipulaElevador),
	ptrOcupante(0),
	luz(numeroPiso)
{
	cout<<"piso "<<numeroPiso<<" construido"<<endl;
}

//destructor
Piso::~Piso()
{
	delete ptrOcupante;
	cout<<"piso "<<numeroPiso<<" destruido"<<endl;
}

//determina si el piso esta ocupado
bool Piso::estaOcupado() const 
{
	return(ptrOcupante != 0);
}
//devuelve el numero de este piso
int Piso::obtieneNumero() const
{
	return numeroPiso;
}
//la persona llega la piso
void Piso::llegaPersona(Persona * const ptrPersona)
{
	ptrOcupante=ptrPersona;
}
//notifica al piso que el elevador llego
Persona *Piso::llegaElevador()
{
	cout<<"piso "<<numeroPiso<<" restablece su boton"<<endl;
	botonPiso.restableceBoton();
	luz.enciende();
	
	return ptrOcupante;
}
//indica al piso que el elevador parte
void Piso::elevadorParte()
{
	luz.apaga();
}
//notifica al piso que la persona se va
void Piso::personaAbordaElevador()
{
	ptrOcupante=0; //la persona ya no se encuentra en le piso
}
