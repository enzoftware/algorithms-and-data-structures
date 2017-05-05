#include "hash.cpp"
#include <ctime>
#include <sstream> 

Persona *arreglo[10000];
hash *tabla = new hash();
ListaSimple<Persona*> ls;

using namespace std;
ofstream lout("salida.js");

double iht = 0;
double ile = 0;
double iar = 0;

double eht = 0;
double ele = 0;
double ear = 0;

double bht = 0;
double ble = 0;
double bar = 0;

stringstream sht,sle,sar;
stringstream sht1,sle1,sar1;
stringstream sht2,sle2,sar2;
unsigned t0, t1;


int main(){

	srand(time(0));

/*		HASH TABLES */
	t0=clock();
	tabla->Insertar_Datos();
	t1 = clock();
	iht = (double(t1-t0)/CLOCKS_PER_SEC)*1000;

	t0=clock();
	tabla->Eliminar_Item("Tito Susana");
	t1 = clock();
	eht = (double(t1-t0)/CLOCKS_PER_SEC)*1000;

	t0=clock();
	tabla->Encontrar_Item("Eva Susana");
	t1 = clock();
	bht = (double(t1-t0)/CLOCKS_PER_SEC)*1000;

/*----------------------------*/


/*		ARREGLOS		*/
	t0=clock();
	Insertar_Datos_Arr(arreglo);
	t1 = clock();
	iar = (double(t1-t0)/CLOCKS_PER_SEC)*1000;

	t0=clock();
	Eliminar_Datos_Arr("Tito Susana",arreglo);
	t1 = clock();
	ear = (double(t1-t0)/CLOCKS_PER_SEC)*1000;

	t0=clock();
	Buscar_Datos_Arr("Eva Susana",arreglo);
	t1 = clock();
	bar = (double(t1-t0)/CLOCKS_PER_SEC)*1000;

/*----------------------------*/


/*		LISTAS ENLAZADAS		*/
	t0=clock();
	ls.Insertar_Datos_Inicio();
	t1 = clock();
	ile = (double(t1-t0)/CLOCKS_PER_SEC)*1000;

	t0=clock();
	ls.Eliminar_Datos("Tito Susana");
	t1 = clock();
	ele = (double(t1-t0)/CLOCKS_PER_SEC)*1000;

	t0=clock();
	ls.Recuperar_Dato("Eva Susana");
	t1 = clock();
	ble = (double(t1-t0)/CLOCKS_PER_SEC)*1000;

/*----------------------------*/



	tabla->ImprimirTabla();


	sht<<iht;
	sle<<ile;
	sar<<iar;

	sht1<<eht;
	sle1<<ele;
	sar1<<ear;

	sht2<<bht;
	sle2<<ble;
	sar2<<bar;

	cout <<"Para Hash Tables (insertar 10000 items) --> " << iht <<" milisegundos"<<endl;
	cout <<"Para Listas Enlazadas (insertar 10000 items) --> " << ile <<" milisegundos"<<endl;
	cout <<"Para Arreglos (insertar 10000 items) --> " << iar <<" milisegundos"<<endl;

	cout <<"Para Hash Tables (eliminar 1 item) --> " << eht <<" milisegundos"<<endl;
	cout <<"Para Listas Enlazadas (eliminar 1 item) --> " << ele <<" milisegundos"<<endl;
	cout <<"Para Arreglos (eliminar 1 item) --> " << ear <<" milisegundos"<<endl;

	cout <<"Para Hash Tables (buscar 1 item) --> " << bht <<" milisegundos"<<endl;
	cout <<"Para Listas Enlazadas (buscar 1 item) --> " << ble <<" milisegundos"<<endl;
	cout <<"Para Arreglos (buscar 1 item) --> " << bar <<" milisegundos"<<endl;

	string x = "var ht = '"+sht.str()+"';";
	string x1 = "var le = '"+sle.str()+"';";
	string x2 = "var ar = '"+sar.str()+"';";

	string y = "var ht1 = '"+sht1.str()+"';";
	string y1 = "var le1 = '"+sle1.str()+"';";
	string y2 = "var ar1 = '"+sar1.str()+"';";


	string z = "var ht2 = '"+sht2.str()+"';";
	string z1 = "var le2 = '"+sle2.str()+"';";
	string z2 = "var ar2 = '"+sar2.str()+"';";

	lout<<x<<endl;
	lout<<x1<<endl;
	lout<<x2<<endl;


	lout<<y<<endl;
	lout<<y1<<endl;
	lout<<y2<<endl;


	lout<<z<<endl;
	lout<<z1<<endl;
	lout<<z2<<endl;
	
	system("start stats.html");
	return 0;
}

/*
#include <ctime> 
 


*/
