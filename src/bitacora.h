//bitacora.h

#ifndef BITACORA_H
#define BITACORA_H

class Piso; //declaración forward

class Bitacora{
	private:
		void programaTiempo(const Piso & );		//tiempo de la bitacora de llegada a piso
		void tiempoRetardo(const Piso & );	//tiempo de retardo de llegada piso
		void creaNuevaPersona(Piso & );			//crea nueva persona, la coloca en el piso
		void manipulaLlegadas(Piso &, int );	//manipulador de llegada de la persona a un piso
		int tiempoActualDeReloj;
		
		Piso &refPiso1;
		Piso &refPiso2;
		
		int tiempoLlegadaPiso1;
		int tiempoLlegadaPiso2;
		
	public:
		Bitacora(Piso &, Piso &); //constructor
		~Bitacora();             //destructor
		void tiempoProceso(int); //establece el tiempo de la bitacora
};
#endif
