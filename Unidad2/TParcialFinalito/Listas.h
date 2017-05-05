#include <iostream>
#include <fstream>
#include <string.h>
#include <ctime>
#include <vector>
#include <windows.h>

using namespace std;

long int rndbtwn(long int a, long int b) 
{
	return rand() % (b - a + 1) + a;
}

class Persona{

	string nombres;
	string apellidos;
	long int dni;

public:

	Persona(string nombres="vacio", string apellidos="vacio", long int dni=0):nombres(nombres),apellidos(apellidos),dni(dni){}
	string GetNombres(){return nombres;}
	string GetApellidos(){return apellidos;}
	long int GetDni(){return dni;}
	void Imprimir(){cout<<nombres<<" "<<apellidos<<" "<<dni;}
};

void Cargar_Datos(vector<string>& nombres, vector<string>& apellidos)
{
	string dato;
	ifstream fn("Nombres.txt");
	while(getline(fn,dato)){nombres.push_back(dato);}
	fn.close();
	ifstream fa("Apellidos.txt");
	while(getline(fa,dato)){apellidos.push_back(dato);}
	fa.close();
}

void Vaciar_Datos(vector<string>& nombres, vector<string>& apellidos)
{
	nombres.clear();
	apellidos.clear();
}

//Arreglo

void Insertar_Datos_Arr(Persona *Arreglo[10000])
{
	vector<string> nombres;
  	vector<string> apellidos;
  	long int dni;
	string nom,ape;

  	Cargar_Datos(nombres,apellidos);

  	for(int i=0;i<10000;++i)
  	{

  		Persona* oPersona;
  		nom = nombres[rndbtwn(0,nombres.size()-1)] + " " + nombres[rndbtwn(0,nombres.size()-1)];
  		ape = apellidos[rndbtwn(0,apellidos.size()-1)] + " " + apellidos[rndbtwn(0,apellidos.size()-1)];
  		dni = rndbtwn(10000000,99999999);
  		oPersona=new Persona(nom,ape,dni);
  		Arreglo[i]=oPersona;
  		delete oPersona;
  	}

	Vaciar_Datos(nombres,apellidos);
}

Persona* Buscar_Datos_Arr(string dato, Persona *Arreglo[10000])
{
	for(int i=0;i<10000;++i)
	{
		if(Arreglo[i]->GetNombres() == dato)
		{
			return Arreglo[i];
		}
	}

	return NULL;
}

bool Eliminar_Datos_Arr(string nombre, Persona *Arreglo[10000])
{
	Persona *Arr_aux[10000-1];
	Persona *aux;
	bool eliminado=false;;

	if(Buscar_Datos_Arr(nombre,Arreglo)==NULL)
	{
		return false;
	}
	else{

		for(int i=0;i<10000;++i)
		{
			if(Arreglo[i]->GetNombres()==nombre && eliminado==false)
			{
				aux=Arreglo[i];
				delete aux;
				eliminado=true;
			}
			else if(eliminado==false)
			{
				Arr_aux[i]=Arreglo[i];
			}
			else
			{
				Arr_aux[i-1]=Arreglo[i];
			}
		}

	}
	return true;
}

//Lista simple enlazada

template<class T>

class ListaSimple{
	struct Nodo
	{
		Nodo*next;
		Persona *elemento;
		Nodo(Persona *elemento = NULL , Nodo*next = NULL):elemento(elemento),next(next){}
	};
	int n;
	Nodo *inicio;

public:

	class Iterador{

		Nodo*aux;

	public:

		Iterador(Nodo *aux = NULL): aux(aux){}
		bool operator !=(Iterador it){ return aux != it.aux; }
		T operator *(){ return aux->elemento; }
		void operator ++(int dummy){	aux = aux->next; }
	};

	Iterador Primero()
	{
		return inicio;
	}

	Iterador Ultimo()
	{
		return NULL;
	}

public:

	ListaSimple():n(0),inicio(NULL){}
	~ListaSimple(){
		while(inicio != NULL){
			Nodo *aux = inicio;
			inicio = inicio->next;
			delete aux;
		}
	}

	void Insertar_Datos_Inicio()
	{ 	
		vector<string> nombres;
  		vector<string> apellidos;
  		long int dni;
		string nom,ape;
	
  		Cargar_Datos(nombres,apellidos);

  		for(int i=0;i<10000;++i)
  		{
  			Persona* data;
  			nom = nombres[rndbtwn(0,nombres.size()-1)] + " " + nombres[rndbtwn(0,nombres.size()-1)];
  			ape = apellidos[rndbtwn(0,apellidos.size()-1)] + " " + apellidos[rndbtwn(0,apellidos.size()-1)];
  			dni = rndbtwn(10000000,99999999);
  			data=new Persona(nom,ape,dni);
  			Nodo*nuevo = new Nodo(data,inicio);
  			inicio = nuevo;
			++n;
  			delete data,nuevo;
  		}

		Vaciar_Datos(nombres,apellidos);
	}

	void Insertar_Datos_Final()
	{
		vector<string> nombres;
  		vector<string> apellidos;
  		long int dni;
		string nom,ape;
	
  		Cargar_Datos(nombres,apellidos);

  		for(int i=0;i<10000;++i)
  		{
  			Persona* data;
  			nom = nombres[rndbtwn(0,nombres.size()-1)] + " " + nombres[rndbtwn(0,nombres.size()-1)];
  			ape = apellidos[rndbtwn(0,apellidos.size()-1)] + " " + apellidos[rndbtwn(0,apellidos.size()-1)];
  			dni = rndbtwn(10000000,99999999);
  			data=new Persona(nom,ape,dni);
  			
  			if(n==0){
  				Nodo*nuevo = new Nodo(data,inicio);
  				inicio = nuevo;
				++n;
				delete nuevo;
  			}
  			else{

  				Nodo *aux = inicio; int c = 1;
				while(c++ < n)
				{
					aux = aux->next;
				}
				Nodo *nuevo = new Nodo(data,aux->next);
				aux->next = nuevo;
				++n;
				delete nuevo;
  			}
  			delete data;
  		}

		Vaciar_Datos(nombres,apellidos);
	}

	bool Eliminar_Inicio()
	{
		if(n == 0) return false;
		Nodo *aux = inicio;
		inicio = inicio->next;
		delete aux;
		--n;
		return true;
	}

	bool Eliminar_Posicion(int pos)
	{
		if(pos < 0 || pos > n ) return false;
		if(pos == 0) { Eliminar_Inicio(); return true; }
		int c = 1; Nodo*aux = inicio;
		while(c++ < pos)
		{
			aux = aux->next;
		}
		Nodo *aux2 = aux->next;
		aux->next = aux2->next;
		delete aux2;
		--n;
		return true;
	}

	bool Eliminar_Final(){
		Eliminar_Posicion(n-1);
	}

	bool Eliminar_Datos(string data){

		int cont=-1,pos=-1;
		Nodo*aux = inicio;

		while(aux != NULL){

			if(aux->elemento->GetNombres() == data){
				pos=cont;
			} 
			else{
				aux = aux->next;
				cont++;
			}
		}

		if(pos != -1){
			Eliminar_Posicion(pos);
			return true;
		}
		else{
			return false;
		}

	}

	Persona* Recuperar_Dato(string data){

		Nodo*aux = inicio;
		while(aux != NULL){

			if(aux->elemento->GetNombres() == data){

				return aux->elemento;
			} 
			else{
				aux = aux->next;
			} 
		}

		return NULL;
	}

};

