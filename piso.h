//piso.h
//definicion de la funcion Piso.

#ifndef PISO_H
#define PISO_H

#include "botonPiso.h"
#include "luz.h"

class Elevador;
class Persona;

class Piso{
	public:
		Piso(int, Elevador &);
		~Piso();
		bool estaOcupado() const; 	//devuelve verdadero si el piso esta ocupado
		int obtieneNumero() const;	//devuelve el numero de piso
		
		//pasa un manipulador a la nueva persona que entra al piso
		void llegaPersona(Persona * const);
		//notifica al piso que el elevador llego
		Persona *llegaElevador();
		//notifica al piso que el elevador parte
		void elevadorParte();
		//notifica al piso que la persona abandona el piso
		void personaAbordaElevador();
		
		//constantes estaticas que representan los numeros de piso
		static const int PISO1;
		static const int PISO2;
		
		//objeto publico BotonPiso accesible para
		//cualquier codigo cliente con acceso a un piso
		BotonPiso botonPiso;
		
	private:
		const int numeroPiso;	//los numeros de piso
		Elevador &refElevador;	//referencia al elevador
		Persona *ptrOcupante;	//apuntador a la persona en el piso
		Luz luz;				//objeto luz
};
#endif
