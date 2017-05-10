#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>

using namespace std;

class Cliente{
    int id,precio;
    string nombre,apellido,producto;
public:
    Cliente(int id = 0 , string nombre = "" , string apellido = "" , string producto ="", int precio = 0):id(id),nombre(nombre),apellido(apellido),producto(producto),precio(precio){}
    int getID(){return id;}
    int getPrecio(){return precio;}
    string getNombre(){return nombre;}
    string getApellido(){return apellido;}
    string getProducto(){return producto;}
};

class Lista{

    struct Nodo{
        Nodo*next;
        Cliente*elemento;
        Nodo(Cliente*elemento = NULL , Nodo*next = NULL):elemento(elemento),next(next){}
    };
    Nodo*ini;
    Nodo*fin;
    int n;

    public:
    Lista():ini(NULL),n(0){}
    ~Lista(){
        while(ini != NULL){
            Nodo*aux = ini;
            ini = ini->next;
            delete aux;
        }
    }

    bool insertar(Cliente* dato){
        Nodo* nuevo = new Nodo(dato,ini);
        ini = nuevo;
        n++;
    }

    int sumaPrecioC(string nombre , string apellido){
        Nodo*aux = ini;
        int suma = 0 ;
        for(int i = 0 ; i<n ; i++){
            if(aux->elemento->getNombre() == nombre && aux->elemento->getApellido() == apellido){
                suma += aux->elemento->getPrecio();
            }
            aux = aux->next;
        }
        return suma;
    }

    Cliente * encontrarCvip(){
        Nodo*aux = ini;
        int mayor = 0 ;
        string nvip = "vacio";
        string avip = "vacio";
        for(int i = 0 ; i<n ; i++){
            if(sumaPrecioC(aux->elemento->getNombre(),aux->elemento->getApellido()) > mayor){
                nvip = aux->elemento->getNombre();
                avip = aux->elemento->getApellido();
                mayor = sumaPrecioC(aux->elemento->getNombre(),aux->elemento->getApellido());
            }
            aux = aux->next;
        }
        if(nvip != "vacio" && avip != "vacio" && mayor != 0){
            Cliente * c = new Cliente(0,nvip,avip,"",mayor);
            return c;
        }

        return NULL;
    }

    int sumaPrecProd(string prod){
        Nodo *auxi = ini;
        int suma = 0 ;
        for(int i = 0 ; i<n ; i++){
            if(auxi->elemento->getProducto() == prod){
                suma += auxi->elemento->getPrecio();
            }
            auxi = auxi->next;
        }
        return suma;
    }

    Cliente * enconPvip(){
        Nodo*aux = ini;
        string prodvip = "vacio";
        int mayor = 0;
        for(int i = 0 ; i<n ; i++){
            if(sumaPrecProd(aux->elemento->getProducto()) > mayor){
                prodvip = aux->elemento->getProducto();
                mayor = sumaPrecProd(aux->elemento->getProducto());
            }
            aux = aux->next;
        }

        if(prodvip != "vacio" && mayor != 0){
            Cliente * c = new Cliente(0,"","",prodvip,mayor);
            return c;
        }

        return NULL;
    }

};


int randbtn(int a , int b){
    return rand()%(b-a+1)+a;
}


void LoadDatos(vector<string>& nombres ,vector<string>& apellidos ,vector<string>& productos ){
    string dato;
    ifstream ifn("Nombres.txt");
    while(getline(ifn,dato)) nombres.push_back(dato);
    ifn.close();
    ifstream ifa("Apellidos.txt");
    while(getline(ifa,dato)) apellidos.push_back(dato);
    ifa.close();
    ifstream ifp("Productos.txt");
    while(getline(ifp,dato)) productos.push_back(dato);
    ifp.close();
}

void GenerateDatos(int n){
    vector<string> nombres;
    vector<string> apellidos;
    vector<string> productos;
    LoadDatos(nombres,apellidos,productos);
    string name,apel,prod;
    int id, prc;
    ofstream ofi("input.txt");
    for(int i = 0 ; i<n ; i++){
        id = i+1;
        name = nombres[randbtn(0,nombres.size()-1)];
        apel = apellidos[randbtn(0,apellidos.size()-1)];
        prod = productos[randbtn(0,productos.size()-1)];
        prc = randbtn(10,1000);
        ofi<<id<<","<<name<<","<<apel<<","<<prod<<","<<prc<<endl;
    }

}

void ReadDatos(Lista& ls){
    ifstream ifi("input.txt");
    string name,apel,prod,t1,t2,linea;
    int id,prc;
    while(getline(ifi,linea)){
        getline(ifi,t1,','); id = atoi(t1.c_str());
        getline(ifi,name,',');
        getline(ifi,apel,',');
        getline(ifi,prod,',');
        getline(ifi,t2,','); prc=atoi(t2.c_str());
        ls.insertar(new Cliente(id,name,apel,prod,prc));
    }
}



int main(){
    srand(time(0));
    Lista ls;
    GenerateDatos(10000);
    ReadDatos(ls);
    stringstream ss,ss2;
    ofstream vip("vip.txt");

    Cliente *c = ls.encontrarCvip();

    if(c != NULL){
        ss<<"CLIENTE VIP : "<<c->getNombre()<<" "<<c->getApellido()<<" ($ "<<c->getPrecio()<<" ) "<<endl;
    }else{
        ss<<"NO HAY CLIENTE VIP"<<endl;
    }

    Cliente* p = ls.enconPvip();
    if(p!= NULL){
        ss2<<"PRODUCTO VIP : "<<p->getProducto()<<" ($"<<p->getPrecio()<<")"<<endl;
    }else{
        ss2<<"NO HAY PRODUCTO VIP"<<endl;
    }

    vip<<ss.str();
    vip<<ss2.str();

    return 0;
}
