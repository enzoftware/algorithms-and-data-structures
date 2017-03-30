//Eliminar el elemento en una posición de un arreglo

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int>vec;
int valor,pos;

void imprimir(int i){
    cout<<i<<" ";
}

int main(){
    cout<<"Ingrese valores al arreglo y para detenerse ingrese 0"<<endl;
    while(true){
        cin>>valor;
        if(valor == 0)break;
        else vec.push_back(valor);
    }

    cout<<"Ingresa la POSICION del valor que deseas eliminar"<<endl;
    cin>>pos;
    vec.erase(vec.begin()+pos);
    for_each(vec.begin(),vec.end(),imprimir);

    return 0;
}
