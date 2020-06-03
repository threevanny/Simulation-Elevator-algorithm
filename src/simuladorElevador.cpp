//simulador del elevador - simuladorElevador.cpp

#include <iostream>
using namespace std;

#include "edificio.h"

int main()
{
	int duracion; //longitud de la simulacion en segundos
	cout<<"intorduzca tiempo de ejecucion: ";
	cin>>duracion;
	cin.ignore(); //ingnora el caracter devuelto
	
	Edificio edificio; //crea el edificio
	
	cout<<endl<<"*** COMIENZA LA SIMULACION DEL ELEVADOR***"<<endl<<endl;
	
	edificio.ejecutaSimulador(duracion);
	cout<<"*** TERMINA LA SIMULACION DEL ELEVADOR***"<<endl;
	
	return 0;
}
