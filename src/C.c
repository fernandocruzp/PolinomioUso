#include "C.h"
#include <stdio.h>

Complejo sumaComplejos(Complejo c1, Complejo c2) {
    Complejo resultado;
    resultado.real = c1.real + c2.real;
    resultado.imaginario = c1.imaginario + c2.imaginario;
    return resultado;
}

Complejo restaComplejos(Complejo c1, Complejo c2) {
    Complejo resultado;
    resultado.real = c1.real - c2.real;
    resultado.imaginario = c1.imaginario - c2.imaginario;
    return resultado;
}

Complejo multiplicaComplejos(Complejo c1, Complejo c2) {
    Complejo resultado;
    resultado.real = c1.real * c2.real - c1.imaginario * c2.imaginario;
    resultado.imaginario = c1.real * c2.imaginario + c1.imaginario * c2.real;
    return resultado;
}

Complejo divideComplejos(Complejo c1, Complejo c2) {
    Complejo resultado;
    double divisor = c2.real * c2.real + c2.imaginario * c2.imaginario;

    if (divisor != 0) {
        resultado.real = (c1.real * c2.real + c1.imaginario * c2.imaginario) / divisor;
        resultado.imaginario = (c1.imaginario * c2.real - c1.real * c2.imaginario) / divisor;
    } else {
        // Manejar el caso de división por cero
        resultado.real = resultado.imaginario = 0;
    }

    return resultado;
}
void guardaComplejoEnArchivo(Complejo c, const char* nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "w");
    if (archivo != NULL) {
        fprintf(archivo, "%lf %lf\n", c.real, c.imaginario);
        fclose(archivo);
    } else {
        printf("Error al abrir el archivo para escritura.\n");
    }
}

Complejo cargaComplejoDesdeArchivo(const char* nombreArchivo) {
    Complejo c = {0, 1};
    FILE *archivo = fopen(nombreArchivo, "r");
    if (archivo != NULL) {
        fscanf(archivo, "%d %d", &c.real, &c.imaginario);
        fclose(archivo);
    } else {
        printf("Error al abrir el archivo para lectura.\n");
    }
    return c;
}
