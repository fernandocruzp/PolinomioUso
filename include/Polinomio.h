#include "Coeficiente.h"
#include <stdio.h>
#include <string.h>
#ifndef Coeficiente_H
#define Coeficiente_H
#ifdef __cplusplus
}
#endif
typedef struct PolinomioNodo{
  Coeficiente valor;
  int exponente;
  struct PolinomioNodo* siguiente;
} PolinomioNodo;

PolinomioNodo* crearNodo(Coeficiente coef, int exp);
PolinomioNodo* sumaPol(PolinomioNodo* p1, PolinomioNodo* p2);
PolinomioNodo* restaPol(PolinomioNodo* p1, PolinomioNodo* p2);
PolinomioNodo* multPol(PolinomioNodo* p1, PolinomioNodo* p2);
PolinomioNodo* divPol(PolinomioNodo* p1, PolinomioNodo* p2);
PolinomioNodo* leerPolinomioDesdeArchivo(const char* nombreArchivo);
void escribirPolinomioEnArchivo(const char* nombreArchivo, PolinomioNodo* p);

#endif // ZP_H
