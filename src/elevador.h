//elevador.h
//definicon de la clase Elevador.

#ifndef ELEVADOR_H
#define ELEVADOR_H

#include "botonElevador.h"
#include "puerta.h"
#include "campana.h"

class Piso; //declaracion forward
class Persona; //declaracion forward

class Elevador{
	public:
		Elevador(Piso &, Piso &);
		~Elevador();
		
		void llamaElevador(int); //solicitud de servicio al piso
		void preparaParaPartir(bool); //prepara para partir
		void tiempoProceso(int); //indica el tiempo actual al elevador
		void pasajeroEntra(Persona*const); //aborda un pasajero
		void pasajeroSale(); //sale un pasajero
	
		
		//objeto público accesible al codigo cliente
		//con acceso al objeto Elevador
		BotonElevador botonElevador;
		
	private:
		//funciones de utilidad
		void procesaPosibleLlegada();
		void procesaPosiblePartida();
		void llegaAlPiso(Piso &);
		void mover();
		
		//constantes estaticas que representan el tiempo requerido para viajar
		//entre los pisos y las direcciones del elevador
		static const int TIEMPO_VIAJE_ELEVADOR;
		static const int ARRIBA;
		static const int ABAJO;
		
		//datos miembro
		int tiempoActualRelojDelEdificio;   //tiempo actual
		bool enMovimiento;                  //estado del elevador
		int direccion;                      //direccion actual
		int pisoActual;                     //ubicacion actual
		int tiempoLlegada;                  //tiempo de llegada al piso
		bool piso1NecesitaServicio;         //bandera al servicio piso1
		bool piso2NecesitaServicio;         //bandera al servicio piso2
		
		Piso &refPiso1;                     //referencia al piso 1
		Piso &refPiso2;                     //referencia al piso 2
		Persona *ptrPasajero;               //apuntador para pasajero
		
		Puerta puerta;                      //objeto puerta
		Campana campana;                    //objeto campana
}; //fin de la clase Elevador

#endif
