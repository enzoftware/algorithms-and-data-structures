/* Encontrar el elemento mayor en un arreglo. */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
double maxi;
double v;

vector<double> vd;

template<typename T>
T hallarMaximo(T i){
    maxi = (i > maxi ? i : maxi);
}

int main(){

    cout<<"Ingrese los elementos del vector y para finalizar ingrese 0"<<endl;

    while(true){
        cin>>v;
        if(v == 0) {
            break;
        }else{
            vd.push_back(v);
        }
    }
    maxi= vd[0];
    for_each(vd.begin(),vd.end(),hallarMaximo<double>);

    cout<<maxi;
    return 0;
}
