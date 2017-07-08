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
  arbol->insertar(5);
  arbol->insertar(1);
  arbol->insertar(52);
  arbol->insertar(2);
  arbol->insertar(511);
  arbol->insertar(53);
  arbol->eliminar(2);
  arbol->enOrden();
  cout << endl;
  return 0;
}
