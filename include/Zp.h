// Zp.h
#include <stdio.h>

#ifndef ZP_H
#define ZP_H

typedef struct {
    int valor;
    int p; // El módulo
} Zp;

Zp crearZp(int valor, int p);
Zp sumaZp(Zp a, Zp b);
Zp restaZp(Zp a, Zp b);
Zp multiplicacionZp(Zp a, Zp b);
Zp divisionZp(Zp a, Zp b); // Asegúrate de manejar la división por cero
Zp leerZpDesdeArchivo(const char* nombreArchivo);
void escribirZpEnArchivo(const char* nombreArchivo, Zp zp);

#endif // ZP_H
