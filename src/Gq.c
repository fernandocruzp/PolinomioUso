#include <stdio.h>
#include "Gq.h"
#include "Q.h"
#include <stdio.h>

// Suma de dos números complejos
Gaussianoq sumaGaussianoq(Gaussianoq c1, Gaussianoq c2){
  Gaussianoq resultado;
  resultado.real = sumaRacional(c1.real, c2.real);
  resultado.imaginario = sumaRacional(c1.imaginario,c2.imaginario);
  return resultado;
}

// Resta de dos números complejos
Gaussianoq restaGaussianoq(Gaussianoq c1, Gaussianoq c2){
  Gaussianoq resultado;
  resultado.real = restaRacional(c1.real, c2.real);
  resultado.imaginario = restaRacional(c1.imaginario, c2.imaginario);
  return resultado;
}

// Multiplicación de dos números complejos
Gaussianoq multiplicaGaussianoq(Gaussianoq c1, Gaussianoq c2){
  Gaussianoq resultado;
  resultado.real = restaRacional(multiplicaRacional(c1.real, c2.real),multiplicaRacional(c1.imaginario,c2.imaginario));
  resultado.imaginario = sumaRacional(multiplicaRacional(c1.real,c2.imaginario),multiplicaRacional(c1.imaginario,c2.real));
  return resultado;
}

// División de dos números complejos
Gaussianoq divideGaussianoq(Gaussianoq c1, Gaussianoq c2){
  Gaussianoq resultado;
  Racional divisor = sumaRacional(multiplicaRacional(c2.real,c2.real),multiplicaRacional(c2.imaginario, c2.imaginario));

    if (divisor.numerador != 0 && divisor.denominador!=0) {
      resultado.real = divideRacional(sumaRacional(multiplicaRacional(c1.real, c2.real),multiplicaRacional(c1.imaginario,c2.imaginario)),divisor);
      resultado.imaginario = divideRacional(restaRacional(multiplicaRacional(c1.imaginario, c2.real),multiplicaRacional(c1.real,c2.imaginario)),divisor);
    } else {
        // Manejar el caso de división por cero
      resultado.real.numerador = resultado.imaginario.numerador = resultado.real.denominador = resultado.imaginario.denominador = 0;
    }

    return resultado;
}

void guardaGaussianoqEnArchivo(Gaussianoq c, const char* nombreArchivo){
  FILE *archivo = fopen(nombreArchivo, "w");
    if (archivo != NULL) {
        fprintf(archivo, "%d/%d +  %d/%d i\n", c.real.numerador, c.real.denominador, c.imaginario.numerador, c.imaginario.denominador);
        fclose(archivo);
    } else {
        printf("Error al abrir el archivo para escritura.\n");
    }
}
Gaussianoq cargaGaussianoqDesdeArchivo(const char* nombreArchivo){
  Gaussianoq r; // Inicializa con un valor por defecto
  FILE *archivo = fopen(nombreArchivo, "r");
  if (archivo != NULL) {
    fscanf(archivo, "%d/%d + %d/%d i", &r.real.numerador, &r.real.denominador, &r.imaginario.numerador, &r.imaginario.denominador);
    fclose(archivo);
  } else {
    printf("Error al abrir el archivo para lectura.\n");
  }
  return r;
}
