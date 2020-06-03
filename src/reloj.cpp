//reloj.cpp

#include <iostream>
using namespace std;

#include "reloj.h"

Reloj::Reloj()   //constructor
	:tiempo(0)   //inicializa el tiempo en 0
	{
		cout<<"reloj construido"<<endl;
	}
	
	
Reloj::~Reloj()    //destructor  
{
	cout<<"reloj destruido"<<endl;
}

void Reloj::marcaSeg()    //incrementa el tiempo en 1
{
	tiempo++;
}



int Reloj::obtieneTiempo() const  //retorna el tiempo actual
{
	return tiempo;
}
