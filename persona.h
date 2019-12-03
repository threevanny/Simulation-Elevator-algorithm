//persona.h
//defincion de la clase Persona.
#ifndef PERSONA_H
#define PERSONA_H
class Piso;
class Elevador;

class Persona{
	public:
		Persona(int);
		~Persona();
		int obtieneID() const; //devuelve ID de la persona
		void entraAlPiso(Piso &);
		void entraElevador(Elevador &, Piso &);
		void saleElevador(const Piso &, Elevador &) const;
	private:
		static int cuentaPersonas; //numero total de gente
		const int ID;              //numero ID unico de la persona
		const int pisoDestino;     //numero de piso de destino		
};

#endif
