
#include <bits/stdc++.h>

using namespace std;

int contarString(string str , char x){

        for(int i = 0 ; i< str.size() ; i++){
            if(str[i]==x) return i;
            else{
                return -1;
            }
        }
}

int main(){
	
	cout<<contarString("Hola como estas",'a'); 

  return 0;
}

