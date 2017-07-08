/*Calcular el factorial de N*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N;

int fact(int n){

        if(n==1) return 1;
        return(n*fact(n-1));

}

int main(){
    cout<<"Ingresa el valor de N y se hallara el factorial"<<endl;
    cin>>N;
    cout<<fact(N)<<endl;
    return 0;
}
