#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

char letters[9] = "abcdefgh" , aux[9];
int test; 

void programline(int x , int y){
	if(x == test){
		for (int i = 0; i < y; i++){
			cout<<" ";
		}
		cout<<"writeln(";
		for(int i = 0 ; i < test-1 ; i++){
			cout<<aux[i]<<",";
		}
		cout<<aux[test-1]<<")"<<endl;
		return;
	}

	for(int i = x ; i>= 0 ; i--){
		if(i == x) aux[i] = letters[x];
		else swap(aux[i],aux[i+1]);
		if(x>0)
			if(i==x){
				for (int k = 0; k < y; k++) cout << " ";
					cout << "if " << aux[i - 1] << " < " << aux[i] << " then" << endl;
			}else {
			for (int k = 0; k < y; k++) cout << " ";
			if (i>0) cout << "else if " << aux[i - 1] << " < " << aux[i] << " then" << endl;
			else cout << "else" << endl;
		}
		programline(x+1,y+2);
	}

	for(int i = 0 ; i<x ; i++) swap(aux[i],aux[i+1]);

}

int main(){
	int numcases;
	cin>>numcases;

	while(numcases--){
		cin>>test;
		cout<<"program sort(input,output);"<<endl;
		cout<<"var"<<endl;
		for (int i = 0; i < test-1; i++){
			cout<<letters[i]<<",";	
		}
		cout<<letters[test-1]<<" : integer; "<<endl;
		cout<<"begin"<<endl;
		cout<<"  readln(";
		for (int i = 0; i < test-1; i++){
			cout<<letters[i]<<",";
		}
		cout<<letters[test-1]<<");"<<endl;
		programline(0,0);
		cout<<"end."<<endl;
		if(numcases>0) cout<<endl;
	}

	
	return 0;
}