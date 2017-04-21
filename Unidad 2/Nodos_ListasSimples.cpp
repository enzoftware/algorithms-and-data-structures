#include<bits/stdc++.h>
using namespace std;

template<class T>

class Nodo{
    public:
    Nodo * siguiente;
    T dato;

    Nodo(){
        dato = NULL;
        siguiente = NULL;
    }
    Nodo(T data){
        dato = data;
        siguiente = NULL;
    }

    void imprimir(){
        //cout << "Nodo-> " << "Dato: " << dato << " Direcion: " << this << " Siguiente: " << next << endl;
        cout<<dato<<" -> ";
    }


};


template<class T>

class Lista{

    private:
        Nodo<T> *elemento_cabeza;
        int num_nodos;
    public:

        Lista(){}
        void insertar_inicio(T data){
            Nodo<T> *nuevo_nodo = new Nodo<T>(data);
            Nodo<T> *temporal = elemento_cabeza;

            if(!elemento_cabeza){
                elemento_cabeza = nuevo_nodo;
            }else{
                nuevo_nodo->siguiente = elemento_cabeza;
                elemento_cabeza = nuevo_nodo;

                while(temporal){
                    temporal = temporal->siguiente;
                }

            }
            num_nodos++;
        }

        void insertar_final(T data){
            Nodo<T>* nuevo_nodo = new Nodo<T>(data);
            Nodo<T>* temporal = elemento_cabeza;

            if(!elemento_cabeza){
                elemento_cabeza = nuevo_nodo;
            }else{
                while(temporal->siguiente != NULL){
                    temporal = temporal->siguiente;
                }
                temporal->siguiente = nuevo_nodo;
            }

            num_nodos++;

        }

        int getNumNodos(){
            return num_nodos;
        }

        bool insertar_posicion(int pos , T data){
            Nodo<T>*nuevo_nodo = new Nodo<T>(data);
            Nodo<T>*temporal = elemento_cabeza;
            int conta = 0;

            if(!elemento_cabeza && pos != 0)    return false;
            else if(!elemento_cabeza && pos == 0){
                elemento_cabeza = nuevo_nodo;
            num_nodos++;
            return true;
            }else if(pos > num_nodos){
                return false;
            }else{

                while(temporal->siguiente != NULL && conta != pos){
                    temporal = temporal->siguiente;
                    conta++;
                }
                temporal->siguiente = nuevo_nodo;
                num_nodos++;
                return true;
            }


        }


        void ordenar(){
            T dato_temporal;
            Nodo<T>*nodo_auxi = elemento_cabeza;
            Nodo<T>*temporal = nodo_auxi;

            while(nodo_auxi){
                temporal = nodo_auxi;
                while(temporal->siguiente){
                    temporal = temporal->siguiente;
                    if(nodo_auxi->dato > temporal->dato){
                        dato_temporal = nodo_auxi->dato;
                        nodo_auxi->dato = temporal->dato;
                        temporal->dato = dato_temporal;
                    }
                }
                nodo_auxi = nodo_auxi->siguiente;
            }

        }


        void insertar_ordenado(T data){
            Nodo<T>*nuevo_nodo = new Nodo<T>(data);
            Nodo<T>*temporal = elemento_cabeza;

            if(!elemento_cabeza){
                elemento_cabeza = nuevo_nodo;
            }else{
                if(elemento_cabeza->dato > data){
                    nuevo_nodo->siguiente = elemento_cabeza;
                    elemento_cabeza = nuevo_nodo;
                }else{
                    while((temporal->siguiente->dato < data ) && (temporal->siguiente != NULL)){
                        temporal = temporal->siguiente;
                    }

                    nuevo_nodo->siguiente = temporal->siguiente;
                    temporal->siguiente = nuevo_nodo;
                }
            }

            num_nodos++;

        }

        void eliminar_inicio(){

        }

        void eliminar_final(){


        }

        void eliminar_por_posicion(int pos){

        }

        void buscar_elemento(T data){

        }

        void imprimir_lista(){
            Nodo<T>*temporal = elemento_cabeza;
            if(!elemento_cabeza){   cout<<"La lista esta vacia "<<endl; }
            else{
                while(temporal){
                    temporal->imprimir();
                    if(!temporal->siguiente) cout<<"NULL"<<endl;
                        temporal = temporal->siguiente;
                }
            }

            cout<<endl;

        }

};


int main(){

    Lista<int> *lista = new Lista<int>();
    int e,pos;



    cin>>e;
    lista->insertar_final(e);
    cin>>e;
    lista->insertar_final(e);
    cin>>e;
    lista->insertar_final(e);
    cin>>e;
    lista->insertar_final(e);
    cin>>e>>pos;
    if(!lista->insertar_posicion(pos,e)) cout<<"Posicion no aceptada"<<endl;
    //lista->ordenar();
    cout<<lista->getNumNodos()<<endl;
    lista->imprimir_lista();





    return 0;
}
