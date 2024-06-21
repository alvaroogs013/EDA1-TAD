#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "pila.h"



int pilaCreaVacia(Pila *p)
{
    Pila pila = &p;
    if (p == NULL) 
		return -2;
    else if (NULL == (pila = (tipoCelda *)malloc(sizeof(tipoCelda)))) 
		return -1;
    else {
        pila->sig = NULL;
        return 0;
    }
}

int pilaVacia(Pila *p)
{
	if (p == NULL) 
		return 1;
    else 
		return 0;
}

int pilaInserta(Pila *p,tipoElemento elemento)
{
    Pila nuevaPosicion = &p;
    if (pilaVacia(p)) 
		return -1;
    if(NULL == (nuevaPosicion->sig = malloc(sizeof(tipoCelda)))) 
		return -2;
    nuevaPosicion = nuevaPosicion->sig;
    nuevaPosicion->elemento = elemento;
    return 0
}

tipoElemento pilaSuprime(Pila *p)
{
    Pila nuevaPosicion = &p;
    tipoElemento valor = nuevaPosicion->elemento;
    if (pilaVacia(p)) 
		return -1;
    free(nuevaPosicion);
    return valor;
}
