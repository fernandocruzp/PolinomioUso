// H.c

#include "H.h"
#include <stdio.h>

// Implementación de las operaciones de cuaterniones

Cuaternion sumaCuaterniones(Cuaternion q1, Cuaternion q2) {
    Cuaternion resultado = {q1.a + q2.a, q1.b + q2.b, q1.c + q2.c, q1.d + q2.d};
    return resultado;
}

Cuaternion restaCuaterniones(Cuaternion q1, Cuaternion q2) {
    Cuaternion resultado = {q1.a - q2.a, q1.b - q2.b, q1.c - q2.c, q1.d - q2.d};
    return resultado;
}

Cuaternion multiplicaCuaterniones(Cuaternion q1, Cuaternion q2){
  Cuaternion resultado;
  resultado.a=(q1.a*q2.a - q1.b*q2.b - q1.c*q2.c- q1.d*q2.d);
  resultado.b=(q1.a*q2.b+q1.b*q2.a+q1.c*q2.d- q1.d*q2.c);
  resultado.c=(q1.a*q2.c-q1.b*q2.d + q1.c*q2.a+q1.d*q2.b);
  resultado.d=(q1.a*q2.d + q1.b*q2.c-q1.c*q2.b+q1.d*q2.a);
  return resultado;
}
Cuaternion divideCuaterniones(Cuaternion q1, Cuaternion q2){
  return multiplicaCuaterniones(q1,q2);
}


// Funciones para manejar archivos

void guardaCuaternionEnArchivo(Cuaternion q, const char* nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "w");
    if (archivo != NULL) {
        fprintf(archivo, "%lf %lf %lf %lf\n", q.a, q.b, q.c, q.d);
        fclose(archivo);
    } else {
        printf("Error al abrir el archivo para escritura.\n");
    }
}

Cuaternion cargaCuaternionDesdeArchivo(const char* nombreArchivo) {
    Cuaternion q = {0, 0, 0, 0}; // Inicializa con valores por defecto
    FILE *archivo = fopen(nombreArchivo, "r");
    if (archivo != NULL) {
        fscanf(archivo, "%lf %lf %lf %lf", &q.a, &q.b, &q.c, &q.d);
        fclose(archivo);
    } else {
        printf("Error al abrir el archivo para lectura.\n");
    }
    return q;
}
