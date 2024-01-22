#include "G.h"
#include <stdio.h>

// Suma de dos números complejos
Gaussiano sumaGaussiano(Gaussiano c1, Gaussiano c2){
  Gaussiano resultado;
    resultado.real = c1.real + c2.real;
    resultado.imaginario = c1.imaginario + c2.imaginario;
    return resultado;
}

// Resta de dos números complejos
Gaussiano restaGaussiano(Gaussiano c1, Gaussiano c2){
  Gaussiano resultado;
    resultado.real = c1.real - c2.real;
    resultado.imaginario = c1.imaginario - c2.imaginario;
    return resultado;
}

// Multiplicación de dos números complejos
Gaussiano multiplicaGaussiano(Gaussiano c1, Gaussiano c2){
  Gaussiano resultado;
  resultado.real = c1.real * c2.real - c1.imaginario * c2.imaginario;
  resultado.imaginario = c1.real * c2.imaginario + c1.imaginario * c2.real;
  return resultado;
}

// División de dos números complejos
Gaussiano divideGaussiano(Gaussiano c1, Gaussiano c2){
  Gaussiano resultado;
  int divisor = c2.real * c2.real + c2.imaginario * c2.imaginario;

    if (divisor != 0) {
        resultado.real = (c1.real * c2.real + c1.imaginario * c2.imaginario) / divisor;
        resultado.imaginario = (c1.imaginario * c2.real - c1.real * c2.imaginario) / divisor;
    } else {
        // Manejar el caso de división por cero
        resultado.real = resultado.imaginario = 0;
    }

    return resultado;
}

void guardaGaussianoEnArchivo(Gaussiano c, const char* nombreArchivo){
  FILE *archivo = fopen(nombreArchivo, "w");
    if (archivo != NULL) {
        fprintf(archivo, "%d %d\n", c.real, c.imaginario);
        fclose(archivo);
    } else {
        printf("Error al abrir el archivo para escritura.\n");
    }
}
Gaussiano cargaGaussianoDesdeArchivo(const char* nombreArchivo){
  Gaussiano r = {0, 1}; // Inicializa con un valor por defecto
  FILE *archivo = fopen(nombreArchivo, "r");
  if (archivo != NULL) {
    fscanf(archivo, "%d %d", &r.real, &r.imaginario);
    fclose(archivo);
  } else {
    printf("Error al abrir el archivo para lectura.\n");
  }
  return r;
}
