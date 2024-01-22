#include "Polinomio.h"
#include <stdio.h>

static PolinomioNodo* simplificar(PolinomioNodo* resultado, Coeficiente nueCoef, int nueExp);
static PolinomioNodo* copiarPoli(PolinomioNodo* p);
PolinomioNodo* crearNodo(Coeficiente coef, int exp) {
    PolinomioNodo* nuevo = (PolinomioNodo*)malloc(sizeof(PolinomioNodo));
    if (nuevo == NULL) {
        return NULL;
    }
    nuevo->valor = coef;
    nuevo->exponente = exp;
    nuevo->siguiente = NULL;
    return nuevo;
}
PolinomioNodo* sumaPol(PolinomioNodo* p1, PolinomioNodo* p2) {
    PolinomioNodo *resultado = NULL, *actual, *tmp;
    while (p1 != NULL && p2 != NULL) {
        if (p1->exponente == p2->exponente) {
            Coeficiente sumCoef = Sumar(p1->valor, p2->valor);
            if (!esCero(sumCoef)) {
                tmp = crearNodo(sumCoef, p1->exponente);
                if (resultado == NULL) {
                    resultado = tmp;
                } else {
                    actual->siguiente = tmp;
                }
                actual = tmp;
            }
            p1 = p1->siguiente;
            p2 = p2->siguiente;
        } else if (p1->exponente > p2->exponente) {
            tmp = crearNodo(p1->valor, p1->exponente);
            if (resultado == NULL) {
                resultado = tmp;
            } else {
                actual->siguiente = tmp;
            }
            actual = tmp;
            p1 = p1->siguiente;
        } else { // p2->exponente > p1->exponente
            tmp = crearNodo(p2->valor, p2->exponente);
            if (resultado == NULL) {
                resultado = tmp;
            } else {
                actual->siguiente = tmp;
            }
            actual = tmp;
            p2 = p2->siguiente;
        }
    }
    while (p1 != NULL) {
        tmp = crearNodo(p1->valor, p1->exponente);
        if (resultado == NULL) {
            resultado = tmp;
        } else {
            actual->siguiente = tmp;
        }
        actual = tmp;
        p1 = p1->siguiente;
    }
    while (p2 != NULL) {
        tmp = crearNodo(p2->valor, p2->exponente);
        if (resultado == NULL) {
            resultado = tmp;
        } else {
            actual->siguiente = tmp;
        }
        actual = tmp;
        p2 = p2->siguiente;
    }

    return resultado;
}

PolinomioNodo* restaPol(PolinomioNodo* p1, PolinomioNodo* p2){
  PolinomioNodo *resultado = NULL, *actual, *tmp;
    while (p1 != NULL && p2 != NULL) {
        if (p1->exponente == p2->exponente) {
            Coeficiente sumCoef = Restar(p1->valor, p2->valor);
            if (!esCero(sumCoef)) {
                tmp = crearNodo(sumCoef, p1->exponente);
                if (resultado == NULL) {
                    resultado = tmp;
                } else {
                    actual->siguiente = tmp;
                }
                actual = tmp;
            }
            p1 = p1->siguiente;
            p2 = p2->siguiente;
        } else if (p1->exponente > p2->exponente) {
            tmp = crearNodo(p1->valor, p1->exponente);
            if (resultado == NULL) {
                resultado = tmp;
            } else {
                actual->siguiente = tmp;
            }
            actual = tmp;
            p1 = p1->siguiente;
        } else { // p2->exponente > p1->exponente
	  Coeficiente resCoef=Restar(Cero(p2->valor.tipo),p2->valor);
            tmp = crearNodo(resCoef, p2->exponente);
            if (resultado == NULL) {
                resultado = tmp;
            } else {
                actual->siguiente = tmp;
            }
            actual = tmp;
            p2 = p2->siguiente;
        }
    }
    while (p1 != NULL) {
        tmp = crearNodo(p1->valor, p1->exponente);
        if (resultado == NULL) {
            resultado = tmp;
        } else {
            actual->siguiente = tmp;
        }
        actual = tmp;
        p1 = p1->siguiente;
    }
    while (p2 != NULL) {
      Coeficiente resCoef=Restar(Cero(p2->valor.tipo),p2->valor);
      tmp = crearNodo(resCoef, p2->exponente);
      if (resultado == NULL) {
	resultado = tmp;
      } else {
	actual->siguiente = tmp;
      }
      actual = tmp;
      p2 = p2->siguiente;
    }

    return resultado;
}
PolinomioNodo* multPol(PolinomioNodo* p1, PolinomioNodo* p2) {
    if (p1 == NULL || p2 == NULL) return NULL;

    PolinomioNodo* resultado = NULL;
    PolinomioNodo* tempP1 = p1;
    PolinomioNodo* tempP2;

    while (tempP1 != NULL) {
        tempP2 = p2;
        while (tempP2 != NULL) {
            Coeficiente nueCoef = Multiplicar(tempP1->valor, tempP2->valor);
            int nueExp = tempP1->exponente + tempP2->exponente;
            resultado = simplificar(resultado, nueCoef, nueExp);
            tempP2 = tempP2->siguiente;
        }
        tempP1 = tempP1->siguiente;
    }
    return resultado;
}
static PolinomioNodo* simplificar(PolinomioNodo* resultado, Coeficiente nueCoef, int nueExp){
  PolinomioNodo* actual= resultado;
  if (actual == NULL) {
    actual = crearNodo(nueCoef, nueExp);
    return actual;
  }
  if(actual->exponente < nueExp){
    PolinomioNodo* nuevo= crearNodo(nueCoef,nueExp);
    nuevo->siguiente=resultado;
    return nuevo;
  }
  do{
    if(actual->exponente == nueExp){
      actual->valor=Sumar(actual->valor,nueCoef);
      return resultado;
    }
    if(actual->siguiente !=NULL){
      actual=actual->siguiente;
    }
  }while(actual->siguiente != NULL);

  PolinomioNodo* nuevo= crearNodo(nueCoef,nueExp);
  actual->siguiente=nuevo;
  return resultado;

}
PolinomioNodo* divPol(PolinomioNodo* p1, PolinomioNodo* p2){
  if(p2==NULL){
    return NULL;
  }

  PolinomioNodo* res =NULL;
  PolinomioNodo* sobrante= copiarPoli(p1);
  while(sobrante != NULL && sobrante->exponente >= p2 -> exponente){
    Coeficiente coef = Dividir(sobrante->valor,p2->valor);
    int exp= sobrante->exponente - p2->exponente;

    res=simplificar(res,coef,exp);
    PolinomioNodo* temp = crearNodo(coef,exp);
    temp=multPol(temp,p2);
    sobrante=restaPol(sobrante,temp);
  }
  return res;
}

static PolinomioNodo* copiarPoli(PolinomioNodo* p) {
    if (p == NULL) {
        return NULL; // Si el polinomio original es NULL, devuelve NULL
    }

    // Reserva memoria para el nodo inicial de la copia
    PolinomioNodo* copia = (PolinomioNodo*)malloc(sizeof(PolinomioNodo));
    if (copia == NULL) {
        return NULL; // Fallo en la asignación de memoria
    }

    // Copia el primer nodo
    copia->valor = p->valor;
    copia->exponente = p->exponente;
    copia->siguiente = NULL; // Importante para evitar que apunte a lugares aleatorios

    PolinomioNodo* actual = p->siguiente;
    PolinomioNodo* nodoCopia = copia;

    // Copia el resto de los nodos
    while (actual != NULL) {
        PolinomioNodo* temp = crearNodo(actual->valor, actual->exponente);
        if (temp == NULL) {
            return NULL; // Fallo en la asignación de memoria
        }
        nodoCopia->siguiente = temp;
        nodoCopia = temp;
        actual = actual->siguiente;
    }

    return copia;
}

PolinomioNodo* leerPolinomioDesdeArchivo(const char* nombreArchivo) {
    FILE *file = fopen(nombreArchivo, "r");
    if (file == NULL) {
        perror("Error al abrir el archivo");
        return NULL;
    }

    TipoConjunto tipo;
    if (fscanf(file, "%u\n", &tipo) != 1) {
        fclose(file);
        return NULL;  // Error leyendo el tipo de coeficiente
    }

    PolinomioNodo* cabeza = NULL;
    PolinomioNodo* actual = NULL;

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file)) {
        // Encuentra el último espacio para separar el exponente del coeficiente
        char *espacio = strrchr(buffer, ' ');
        if (!espacio) {
            // Error en el formato de la línea
            continue;
        }

        int exp;
        if (sscanf(espacio + 1, "%d", &exp) != 1) {
            // Error leyendo el exponente
            continue;
        }

        // Finaliza el string del coeficiente justo antes del espacio
        *espacio = '\0';
        Coeficiente coef = leer(tipo, buffer);

        PolinomioNodo* nuevoNodo = crearNodo(coef, exp);
        if (cabeza == NULL) {
            cabeza = nuevoNodo;
        } else {
            actual->siguiente = nuevoNodo;
        }
        actual = nuevoNodo;
    }

    fclose(file);
    return cabeza;
}

void escribirPolinomioEnArchivo(const char* nombreArchivo, PolinomioNodo* p){
  FILE* archivo = fopen(nombreArchivo, "w");
  if (!archivo) {
    perror("Error al abrir el archivo");
    return;
  }
  PolinomioNodo* actual=p;
  fprintf(archivo, "%d\n", actual->valor.tipo);
  while (actual != NULL) {
    char* coeficienteStr=cadena(actual->valor);
    fprintf(archivo, "%s, %d\n", coeficienteStr, actual->exponente);
    free(coeficienteStr);
    // Avanzar al siguiente nodo
    actual = actual->siguiente;
  }
  fclose(archivo);
}
