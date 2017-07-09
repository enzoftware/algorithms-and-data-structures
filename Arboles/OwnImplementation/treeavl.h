#include <cstddef>
template<class T>
struct Node{
  T element;
  Node* leftSon;
  Node* rightSon ;
  int height;
  Node(){
     height = 0;
     rightSon = NULL;
     leftSon = NULL;
  }
};

template<class T>
class BinaryTree{
  Node<T>* root;
  void (*process)(T);  // Templates of fuctions that print and
  int (*compare)(T,T);// compare to be easy to implement.

  bool _insert(Node<T>*& node , T e){
    if(node == NULL){
      node = new Node<T>;
      node->element = e;
    }else if(compare(e, node->element) < 0){
      _insert(node->leftSon , e);
    }else{
      _insert(node->rightSon,e);
    }


  }

int _heightTree(Node<T>* node){
  if(node == NULL) return -1;
  return node->height;
}

T _search(Node<T>* node , T e){
  if(node == NULL) return 0;
  if(compare(e,node->element) == 0){
    return node->element;
  }else{
    return _search(compare(e,node->element) > 0 ? node->rightSon : node->leftSon , e);
  }
}

void _inOrder(Node<T>* node){
  if(node == NULL) return;
  _inOrder(node->leftSon);
  process(node->element);
  _inOrder(node->rightSon);
}

//-><--><--><--><--><--><--><--><--><--><--><--><--><--><--><--><--><--><--><--><--><-
//TODO : Delete a node and balance the tree
//-><--><--><--><--><--><--><--><--><--><--><--><--><--><--><--><--><--><--><--><--><-

void _rotateLeft(Node<T>*& x ,Node<T>*& y ,Node<T>*& father ){
  father = y;
  x->rightSon = y->leftSon;
  father->leftSon = x;
}

void _rotateRight(Node<T>*& x ,Node<T>*& y ,Node<T>*& father){
  father = x;
  y->leftSon = x->rightSon;
  father->rightSon = y;
}


Node<T>* _quitMin(Node<T>*node , Node<T>*& vinc){
  if(node == NULL) return NULL;
  if(node->leftSon == NULL){ // Alredy found the min
      vinc = node->rightSon;
      node->rightSon = NULL;
      return node;
  }else{
    return _quitMin(node->leftSon,node->leftSon);
  }
}

  Node<T>* _quitMax(Node<T>*node , Node<T>*& vinc){
    if(node == NULL) return NULL;
    if(node->rightSon == NULL){ // Alredy found the min
        vinc = node->leftSon;
        node->leftSon = NULL;
        return node;
    }else{
      return _quitMax(node->rightSon,node->rightSon);
    }
}

bool _deleteThis(T e , Node<T>* node , Node<T>*& vinc){
    if(compare(e,node->element) == 0){
      int hl = _heightTree(node->leftSon);
      int hr = _heightTree(node->rightSon);
      if(hl == -1 && hr == -1){
        vinc = NULL;
        delete node;
        return true;
      }
      else if(hl > hr){
        Node<T>* replace = _quitMax(node->leftSon,node->leftSon);
        replace->leftSon = node->leftSon;
        replace->rightSon = node->rightSon;
        vinc = replace;
        delete node;
      }
      else{
        Node<T>* replace = _quitMin(node->rightSon, node->rightSon);
        replace->leftSon = node->leftSon;
        replace->rightSon = node->rightSon;
        vinc = replace;
        delete node;
      }
    }
    else if(compare(e,node->element) > 0 && node->rightSon != NULL){
      return _deleteThis(e,node->rightSon, node->rightSon);
    }
    else if(compare(e,node->element) > 0 && node->leftSon != NULL){
      return _deleteThis(e,node->leftSon,node->leftSon);
    }
    else{
      return false;
    }
}



public:
  BinaryTree(void (*processF)(T),int (*compareF)(T,T) ){
    this->process = processF;
    this->compare = compareF;
    root = NULL;
  }

  bool insertElement(T e){
    return _insert(root,e);
  }

  void OrderTree(){
    _inOrder(root);
  }

  int getHeight(){
    _heightTree(root);
  }

  T searchElement(T e){
    return _search(root,e);
  }

  bool deleteElement(T e){
    return _deleteThis(e,root,root);
  }


};
