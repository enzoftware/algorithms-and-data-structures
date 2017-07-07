#include "avl.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>
#include <algorithm>

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
  auto impr = [](int) { };
  auto comparar = [](int a, int b) { return a - b;};
  // ArbolAVL<int>* arbol = new ArbolAVL<int>(imprimir, comparar); // la vieja escuela
  Arbolito arbol(impr, comparar); // la nueva escuela

  vector<int> arreglito(MAX);

  for (int i = 0; i < MAX; ++i) {
    arbol.insertar(i + 1);
    arreglito[i] = i + 1;
    //arbol->insertar(rand() % 100);
  }
  // arbol->enOrden();
  long start = clock();
  cout << buscar(arreglito, MAX) << endl;
  cout << "Tiempo busqueda lineal en arreglo: " << (clock() - start) << endl;
  start = clock();
  cout << arbol.buscar(MAX, comparar) << endl;
  cout << "Tiempo busqueda binaria en AVLTree: " << (clock() - start) << endl;

  return 0;
}