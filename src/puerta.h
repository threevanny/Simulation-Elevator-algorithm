//puerta.h
//definicion de la clase puerta.

#ifndef PUERTA_H
#define PUERTA_H
class Persona;	//declaracion forward
class Piso;		//declaracion forward
class Elevador;	//declaracion forward

class Puerta{
	public:
		Puerta();
		~Puerta();
		void abrePuerta(Persona * const, Persona * const, Piso &, Elevador & ); //abre la puerta
		void cierraPuerta(const Piso &);
	private:
		bool abierta; //abierto o cerrado
};

#endif
