// edifico.cpp

#include <iostream>
using namespace std;

#include "edificio.h"

//constructor 
Edificio::Edificio()
	:piso1(Piso::PISO1, elevador),
	piso2(Piso::PISO2, elevador),
	elevador(piso1, piso2),
	bitacora(piso1, piso2)
	
	{
		cout<<"edificio construido"<<endl;
	} //fin de constructor Edificio
	
	//destructor
	
	Edificio::~Edificio()
	{
		cout<<"edificio destruido"<<endl;
	} //fin del destructor ~Edificio
	
	
	void Edificio::ejecutaSimulador(int tiempoTotal)
	{
		int tiempoActual=0;
		
		while(tiempoActual<tiempoTotal){
			reloj.marcaSeg();					//incrementa el tiempo
			tiempoActual = reloj.obtieneTiempo();    //obtiene tiempo nuevo
			cout<<"TIEMPO: "<<tiempoActual<<endl;
			
			bitacora.tiempoProceso(tiempoActual);  //procesa la llegada de personas apra tiempoActual
			cin.get();     //espera a que se digite una tecla, de manera que el usuario vea la salida
		}
	}
