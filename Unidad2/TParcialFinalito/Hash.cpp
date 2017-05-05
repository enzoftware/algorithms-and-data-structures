#include "hash.h"
ofstream fout("output.txt");

hash::hash(){

	for (int i=0;i<tableSize;i++){
		HashTable[i]= new item;//Se crea un nuevo item
		HashTable[i]->oPersona=new Persona();//Se instancia vacio
		HashTable[i]->next=NULL;//El siguiente es NULL
	}
}

void hash::Insertar_Datos(){
		
	vector<string> nombres;
  	vector<string> apellidos;
  	long int dni;
	string nom,ape;
	Persona* oPersona;
  	Cargar_Datos(nombres,apellidos);

  	for(int i=0;i<10000;++i)
  	{

  		
  		nom = nombres[rndbtwn(0,nombres.size()-1)] + " " + nombres[rndbtwn(0,nombres.size()-1)];
  		ape = apellidos[rndbtwn(0,apellidos.size()-1)] + " " + apellidos[rndbtwn(0,apellidos.size()-1)];
  		dni = rndbtwn(10000000,99999999);
  		oPersona=new Persona(nom,ape,dni);
  		
  		//Insercción hash

  		int index= Hash(oPersona->GetNombres());//En el index "X" se pone el HASH en string

  		if(HashTable[index]->oPersona->GetNombres()=="vacio"){//Si es vacio se agrega el item
			
			HashTable[index]->oPersona=oPersona;
		}
		else{

			item* Puntero=HashTable[index];//El comienzo
			item* n= new item;
			n->oPersona= oPersona;
			n->next=Puntero->next;
			Puntero->next = n;
			/*while(Puntero->next!=NULL){
				Puntero=Puntero->next;		
			}
			Puntero->next=n;*/
		}

  		//Fin insercción hash

  		//delete oPersona;
  	}

	Vaciar_Datos(nombres,apellidos);
}


int hash::Numero_Items_Index(int index){

	int contador=0;
	if(HashTable[index]->oPersona->GetNombres()=="vacio"){
		return contador;
	}
	else{
		contador++;
		item *Puntero= HashTable[index];
		while(Puntero->next!=NULL){
			contador++;
			Puntero=Puntero->next;
		}
	}
	return contador;
}

void hash::ImprimirTabla(){
	int number;
	for(int i=0;i<tableSize;i++){
		
		number=Numero_Items_Index(i);
		fout<<"---------------------------------\n";
		fout<<"index = "<<i<<endl;
		fout<<HashTable[i]->oPersona->GetNombres()<<endl;
		fout<<"La cantidad de items son: "<<number<<endl;
		fout<<"---------------------------------\n";
	}
}

void hash::Imprimir_Items_Index(int index){

	item* Puntero= HashTable[index];
	
	if(Puntero->oPersona->GetNombres()=="vacio"){
		cout<<"Index: "<<index<<" es vacio";
	}
	else{
		cout<<"Index: "<<index <<" contiene los siguientes items"<<endl;
		while(Puntero->oPersona!=NULL){
			cout<<"--------------------------\n";
			cout<<Puntero->oPersona->GetNombres()<<endl;
			cout<<Puntero->oPersona->GetApellidos()<<endl;
			cout<<Puntero->oPersona->GetDni()<<endl;
			cout<<"--------------------------\n";
			Puntero=Puntero->next;
		}
	}
}

Persona* hash::Encontrar_Item(string nombre){
	
	int index= Hash(nombre);
	
	item* Puntero = HashTable[index];
	while(Puntero!=NULL){

		if(Puntero->oPersona->GetNombres()==nombre){
			return Puntero->oPersona;
		}
		Puntero=Puntero->next;
	}	
	return NULL;
}

bool hash::Eliminar_Item(string nombre){
	int index= Hash(nombre);//Se eliminará por nombre, la funcion hash lo convierte en entero y se guarda en el index
	item* BorrarPtr;
	item* P1;
	item* P2;
	
	//Caso 0 = caja está vacia
	//Caso 1 = cuando solo tiene 1 item la caja y tiene el mismo nombre
	//Caso 2 = cuando se encuentra el ITEM pero tiene muchos items en la caja(Caja es donde se almacena) o Contenedor
	//Caso 3 = La caja contiene elementos pero el primer elemento no es coincidente
	//Caso 3.1= no se encuentran
	//Caso 3.2= se emparejan
	
	if(HashTable[index]->oPersona->GetNombres()=="vacio")//Caso 0
	 {
	 	return false;
	 }
	 else if(HashTable[index]->oPersona->GetNombres()==nombre && HashTable[index]->next==NULL){//Caso 1
		Persona* aux=HashTable[index]->oPersona;
		delete aux;
		HashTable[index]->oPersona=NULL;
		return true;
	 }
	 else if(HashTable[index]->oPersona->GetNombres()==nombre){//Caso 2

	 	BorrarPtr=HashTable[index];
	 	HashTable[index]=HashTable[index]->next;
	 	delete BorrarPtr;
	 	return true;
	 }
	 else{//Caso 3
	 	P1= HashTable[index]->next;
	 	P2= HashTable[index];
	 	while(P1!=NULL && P1->oPersona->GetNombres()!=nombre){
	 		P2=P1;
	 		P1=P1->next;
		 }
		 //Caso 3.1
		 if(P1==NULL){
		 	return false;
		 }
		 //Caso 3.2
		else{
			BorrarPtr=P1;
			P1=P1->next;
			P2->next=P1;
			delete BorrarPtr;
			return true;
		}	
	 }
}

int hash::Hash(string key){
	int hash=0;
	int index;
	
	for(int i=0;i<key.length();i++)
	{
		hash+=(int)key[i]*13;//Cada caracter tiene un key diferente y se almacena en el HASH
		//cout<<"Hash = "<<hash<<endl;// For para obtener el HASH de cada key
	}	
	
	index = hash%tableSize;//Como obtener el index de cada hash
	return index;
}
