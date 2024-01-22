#include "Coeficiente.h"
#include <stdio.h>

Coeficiente leer(TipoConjunto tipo, char* str){
      Coeficiente coef;
      coef.tipo=tipo;
      switch (tipo) {
        case TIPO_Q:
	 Racional r;
	 sscanf(str, "%d/%d", &r.numerador, &r.denominador);
	 coef.conjunto.q=r;
	 break;
        case TIPO_R:
	   Real real;
	   sscanf(str, "%f", &real.real);
	   coef.conjunto.r=real;
	   break;
        case TIPO_H:
	  Cuaternion h;
	  sscanf(str, "%.2fa + %.2fb + %.2fc + %.2fd", &h.a, &h.b, &h.c, &h.d);
	  coef.conjunto.h=h;
	  break;
        case TIPO_ZP:
	   Zp z;
	   sscanf(str, "%d (mod %d)", &z.valor, &z.p);
	   coef.conjunto.zp=z;
	   break;
        case TIPO_C:
	   Complejo c;
	   sscanf(str, "%lf + %lfi", &c.real, &c.imaginario);
	   coef.conjunto.c=c;
	   break;
        case TIPO_G:
	  Gaussiano g;
	  sscanf(str, "%d + %di", &g.real, &g.imaginario);
	  coef.conjunto.g=g;
	  break;
        case TIPO_Gq:
	   Gaussianoq gq;
	   sscanf(str, "%d/%d + %d/%di", &gq.real.numerador, &gq.real.denominador, &gq.imaginario.numerador, &gq.imaginario.denominador);
	   coef.conjunto.gq=gq;
	   break;
        default:
	  break;
      }
      return coef;
}

Coeficiente Sumar(Coeficiente a, Coeficiente b){
  Coeficiente resultado;
  if(a.tipo!=b.tipo){
    return a;
  }
  switch (a.tipo) {
        case TIPO_Q:
            resultado.conjunto.q = sumaRacional(a.conjunto.q, b.conjunto.q);
            break;
        case TIPO_R:
            resultado.conjunto.r = sumaReal(a.conjunto.r, b.conjunto.r);
            break;
	case TIPO_H:
            resultado.conjunto.h = sumaCuaterniones(a.conjunto.h, b.conjunto.h);
            break;
        case TIPO_ZP:
            resultado.conjunto.zp = sumaZp(a.conjunto.zp, b.conjunto.zp);
            break;
	case TIPO_C:
            resultado.conjunto.c = sumaComplejos(a.conjunto.c, b.conjunto.c);
            break;
        case TIPO_G:
            resultado.conjunto.g = sumaGaussiano(a.conjunto.g, b.conjunto.g);
            break;
	case TIPO_Gq:
            resultado.conjunto.gq = sumaGaussianoq(a.conjunto.gq, b.conjunto.gq);
            break;
        default:
            break;
    }

    resultado.tipo = a.tipo; // El tipo del resultado será el mismo que el de los operandos
    return resultado;
}
Coeficiente Restar(Coeficiente a, Coeficiente b){
  Coeficiente resultado;
  if(a.tipo!=b.tipo){
    return a;
  }
  switch (a.tipo) {
        case TIPO_Q:
            resultado.conjunto.q = restaRacional(a.conjunto.q, b.conjunto.q);
            break;
        case TIPO_R:
            resultado.conjunto.r = restaReal(a.conjunto.r, b.conjunto.r);
            break;
	case TIPO_H:
            resultado.conjunto.h = restaCuaterniones(a.conjunto.h, b.conjunto.h);
            break;
        case TIPO_ZP:
            resultado.conjunto.zp = restaZp(a.conjunto.zp, b.conjunto.zp);
            break;
	case TIPO_C:
            resultado.conjunto.c = restaComplejos(a.conjunto.c, b.conjunto.c);
            break;
        case TIPO_G:
            resultado.conjunto.g = restaGaussiano(a.conjunto.g, b.conjunto.g);
            break;
	case TIPO_Gq:
            resultado.conjunto.gq = restaGaussianoq(a.conjunto.gq, b.conjunto.gq);
            break;
        default:
            break;
    }

    resultado.tipo = a.tipo; // El tipo del resultado será el mismo que el de los operandos
    return resultado;
}
Coeficiente Multiplicar(Coeficiente a, Coeficiente b){
  Coeficiente resultado;
  if(a.tipo!=b.tipo){
    return a;
  }
  switch (a.tipo) {
        case TIPO_Q:
            resultado.conjunto.q = multiplicaRacional(a.conjunto.q, b.conjunto.q);
            break;
        case TIPO_R:
            resultado.conjunto.r = multiplicaReal(a.conjunto.r, b.conjunto.r);
            break;
	case TIPO_H:
            resultado.conjunto.h = multiplicaCuaterniones(a.conjunto.h, b.conjunto.h);
            break;
        case TIPO_ZP:
            resultado.conjunto.zp = multiplicacionZp(a.conjunto.zp, b.conjunto.zp);
            break;
	case TIPO_C:
            resultado.conjunto.c = multiplicaComplejos(a.conjunto.c, b.conjunto.c);
            break;
        case TIPO_G:
            resultado.conjunto.g = multiplicaGaussiano(a.conjunto.g, b.conjunto.g);
            break;
	case TIPO_Gq:
            resultado.conjunto.gq = multiplicaGaussianoq(a.conjunto.gq, b.conjunto.gq);
            break;
        default:
            break;
    }

    resultado.tipo = a.tipo; // El tipo del resultado será el mismo que el de los operandos
    return resultado;
}
Coeficiente Dividir(Coeficiente a, Coeficiente b){
  Coeficiente resultado;
if(a.tipo!=b.tipo){
    return a;
  }
  switch (a.tipo) {
        case TIPO_Q:
            resultado.conjunto.q = divideRacional(a.conjunto.q, b.conjunto.q);
            break;
        case TIPO_R:
            resultado.conjunto.r = divideReal(a.conjunto.r, b.conjunto.r);
            break;
	case TIPO_H:
            resultado.conjunto.h = divideCuaterniones(a.conjunto.h, b.conjunto.h);
            break;
        case TIPO_ZP:
            resultado.conjunto.zp = divisionZp(a.conjunto.zp, b.conjunto.zp);
            break;
	case TIPO_C:
            resultado.conjunto.c = divideComplejos(a.conjunto.c, b.conjunto.c);
            break;
        case TIPO_G:
            resultado.conjunto.g = divideGaussiano(a.conjunto.g, b.conjunto.g);
            break;
	case TIPO_Gq:
            resultado.conjunto.gq = divideGaussianoq(a.conjunto.gq, b.conjunto.gq);
            break;
        default:
            break;
    }

    resultado.tipo = a.tipo; // El tipo del resultado será el mismo que el de los operandos
    return resultado;
}

Coeficiente Cero(TipoConjunto tipo){
  Coeficiente coef;
    coef.tipo = tipo;

    switch (tipo) {
        case TIPO_Q:
	  coef.conjunto.q.numerador = coef.conjunto.q.denominador = 0;
            break;
        case TIPO_R:
	  coef.conjunto.r.real=0;
            break;
        case TIPO_H:
	  coef.conjunto.h.a = coef.conjunto.h.b= coef.conjunto.h.c = coef.conjunto.h.d= 0;
            break;
        case TIPO_ZP:
	  coef.conjunto.zp.valor =0;
            break;
        case TIPO_C:
	  coef.conjunto.c.real=coef.conjunto.c.imaginario=0;
            break;
        case TIPO_G:
	  coef.conjunto.g.real=coef.conjunto.g.imaginario=0;
            break;
        case TIPO_Gq:
	  coef.conjunto.gq.real.numerador=coef.conjunto.gq.imaginario.numerador=coef.conjunto.gq.real.denominador=coef.conjunto.gq.imaginario.denominador=0;
            break;
        default:

            break;
    }

    return coef;
}

bool esCero(Coeficiente coef) {
    switch (coef.tipo) {
        case TIPO_Q:
            return coef.conjunto.q.numerador == 0;
        case TIPO_R:
            return coef.conjunto.r.real == 0;
        case TIPO_H:
            return coef.conjunto.h.a == 0 && coef.conjunto.h.b == 0 &&
                   coef.conjunto.h.c == 0 && coef.conjunto.h.d == 0;
        case TIPO_ZP:
            return coef.conjunto.zp.valor == 0;
        case TIPO_C:
            return coef.conjunto.c.real == 0 && coef.conjunto.c.imaginario == 0;
        case TIPO_G:
            return coef.conjunto.g.real == 0 && coef.conjunto.g.imaginario == 0;
        case TIPO_Gq:
            return coef.conjunto.gq.real.numerador == 0 && coef.conjunto.gq.imaginario.numerador == 0 &&
                   coef.conjunto.gq.real.denominador != 0 && coef.conjunto.gq.imaginario.denominador != 0;
        default:

            return false;
    }
}

    char* cadena(Coeficiente coef){
      char* str = malloc(100);
      if (str == NULL) {
        return NULL;
      }
      switch (coef.tipo) {
        case TIPO_Q:
	  sprintf(str, "%d/%d",coef.conjunto.q.numerador, coef.conjunto.q.denominador);
	  break;
        case TIPO_R:
	  sprintf(str, "%.2f",coef.conjunto.r.real);
	  break;
        case TIPO_H:
	  sprintf(str, "%.2fa + %.2fb + %.2fc + %.2fd", coef.conjunto.h.a,coef.conjunto.h.b,coef.conjunto.h.c,coef.conjunto.h.d);
	  break;
        case TIPO_ZP:
	   sprintf(str, "%d (mod %d)", coef.conjunto.zp.valor, coef.conjunto.zp.p);
	   break;
        case TIPO_C:
	   sprintf(str, "%.2f + %.2fi", coef.conjunto.c.real, coef.conjunto.c.imaginario);
	   break;
        case TIPO_G:
	   sprintf(str, "%d + %di",coef.conjunto.g.real, coef.conjunto.g.imaginario);
	   break;
        case TIPO_Gq:
	   sprintf(str, "%d/%d + %d/%di",coef.conjunto.gq.real, coef.conjunto.gq.imaginario);
	   break;
        default:
	  break;
      }
      return str;
    }
    

