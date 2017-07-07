#include "avl.h"
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <time.h>

#define MAX 1000000

using namespace std;

class Cancion {
  string titulo;
  string artista;
  int anio;
public:
  Cancion(string titulo = "",
          string artista = "",
          int anio = 1970) : titulo(titulo), artista(artista), anio(anio) {}
  ~Cancion() {}
  string getTitulo() { return titulo; }
  string getArtista() { return artista; }
  int getAnio() { return anio; }
};

typedef function<void(Cancion*)> LambdaProc;
typedef function<int(Cancion*, Cancion*)> LambdaComp;
typedef ArbolAVL<Cancion*, LambdaProc, LambdaComp> Arbolito;

void indexar(vector<Cancion*> canciones, Arbolito* arbol) {
  for_each(canciones.begin(), canciones.end(), [arbol](Cancion* c) { arbol->insertar(c); });
}

int main() {
  vector<Cancion*> canciones(MAX);

  srand(time(0));
  cout << "Insertando elementos!" << endl;
  for (int i = 0; i < MAX; ++i) { // creando datos aleatorios
    stringstream titulo; titulo << "cancion " << i;
    stringstream artista; artista << "cantante " << (rand() % 1000);
    int anio = 2015 - rand() % 60;
    canciones[i] = new Cancion(titulo.str(), artista.str(), anio);
  }

  auto mostrar = [](Cancion* c) { /* no es necesario */ };
  auto comparar = [](Cancion* a, Cancion* b) { return a->getAnio() - b->getAnio(); }; // comparando por año

  Arbolito* arbol = new Arbolito(mostrar, comparar); // arbolito para indexar

  cout << "Indexando!" << endl;
  indexar(canciones, arbol);

  Cancion* dummy = new Cancion("", "", 1999);
  Cancion* cancion = arbol->buscar(dummy, comparar);
  delete dummy;

  if (cancion != nullptr) {
    cout << "Encontrado!" << endl;
    cout << "Cancion: " << cancion->getTitulo() << endl
          << "Artista: " << cancion->getArtista() << endl;
  }
  cout << "Borrando todo!" << endl;
  for (int i = 0; i < MAX; ++i) {
    delete canciones[i];
  }
  cout << "Bye bye!" << endl;
  return 0;
}