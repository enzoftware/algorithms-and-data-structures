#ifndef __ARBOLB_H__
#define __ARBOLB_H__

template <class T>
struct Nodo {
  T elemento;
  Nodo* izq;
  Nodo* der;
};

template <class T>
class ArbolB {
  Nodo<T>* raiz;
  void (*procesar)(T); //Puntero a funcion
private:
  bool _insertar(Nodo<T>*& nodo, T e) {
    if (nodo == nullptr) {
      nodo = new Nodo<T>();
      nodo->elemento = e;
    } else if (e < nodo->elemento) {
      _insertar(nodo->izq, e);
    } else if (e >= nodo->elemento) {
      _insertar(nodo->der, e);
    }
  }
  void _enOrden(Nodo<T>* nodo) {
    if (nodo == nullptr) return;
    _enOrden(nodo->izq);
    procesar(nodo->elemento);
    _enOrden(nodo->der);
  }
public:
  ArbolB(void (*otroPunteroAFuncion)(T)) {
    this->procesar = otroPunteroAFuncion;
    raiz = nullptr;
  }
  bool insertar(T e) {
    return _insertar(raiz, e);
  }
  void enOrden() {
    _enOrden(raiz);
  }
};

#endif