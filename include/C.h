#include <stdio.h>
#ifndef C_H
#define C_H

// Estructura para representar un número complejo
typedef struct {
    double real;
    double imaginario;
} Complejo;

// Declaraciones de funciones para operaciones con números complejos

// Suma de dos números complejos
Complejo sumaComplejos(Complejo c1, Complejo c2);

// Resta de dos números complejos
Complejo restaComplejos(Complejo c1, Complejo c2);

// Multiplicación de dos números complejos
Complejo multiplicaComplejos(Complejo c1, Complejo c2);

// División de dos números complejos
Complejo divideComplejos(Complejo c1, Complejo c2);

void guardaComplejoEnArchivo(Complejo c, const char* nombreArchivo);
Complejo cargaComplejoDesdeArchivo(const char* nombreArchivo);
#endif // C_H
