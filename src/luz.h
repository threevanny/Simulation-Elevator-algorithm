//luz.h
//desinicion de la clase luz
#ifndef LUZ_H
#define LUZ_H

class Luz {
	
	public:
		Luz(int);
		~Luz();
		void enciende(); //enciende la luz
		void apaga(); //apaga la luz
	private:
		bool encendida; //veradero si esta encendida, falso si esta apagada
		const int numeroPiso; //numero del piso que contiene la luz
};
#endif
