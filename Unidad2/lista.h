
template <class T>
class ListaSE {
  struct Nodo {
    T elem;
    Nodo* next;

    Nodo(T elem = 0, Nodo* next = NULL) : elem(elem), next(next) {}
  };

  Nodo* inicio;
  int n;
public:
  class Iterador {
    Nodo* aux;
  public:
    Iterador(Nodo* aux = NULL) : aux(aux) {}
    void operator ++(int dummy) { aux = aux->next; }
    bool operator != (Iterador it) { return aux != it.aux; }
    T operator *() { return aux->elem; }
  };

public:
  ListaSE() : n(0), inicio(NULL) {}
  ~ListaSE() {
    while (inicio != NULL) {
      Nodo* aux = inicio;
      inicio = inicio->next;
      delete aux;
    }
  }
  Iterador inicial() {
    return Iterador(inicio);
  }
  Iterador ultimo() {
    return Iterador(NULL);
  }

  int tamanio() { // size()
    return n;
  }

  
  bool insertarInicio(T elem) { // push_front()
    Nodo* nuevo = new Nodo(elem, inicio);
    if (nuevo == NULL) return false;
    inicio = nuevo;
    ++n;
    return true;
  }
  bool insertar(T elem, int p) { // insert*
    if (p < 0 || p > n) return false;
    if (p == 0) insertarInicio(elem);
    int c = 1;
    Nodo* aux = inicio;
    while (c++ < p) {
      aux = aux->next;
    }
    Nodo* nuevo = new Nodo(elem, aux->next);
    if (nuevo == NULL) return false;
    aux->next = nuevo;
    ++n;
    return true;
  }
  bool insertarFinal(T elem) { // push_back()
    insertar(elem, n);
  }
  bool eliminarInicio() {
    if (n == 0) return false;
    Nodo* aux = inicio;
    inicio = inicio->next;
    delete aux;
    --n;
    return true;
  }
};
