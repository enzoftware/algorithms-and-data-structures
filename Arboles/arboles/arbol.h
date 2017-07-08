#include <cstddef>
#include <iostream>
using namespace std;

template <class T>
struct Nodo {
  T elemento;
  Nodo* izq;
  Nodo* der;
};

template <class T>
class ArbolB {
  Nodo<T>* raiz;
  void (*procesar)(T);
private:
  bool _insertar(Nodo<T>*& nodo, T e) {
    if (nodo == NULL) {
      nodo = new Nodo<T>();
      nodo->elemento = e;
    } else if (e < nodo->elemento) {
      _insertar(nodo->izq, e);
    } else if (e >= nodo->elemento) {
      _insertar(nodo->der, e);
    }
  }

  void _eliminar(Nodo<T>*& nodo , Nodo<T>*& nodoPadre, T e){
    if(nodo->elemento != e) {
      if(e < nodo->elemento) _eliminar(nodo->izq, nodo, e);
      else _eliminar(nodo->der ,nodo,e);
    }else{
      if(nodo->izq == NULL && nodo->der == NULL){ // Eliminando hoja
      /*  if(nodo->elemento < nodoPadre->elemento){
          nodoPadre->izq = NULL;
        }else{
          nodoPadre->der = NULL;
        }*/
      }
    }

  }

  void _enOrden(Nodo<T>* nodo) {
    if (nodo == NULL) return;
    _enOrden(nodo->izq);
    procesar(nodo->elemento);
    _enOrden(nodo->der);
  }
public:
  ArbolB(void (*otroPunteroAFuncion)(T)) {
    this->procesar = otroPunteroAFuncion;
    raiz = NULL;
  }
  bool insertar(T e) {
    return _insertar(raiz, e);
  }
  void enOrden() {
    _enOrden(raiz);
  }

  void eliminar(T e){
    _eliminar(raiz,NULL,e);
  }

};
