using namespace std;

template <typename Tbase> 
bool Pila_max_vector<Tbase>::vacia() const {
    return pila.empty();
}

template <typename Tbase>
ElementoPila<Tbase>& Pila_max_vector<Tbase>::tope() {
    return pila.back();
}

template <typename Tbase>
const ElementoPila<Tbase>& Pila_max_vector<Tbase>::tope() const {
    return pila.back();
}

template <typename Tbase>
void Pila_max_vector<Tbase>::poner (const Tbase& nuevo) {
    ElementoPila<Tbase> elemento_nuevo; elemento_nuevo.elemento = nuevo;
    if (vacia()) {
        elemento_nuevo.maximo = nuevo;
    }
    else
        elemento_nuevo.maximo = tope().maximo;
    if (elemento_nuevo.elemento > elemento_nuevo.maximo)
        elemento_nuevo.maximo = elemento_nuevo.elemento;
    
    pila.push_back(elemento_nuevo);
}

template <typename Tbase>
void Pila_max_vector<Tbase>::quitar () {
    pila.pop_back();
}

template <typename Tbase>
std::ostream& operator<<(std::ostream& out, const ElementoPila<Tbase>& elemento) {
    out << "Elemento: " << elemento.elemento << " // Maximo: " << elemento.maximo;
    return out;
}