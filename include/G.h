#include <stdio.h>

#ifndef G_H
#define G_H

// Estructura para representar un número complejo
typedef struct {
    int real;
    int imaginario;
} Gaussiano;

// Declaraciones de funciones para operaciones con números complejos

// Suma de dos números complejos
Gaussiano sumaGaussiano(Gaussiano c1, Gaussiano c2);

// Resta de dos números complejos
Gaussiano restaGaussiano(Gaussiano c1, Gaussiano c2);

// Multiplicación de dos números complejos
Gaussiano multiplicaGaussiano(Gaussiano c1, Gaussiano c2);

// División de dos números complejos
Gaussiano divideGaussiano(Gaussiano c1, Gaussiano c2);

void guardaGaussianoEnArchivo(Gaussiano c, const char* nombreArchivo);
Gaussiano cargaGaussianoDesdeArchivo(const char* nombreArchivo);
#endif // G_H
