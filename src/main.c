#include "Polinomio.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  Coeficiente coef1,coef2,coef3,coef4;
  coef1.tipo=TIPO_R;
  coef1.conjunto.r.real=2.0;// Ejemplo: coeficiente 2.0
  coef2.tipo=TIPO_R;
  coef2.conjunto.r.real=1.0; // coeficiente 1.0
  coef3.tipo=TIPO_R;
  coef3.conjunto.r.real=3.0;// coeficiente 3.0
  coef4.tipo=TIPO_R;
  coef4.conjunto.r.real=-1.0; // coeficiente -1.0
  
  // Crear algunos polinomios de prueba
  PolinomioNodo *p1 = crearNodo(coef1, 2); // 2x^2
  p1->siguiente = crearNodo(coef2, 0);     // + 1
  PolinomioNodo *p2 = crearNodo(coef3, 1); // 3x
  p2->siguiente = crearNodo(coef4, 0);     // - 1
  escribirPolinomioEnArchivo("poli.txt",p1);
  PolinomioNodo *p3 = leerPolinomioDesdeArchivo("poli.txt");
  escribirPolinomioEnArchivo("poli2.txt",p3);
  // Realizar operaciones
  PolinomioNodo *suma = sumaPol(p1, p2);
  escribirPolinomioEnArchivo("suma.txt", suma);
  PolinomioNodo *resta = restaPol(p1, p2);
  escribirPolinomioEnArchivo("resta.txt", resta);
  
  PolinomioNodo *producto = multPol(p1, p2);
  escribirPolinomioEnArchivo("producto.txt", producto);
  PolinomioNodo *division = divPol(p1, p2); // Asegúrate de manejar la división correctamente
  
  escribirPolinomioEnArchivo("div.txt", division);
  
  
  return 0;
}
