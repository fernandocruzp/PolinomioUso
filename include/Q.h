#include <stdio.h>

#ifndef Q_H
#define Q_H

typedef struct {
    int numerador;
    int denominador;
} Racional;

// Funciones para operar con racionales
Racional sumaRacional(Racional r1, Racional r2);
Racional restaRacional(Racional r1, Racional r2);
Racional multiplicaRacional(Racional r1, Racional r2);
Racional divideRacional(Racional r1, Racional r2);
void guardaRacionalEnArchivo(Racional r, const char* nombreArchivo);
Racional cargaRacionalDesdeArchivo(const char* nombreArchivo);


#endif 
