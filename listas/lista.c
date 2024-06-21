#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "lista.h"



int
creaVacia(Lista *l)
{
    if (l == NULL)
        return -2;
    else if (NULL == (l->raiz = l->ultimo = (tipoCelda *)malloc(sizeof(tipoCelda))))
        return -1;
    else {
        l->raiz->sig = NULL;
        return 0;
    }
}


int
vacia(Lista *l)
{
    if (l == NULL || l->raiz == NULL) {
        return -1;
    }
    else if (l->raiz->sig == NULL)
        return 1;
    else
        return 0;
}

int
destruye(Lista *l)
{
    if (l == NULL || l->raiz == NULL) {
        return -1;
    }
    else if (l->raiz->sig != NULL){
        return -2;
    }
    else {
        free(l->raiz);
        l->raiz = l->ultimo = NULL;
        return 0;
    }
}


void
imprime(Lista *l)
{
    tipoCelda *aImprimir;
    int posicion;
    
    if (l == NULL || l->raiz == NULL) {
        return;
    }
    else {
        posicion = 1;
        aImprimir = l->raiz->sig;
        while (aImprimir != NULL) {
            printf("Valor: %d en posición: %d\n",aImprimir->elemento, posicion++);
            aImprimir = aImprimir->sig;
        }
        printf("%d valores en la lista\n",posicion-1);
    }
}

tipoPosicion
anterior(tipoPosicion p, Lista *l)
{
    tipoCelda *anterior;
    
    if (l == NULL || l->raiz == NULL || p == NULL) {
        return NULL;
    }
    else if (p == l->raiz){
        return l->raiz;
    }
    else {
        anterior = l->raiz;
        while (anterior->sig != p)
            anterior = anterior->sig;
        return anterior;
    }
}


tipoPosicion
primero(Lista *l)
{
    if (l == NULL || l->raiz == NULL) 
		return NULL;
    else return 
		l->raiz;
}



tipoPosicion
fin(Lista *l)
{
    tipoPosicion posicion; 
    if (vacia(l) != 0) 
		return NULL;
    else {
        posicion = l->raiz;
        while (posicion->sig != NULL) 
			posicion = posicion->sig;
        return posicion;
    }
}




int
inserta(tipoElemento x, tipoPosicion p, Lista *l)
{
    tipoPosicion nuevaPosicion;
    if (vacia(l) == -1) 
		return -1;
    if(NULL == (nuevaPosicion = malloc(sizeof(tipoCelda)))) 
		return -2;
    nuevaPosicion->elemento = x;
    nuevaPosicion->sig = p->sig;
    p->sig = nuevaPosicion;
    if(p == fin(l)) 
		l->ultimo = fin(l);
    return 0;
}


int
suprime (tipoPosicion p, Lista *l)
{
    tipoPosicion aBorrar;
    if (vacia(l) != 0 || p == NULL) 
		return -1;
    else {
        aBorrar = p->sig;
        if(aBorrar == NULL) 
			return -2;
        p->sig = aBorrar->sig;
        free(aBorrar);
        l->ultimo = fin(l);
        return 0;
    }
}



tipoPosicion
siguiente(tipoPosicion p,Lista *l)
{
    tipoPosicion posicion;
    if (vacia(l) != 0 || p == NULL) 
		return NULL;
    else {
        if(p == fin(l)) 
			return p;
        return p->sig;
    }  
}




tipoPosicion
localiza (tipoElemento x, Lista *l)
{
	tipoPosicion posicion;
    if (vacia(l) != 0) 
		return NULL;
	else{
        posicion = l->raiz;
        while (posicion->sig != NULL)
        {
            if (posicion->sig->elemento == x) 
				return posicion;
            posicion = posicion->sig;
        } return posicion;
    }
}



tipoElemento
recupera(tipoPosicion p, Lista *l)
{
    if (l == NULL || l->raiz == NULL || p == NULL) 
		return -1;
    else {
        if(p == fin(l)) 
			return -2;
        return p->sig->elemento;
    }
}


int
anula(Lista *l)
{
    tipoPosicion posicion, aBorrar;
    if(vacia(l) != 0) 
		return -1;
    posicion = l->raiz->sig;
    l->raiz->sig = NULL;
    while(posicion != NULL){
        aBorrar = posicion;
        posicion = posicion->sig;
        free(aBorrar);
    } return 0;
}

int
concatena(Lista *lA, Lista *lB)
{
    int errNum=0;
    tipoPosicion comienzoB, posicion;
    if (vacia(lA) != 0 || vacia(lB) != 0) 
		return -1;
    comienzoB = primero(lB);
    posicion = comienzoB->sig;
    while(posicion != NULL) {
        inserta(posicion->elemento,fin(lA),lA);
        posicion = posicion->sig;
    } 
    errNum = anula(lB);
    if(errNum == 0) 
		return 0;
    else return 
		-2;
}



