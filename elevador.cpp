//elevador.cpp
//definicion de las funciones miembro para la clase Elevador
#include <iostream>
using namespace std;
#include "elevador.h"
#include "persona.h"
#include "piso.h"

//constantes que representan ek tiempo que se requiere para viajar 
//entre pisos y direcciones del elevador

const int Elevador::TIEMPO_VIAJE_ELEVADOR=5;
const int Elevador::ARRIBA=0;
const int Elevador::ABAJO=1;

//constructor
Elevador::Elevador(Piso &primerPiso, Piso &segundoPiso)
	:botonElevador(*this),
	tiempoActualRelojDelEdificio(0), 
	enMovimiento(false),
	direccion(ARRIBA),
	pisoActual(Piso::PISO1),
	tiempoLlegada(0),
	piso1NecesitaServicio(false),
	piso2NecesitaServicio(false),
	refPiso1(primerPiso),
	refPiso2(segundoPiso),
	ptrPasajero(0)
	{
		cout<<"elevador construido"<<endl;
	} //fin del constructor Elevador
	
//destructor
Elevador::~Elevador()
{
	delete ptrPasajero;
	cout<<"elevador destruido"<<endl;
} //fin del destructor


//da tiempo al elevador 
void Elevador::tiempoProceso(int tiempo)
{
	tiempoActualRelojDelEdificio=tiempo;
	
	if(enMovimiento)					//elevador en movimiento
		procesaPosibleLlegada();
	
	else
		procesaPosiblePartida();
		
	if(!enMovimiento)
		cout<<"el elevador descansa en el piso "<<pisoActual<<endl;	
}

//cuando el elevador se encuentra en movimiento, determina si se debe detener
void Elevador::procesaPosibleLlegada()
{
	if (tiempoActualRelojDelEdificio == tiempoLlegada){
		pisoActual =                       //actualiza el tiempo actual
		(pisoActual == Piso::PISO1 ?
		Piso::PISO2 : Piso::PISO1);
		
		direccion =                        //actualiza direccion
		(pisoActual == Piso::PISO1 ? ARRIBA : ABAJO);
		
		cout<<"el elevador llega al piso "<<pisoActual<<endl;
		
		//procesa la llegada a pisoActual
		llegaAlPiso(pisoActual == Piso::PISO1 ? refPiso1 : refPiso2);
		
		return;
	}	
	
	//el elevador sigue en movimiento
	cout<<"elevador en movimiento"<<(direccion == ARRIBA ? "arriba" : "abajo")<<endl;
	
}	//fin de la funcion procesaPosibleLlegada



void Elevador::procesaPosiblePartida() //determina si el elevador debe moverse
{
	bool pisoActualNecesitaServicio=pisoActual == Piso::PISO1 ? //¿este piso necesita servicio?
		piso1NecesitaServicio : piso2NecesitaServicio;
		
	bool otroPisoNecesitaServicio=pisoActual == Piso::PISO1 ? //¿el otro piso necesita servicio?
		piso2NecesitaServicio : piso1NecesitaServicio;
		
	//servicio en este piso(si es necesario)
	if (pisoActualNecesitaServicio){
		llegaAlPiso(pisoActual==Piso::PISO1 ?
			refPiso1 : refPiso2);
			
		return;
	}
		
		//servicio en el otro piso(si es necesario)
		if (otroPisoNecesitaServicio)
			preparaParaPartir(true);
}


void Elevador::llegaAlPiso(Piso& llegaAlPiso)   //llega a un piso en particular
{
	enMovimiento = false;                       //restablece el estado
	
	cout<<"el elevador restablece su boton"<<endl;
	botonElevador.restableceBoton();
	
	campana.suenaCampana();
	
	//notifica al piso que el elevador llego
	Persona *ptrPisoPersona = llegaAlPiso.llegaElevador();
	
	puerta.abrePuerta(
	ptrPasajero, ptrPisoPersona, llegaAlPiso, *this);
	
	//¿este piso necesita servicio?
	bool pisoActualNecesitaServicio = 
		pisoActual == Piso::PISO1 ?
			piso1NecesitaServicio : piso2NecesitaServicio;
	//¿el otro piso necesita servicio?
	bool otroPisoNecesitaServicio = 
		pisoActual == Piso::PISO1 ?
			piso2NecesitaServicio : piso2NecesitaServicio;
	//si este piso no necesita servicio se prepara para partir hacia el otro piso
	if (!pisoActualNecesitaServicio)
		preparaParaPartir(otroPisoNecesitaServicio);
	else  //de lo contrario, restablece la bandera de servicio
		pisoActual == Piso::PISO1 ?
			piso1NecesitaServicio = false: piso2NecesitaServicio = false;			
}

//solicita servcio del elevador
void Elevador::llamaElevador(int piso)
{
	//establece la bandera del servcio apropiada
	piso==Piso::PISO1 ?
		piso1NecesitaServicio = true : piso2NecesitaServicio = true;
}
//acepta un pasajero
void Elevador::pasajeroEntra(Persona * const ptrPersona)
{
	//el pasajero aborda
	ptrPasajero = ptrPersona;
	
	cout<<"persona "<<ptrPasajero->obtieneID()<<" entra el elevador desde el piso "<<pisoActual<<endl;
}

//notifica la elevador que el pasajero va a salir 
void Elevador::pasajeroSale()
{
	ptrPasajero = 0;
}
//se prepara para abandonar el piso
void Elevador::preparaParaPartir(bool parte)
{
	//obtiene la referencia al piso actual
	Piso &estePiso = 
	pisoActual == Piso::PISO1 ? refPiso1:refPiso2;
	
	//notifica al piso que el elevador puede partir
	estePiso.elevadorParte();
	
	puerta.cierraPuerta(estePiso);
	
	if (parte)   //parte, si es necesario
		mover();
}
//va a otro piso
void Elevador::mover()
{
	enMovimiento=true; //cambiar estado
	
	//programa tiempo de llegada
	tiempoLlegada=tiempoActualRelojDelEdificio+
	TIEMPO_VIAJE_ELEVADOR;
	
	cout<<"el elevador comienza a moverse "<< (direccion == ABAJO ? "abajo" : "arriba")
		<<"al piso"<<(direccion==ABAJO ? "1" : "2")<<"(llega a tiempo "<<tiempoLlegada<<")"<<endl;
		
}

