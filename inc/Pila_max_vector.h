/**
 * @file Pila_max_cola.h
 * @brief Fichero cabecera del TDA Pila_max_Cola
 * 
 * Gestiona una pila de elementos que almacena además el máximo de la pila. Para
 * su implementación, usaremos la implementación de la cola (Módulo cola) concedida
 */

#ifndef __Pila_max_cola_H__
#define __Pila_max_cola_H__

#include "cola.h"
#include <cassert>
#include <vector>
#include <iostream>

/**
 * @brief T.D.A ElementoPila
 * 
 * Una estructura @e E del tipo de dato abstracto ElementoPila sobre un dominio
 * @e Tbase es un par de datos de tipo Tbase que serán posteriormente parte de la
 * clase @e Pila_max_vector, y que nos indicarán el @e elemento que se apila, y el
 * @e máximo elemento que podemos encontrar en la pila hasta la inserción del mismo.
 * 
 * @author Fernando Luque
 * @date Noviembre 2020
 */
template <typename Tbase>
struct ElementoPila {
    Tbase elemento;
    Tbase maximo;
};

/**
 * @brief Operador de salida por flujo de datos del tipo @e ElementoPila sobre un
 * dominio @e Tbase
 * @param out El flujo de salida
 * @param elemento El elemento a introducir en el flujo
 * @return El flujo para sentencias concatenadas
 * @pre Debe estar implementado el flujo de salida para la clase (o tipo de dato) Tbase
 */
template <typename Tbase>
std::ostream& operator<<(std::ostream& out, const ElementoPila<Tbase>& elemento);

/**
 * @brief TDA Pila_max_vector
 * 
 * Una instancia @e p del tipo de dato abstracto Pila sobre un dominio @e Tbase
 * es una sucesión finita de elementos con un funcionamiento @e LIFO (Last In, First Out).
 * En una pila, las operaciones tanto de inserción, extracción y consulta, tienen lugar en
 * un sólo extremo, denominado el @e tope de la cola. Una cola de lungitud @e n la denotamos
 * 
 * - >a1, a2, a3, ..., an>
 * 
 * En esta pila, tendremos acceso únicamente al elemento del @e tope, es decir, al elemento
 * @e an, tope de la pila.
 * 
 * Si n=0, diremos que la pila está vacía
 * 
 * @author Fernando Luque
 * @date Noviembre 2020
 */
template <typename Tbase>
class Pila_max_vector {
    private:
    std::vector <ElementoPila<Tbase>> pila;     ///< Elemento que almacenará los datos de tipo ElementoPila

    public:
    /**
     * @brief Constructor por defecto
     * 
     * No necesita ninguna implementación pues usará el constructor de la clase vector de la STL
     */
    Pila_max_vector() = default;
    /**
     * @brief Constructor de copia
     * 
     * Ídem @see Constructor por defecto
     */
    Pila_max_vector(const Pila_max_vector<Tbase>& otra) = default;
    /**
     * @brief Destructor por defecto
     * 
     * No necesita ninguna implementación pues usará el destructor de la clase vector de la STL
     */
    ~Pila_max_vector() = default;

    /**
     * @brief Operador de asignación
     * @param otra La pila a copiar
     * @return Referencia a la pila copiada (para asignaciones concatenadas)
     * 
     * No necesita ninguna implementación porque usará también la asignación de la clase vector de la STL
     */
    Pila_max_vector& operator=(const Pila_max_vector<Tbase>& otra) = default;
    
    /**
     * @brief Comprueba si la cola está vacía
     * @return true si lo está, false si no
     */
    bool vacia() const;

    /**
     * @brief Devuelve el elemento del tope de la pila
     * @return El último elemento del vector (tope de la pila)
     */
    ElementoPila<Tbase>& tope();
    /**
     * @brief Devuelve el elemento del tope de una pila constante
     * @return El último elemento del vector (tope de la pila)
     */
    const ElementoPila<Tbase>& tope() const;

    /**
     * @brief Añade un elemento por encima del tope de la pila
     * @param nuevo El dato de tipo Tbase
     * 
     * Se compara si el nuevo elemento supera al máximo, si lo hace, él será el nuevo máximo
     */
    void poner(const Tbase& nuevo);
    /**
     * @brief Elimina el elemento tope de la pila
     * 
     * Si este era el máximo, el máximo del elemento que pasa a ser el tope será el nuevo máximo
     */
    void quitar();

};


#include "../src/Pila_max_vector.cpp"
#endif