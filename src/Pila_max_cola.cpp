using namespace std;

template <typename Tbase>
bool Pila_max_cola<Tbase>::vacia() const {
    return pila.vacia();
}

template <typename Tbase>
ElementoPila<Tbase>& Pila_max_cola<Tbase>::tope() {
    return pila.frente();
}

template <typename Tbase>
const ElementoPila<Tbase>& Pila_max_cola<Tbase>::tope() const {
    return pila.frente();
}

template <typename Tbase>
void Pila_max_cola<Tbase>::poner(const Tbase& nuevo) {
    ElementoPila<Tbase> nuevo_elemento;
    nuevo_elemento.elemento = nuevo;
    if (pila.vacia())
        nuevo_elemento.maximo = nuevo;
    else 
        nuevo_elemento.maximo = max(nuevo, tope().maximo);
    Cola<ElementoPila<Tbase>> aux;
    aux.poner(nuevo_elemento);
    while (!pila.vacia()) {
        aux.poner(pila.frente());
        pila.quitar();
    }
    pila = aux;
}

template <typename Tbase>
void Pila_max_cola<Tbase>::quitar() {
    pila.quitar();
}


template <typename Tbase>
ostream& operator<<(ostream& out, const ElementoPila<Tbase>& elemento) {
    out << "Elemento: " << elemento.elemento << " // Maximo: " << elemento.maximo;
    return out;
}
