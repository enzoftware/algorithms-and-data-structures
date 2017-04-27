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
        if(vacio()) return false;
        if(primero == ultimo){
            primero = ultimo = NULL;
        }else{
            Nodo * temp = primero;
            primero = primero->next;
            ultimo->next = primero;
            delete temp;
        }
        --n;
        return true;
    }

    bool eliminarFinal(){

        if(vacio()) return false;
        if(primero == ultimo){
            primero = ultimo = NULL;
        }else{
            Nodo * temp = primero;
            bool seguir = true;
            while(seguir){
                if(temp->next == ultimo){
                    Nodo *aux = ultimo;
                    ultimo = temp;
                    temp->next = primero;
                    delete aux;
                    seguir = false;
                }else
                    temp = temp->next;
            }
        }
        --n;
        return true;
    }

    int EncontrarDato(T dat){
        if(vacio() ) return -1;
        Nodo * aux = primero;
        int pos = 0 , c = 0 ;
        while(c++ < n ){
            if(aux->dato == dat)
                return pos;
            else{
                ++pos;
                aux = aux->next;
            }
        }
        return -1;
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

    lc.eliminarInicio();
    lc.eliminarFinal();

    ListaCircular<char>::iterador it = lc.first();
    for( ; it != lc.last() ; it++){
        cout<< *it << "  ";
    }
    /*      Ultimo elmento no se imprime dentro del for se imprime individual saliendo      */
    cout<< *it << " "<<endl;

    if(lc.EncontrarDato('m') < 0) cout<<" No ";
    else cout<<" SI";

    cout<<endl;

    return 0;
}
