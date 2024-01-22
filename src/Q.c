// Q.c

#include "Q.h"
#include <stdio.h>

// Función auxiliar para calcular el máximo común divisor
static int mcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Función auxiliar para simplificar un racional
static Racional simplificar(Racional r) {
    int divisor = mcd(r.numerador, r.denominador);
    r.numerador /= divisor;
    r.denominador /= divisor;
    return r;
}

Racional sumaRacional(Racional r1, Racional r2) {
    Racional resultado;
    resultado.numerador = r1.numerador * r2.denominador + r2.numerador * r1.denominador;
    resultado.denominador = r1.denominador * r2.denominador;
    return simplificar(resultado);
}

Racional restaRacional(Racional r1, Racional r2) {
    Racional resultado;
    resultado.numerador = r1.numerador * r2.denominador - r2.numerador * r1.denominador;
    resultado.denominador = r1.denominador * r2.denominador;
    return simplificar(resultado);
}

Racional multiplicaRacional(Racional r1, Racional r2) {
    Racional resultado;
    resultado.numerador = r1.numerador * r2.numerador;
    resultado.denominador = r1.denominador * r2.denominador;
    return simplificar(resultado);
}

Racional divideRacional(Racional r1, Racional r2) {
    Racional resultado;
    resultado.numerador = r1.numerador * r2.denominador;
    resultado.denominador = r1.denominador * r2.numerador;
    return simplificar(resultado);
}

void guardaRacionalEnArchivo(Racional r, const char* nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "w");
    if (archivo != NULL) {
        fprintf(archivo, "%d %d\n", r.numerador, r.denominador);
        fclose(archivo);
    } else {
        printf("Error al abrir el archivo para escritura.\n");
    }
}

Racional cargaRacionalDesdeArchivo(const char* nombreArchivo) {
    Racional ra;
    FILE *archivo = fopen(nombreArchivo, "r");
    if (archivo != NULL) {
        fscanf(archivo, "%d %d", &ra.numerador, &ra.denominador);
        fclose(archivo);
    } else {
        printf("Error al abrir el archivo para lectura.\n");
    }
    return ra;
}
