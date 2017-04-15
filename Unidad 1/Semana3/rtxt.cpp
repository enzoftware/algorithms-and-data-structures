#include <bits/stdc++.h>

using namespace std;

int main()
{
	ifstream datos("Datos.upc"); 
	
	string str;
	
	string str1,str2;
	int a,b,c;
	float x;
	
	getline(datos,str1); //para leer una sola palabra
	getline(datos,str2); //leer linea hasta salto de linea
	datos >> a >> b >> c; //se puede leer varias variables a la vez
	datos >> x; //tipos son cenvertidos automaticamente
	
	cout<<str1<<endl;
	cout<<str2<<endl;
	cout<< a <<" , "<< b << " , " << c <<endl;
	cout<< x << endl;
		
	return 0;	
}
