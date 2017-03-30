/*Buscar un número en un arreglo*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>vi;
int valor,val;

int main(){

    cout<<"Llenar el arreglo y detenerse con el 0"<<endl;
    while(true){
        cin>>valor;
        if(valor == 0)break;
        else vi.push_back(valor);
    }

    cout<<"Ingresa el valor que deseas encontrar : ";
    cin>>val;

    bool encontro = binary_search(vi.begin(),vi.end(),val);
    (encontro == true ? cout<<"Si esta el elemento" : cout<<"El elemento no fue encontrado");
    return 0;
}
