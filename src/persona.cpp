//persona.cpp
//definicon de la funciones miembro para la clase Persona.
#include <iostream>
using namespace std;
#include "persona.h"
#include "piso.h"
#include "elevador.h"

//incializa el miembro estatico cuentaPersona
int Persona::cuentaPersonas=0;
//constructor
Persona::Persona( int pisoDest)
	:ID(++cuentaPersonas),
	pisoDestino(pisoDest)
{
	cout<<"persona "<<ID<<" construida"<<endl;
}
//destructor
Persona::~Persona()
{
	cout<<"(persona "<<ID<<" destructor invocado)"<<endl;
}
//devuelve el numeo ID de persona
int Persona::obtieneID() const
{
	return ID;
}
//la persona entra al piso
void Persona::entraAlPiso(Piso& piso)
{
	//notifica al piso que se viene la persona
	cout<<" la persona "<<ID<<" entra al piso "<<piso.obtieneNumero()<<endl;
	piso.llegaPersona(this);
	//presiona boton del piso
	cout<<"persona "<<ID<<" presiona el boton del piso en el piso "<<piso.obtieneNumero()<<endl;
	piso.botonPiso.presionaBoton();
}

//la persona entra en el elevador 
void Persona::entraElevador(Elevador &elevador, Piso &piso)
{
	piso.personaAbordaElevador(); //la persona abandona el piso
	
	elevador.pasajeroEntra(this); //la persona entra en el elevador
	
	//presiona el boton del elevador 
	cout<<"persona "<<ID<<"presiona el boton del elevador"<<endl;
	elevador.botonElevador.presionaBoton();
}

//la persona sale del elevador 
void Persona::saleElevador(
	const Piso &piso, Elevador &elevador) const
{
	cout<<"persona "<<ID<<" sale del elevador en el piso "<<piso.obtieneNumero()<<endl;
	elevador.pasajeroSale();
}
