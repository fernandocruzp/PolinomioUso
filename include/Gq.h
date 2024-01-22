#include <stdio.h>
#include "Q.h"
#ifndef Gq_H
#define Gq_H


// Estructura para representar un número complejo
typedef struct {
    Racional real;
    Racional imaginario;
} Gaussianoq;

// Declaraciones de funciones para operaciones con números complejos

// Suma de dos números complejos
Gaussianoq sumaGaussianoq(Gaussianoq c1, Gaussianoq c2);

// Resta de dos números complejos
Gaussianoq restaGaussianoq(Gaussianoq c1, Gaussianoq c2);

// Multiplicación de dos números complejos
Gaussianoq multiplicaGaussianoq(Gaussianoq c1, Gaussianoq c2);

// División de dos números complejos
Gaussianoq divideGaussianoq(Gaussianoq c1, Gaussianoq c2);

void guardaGaussianoqEnArchivo(Gaussianoq c, const char* nombreArchivo);
Gaussianoq cargaGaussianoqDesdeArchivo(const char* nombreArchivo);
#endif // G_q
