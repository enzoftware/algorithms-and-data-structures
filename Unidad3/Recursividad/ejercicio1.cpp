/*
Implementar un método recursivo que permita imprimir en consola un triángulo invertido de altura N.
*/

#include <iostream>
using namespace std;

void piramide(int i , int j){
	int auxi = 0 ; int auxj =0;
	if(i>0){
		cout<<"*";
		piramide(--i,j);

	}else{
		if(j>0){
			i = j;
			cout<<endl;
			piramide(--i,--j);
		}
	}
}

int main(){

	piramide(5,5);
	return 0; 

}