//reloj.h
//definicion de la clase reloj.

#ifndef RELOJ_H
#define RELOJ_H

class Reloj{
	private:
		int tiempo;   //tiempo del reloj
	public:
		Reloj();   //constructor
		~Reloj();   //destructor
		void marcaSeg();   //incrementa el reloj un segundo
		int obtieneTiempo()const;   //devuelve el tiempo actual del reloj
};
#endif
