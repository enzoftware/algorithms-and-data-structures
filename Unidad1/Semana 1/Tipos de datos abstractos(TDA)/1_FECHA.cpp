// Example program
#include <iostream>


using namespace std;



class Fecha{
    int dia, mes , anio, diasTotales;
    public:
    Fecha(int dia = 1 , int mes = 1 , int anio = 1, int diasTotales = 0 ) : dia(dia) , mes(mes) , anio(anio), diasTotales(diasTotales){}
    
    void calcDif(){
        for(int i = 1 ; i<= this->anio ; i++){
            if(esBisiesto(i)) diasTotales += 366;
            else diasTotales += 365;
        }
        for( int i = 1 ; i<= this->mes ; i++){
            switch(i){
                case 2 : 
                if(esBisiesto(this->anio)) diasTotales+=29;
                else diasTotales += 28 ;
                break;
                case 1 : case 3 : case 5: case 7 : case 8 : case 10 : case 12 : diasTotales += 31; break;
                case 4 : case 6 : case 9 : case 11: diasTotales += 30; break;
            }
        }
        
        diasTotales += this->dia;    
    }
    
    bool esBisiesto(int a){
        return((a%400 == 0 && a%4==0) || a%100 != 0  ? true : false);    
    }
    
    Fecha operator -(Fecha f){
        return Fecha(0,0,0,this->diasTotales - f.diasTotales);
    }
    
    int imprimirResultado(){
        return(this->diasTotales);
    }
};

int d,m,a;

int main() {
    
    cout<<"Ingresa datos de fecha 1 "<<endl;
    cin>>d>>m>>a;
    Fecha f1(d,m,a,0);
    f1.calcDif();
    cout<<"Ingresa datos de fecha 2 "<<endl;
    cin>>d>>m>>a;
    Fecha f2(d,m,a,0);
    f2.calcDif();
    Fecha f3 = f1 - f2;
    cout<<"La diferencia entre f1 y f2 es "<<labs(f3.imprimirResultado())<<" dias"<<endl;
    return 0;
}
