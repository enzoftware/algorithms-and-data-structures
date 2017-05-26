/*Ordenar un arreglo de números enteros*/

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> vi;
int valor;

void printArreglo(int i){
    cout<<i<<" ";
}

int main(){
    cout<<"Ingrese los valores del arreglo y para detenerse ingrese 0"<<endl;
    while(true){
        cin>>valor;
        if(valor == 0)break;
        else vi.push_back(valor);
    }

    sort(vi.begin(),vi.end());
    cout<<"El arreglo ordenado es : "<<endl;
    for_each(vi.begin(),vi.end(),printArreglo);

    return 0;
}
