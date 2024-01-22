// H.h
#include <stdio.h>
#ifndef H_H
#define H_H

// Estructura de un cuaternión
typedef struct {
    double a, b, c, d; // Componentes del cuaternión
} Cuaternion;

// Declaraciones de funciones para operaciones de cuaterniones
Cuaternion sumaCuaterniones(Cuaternion q1, Cuaternion q2);
Cuaternion restaCuaterniones(Cuaternion q1, Cuaternion q2);
Cuaternion multiplicaCuaterniones(Cuaternion q1, Cuaternion q2);
Cuaternion divideCuaterniones(Cuaternion q1, Cuaternion q2);

// Funciones para manejar archivos
void guardaCuaternionEnArchivo(Cuaternion q, const char* nombreArchivo);
Cuaternion cargaCuaternionDesdeArchivo(const char* nombreArchivo);

#endif // H_H
