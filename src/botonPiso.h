//botonPiso.h
//definicion de la clase piso
#ifndef BOTONPISO_H
#define BOTONPISO_H

class Elevador;

class BotonPiso{
	public:
		BotonPiso( int, Elevador &); //constructor
		~BotonPiso(); //destructor
		
		void presionaBoton();
		void restableceBoton();
	private:
		const int numeroPiso; //numero de piso del boton
		bool presionado; //restablece le boton
		
		//referencia al elevador utilizado para llamar al elevador al piso 
		Elevador &refElevador;
};
#endif
