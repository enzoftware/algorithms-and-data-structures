#include<bits/stdc++.h>
using namespace std;
string str;

int main(){
    getline(cin,str);

    for(int i = 0 ; i < str.size() ; i++){

        if(i==0){str[i]=toupper(str[i]); continue;}

        if(int(str[i])==32 && int(str[i+1]) > 96){
            str[i+1] = toupper(str[i+1]);
        }else if(int(str[i-1]) != 32 ){
            str[i] = tolower(str[i]);
        }


    }
    cout<<str;
    return 0;
}
