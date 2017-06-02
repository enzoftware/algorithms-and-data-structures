#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){

	int n;
	while(cin>>n){
		vector<int> v;
		int count = 0,aux;
		for(int i = 0 ; i<n ; i++){
			cin>>aux;
			v.push_back(aux);
		}

		for(int i = n-1 ; i>=0 ; i--){
			for(int j = 0 ; j< i ; j++){
				if(v[j] > v[j+1]){
					swap(v[j],v[j+1]);
					count++;
				}
			}
		}

		cout<<"Minimum exchange operations : "<<count<<endl;

	}


	return 0;
}
