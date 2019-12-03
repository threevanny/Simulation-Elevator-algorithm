/*definiciones de las funciones de la clase libro*/

int libro::contador=0;	//contador inicializado en cero

libro::libro(string titulo, string autor){
	this->titulo=titulo;
	this->titulo=titulo;
	id=++contador; 		//el contador aumenta en uno por cada objeto creado y le asigna el valor a ID
}
libro::~libro(){
	cout<<"El libro ha sido destruido"<<endl;
}

void libro::mostrar(){
		cout<<"libro "<<id<<": \t"<<titulo<<endl;
		cout<<"\t\t"<<autor<<endl<<endl;
}
