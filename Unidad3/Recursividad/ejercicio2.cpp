/*
Implementar un método recursivo que permita imprimir en consola un triángulo invertido de altura N.
*/

#include <iostream>
#include <string.h>
using namespace std;

void piramide(int numcar , string entrada , string actual){
	if(actual.length() == numcar){
		cout<<actual<<endl;
	}else{
		cout<<actual<<endl;
		actual += entrada;
		piramide(numcar,entrada,actual);
	}
}

int main(){

    piramide(5,"*","*");

	return 0;
}
