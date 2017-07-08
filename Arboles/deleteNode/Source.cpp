#include "avl.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#define MAX 1000000

using namespace std;

void imprimir(int e) {
	cout << " " << e;
}

int buscar(vector<int> v, int e) {
	for (int i = 0; i < v.size(); ++i) {
		if (v[i] == e) {
			return v[i];
		}
	}
}

typedef function<void(int)> LambdaProc;
typedef function<int(int, int)> LambdaComp;
typedef ArbolAVL<int, LambdaProc, LambdaComp> Arbolito;

int main() {
	srand(time(0));
	auto impr = [](int) {};
	auto comparar = [](int a, int b) { return a - b; };
	// ArbolAVL<int>* arbol = new ArbolAVL<int>(imprimir, comparar); // la vieja escuela
	Arbolito arbol(imprimir, comparar); // la nueva escuela

	//vector<int> arreglito(MAX);

	//for (int i = 0; i < MAX; ++i) {
	//	arbol.insertar(i + 1);
	//	arreglito[i] = i + 1;
	//	//arbol->insertar(rand() % 100);
	//}
	//// arbol->enOrden();
	//long start = clock();
	//cout << buscar(arreglito, MAX) << endl;
	//cout << "Tiempo busqueda lineal en arreglo: " << (clock() - start) << endl;
	//start = clock();
	//cout << arbol.buscar(MAX, comparar) << endl;
	//cout << "Tiempo busqueda binaria en AVLTree: " << (clock() - start) << endl;

	arbol.insertar(50);
	arbol.insertar(60);
	arbol.insertar(70);
	arbol.insertar(80);
	arbol.insertar(90);
	arbol.insertar(40);
	arbol.insertar(30);
	arbol.enOrden();
	arbol.eliminar(80);
	cout << endl;
	arbol.enOrden();
	return 0;
}
