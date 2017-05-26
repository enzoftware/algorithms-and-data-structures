#include <bits/stdc++.h>
using namespace std;
	
	string reverse(string str){
		string x;
		for(int i = str.size()-1 ; i >= 0 ; i--){
			x+=str[i];	
		}
		return x;
	}

int main(){
	string x = "Hola como estas";
	cout<<reverse(x);
}
