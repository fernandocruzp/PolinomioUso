#include <stdio.h>

#ifndef R_H
#define R_H

typedef struct {
    float real;
} Real;

// Funciones para operar con reales
Real sumaReal(Real r1, Real r2);
Real restaReal(Real r1, Real r2);
Real multiplicaReal(Real r1, Real r2);
Real divideReal(Real r1, Real r2);
void guardaRealEnArchivo(Real r, const char* nombreArchivo);
Real cargaRealDesdeArchivo(const char* nombreArchivo);


#endif 
