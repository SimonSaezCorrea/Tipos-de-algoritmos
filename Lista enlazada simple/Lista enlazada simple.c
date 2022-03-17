/**
 * @file Lista enlazada simple.c
 * @author Simón Sáez (NaYxXaXx) - nayxxaxx789super@gmail.com
 * @brief TDA de una lista enlazada simple (Pila, Cola y por posicion)
 * @version 0.1
 * @date 2022-03-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Estructura de la lista enlazada simple
 * 
 */
typedef struct listaEnlazadaSimple{
    int dato1;
    char *dato2;

    struct listaEnlazadaSimple *sig;
}listaEnlazadaSimple;

//----------------------------------------- AGREGAR ---------------------------------------------

/**
 * @brief Añade un elemento al inicio de la lista
 * 
 * @param L Es la lista a añadir el elemento
 * @param dato1 El dato 1 que se le añade
 * @param dato2 El dato 2 que se le añade
 * @return Se retorna la lista con el elemento
 * 
 */
listaEnlazadaSimple *add_start(listaEnlazadaSimple *L, int dato1, char *dato2){
    
    if(L != NULL){
        listaEnlazadaSimple *aux;

        aux = (listaEnlazadaSimple *)malloc(sizeof(listaEnlazadaSimple));
        aux->dato1 = dato1;
        aux->dato2 = dato2;
        aux->sig = L;

        return aux;
    }
    else{
        L = (listaEnlazadaSimple *)malloc(sizeof(listaEnlazadaSimple));
        L->dato1 = dato1;
        L->dato2 = dato2;
        L->sig = NULL;

        return L;
    }
}

/**
 * @brief Añade un elemento al final de la lista
 * 
 * @param L Es la lista a añadir el elemento
 * @param dato1 El dato 1 que se le añade
 * @param dato2 El dato 2 que se le añade
 * @return Se retorna la lista con el elemento
 * 
 */
listaEnlazadaSimple *add_end(listaEnlazadaSimple *L, int dato1, char *dato2){
    listaEnlazadaSimple *aux = L;

    if(aux != NULL){
        while(aux->sig!=NULL){
                aux = aux->sig;
        }
        aux->sig = (listaEnlazadaSimple *)malloc(sizeof(listaEnlazadaSimple));
        aux->sig->dato1 = dato1;
        aux->sig->dato2 = dato2;
        aux->sig->sig = NULL;
    }
    else{
        aux = (listaEnlazadaSimple *)malloc(sizeof(listaEnlazadaSimple));
        aux->dato1 = dato1;
        aux->dato2 = dato2;
        aux->sig = NULL;
        L = aux;
    }

    return L;
}

/**
 * @brief Añade un elemento en una posicion X de la lista
 * 
 * @param L Es la lista a añadir el elemento
 * @param posicion Es la posicion donde se añadirá el elemento
 * @param date1 El dato 1 que se le añade
 * @param dato2 El dato 2 que se le añade
 * @return Se retorna la lista con el elemento
 * 
 */
listaEnlazadaSimple *add_position(listaEnlazadaSimple *L, int posicion, int dato1, char *dato2){
    listaEnlazadaSimple *aux = L;
    
    if(aux != NULL){
        if(posicion!=0){
            int i = 1;
            while(aux->sig != NULL && i != posicion){
                    aux = aux->sig;
                    i++;
            }
            
            if(i == posicion){
                if(aux->sig != NULL){
                    listaEnlazadaSimple *aux2 = (listaEnlazadaSimple *)malloc(sizeof(listaEnlazadaSimple));
                    aux2->dato1 = aux->sig->dato1;
                    aux2->dato2 = aux->sig->dato2;
                    aux2->sig = aux->sig->sig;

                    aux->sig = (listaEnlazadaSimple *)malloc(sizeof(listaEnlazadaSimple));
                    aux->sig->dato1 = dato1;
                    aux->sig->dato2 = dato2;
                    aux->sig->sig = aux2;      
                }
                else{
                    aux->sig = (listaEnlazadaSimple *)malloc(sizeof(listaEnlazadaSimple));
                    aux->sig->dato1 = dato1;
                    aux->sig->dato2 = dato2;
                    aux->sig->sig = NULL;
                }

    
            }
            else{
                printf("No se puede añadir el elemento, no se puede llegar a esa posición");
            }
        }
        else{
            listaEnlazadaSimple *aux2 = (listaEnlazadaSimple *)malloc(sizeof(listaEnlazadaSimple));
            aux2->dato1 = dato1;
            aux2->dato2 = dato2;
            aux2->sig = aux;
            return aux2;
        }
    }
    else{
        if(posicion == 0){
            aux = (listaEnlazadaSimple *)malloc(sizeof(listaEnlazadaSimple));
            aux->dato1 = dato1;
            aux->dato2 = dato2;
            aux->sig = NULL;
            L = aux;
        }
        else{
            printf("No se puede añadir el elemento, no se puede llegar a esa posición");
        }
    }

    return L;
}

//----------------------------------------- BORRAR ---------------------------------------------
/**
 * @brief Elimina el último elemento de la lista
 * 
 * @param L La lista que se le eliminará el elemento
 * @return Devuelve la lista con el elemento eliminado
 */
listaEnlazadaSimple *remove_stack(listaEnlazadaSimple *L){
    if(L != NULL){
        listaEnlazadaSimple *aux = L;
        while(aux->sig->sig != NULL){
            aux = aux->sig;
        }
        listaEnlazadaSimple *aux2 = aux->sig->sig;
        free(aux->sig);
        aux->sig = aux2;

        return L;
    }
    else{
        printf("No hay elementos para borrar");
        return L;
    }
    
}

/**
 * @brief Elimina el primer elemento de la lista
 * 
 * @param L La lista que se le eliminará el elemento
 * @return Devuelve la lista con el elemento eliminado
 */
listaEnlazadaSimple *remove_queue(listaEnlazadaSimple *L){
    if(L != NULL){
        listaEnlazadaSimple *aux = L->sig;
        free(L);
        return aux; 
    }
    else{
        printf("No hay elementos para borrar");
        return L;
    }
}

/**
 * @brief Elimina el elemento en una posición de la lista
 * 
 * @param L La lista que se le eliminará el elemento
 * @return Devuelve la lista con el elemento eliminado
 */
listaEnlazadaSimple *remove_position(listaEnlazadaSimple *L, int posicion){
    if(L != NULL){
        if(posicion != 0){
            int i = 1;
            listaEnlazadaSimple *aux = L;
            while(aux->sig != NULL && i != posicion){
                aux = aux->sig;
                i++;
            }
            if(i == posicion){
                if(aux->sig != NULL){
                    listaEnlazadaSimple *aux2 = aux->sig->sig;
                    free(aux->sig);
                    aux->sig = aux2;
                }
                else{
                    free(aux->sig);
                }
                return L;
            }
            else{
                printf("No existe esa posicion");
                return L;
            }
        }
        else{
            listaEnlazadaSimple *aux = L->sig;
            free(L);
            return aux;
        }
    }
    else{
        printf("No hay elementos para borrar");
        return L;
    }
}


//----------------------------------------- OTROS ---------------------------------------------

/**
 * @brief Muestra los elementos de la lista
 * 
 * @param L La lista a mostrar
 */
void show(listaEnlazadaSimple *L){
    listaEnlazadaSimple *aux = L;
    while(aux != NULL){
        printf("dato1: %d       dato2: %s\n", aux->dato1, aux->dato2);
        aux = aux->sig;
    }
    printf("\n");
}

/**
 * @brief Calcula el largo de la lista
 * 
 * @param L La lista a calcular el largo
 * @return El largo de la lista
 */
int len(listaEnlazadaSimple *L){
    listaEnlazadaSimple *aux = L;
    int contador = 0;
    while (aux != NULL){
        contador++;
        aux = aux->sig;
    }

    return contador;
}

/**
 * @brief Libera la memoria de la lista
 * 
 * @param L La lista a liberar
 */
void liberar(listaEnlazadaSimple *L){
    listaEnlazadaSimple *aux = L;
    listaEnlazadaSimple *aux2;
    while(aux != NULL){
        aux2 = aux->sig;
        free(aux);
        aux = aux2;
    }
}

int main(){

    listaEnlazadaSimple *L1 = NULL;

    L1 = add_start(L1, 1, "1");
    L1 = add_start(L1, 2, "2");
    L1 = add_start(L1, 3, "3");
    L1 = add_start(L1, 4, "4");
    L1 = remove_queue(L1);
    L1 = remove_queue(L1);

    printf("Largo = %d\n", len(L1));
    show(L1);
    

    listaEnlazadaSimple *L2 = NULL;

    L2 = add_end(L2, 1, "1");
    L2 = add_end(L2, 2, "2");
    L2 = add_end(L2, 3, "3");
    L2 = add_end(L2, 4, "4");
    L2 = remove_stack(L2);
    L2 = remove_stack(L2);

    printf("Largo = %d\n", len(L2));
    show(L2);


    listaEnlazadaSimple *L3 = NULL;

    L3 = add_position(L3, 0, 1, "1");
    L3 = add_position(L3, 1, 2, "2");
    L3 = add_position(L3, 0, 3, "3");
    L3 = add_position(L3, 2, 4, "4");
    L3 = remove_position(L3, 2);
    L3 = remove_position(L3, 2);

    printf("Largo = %d\n", len(L3));
    show(L3);


    liberar(L1);

    liberar(L2);

    liberar(L3);

    return 0;
}