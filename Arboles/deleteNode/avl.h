#ifndef __ARBOLB_H__
#define __ARBOLB_H__
#include <cstddef>
// #include <algorithm>

// using namespace std;

template <class T>
struct Nodo {
	T elemento; // payload
	Nodo* izq;
	Nodo* der;
	int h; // altura: numero de ramas desde el nodo hasta la hoja m�s lejana
public:
	Nodo() {
		h = 0;
		izq = NULL;
		der = NULL;
	}
};

template <class T, class P, class C> // P para funcion procesar y C para funcion comparar
class ArbolAVL {
	Nodo<T>* raiz;
	P procesar; // templates de punteros a funciones o lambdas
	C comparar; // templates de punteros a funciones o lambdas
private:
	void _rotarIzq(Nodo<T>*  x, Nodo<T>*& y, Nodo<T>*& p) { // p es el padre de x
		p = y;
		x->der = y->izq;
		p->izq = x;
	}
	void _rotarDer(Nodo<T>*&  x, Nodo<T>* y, Nodo<T>*& p) { // p es el padre de y
		p = x;
		y->izq = x->der;
		p->der = y;
	}

	bool _insertar(Nodo<T>*& nodo, T e) {
		if (nodo == NULL) {
			nodo = new Nodo<T>(); // h = 0
			nodo->elemento = e;
		}
		else if (comparar(e, nodo->elemento) < 0) { // con lambda
			_insertar(nodo->izq, e);
		}
		else /* if (comparar(e, nodo->elemento) > 0) */ { // descomentar para no aceptar duplicados
			_insertar(nodo->der, e);
		}
		int hi = _altura(nodo->izq);
		int hd = _altura(nodo->der);
		int d = hd - hi;
		if (d > 1) { // pesado a la derecha
			int hni = _altura(nodo->der->izq);
			int hnd = _altura(nodo->der->der);
			if (hni > hnd) { // zig zag derecha izquierda
				_rotarDer(nodo->der->izq, nodo->der, nodo->der);
			}
			_rotarIzq(nodo, nodo->der, nodo);
		}
		else if (d < -1) { // pesado a la izquierda
			int hni = _altura(nodo->izq->izq);
			int hnd = _altura(nodo->izq->der);
			if (hnd > hni) { // zig zag izquierda derecha
				_rotarIzq(nodo->izq, nodo->izq->der, nodo->izq);
			}
			_rotarDer(nodo->izq, nodo, nodo);
		}
		hi = _altura(nodo->izq);
		hd = _altura(nodo->der);
		nodo->h = 1 + (hi > hd ? hi : hd);
		return true;
	}


	void _enOrden(Nodo<T>* nodo) {
		if (nodo == NULL) return;
		_enOrden(nodo->izq);
		procesar(nodo->elemento);
		_enOrden(nodo->der);
	}
	int _altura(Nodo<T>* nodo) {
		if (nodo == NULL) return -1;
		return nodo->h; // implementacion optima en tiempo
	}
	T _buscar(Nodo<T>* nodo, T e, C comparar) { // template funcional
		if (nodo == NULL) return 0;
		if (comparar(e, nodo->elemento) == 0) {
			return nodo->elemento;
		}
		else {
			return _buscar(
				comparar(e, nodo->elemento) > 0 ?
				nodo->der :
				nodo->izq,
				e, comparar);
		}
	}
	Nodo<T>* _quitarMenor(Nodo<T>* nodo, Nodo<T>*& vinc) {
		if (nodo == NULL) return NULL; // ERROR!!
		if (nodo->izq == NULL) { // encontramos el menor!!
			vinc = nodo->der;
			nodo->der = NULL;
			return nodo;
		}
		else {
			return _quitarMenor(nodo->izq, nodo->izq);
		}
	}
	Nodo<T>* _quitarMayor(Nodo<T>* nodo, Nodo<T>*& vinc) {
		if (nodo == NULL) return NULL; // ERROR!!
		if (nodo->der == NULL) { // encontramos el menor!!
			vinc = nodo->izq;
			nodo->izq = NULL;
			return nodo;
		}
		else {
			return _quitarMayor(nodo->der, nodo->der);
		}
	}
	bool _eliminar(T e, Nodo<T>* nodo, Nodo<T>*& vinc) {
		if (comparar(e, nodo->elemento) == 0) {
			int hi = _altura(nodo->izq);
			int hd = _altura(nodo->der);
			if (hi == -1 && hd == -1) {
				vinc = NULL;
				delete nodo;
				return true;
			}
			else if (hi > hd) {
				Nodo<T>* reemplazo = _quitarMayor(nodo->izq, nodo->izq);
				reemplazo->izq = nodo->izq;
				reemplazo->der = nodo->der;
				vinc = reemplazo;
				delete nodo;
			}
			else {
				Nodo<T>* reemplazo = _quitarMenor(nodo->der, nodo->der);
				reemplazo->izq = nodo->izq;
				reemplazo->der = nodo->der;
				vinc = reemplazo;
				delete nodo;
			}
		}
		else if (comparar(e, nodo->elemento) > 0 && nodo->der != NULL) {
			return _eliminar(e, nodo->der, nodo->der);
		}
		else if (comparar(e, nodo->elemento) < 0 && nodo->izq != NULL) {
			return _eliminar(e, nodo->izq, nodo->izq);
		}
		else {
			return false;
		}
	}
public:
	ArbolAVL(P funcion1, C funcion2) { // con template funcional
		this->procesar = funcion1;
		this->comparar = funcion2;
		raiz = NULL;
	}
	bool insertar(T e) {
		return _insertar(raiz, e);
	}
	void enOrden() {
		_enOrden(raiz);
	}
	int altura() {
		_altura(raiz);
	}
	T buscar(T e, C comparar) { // con template funcional
		return _buscar(raiz, e, comparar);
	}
	bool eliminar(T e) {
		return _eliminar(e, raiz, raiz);
	}
};

#endif
