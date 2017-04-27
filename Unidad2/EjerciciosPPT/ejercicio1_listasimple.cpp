#include <iostream>
using namespace std;
template<class T>

class ListaSimple{
private:
    struct Nodo{
        Nodo *next;
        T elemento;
        Nodo(T elemento = 0 , Nodo * next = NULL) : elemento(elemento) , next(next) {}
    };

    Nodo *inicio;
    int n;

/*      Clase iterador para poder acceder a los elemnetos de nuestra propia lista       */

public:

class iterador{
    Nodo* auxi;
public:
    iterador(Nodo *auxi = NULL) : auxi(auxi){}
    void operator ++(int dummy){ auxi = auxi->next;   }
    bool operator !=(iterador t){ return auxi != t.auxi;   }
    T operator*(){ return auxi->elemento;   }
};

/*      Clase iterador para poder acceder a los elemnetos de nuestra propia lista       */


public:
    ListaSimple() : n(0), inicio(NULL){}
    ~ListaSimple(){
        while(inicio != NULL){
            Nodo * aux = inicio;
            inicio = inicio->next;
            delete aux;
        }
    }


    /*      INICIO METODOS Iterador     */

    iterador Inicio(){
        return iterador(inicio);
    }

    iterador Finalito(){
        return iterador(NULL);
    }

    /*      FIN METODOS Iterador      */

    bool insertarInicio(T data){
        Nodo * nuevo = new Nodo(data,inicio);
        if(nuevo == NULL) return false;
        inicio = nuevo;
        ++n;
        return true;
    }

    bool insertarPosicion(T data , int pos){
        if(pos > n || pos < 0) return false;
        if(pos == 0 ) insertarInicio(data);
        int cont = 1;
        Nodo *auxi = inicio;
        /*      Se aumenta el contador dentro del while por el '++'     */
        while(cont++ < pos){
            auxi = auxi->next;
        }

        Nodo* nuevo = new Nodo(data, auxi->next);
        if(nuevo == NULL) return false;
        auxi->next = nuevo;
        ++n;
        return true;
    }

    bool insertarOrdenado( T data){
        Nodo * nuevo = new Nodo(data,inicio);
        Nodo *temp = inicio;
        if(nuevo == NULL) return false;
        if(n == 0 ) insertarInicio(data);
        if(inicio->elemento > data){
            nuevo->next = inicio;
            inicio = nuevo;
        }else{
            while(temp->next != NULL && temp->next->elemento < data){
                temp = temp->next;
            }
            nuevo->next = temp->next;
            temp->next = nuevo;
        }
        ++n;
        return true;
    }

    bool Ordenar(){
        if(n==0) return false;
        T temp_data;
        Nodo * aux_node = inicio;
        Nodo *temp = aux_node;
        while (aux_node){
            temp = aux_node;
            while (temp->next){
                temp = temp->next;
                if(aux_node->elemento > temp->elemento){
                    temp_data = aux_node->elemento ;
                    aux_node->elemento = temp->elemento;
                    temp->elemento = temp_data;
                }
            }
            aux_node = aux_node->next;
        }
        return true;
    }


    bool insertarFinal(T data){
        insertarPosicion(data,n);
        return true;
    }

    bool eliminarInicio(){
        if(n == 0 )return false;
        Nodo* aux = inicio;
        inicio = inicio->next;
        delete aux;
        --n;
        return true;
    }

    bool eliminarPosicion(int pos){
        if(pos == 0) eliminarInicio();
        if(pos < 0 || pos > n ) return false;
        Nodo *aux1 = inicio;
        int conta = 1;
        while(conta++ < pos ){
            aux1 = aux1 ->next;
        }
        Nodo* aux2 = aux1 -> next;
        aux1->next = aux2->next;
        delete aux2;
        --n;
        return true;
    }

    bool eliminarFinal(){
        eliminarPosicion(n-1);
        --n;
        return true;
    }

    int tamanio(){
        return n;
    }

};


int main(){
    int x;
    ListaSimple<int> ls;
    cin>>x;
    ls.insertarInicio(x);
    cin>>x;
    ls.insertarInicio(x);
    cin>>x;
    ls.insertarFinal(x);
    cin>>x;
    ls.insertarFinal(x);
    cin>>x;
    ls.insertarFinal(x);
    cin>>x;
    ls.insertarFinal(x);
    ls.Ordenar();

    cin>>x;
    ls.insertarOrdenado(x);

    ListaSimple<int>::iterador it= ls.Inicio();

    for( ; it != ls.Finalito() ; it++){
        cout<< *it << "  ";
    }

    cout<<endl;


    return 0;
}
