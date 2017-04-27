#include <iostream>
using  namespace std;

template<class T>
class ListaCircular{
private:
    struct Nodo{
        Nodo* next;
        T dato;
        Nodo(T dato = 0, Nodo * next = NULL ) : dato(dato) , next(next){}
    };

    Nodo * primero;
    Nodo * ultimo;
    int n;

public:

    class iterador{
    private:
        Nodo *aux;
    public:
        iterador(Nodo * aux = NULL) : aux(aux){}
        bool operator !=(iterador it){ return (aux != it.aux); }
        T operator *(){  return aux->dato; }
        void operator ++(int dummy){ aux = aux->next;   }
    };

public:
    ListaCircular():primero(NULL),ultimo(NULL),n(0){}

    ~ListaCircular(){

        while(primero != NULL){
            Nodo * aux = primero;
            primero = primero->next;
            delete aux;
        }
    }

    bool vacio(){
        return (primero == NULL);
    }

    iterador first(){
        return primero;
    }

    iterador last(){
        return ultimo;
    }

    int tamanio(){  return n;   }

    bool insertarInicio(T data){
        Nodo * nuevo = new Nodo(data,primero);
        if(nuevo == NULL) return false;
        if(vacio()){
            primero = ultimo = nuevo;
            ultimo->next = primero;
        }else{
            ultimo->next = nuevo;
            nuevo->next = primero;
            primero = nuevo;
        }
        ++n;
        return true;
    }

    bool insertarFinal(T data){
        Nodo *nuevo = new Nodo(data,primero);
        if(nuevo == NULL) return false;
        if(vacio()){
            ultimo = primero = nuevo;
            ultimo->next = primero;
        }else{
            ultimo->next = nuevo;
            ultimo = nuevo;
            nuevo->next = primero;
        }
        ++n;
        return true;
    }

    bool eliminarInicio(){
        
    }

};

int main(){
    ListaCircular<char> lc;
    char x;

    cin>>x;
    lc.insertarInicio(x);
    cin>>x;
    lc.insertarInicio(x);
    cin>>x;
    lc.insertarInicio(x);
    cin>>x;
    lc.insertarInicio(x);
    cin>>x;
    lc.insertarFinal(x);

    ListaCircular<char>::iterador it = lc.first();
    for( ; it != lc.last() ; it++){
        cout<< *it << "  ";
    }
    /*      Ultimo elmento no se imprime dentro del for se imprime individual saliendo      */
    cout<< *it << " ";

    cout<<endl;

    return 0;
}
