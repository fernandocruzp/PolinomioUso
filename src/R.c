#include "R.h"
#include <stdio.h>
Real sumaReal(Real r1, Real r2){
  Real res;
  res.real=r1.real + r2.real;
  return res;
}
Real restaReal(Real r1, Real r2){
  Real res;
  res.real=r1.real - r2.real;
  return res;
}
Real multiplicaReal(Real r1, Real r2){
  Real res;
  res.real=r1.real * r2.real;
  return res;
}
Real divideReal(Real r1, Real r2){
  Real res;
  res.real=r1.real / r2.real;
  return res;
}
void guardaRealEnArchivo(Real r, const char* nombreArchivo){
  FILE *archivo = fopen(nombreArchivo, "w");
    if (archivo != NULL) {
        fprintf(archivo, "%d\n", r.real);
        fclose(archivo);
    } else {
        printf("Error al abrir el archivo para escritura.\n");
    }
}
Real cargaRealDesdeArchivo(const char* nombreArchivo){
  Real r = {0}; // Inicializa con un valor por defecto
  FILE *archivo = fopen(nombreArchivo, "r");
  if (archivo != NULL) {
    fscanf(archivo, "%d", &r.real);
    fclose(archivo);
  } else {
    printf("Error al abrir el archivo para lectura.\n");
  }
  return r;
}
