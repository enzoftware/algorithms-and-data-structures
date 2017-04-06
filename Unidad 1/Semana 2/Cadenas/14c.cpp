#include <iostream>
#include <string>
using namespace std;

string str,str2,str3;

int main(){
    cout<<"Oracion inicial : ";
    getline(cin,str);
    cout<<"Palbra a encontrar  ";
    cin>>str2;
    cout<<"Palbra reemplazadora  ";
    cin>>str3;

    str.replace(str.find(str2),str2.length(),str3);
    cout<<str;
}
