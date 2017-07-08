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
  return 0;
}
