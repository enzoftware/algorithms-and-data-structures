#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

class ArbolAVL {

  struct Nodo{
    Nodo *l;
    Nodo* r;
    int e;
    int h;
    Nodo(int e = 0 , Nodo *l = NULL ,Nodo* r = NULL) : e(e),l(l),r(r){
      int hnl = (l == NULL) ? -1 : l->h;
      int hnr = (r == NULL) ? -1 : r->h ;
      this->h = ( (hnl > hnr) ? hnl : hnr ) + 1 ;
    }
  };

  void imprimirOrdenado(Nodo* n){
    if(n != NULL){
      imprimirOrdenado(n->l);
      imprimir(n->e);
      imprimirOrdenado(n->r);
    }
  }


  bool _insertar(Nodo *&nodo , int ele){
    if(nodo == NULL){
      nodo = new Nodo(ele);
      nodos++;
      return nodo != NULL;
    }else if (ele < nodo->e){
      _insertar(nodo->l,ele);
    }else{
      _insertar(nodo->r,ele);
    }
  }



private:
   Nodo * raiz;
   int nodos;
   void (*imprimir)(int);

public:
  ArbolAVL (void (*ptrFunc)(int)){
    this->imprimir = ptrFunc;
  }

  int getNumNodos(){
    return nodos;
  }

  void printTree(){
    imprimirOrdenado(raiz);
  }

  bool insertarNodo(int e){
    return _insertar(raiz,e);
  }

};


void imprimir(int e){
  cout<<" "<<e;
}

int main(int argc, char const *argv[]) {
  srand(time(0));
  ArbolAVL * arbol = new ArbolAVL(imprimir);
  for (int i = 0; i < 15; i++) {
    arbol->insertarNodo(rand()%100);
  }
  arbol->printTree();

  return 0;
}
