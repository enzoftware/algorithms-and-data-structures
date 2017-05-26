#include<bits/stdc++.h>
using namespace std;

ofstream fout("libros.txt");



struct Libro{
    int isbn;
    string titulo;
    string autor;
    string genero;
};

void printBook(Libro l){
    cout<<l.isbn<<" , "<<l.titulo<<" , "<<l.autor<<" , "<<l.genero<<endl;
}

void printText(Libro l){
    fout<<l.isbn<<" , "<<l.titulo<<" , "<<l.autor<<" , "<<l.genero<<endl;
}

void imprimirLibros(vector<Libro>l){
    for_each(l.begin(),l.end(),printBook);
}

void imprimirLibrostxt(vector<Libro>l){
    for_each(l.begin(),l.end(),printText);
}



class GestorLibros{

private:

    vector<Libro>libros;

public:

    GestorLibros(){}

    bool existe(int isbn){
        for(int i = 0 ; i < libros.size() ; ++i){
            if(libros[i].isbn == isbn ) return true;
        }
        return false;
    }
    void AnadirLibro(int isbn , string t ,string a ,string g){
        Libro l;
        l.isbn = isbn;
        l.titulo = t;
        l.autor = a;
        l.genero = g;
        libros.push_back(l);

    }

    void EliminarLibro(int isbn){
        for(int i = 0  ; i< libros.size(); ++i){
            if(libros[i].isbn == isbn){
               libros.erase(libros.begin()+i);
               return;
            }
        }

        cout<<"Este ISBN de libro no existe"<<endl;
    }

    vector<Libro> ListarLibros(){
        return libros;
    }

    void ModificarLibro(Libro l){
        for(int i = 0 ; i < libros.size() ; ++i){
            if(l.isbn == libros[i].isbn){
                libros[i].isbn = l.isbn;
                libros[i].titulo = l.titulo;
                libros[i].autor = l.autor;
                libros[i].genero = l.genero;
                return;
            }
        }

        cout<<"Este ISBN de libro no existe"<<endl;
    }

    void BuscarLibro(string aut){
        for(int i = 0 ; i<libros.size() ; ++i){
            if(libros[i].autor == aut){
                printBook(libros[i]);
                return;
            }
        }
        cout<<"Este autor no existe"<<endl;
    }

    void LeerArchivo(){

    ifstream fin("datos.txt");
    int isbn;
    string num,linea;
    Libro l;
    while(getline(fin,linea)){
            stringstream ss(linea);
            getline(ss,num,','); l.isbn = atof(num.c_str());
            getline(ss,l.titulo,',');
            getline(ss,l.autor,',');
            getline(ss,l.genero,',');
            libros.push_back(l);
        }
    }

};




int main(){

    GestorLibros *gestor = new GestorLibros();
    int isbn,op,v;
    Libro book;
    bool cont =true;
    string t,a,g,aut;
    gestor->LeerArchivo();
    while(cont){
        cout<<endl<<"------------------------------------"<<endl;
        cout<<"Bienvenido a la biblioteca"<<endl;
        cout<<"1.Añadir libro"<<endl;
        cout<<"2.Eliminar libro"<<endl;
        cout<<"3.Modificar libro"<<endl;
        cout<<"4.Buscar libro "<<endl;
        cout<<"5.Listar todos los libros"<<endl;
        cout<<"6.Salir"<<endl<<endl;
        cout<<"OPCION : ";cin>>op;

        switch(op){
        case 1:
            cout<<"Ingresa el ISBN : ";cin>>isbn; cin.ignore();
            cout<<"Ingresa el titulo : ";getline(cin,t);
            cout<<"Ingresa el autor : ";getline(cin,a);
            cout<<"Ingresa el genero : ";getline(cin,g);
            if(gestor->existe(isbn)) cout<<"Ya existe el isbn "<<endl;
            else gestor->AnadirLibro(isbn,t,a,g);
        break;
        case 2:
            cout<<"Ingresa el ISBN del libro a eliminar ";
            cin>>v;
            gestor->EliminarLibro(v);
        break;
        case 3 :
            cout<<"Ingresa el isbn del libro a modificar : "; cin>>book.isbn; cin.ignore();
            cout<<"Ingresa el titulo del libro a modificar : "; getline(cin,book.titulo);
            cout<<"Ingresa el autor del libro a modificar : "; getline(cin,book.autor);
            cout<<"Ingresa el genero del libro a modificar : "; getline(cin,book.genero);
            gestor->ModificarLibro(book);
        break;
        case 4:
            cout<<"Ingresa el nombre del autor del libro a buscar : "; cin>>aut;
            gestor->BuscarLibro(aut);
        break;
        case 5:
            imprimirLibros(gestor->ListarLibros());
        break;
        case 6:
            cout<<"Gracias por usar la biblioteca"<<endl;
            cont = false;
        break;
        }

    }


    imprimirLibrostxt(gestor->ListarLibros());

    return 0;
}
