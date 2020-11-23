#include "Pila_max_cola.h"
#include <iostream>

using namespace std;

int main () {
    Pila_max_cola<int> p;
    for (int i=0; i<=10; i++)
        p.poner(i);
    Pila_max_cola<int> otra(p);
    while (!p.vacia()) {
        cout << p.tope() << endl;
        p.quitar();
    }
    cout << "Otra pila" << endl;
    while (!otra.vacia()) {
        cout << otra.tope() << endl;
        otra.quitar();
    }
}