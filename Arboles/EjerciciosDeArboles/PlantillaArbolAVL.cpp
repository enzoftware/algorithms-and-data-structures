#include <iostream>
using namespace std;

//
//TODO: EN ESTE EJEMPLO TRATARE DE SER LO MAS EXPLICATIVO POSIBLE COMENTANDO EL CODIGO
//


class ARBOLITOAVL{ // CREACION DEL ARBOL AVL
  struct Nodo{
    Nodo* left; //HIJO IZQUIERDO
    Nodo* right; // HIJO DERECHO
    int elemento;
    int altura; //ALTURA DEL ARBOL
    Nodo(int elemento = 0 , Nodo* left = NULL ,Nodo* right = NULL ): elemento(elemento),left(left),right(right){
                                                        //INICIALIZANDO LOS VALORES DEL ARBOL
      int hnl = (left == NULL)? -1 : left->altura;     //ALTURA DEL HIJO IZQUIERDO
      int hnr = (right == NULL) ? -1 : right->altura; //ALTURA DEL HIJO DERECHO
      this->altura = ((hnl > hnr) ? hnl : hnr ) +1 ; //OBTIENE LA ALTURA DEL MAYOR Y LE AUMENTA SU VALOR EN 1
    }
  };

  int getAltura(Nodo* n){
    return (n == NULL) ? -1 : n->altura;
    //OBTENEMOS LA ALTURA DE UN NODO
  }

  void fixAltura(Nodo *n){
    n->altura = ( ( getAltura(n->left) > getAltura(n->right) ) ? getAltura(n->left) : getAltura(n->right) ) +1;
    //ACTUALIZAMOS LA ALTURA DE UN NODO , COMO EN SU INICIALIZACION
  }

  void imprimirEnOrden(Nodo*n) {
    if(n != NULL) {
      imprimirEnOrden(n->left);
      imprimir(n->elemento);
      imprimirEnOrden(n->right);
    }

    //FUNCION RECURSIVA QUE PERMITE IMPRIMIR DE MANERA ORDENADA EL ARBOL PORQUE
    //VA PRIMERO AL NODO QUE ESTA MAS A LA IZQUIERDA DE CADA NODO
    // Y SE VA MOVIENDO A LA DERECHA EN CADA RECORRIDO

  }

  void RotarIzquierda(Nodo*& x){
    Nodo*y = x->right;
    x->right = y->left;
    y->left = x;
    x = y;
    fixAltura(x->left);
    fixAltura(x);

    //ROTA A LA IZQUIERDA UN NODO

  }

  void RotarDerecha(Nodo*& y){
    Nodo*x = y->left;
    y->left = x->right;
    x->right = y;
    y = x;
    fixAltura(y->right);
    fixAltura(y);

    //ROTA A LA DERECHA UN NODO

  }

  void BalancearArbol(Nodo*& nodo){
    if(getAltura(nodo->left) - getAltura(nodo->right) > 1){ // PESADO A LA IZQUIERDA
      if(getAltura(nodo->left->right) > getAltura(nodo->left->left)){ //EN FORMA DE ZIGZAG
        RotarIzquierda(nodo->left); // COMO ESTA EN ZIGZAG SE ROTA A LA DERECHA EL SUBNODO
      }
      RotarDerecha(nodo);
    }else if(getAltura(nodo->right) - getAltura(nodo->left) > 1){ //PESADO A LA DERECHA
        if(getAltura(nodo->right->left) > getAltura(nodo->right->right)){ //ZIGZAG
            RotarDerecha(nodo->right); // COMO ESTA EN ZIGZAG SE ROTA A LA IZQUIERDA EL SUBNODO
        }
        RotarIzquierda(nodo);
    }
  }

  bool insertarNodo(int e , Nodo*& nodo){
    bool flag = false; //INICIAMOS EN FALSO PARA VERIFICAR SI SE HIZO LA INSERCION DE UN NUEVO NODO
      if(nodo == NULL){
        nodo = new Nodo(e); //SE CREA UN NUEVO NODO SI ESTA VACIA LA POSICION
        numNodos++; // EL NUMERO DE NODOS AUMENTA
        return nodo!= NULL; // RETORNARA VERDADERO
      }else if(e < nodo->elemento){
        flag=  insertarNodo(e,nodo->left); // SI EL ELEMENTO ES MENOR AL NODO BASE SE VA A LA IZQUIERDA
      }else{
        flag= insertarNodo(e,nodo->right); // SI EL ELEMENTO ES MAYOR AL NODO BASE SE VA A LA DERECHA
      }

      if (flag){
        BalancearArbol(nodo); // BALANCEA EL ARBOL EN INSERCION , MUCHO MAS OPTIMO
        fixAltura(nodo); // ACTUALIZA LA ALTURA DEL NODO DESPUES DE BALANCERLO , YA QUE PUEDE VARIAR
      }
      return flag;
  }


public:
  ARBOLITOAVL(void (*imprimir) (int)):raiz(NULL),numNodos(0){ //INICIANDO EL ARBOL CON UN PUNTERO A FUNCION
                                                              //QUE IMPRIMA UN ELEMENTO DEL ARBOL
    this->imprimir = imprimir;
  }


  bool InsertarNuevoNodo(int e){
    return insertarNodo(e,raiz); //SE INSERTA UN NUEVO NODO TENIENDO COMO BASE EL NODO RAIZ
  }

  void ImprimirOrdenadito(){
    imprimirEnOrden(raiz); // SE IMPRIME LOS NODOS EN ORDEN
  }

  int getnumNodos(){
    return numNodos; //OBTIENE EL NUMERO DE NODOS DEL ARBOL
  }

  int alturaArbol(){
    return getAltura(raiz); // ALTURA DEL ARBOL
  }



private:
  Nodo* raiz; //LA RAIZ DEL ARBOL
  int numNodos; //NUMERO NODOS DEL ARBOL
  void (*imprimir)(int); //PUNTERO A FUNCION QUE OBTIENE EL VALOR DEL ARBOL
  int comparar(int a , int b){
      return a-b;  // COMPARA DOS VALORES DEL ARBOL
  }
};

void printTree(int e){
  cout<<" "<<e;
}

int main(int argc, char const *argv[]) {
  ARBOLITOAVL * ArVoL = new ARBOLITOAVL(printTree); //INICIAMOS EL ARBOL CON EL PTR A FUNCION
  ArVoL->InsertarNuevoNodo(5);
  ArVoL->InsertarNuevoNodo(3);
  ArVoL->InsertarNuevoNodo(7);
  ArVoL->InsertarNuevoNodo(77);
  ArVoL->ImprimirOrdenadito();
  cout<<endl;
  cout<<ArVoL->getnumNodos();
  cout<<endl;
  cout<<ArVoL->alturaArbol();


  /*
              5
          3       7
                    77

        altura = 2
        numeronodos = 4
  */
  return 0;
}
