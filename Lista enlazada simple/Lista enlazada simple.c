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

// Falta crear mejor testeos a los códigos, se han probado con casos mostrados en el main

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Estructura de la lista enlazada simple
 * 
 */
typedef struct listaEnlazadaSimple{
    int dato;
    struct listaEnlazadaSimple *sig;
}listaEnlazadaSimple;

//----------------------------------------- AGREGAR ---------------------------------------------

/**
 * @brief Añade un elemento al inicio de la lista
 * 
 * @param L Es la lista a añadir el elemento
 * @param dato1 El dato que se le añade
 * @return Se retorna la lista con el elemento
 * 
 */
listaEnlazadaSimple *add_start(listaEnlazadaSimple *L, int dato){
    
    if(L != NULL){
        listaEnlazadaSimple *aux;

        aux = (listaEnlazadaSimple *)malloc(sizeof(listaEnlazadaSimple));
        aux->dato = dato;
        aux->sig = L;

        return aux;
    }
    else{
        L = (listaEnlazadaSimple *)malloc(sizeof(listaEnlazadaSimple));
        L->dato = dato;
        L->sig = NULL;

        return L;
    }
}

/**
 * @brief Añade un elemento al final de la lista
 * 
 * @param L Es la lista a añadir el elemento
 * @param dato1 El dato que se le añade
 * @return Se retorna la lista con el elemento
 * 
 */
listaEnlazadaSimple *add_end(listaEnlazadaSimple *L, int dato){
    listaEnlazadaSimple *aux = L;

    if(aux != NULL){
        while(aux->sig!=NULL){
                aux = aux->sig;
        }
        aux->sig = (listaEnlazadaSimple *)malloc(sizeof(listaEnlazadaSimple));
        aux->sig->dato = dato;
        aux->sig->sig = NULL;
    }
    else{
        aux = (listaEnlazadaSimple *)malloc(sizeof(listaEnlazadaSimple));
        aux->dato = dato;
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
 * @param date1 El dato que se le añade
 * @return Se retorna la lista con el elemento
 * 
 */
listaEnlazadaSimple *add_position(listaEnlazadaSimple *L, int posicion, int dato){
    listaEnlazadaSimple *aux = L;
    if(L != NULL){
        int i = 0;
        listaEnlazadaSimple *aux2;
        aux2 = NULL;
        while(aux != NULL && i != posicion){
            aux2 = aux;
            aux = aux->sig;
            i++;
        }
        if(i == posicion){
            if(aux != NULL){
                listaEnlazadaSimple *aux3 = aux;

                aux = (listaEnlazadaSimple *)malloc(sizeof(listaEnlazadaSimple));
                aux->dato = dato;
                aux->sig = aux3;

                if(aux2 == NULL){
                    return aux;
                }
                aux2->sig=aux;
            }
            else{
                aux = (listaEnlazadaSimple *)malloc(sizeof(listaEnlazadaSimple));
                aux->dato = dato;
                aux->sig = NULL;
                aux2->sig = aux;
            }


        }
        else{
            printf("No se puede a%cadir el elemento, no se puede llegar a esa posici%cn\n", 164,162);
        }
    }
    else{
        if(posicion == 0){
            aux = (listaEnlazadaSimple *)malloc(sizeof(listaEnlazadaSimple));
            aux->dato = dato;
            aux->sig = NULL;
            L = aux;
        }
        else{
            printf("No se puede a%cadir el elemento, no se puede llegar a esa posici%cn", 164,162);
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
        printf("No hay elementos para borrar\n");
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
        printf("No hay elementos para borrar\n");
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
        int i = 0;
        listaEnlazadaSimple *aux = L;
        listaEnlazadaSimple *aux2 = NULL;
        while(aux != NULL && i != posicion){
            aux2 = aux;
            aux = aux->sig;
            i++;
        }
        if(i == posicion){
            if(aux != NULL){
                listaEnlazadaSimple *aux3 = aux->sig;
                free(aux);
                if(aux2 == NULL){
                    return aux3;
                }
                aux2->sig = aux3;
            }
            else{
                free(aux);
                aux2->sig = NULL;
            }
            return L;
        }
        else{
            printf("No existe esa posicion\n");
            return L;
        }
    }
    else{
        printf("No hay elementos para borrar\n");
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
        printf("dato: %d\n", aux->dato);
        aux = aux->sig;
    }
    printf("\n");
}

/**
 * @brief Muestra las ubicaciones de memoria de la lista
 * 
 * @param L La lista a mostrar
 */
void showMemory(listaEnlazadaSimple *L){
    listaEnlazadaSimple *aux = L;
    printf("Here\t\tSig\n");
    while(aux != NULL){
        printf("%p\t%p\n", aux, aux->sig);
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

//----------------------------------------- BUSCAR ---------------------------------------------

/**
 * @brief Permite saber la posicion de un elemento según su contenido
 * 
 * @param L La lista a buscar
 * @param dato El dato que se usará para buscar la posición
 * @return Retorna la posición
 */
int search_date_position(listaEnlazadaSimple *L, int dato){
    listaEnlazadaSimple *aux = L;
    int largo = len(L);
    int i=0;
    int position = -1;
    while(i<largo){
        if(aux->dato == dato){
            position = i;
            i = largo;
        }
        else{
            aux = aux->sig;
            i++;
        }
    }
    if(position != -1){
        return position;
    }
    printf("No se encontró el dato\n");
    return position;
}

/**
 * @brief Permite saber el contenido de la lista (El dato) según su posición
 * 
 * @param L La lista a buscar
 * @param position La posición que se usará para buscar el dato
 * @return Retorna el dato
 */
int search_position_date(listaEnlazadaSimple *L, int position){
    listaEnlazadaSimple *aux = L;
    int largo = len(L);
    if(largo > position){
        int i=0;
        while(i<position){
            aux = aux->sig;
            i++;
        }
        return aux->dato;
    }
    else{
        printf("No se puede acceder a esa posición\n");
        return -1;
    }
}

int main(){
    
    listaEnlazadaSimple *L1 = NULL;

    L1 = add_start(L1, 1);
    L1 = add_start(L1, 2);
    L1 = add_start(L1, 3);
    L1 = add_start(L1, 4);
    printf("Largo = %d\n", len(L1));
    show(L1);
    showMemory(L1);

    L1 = remove_queue(L1);
    L1 = remove_queue(L1);
    printf("Largo = %d\n", len(L1));
    show(L1);
    showMemory(L1);

    printf("posicion buscada: %d\n", search_date_position(L1, 1));
    
    printf("---------------------------------------------");
    //------------------------------------------

    listaEnlazadaSimple *L2 = NULL;

    L2 = add_end(L2, 1);
    L2 = add_end(L2, 2);
    L2 = add_end(L2, 3);
    L2 = add_end(L2, 4);
    printf("Largo = %d\n", len(L2));
    show(L2);
    showMemory(L2);

    L2 = remove_stack(L2);
    L2 = remove_stack(L2);
    printf("Largo = %d\n", len(L2));
    show(L2);
    showMemory(L2);

    printf("dato buscado: %d\n", search_position_date(L2, 2));
    

    printf("---------------------------------------------");
    //---------------------------------------------

    listaEnlazadaSimple *L3 = NULL;

    L3 = add_position(L3, 0, 1);
    L3 = add_position(L3, 1, 2);
    L3 = add_position(L3, 0, 3);
    L3 = add_position(L3, 2, 4);
    printf("Largo = %d\n", len(L3));
    show(L3);
    showMemory(L3);
    
    L3 = remove_position(L3, 0);
    L3 = remove_position(L3, 0);
    printf("Largo = %d\n", len(L3));
    show(L3);
    showMemory(L3);

    printf("posicion buscada: %d\n", search_date_position(L3, 4));


    liberar(L1);
    liberar(L2);
    liberar(L3);

    return 0;
}