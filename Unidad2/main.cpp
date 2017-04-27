#include <iostream>
#include "lista.h"

using namespace std;

ostream& operator << (ostream& os, ListaSE<int>& l) {
  os << "[ ";
  bool ini = true;
  ListaSE<int>::Iterador it;
  for (it = l.inicial(); it != l.ultimo(); it++) {
    os << (ini? "": ", ") << *it;
    ini = false;
  }
  os << " ]";
  return os;
}

int main() {
  ListaSE<int> l;
  for (int i = 0; i < 10; ++i) {
    l.insertarInicio(i);
  }
  cout << l << endl;
  
  return 0;
}
