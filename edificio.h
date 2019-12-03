//edificio.h

#ifndef EDIFICIO_H
#define EDIFICIO_H

#include "elevador.h"
#include "piso.h"
#include "reloj.h"
#include "bitacora.h"

class Edificio{
	private:
		Piso piso1;
		Piso piso2;
		Elevador elevador;
		Reloj reloj;
		Bitacora bitacora;
	public:
		Edificio();   //constructor
		~Edificio();   //destructor
		void ejecutaSimulador(int);   //controla la simulacion
};
#endif
