#include <iostream>
#include <cstdlib>
#include "avl.h"

using namespace std;

int main() {
    AVLTree<long long>* t = new AVLTree<long long>(
        [](long long a) { cout << a << " "; },
        [](long long a, int b) { return a - b; }
    );
    srand(2017);
    for (int i = 0; i < 10000000; ++i) {
        long long val = rand() % 10000000;
        t->insertar(val);
    }
    // t->enOrden();
    cout << "\nNumero de elementos:" << t->size() << endl;
    cout << "Altura:" << t->height() << endl;
    return 0;
}
