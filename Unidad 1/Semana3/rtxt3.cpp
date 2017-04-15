#include <bits/stdc++.h>

using namespace std;

class Alumno{
	string codigo;
	string nombres;
	string apellidos;
	float pc1,tp1,ea,pc2,tf,pa,eb;
		
public:
	Alumno(string codigo, string apellidos, string nombres,float pc1,float tp1,float ea,float pc2,float tf,float pa,float eb) :
		codigo(codigo),apellidos(apellidos),nombres(nombres),pc1(pc1),tp1(tp1),ea(ea),pc2(pc2),
		tf(tf),pa(pa),eb(eb){}
		
		float GetPromedio()
		{
			return 0.1*pc1 + 0.1*tp1 + 0.15*ea + 0.1*pc2 + 0.35*tf+ 0.05*pa + 0.15*eb;
		}
		
		string toString()
		{
			stringstream ss;
			ss<<apellidos<<" "<<nombres<<" : "<<GetPromedio();
			return ss.str();
		}
};

class GestorAlumnos{
	
	vector<Alumno*> alumnos;
	
	public:
		
	~GestorAlumnos(){
		for(Alumno* al: alumnos){
			delete al;
		}
	}
	
	void LeerDatos(){
		
		ifstream datos("Alumnos.csv");
		string cod;
		string nom;
		string ap;
		float pc1,tp1,ea,pc2,tf,pa,eb;
		string linea,num;
		
		while(getline(datos,linea)){
			stringstream ss(linea);
			
			getline(ss, cod, ',');
			getline(ss, ap, ',');
			getline(ss, nom, ',');
			getline(ss, num, ','); pc1=atof(num.c_str());
			getline(ss, num, ','); tp1=atof(num.c_str());
			getline(ss, num, ','); ea=atof(num.c_str());
			getline(ss, num, ','); pc2=atof(num.c_str());
			getline(ss, num, ','); tf=atof(num.c_str());
			getline(ss, num, ','); pa=atof(num.c_str());
			getline(ss, num, ','); eb=atof(num.c_str());
			
			alumnos.push_back(new Alumno(cod,ap,nom,pc1,tp1,ea,pc2,tf,pa,eb));
		}
	}
	
	void GuardarAprobados(){
		
		ofstream datos("Apobados.txt");
		
		for (int i = 0; i < alumnos.size(); ++i) {
			
            if(alumnos[i]->GetPromedio()>12.49){
            	
				datos<<alumnos[i]->toString()<<endl;
			}
        }
	}
	
	void MostrarInfoAlumnos(){
		
		for (int i = 0; i < alumnos.size(); ++i) {
            cout << alumnos[i]->toString() << endl;
        }
		
	}
};

int main(){
	
	GestorAlumnos* ga=new GestorAlumnos();
	
	ga->LeerDatos();
	ga->MostrarInfoAlumnos();
	ga->GuardarAprobados();
	
	delete ga;
	return 0;
}
