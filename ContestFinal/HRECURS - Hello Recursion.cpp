#include <iostream>
using namespace std;

int sumarecursiva(int arr[] , int s , int pos , int cont){
  if(s == pos) return cont;
  else{
    cont+=arr[pos];
    sumarecursiva(arr,s,pos+1,cont);
  }
}


int main(){
  int casos;
  int numcasos = 0;
  int contador = 0;
  cin>>casos;
  while(casos--){
    int tam,posicion = 0;
    cin>>tam;
    int arreglo[tam];
    for(int i = 0 ; i<tam ; i++) {
      cin>>arreglo[i];
    }
    numcasos++;
    cout<<"Case "<<numcasos<<": "<<sumarecursiva(arreglo,tam,posicion,contador)<<endl;
  }

  return 0;
}
