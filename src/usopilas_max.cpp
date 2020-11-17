#include "Pila_max_vector.h"
#include <iostream>

using namespace std;

int main () {
    Pila_max_vector<int> p;
    for (int i=10; i>=0; i--)
        p.poner(i);
    while (!p.vacia()) {
        cout << p.tope() << endl;
        p.quitar();
    }
}