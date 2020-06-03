//bitacora.cpp
//definicones de las funciones miembro de la clase bitacora
#include <iostream>
using namespace std;

#include <new>
#include <cstdlib>
#include <ctime>

#include "bitacora.h"	//definicion de la clase Bitacora 
#include "piso.h"		//definicion de la clase Piso
#include "persona.h"	//definicion de la clase Persona

Bitacora::Bitacora(Piso &primerPiso, Piso &segundoPiso)		//constructor
	:tiempoActualDeReloj (0),
	refPiso1(primerPiso),
	refPiso2(segundoPiso)
	
{
	srand(time(0));   //semilla de generador de numeros aleatorios
	cout<<"bitacora construida"<<endl;
	
	//programa las primeras llegadas para los pisos 1 y 2
	programaTiempo(refPiso1);
	programaTiempo(refPiso2);
}
	
Bitacora::~Bitacora()	//destructor
{
	cout<<"bitacora destruida"<<endl;
}


//programa llegada al piso
void Bitacora::programaTiempo(const Piso &piso)
{
	int numeroPiso = piso.obtieneNumero();
	int tiempoLlegada = tiempoActualDeReloj + (5 + rand()%16);
	
	numeroPiso==Piso::PISO1 ?
		tiempoLlegadaPiso1=tiempoLlegada:
		tiempoLlegadaPiso2=tiempoLlegada;
		
	cout<<"(la bitacora programa a la siguiente persona para el piso "
		<<numeroPiso<<" en tiempo "<<tiempoLlegada<<")"<<endl;
}


//reprogrma la llegada al piso
void Bitacora::tiempoRetardo(const Piso &piso)
{
	int numeroPiso = piso.obtieneNumero();
	int tiempoLlegada = (numeroPiso==Piso::PISO1)?
		++tiempoLlegadaPiso1: ++tiempoLlegadaPiso2;
		
	cout<<"(la bitacora retarda a la siguiente persona para el piso "
	<<numeroPiso<<" hasta tiempo "<<tiempoLlegada<<")"<<endl;
}

//proporciona el tiempo a la bitacora
void Bitacora::tiempoProceso(int tiempo)
{
	tiempoActualDeReloj = tiempo;	//registra el tiempo

	//manipula la llegada al piso 1
	manipulaLlegadas(refPiso1, tiempoActualDeReloj);
	
	//manipula la llegada al piso 2
	manipulaLlegadas(refPiso2, tiempoActualDeReloj);
}

void Bitacora::creaNuevaPersona(Piso &piso)		//crea nueva persona y la coloca en el piso especifico
{
	int pisoDestino=
	piso.obtieneNumero()==Piso::PISO1 ?
		Piso::PISO2:Piso::PISO1;
		
		Persona *ptrNuevaPersona= new Persona(pisoDestino);	//crea una nueva persona
		cout<<"bitacora crea una persona "<<ptrNuevaPersona->obtieneID()<<endl;
		ptrNuevaPersona->entraAlPiso(piso);		//coloca a la persona en el piso apropiado
		programaTiempo(piso); 	//programa la siguiente llegada
}

//manipula las llegadas a un piso especifico
void Bitacora::manipulaLlegadas(Piso &piso, int tiempo)
{
	int numeroPiso = piso.obtieneNumero();
	
	int tiempoLlegada = (numeroPiso == Piso::PISO1) ?
	tiempoLlegadaPiso1 : tiempoLlegadaPiso2;
	
	if(tiempoLlegada == tiempo) {
		
		if(piso.estaOcupado() ); //si el piso el piso esta ocupado,
			tiempoRetardo(piso); //retarda la llegada
			}	                  
		else 
		{
		creaNuevaPersona(piso); //de lo contrario, crea una nueva persona//
		}
}

