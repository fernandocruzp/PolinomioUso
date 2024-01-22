#include <stdbool.h>
#include <stdlib.h>
#include "Q.h"
#include "R.h"
#include "H.h"
#include "C.h"
#include "Zp.h"
#include "G.h"
#include "Gq.h"
#ifndef COEFICIENTE_H
#define COEFICIENTE_H
#ifdef __cplusplus
extern "C" {
#endif
typedef enum {
    TIPO_Q,   // Conjunto de los racionales
    TIPO_R,   // Conjunto de los reales
    TIPO_H,   // Conjunto de los cuaterniones
    TIPO_ZP,  // Conjunto Zp
    TIPO_C,    // Conjunto de los complejos
    TIPO_G,  // Conjunto Zp
    TIPO_Gq    // Conjunto de los complejos
} TipoConjunto;

typedef union {
  Racional q;
  Real r;
  Cuaternion h;
  Zp zp;
  Complejo c;
  Gaussiano g;
  Gaussianoq gq;

} UnionConjunto;

typedef struct {
    TipoConjunto tipo;
    UnionConjunto conjunto;
} Coeficiente;

char* cadena(Coeficiente coef);
Coeficiente leer(TipoConjunto tipo, char* c);
Coeficiente Sumar(Coeficiente a, Coeficiente b);
Coeficiente Restar(Coeficiente a, Coeficiente b);
Coeficiente Multiplicar(Coeficiente a, Coeficiente b);
Coeficiente Dividir(Coeficiente a, Coeficiente b);
Coeficiente Cero(TipoConjunto tipo);
bool esCero(Coeficiente c);
#ifdef __cplusplus
}
#endif
#endif // COEFICIENTE_H
