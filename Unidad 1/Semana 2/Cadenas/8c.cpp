#include <bits/stdc++.h>
using namespace std;
	
	
	string convertir(int d , int m , int an){
		string f; 
		f += to_string(d);
		f+=" de ";
		string ms;
		switch(m){
			case 1 : ms = "enero";
			break;
			case 2 : ms = "febrero";
			break;
			case 3 : ms = "marzo";
			break;
			case 4 : ms = "abril";
			break;
			case 5 : ms = "mayo";
			break;
			case 6 : ms = "junio";
			break;
			case 7 : ms = "julio";
			break;
			case 8 : ms = "agosto";
			break;
			case 9 : ms = "septiembre";
			break;
			case 10 : ms = "octubre";
			break;
			case 11 : ms = "noviembre";
			break;
			case 12 : ms = "diciembre";
			break;
		}
		
		f+=ms;
		f+=" del ";
		f+=to_string(an);
		
		return f;
		
	}

int main(){
	
	cout<<convertir(12,12,2012);
	return 0;

}
