/*Encontrar el número mayor en un arreglo de enteros*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> vi;
int valor;

int main(){

cout<<"Ingrese los elementos del arreglo y para finalizar ingrese 0"<<endl;

    while(true){
        cin>>valor;
        if(valor == 0) {
            break;
        }else{
            vi.push_back(valor);
        }
    }

     cout<<*max_element(vi.begin(),vi.end());

    return 0;
}
