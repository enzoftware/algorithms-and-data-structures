#include<bits/stdc++.h>
using namespace std;
string str;

int main(){
    getline(cin,str);
    for(int i = 0 ; i < str.size() ; i++){
        str[i] = toupper(str[i]);
    }
    cout<<str;
    return 0;
}
