#include <cstddef>
template<class T>
struct Node{
  T element;
  Node* leftSon;
  Node* rightSon;
  int height;
};

template<class T>
class BinaryTree{
  Node<T>* root;
  void (*process)(T);
  int (*compare)(T,T);

  bool _insert(Node<T>*& node , T e){
    if(node == NULL){
      node = new Node<T>;
      node->element = e;
    }else if(compare(e, node->element) < 0){
      _insertar(node->leftSon , e);
    }else{
      _insertar(node->rightSon,e);
    }
  }

int _heightTree(Node<T>* node){
  if(node == NULL) return -1;
  return node->h;
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
public:
  BinaryTree(void (*processF)(T),int (*compareF)(T,T) ){
    this->process = processF;
    this->compare = compareF;
    root = NULL;
  }
};
