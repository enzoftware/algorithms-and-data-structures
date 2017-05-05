#include "Listas.h"

class hash{

	private:

	static const int tableSize=10000;//Valor positivo del tamaño del HASH
		
	struct item{ //Items del Hash que se ingresa
		
		Persona* oPersona ;
		item* next;//Para el siguiente item
	};
		
	item* HashTable[tableSize];
		
	public:

		hash();//Constructor
		~hash();
		int Hash(string key);//Funcion para darle el key
		void Insertar_Datos();//Funcion Agregar
		int Numero_Items_Index(int index);//Funcion para retornar el Numero de items
		void ImprimirTabla();//Imprimir la informacion que contiene los primeros items
		void Imprimir_Items_Index(int index);//Imprimir los items de los index que se repiten
		Persona* Encontrar_Item(string nombre); // Funcion para encontrar
		bool Eliminar_Item(string nombre);// Funcion para eliminar
};

