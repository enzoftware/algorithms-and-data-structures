#include <iostream>
#include "treeavl.h"
using namespace std;

void printTree(int e){
  cout<<" "<<e;
}

int compareElements(int a , int b){
  return a - b;
}

int main(){
  BinaryTree<int>* btree = new BinaryTree<int>(printTree,compareElements);
  btree->insertElement(5);
  btree->insertElement(52);
  btree->insertElement(1);
  btree->insertElement(100);
  btree->insertElement(5);
  btree->insertElement(5);
  btree->insertElement(5);
  btree->insertElement(5);
  btree->insertElement(50000);
  btree->insertElement(10);
  btree->OrderTree();
  cout<<endl;
  btree->deleteElement(1);
  btree->OrderTree();
  return 0;
}
/*
int hl = _heightTree(node->leftSon);
int hr = _heightTree(node->rightSon);
int d = hr-hl;
if(d > 1){ // heavy to right
    int hnl = _heightTree(node->rightSon->leftSon);
    int hnr = _heightTree(node->rightSon->rightSon);
    if(hnl > hnr){ // zigzag rig to lef
        _rotateRight(node->rightSon->leftSon, node->rightSon , node->rightSon);
    }
    _rotateLeft(node,node->rightSon,node);
}
else if(d < -1){ //heavy to left
    int hnl = _heightTree(node->leftSon->leftSon);
    int hnr = _heightTree(node->leftSon->rightSon);
    if(hnr > hnl){ //zigzag lef to rig
      _rotateLeft(node->leftSon,node->leftSon->rightSon, node->leftSon);
    }
    _rotateRight(node->leftSon,node,node);
}
hl = _heightTree(node->leftSon);
hr = _heightTree(node->rightSon);
node->height =1+ (hl > hr ? hl : hr);
return true;
*/
