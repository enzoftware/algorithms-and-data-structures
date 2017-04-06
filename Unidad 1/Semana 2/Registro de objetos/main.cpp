#include<bits/stdc++.h>
#include "point.h"
using namespace std;

void imprimirPuntos(Point p){
        cout<<" X : "<<p.x<<" , Y : "<<p.y<<endl;
}

class Path{
private:
    int numPoints;
    vector<Point> points;

public:

    Path(){}
    void agregarPoint(int x , int y){
        Point p;
        p.x = x; p.y = y;
        points.push_back(p);
    }

    Point getPoint(int pos){
        if(pos < points.size()){
            return points[pos];
        }else{
            cout<<"Posicion invalida"<<endl;
        }
    }

    void mostrarPoints(){
        for_each(points.begin(),points.end(),imprimirPuntos);
    }

    void borrarPoint(int pos){
        points.erase(points.begin()+pos);
    }

};




int memoriaPath(Path p){
    return sizeof(p);
}

int menu(){
    int op;
    cout<<"Ingrese una opcion : "<<endl;
    cout<<"1. Agregar punto "<<endl;
    cout<<"2. Eliminar punto"<<endl;
    cout<<"3. Mostrar todos los puntos"<<endl;
    cout<<"4. Cantidad de memoria de la clase Path"<<endl;
    cout<<"5. Salir"<<endl;
    cout<<" ___ TU OPICON ES : ____ "; cin>>op;

    return op;
}

int main(){
    int x,y,pos;
    Path *path = new Path();
    int xd;

    do{
        xd = menu();

        switch(xd){

            case 1 :
                cout<<"Ingresa coordenadas (X,Y)"; cin>>x>>y;
                path->agregarPoint(x,y);
            break;

            case 2 :
                cout<<"Ingresa posicion a eliminar"; cin>>pos;
                path->borrarPoint(pos);
            break;

            case 3 :
                path->mostrarPoints();
            break;

            case 4 :
                cout<<"La cantidad de memoria que usa la clase es de : "<<memoriaPath(*path)<<endl;

            break;
            case 5 :
                cout<<":D "<<endl;

            break;

        }

    }while(xd != 5);



    return 0;
}
