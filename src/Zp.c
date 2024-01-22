// Zp.c
#include "Zp.h"
#include <stdio.h>
static int inversoMultiplicativo(int a, int m);
Zp crearZp(int valor, int p) {
    Zp z;
    z.valor = valor % p;
    z.p = p;
    return z;
}

Zp sumaZp(Zp a, Zp b) {
    return crearZp((a.valor + b.valor) % a.p, a.p);
}

Zp restaZp(Zp a, Zp b) {
    return crearZp((a.valor - b.valor + a.p) % a.p, a.p);
}

Zp multiplicacionZp(Zp a, Zp b) {
    return crearZp((a.valor * b.valor) % a.p, a.p);
}

// La división requiere encontrar el inverso multiplicativo de b

Zp divisionZp(Zp a, Zp b) {
    // Primero, verificamos que b no sea cero
    if (b.valor == 0) {
        printf("Error: División por cero.\n");
        return crearZp(0, b.p); // Retorna un valor de error
    }

    int inverso = inversoMultiplicativo(b.valor, b.p);
    if (inverso == -1) {
        printf("Error: No existe inverso multiplicativo.\n");
        return crearZp(0, b.p); // Retorna un valor de error
    }

    return crearZp((a.valor * inverso) % a.p, a.p);
}


// Función auxiliar para encontrar el inverso multiplicativo
static int inversoMultiplicativo(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1; // No existe inverso si retorna -1
}



Zp leerZpDeArchivo(const char* nombreArchivo) {
  Zp r = {0, 1}; // Inicializa con un valor por defecto
  FILE *archivo = fopen(nombreArchivo, "r");
  if (archivo != NULL) {
    fscanf(archivo, "%d %d", &r.valor, &r.p);
    fclose(archivo);
  } else {
    printf("Error al abrir el archivo para lectura.\n");
  }
  return r;
}

void escribirZpEnArchivo(const char* nombreArchivo, Zp zp) {
    FILE *file = fopen(nombreArchivo, "a"); // 'a' para añadir al final del archivo
    if (file == NULL) {
        perror("Error al abrir el archivo para escribir");
        return;
    }

    fprintf(file, "%d %d\n", zp.valor, zp.p);
    fclose(file);
}
