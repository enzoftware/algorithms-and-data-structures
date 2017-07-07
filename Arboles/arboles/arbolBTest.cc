#include "arbol.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

void imprimir(int e) {
  cout << " " << e;
}

int main() {
  srand(time(0));
  ArbolB<int>* arbol = new ArbolB<int>(imprimir);
  for (int i = 0; i < 30; ++i) {
    arbol->insertar(rand() % 100);
  }
  arbol->enOrden();
  cout << endl;

  return 0;
}
