#include <iostream>
#include <string>

using namespace std;

template <class T>

class ListaCircularDE {
	struct Nodo {
		T elemento;
		Nodo *next;
		Nodo *prev;
		Nodo(T elemento = 0, Nodo *next = NULL, Nodo *prev = NULL) : elemento(elemento), next(next), prev(prev) {}
	};
	Nodo *inicio;
	//Nodo *ultimo;
	int n;
public:
	class Iterador {
		Nodo *aux;
		int cont;
	public:
		Iterador(Nodo *aux = NULL):aux(aux) {}
		void operator ++(int dummy) { aux = aux->next; cont++; }
		bool operator !=(Iterador it) { return aux != it.aux; }
		T operator *() { return aux->elemento; }
	};
public:
	ListaCircularDE() :inicio(NULL), n(0) {}
	~ListaCircularDE() {
		while (inicio != NULL) {
			Nodo *aux = inicio;
			inicio = inicio->next;
			delete aux;
		}
	}
	Iterador inicial() {
		return Iterador(inicio);
	}
	Iterador ultimito() {
		return Iterador(inicio->prev);
	}
	int tamannio() {
		return n;
	}
	/*T ultimoNext() {
		Nodo *aux = ultimo->next;
		return aux->elemento;
	}*/
	T inicioPrev() {
		Nodo *aux = inicio->prev;
		return aux->elemento;
	}
	bool insertarInicio(T elemento) {
		Nodo *nuevo = new Nodo(elemento, inicio, inicio->prev/* inicio -> prev = ultimo      */);
		if (nuevo == NULL) { return false; }
		if (inicio == NULL) {	Nodo*a = inicio->prev;/* inicio -> prev = ultimo      */  inicio  = nuevo; a->next = inicio; ++n; return true; }
		Nodo*a = inicio->prev;/* inicio -> prev = ultimo      */
		inicio->prev = nuevo;
		inicio = nuevo;
		a->next = inicio;
		++n;
		return true;
	}
	/*bool insertarFinal(T elemento) {
		Nodo *nuevo = new Nodo(elemento, inicio, ultimo);
		if (inicio == NULL) { inicio = ultimo = nuevo; ultimo->next = inicio; ++n; return true; }
		if (nuevo == NULL) { return false; }
		ultimo->next = nuevo;
		inicio->prev = nuevo;
		ultimo = nuevo;
		++n;
		return true;
	}
	bool insertarPOS(T elemento, int pos) {
		if (pos < 0 || pos > n) return false;
		if (pos == 0) { insertarInicio(elemento); return true; }
		if (pos == n) { insertarFinal(elemento); return true; }
		Nodo *aux = inicio;
		int c = 1;
		while (c++ < pos) {
			aux = aux->next;
		}
		Nodo *aux2 = aux->next;
		Nodo *nuevo = new Nodo(elemento, aux2, aux);
		if (nuevo == NULL) return false;
		aux->next = nuevo;
		aux2->prev = nuevo;
		++n;
		return true;
	}
	bool eliminarInicio() {
		if (n == 0) { return false; }
		Nodo *aux = inicio;
		inicio = inicio->next;
		inicio->prev = ultimo;
		ultimo->next = inicio;
		delete aux;
		--n;
		return true;
	}
	bool eliminarFinal() {
		if (n == 0) { return false; }
		Nodo *aux = ultimo;
		Nodo *aux2 = ultimo->prev;
		inicio->prev = aux2;
		aux2->next = inicio;
		ultimo = aux2;
		delete aux;
		--n;
		return true;
	}
	bool eliminarPOS(int pos) {
		if (pos < 0 || pos > n) return false;
		if (n == 0) return false;
		if (pos == 0) { eliminarInicio(); return true; }
		if (pos == n - 1) { eliminarFinal(); return true; }
		Nodo *aux = inicio;
		int c = 1;
		while (c++ < pos) {
			aux = aux->next;
		}
		Nodo *aux2 = aux->next;
		Nodo *aux3 = aux2->next;
		aux->next = aux3;
		aux3->prev = aux;
		delete aux2;
		--n;
		return true;
	}
	T buscarElemento(int pos) {
		if (n == 0) return 0;
		if (pos < 0 || pos > n) return 0;
		Nodo *aux = inicio;
		int c = 1;
		while (c++ <= pos) {
			aux = aux-> next;
		}
		return aux->elemento;
	}
	int encontrarDato(T elemento) {
		if (n == 0) { return 0; }
		Nodo *aux = inicio;
		int c = 0; int pos = 0;
		while (c++ < n) {
			if (aux->elemento == elemento) return pos;
			else {
				++pos;
				aux = aux->next;
			}
		}
		return -1;
	}*/
};


int main()
{
	ListaCircularDE<char>lcde;

	char x;

	cin >> x;
	lcde.insertarInicio(x);
	cin >> x;
	lcde.insertarInicio(x);
	cin >> x;
	lcde.insertarInicio(x);
	cin >> x;
	lcde.insertarInicio(x);
	cin >> x;
	lcde.insertarInicio(x);
	cin >> x;
	lcde.insertarInicio(x);

	/*lcde.eliminarInicio();
	lcde.eliminarFinal();
	lcde.eliminarPOS(2);
	lcde.insertarPOS('h', 2);
	lcde.insertarFinal('k');*/


	ListaCircularDE<char>::Iterador it = lcde.inicial();
	for (; it != lcde.ultimito(); it++)
	{
		cout << *it << " ";
	}
	cout << *it;
	cout << endl << endl;

	/*cout << "Elemento en la posicion 4: " << lcde.buscarElemento(4) << endl;
	cout << "El elemento siguiente del final es: " << lcde.ultimoNext() << endl;
	cout << "El elemento anterior del inicio es: " << lcde.inicioPrev() << endl;

	cout << "Ingrese dato a encontrar: "; cin >> x;
	cout << "\nEl dato se encontro en la posicion: " << lcde.encontrarDato(x) << endl;*/

	return 0;
}
