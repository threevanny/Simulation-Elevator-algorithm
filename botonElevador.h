//botonElevador.h
//definicion de la clase BotonElevador.
#ifndef BOTONELEVADOR_H
#define BOTONELEVADOR_H

class Elevador; //declaracion forward
class BotonElevador{
	public:
		BotonElevador(Elevador &); //constructor
		~BotonElevador();   //destructor
		
		void presionaBoton(); //presiona boton
		void restableceBoton(); //restablece boton
	private:
		bool presionado; //estado del boton
		Elevador &refElevador; //referencia al elevador que contiene este boton
};
#endif

