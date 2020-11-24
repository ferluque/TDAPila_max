#include<iostream>
#ifndef CUAL_COMPILA
#define CUAL_COMPILA 3
#endif
#if CUAL_COMPILA == 1
#include "Pila_max_vector.h"
#elif CUAL_COMPILA == 2
#include "Pila_max_cola.h"
#endif
