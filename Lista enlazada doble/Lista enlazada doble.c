/**
 * @file Lista enlazada doble.c
 * @author Simón Sáez (NaYxXaXx) - nayxxaxx789super@gmail.com
 * @brief TDA de una lista enlazada doble
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
 * @brief Estructura de la lista enlazada doble
 * 
 */
typedef struct listaEnlazadaDoble{
    int dato;
    struct listaEnlazadaDoble *ant;
    struct listaEnlazadaDoble *sig;
}listaEnlazadaDoble;

//----------------------------------------- AGREGAR ---------------------------------------------

/**
 * @brief Añade un elemento al inicio de la lista
 * 
 * @param L Es la lista a añadir el elemento
 * @param dato1 El dato que se le añade
 * @return Se retorna la lista con el elemento
 * 
 */
listaEnlazadaDoble *add_start(listaEnlazadaDoble *L, int dato){
    
    if(L != NULL){
        listaEnlazadaDoble *aux;

        aux = (listaEnlazadaDoble *)malloc(sizeof(listaEnlazadaDoble));
        aux->dato = dato;
        aux->ant = NULL;
        aux->sig = L;

        L->ant = aux;

        return aux;
    }
    else{
        L = (listaEnlazadaDoble *)malloc(sizeof(listaEnlazadaDoble));
        L->dato = dato;
        L->ant = NULL;
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
listaEnlazadaDoble *add_end(listaEnlazadaDoble *L, int dato){
    listaEnlazadaDoble *aux = L;

    if(aux != NULL){
        while(aux->sig!=NULL){
                aux = aux->sig;
        }
        aux->sig = (listaEnlazadaDoble *)malloc(sizeof(listaEnlazadaDoble));
        aux->sig->dato = dato;
        aux->sig->ant = aux;
        aux->sig->sig = NULL;
    }
    else{
        aux = (listaEnlazadaDoble *)malloc(sizeof(listaEnlazadaDoble));
        aux->dato = dato;
        aux->ant = NULL;
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
listaEnlazadaDoble *add_position(listaEnlazadaDoble *L, int posicion, int dato){
    listaEnlazadaDoble *aux = L;
    
    if(aux != NULL){
        if(posicion!=0){
            int i = 1;
            while(aux->sig != NULL && i != posicion){
                    aux = aux->sig;
                    i++;
            }
            
            if(i == posicion){
                if(aux->sig != NULL){
                    listaEnlazadaDoble *aux2 = (listaEnlazadaDoble *)malloc(sizeof(listaEnlazadaDoble));
                    aux2->dato = aux->sig->dato;
                    aux2->sig = aux->sig->sig;

                    aux->sig = (listaEnlazadaDoble *)malloc(sizeof(listaEnlazadaDoble));
                    aux->sig->dato = dato;
                    aux->sig->ant = aux;
                    aux->sig->sig = aux2;     

                    aux2->ant = aux->sig; 
                }
                else{
                    aux->sig = (listaEnlazadaDoble *)malloc(sizeof(listaEnlazadaDoble));
                    aux->sig->dato = dato;
                    aux->sig->ant = aux;
                    aux->sig->sig = NULL;
                }

    
            }
            else{
                printf("No se puede añadir el elemento, no se puede llegar a esa posición");
            }
        }
        else{
            listaEnlazadaDoble *aux2 = (listaEnlazadaDoble *)malloc(sizeof(listaEnlazadaDoble));
            aux2->dato = dato;
            aux2->ant = NULL;
            aux2->sig = aux;
            aux->ant = aux2;
            return aux2;
        }
    }
    else{
        if(posicion == 0){
            aux = (listaEnlazadaDoble *)malloc(sizeof(listaEnlazadaDoble));
            aux->dato = dato;
            aux->ant = NULL;
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
listaEnlazadaDoble *remove_stack(listaEnlazadaDoble *L){
    if(L != NULL){
        listaEnlazadaDoble *aux = L;
        while(aux->sig != NULL){
            aux = aux->sig;
        }
        listaEnlazadaDoble *aux2 = aux->ant;
        free(aux->sig);
        aux2->sig = NULL;

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
listaEnlazadaDoble *remove_queue(listaEnlazadaDoble *L){
    if(L != NULL){
        listaEnlazadaDoble *aux = L->sig;
        free(L);

        aux->ant = NULL;

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
listaEnlazadaDoble *remove_position(listaEnlazadaDoble *L, int posicion){
    if(L != NULL){
        if(posicion != 0){
            int i = 1;
            listaEnlazadaDoble *aux = L;
            while(aux->sig != NULL && i != posicion){
                aux = aux->sig;
                i++;
            }
            if(i == posicion){
                if(aux->sig != NULL){
                    listaEnlazadaDoble *aux2 = aux->sig->sig;
                    free(aux->sig);
                    aux->sig = aux2;
                }
                else{
                    listaEnlazadaDoble *aux2 = aux->ant;
                    free(aux->sig);
                    aux2->sig = NULL;
                }
                return L;
            }
            else{
                printf("No existe esa posicion");
                return L;
            }
        }
        else{
            listaEnlazadaDoble *aux = L->sig;
            free(L);
            aux->ant = NULL;
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
void show(listaEnlazadaDoble *L){
    listaEnlazadaDoble *aux = L;
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
void showMemory(listaEnlazadaDoble *L){
    listaEnlazadaDoble *aux = L;
    printf("Ant\t\tHere\t\tSig\n");
    while(aux != NULL){
        printf("%p\t%p\t%p\n", aux->ant, aux, aux->sig);
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
int len(listaEnlazadaDoble *L){
    listaEnlazadaDoble *aux = L;
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
void liberar(listaEnlazadaDoble *L){
    listaEnlazadaDoble *aux = L;
    listaEnlazadaDoble *aux2;
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
int search_date_position(listaEnlazadaDoble *L, int dato){
    listaEnlazadaDoble *aux = L;
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
int search_position_date(listaEnlazadaDoble *L, int position){
    listaEnlazadaDoble *aux = L;
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

    listaEnlazadaDoble *L1 = NULL;

    L1 = add_start(L1, 1);
    L1 = add_start(L1, 2);
    L1 = add_start(L1, 3);
    L1 = add_start(L1, 4);
    L1 = remove_queue(L1);
    L1 = remove_queue(L1);

    printf("Largo = %d\n", len(L1));
    printf("posicion buscada: %d\n", search_date_position(L1, 1));
    show(L1);
    showMemory(L1);
    

    listaEnlazadaDoble *L2 = NULL;

    L2 = add_end(L2, 1);
    L2 = add_end(L2, 2);
    L2 = add_end(L2, 3);
    L2 = add_end(L2, 4);
    L2 = remove_stack(L2);
    L2 = remove_stack(L2);

    printf("Largo = %d\n", len(L2));
    printf("dato buscado: %d\n", search_position_date(L2, 2));
    show(L2);
    showMemory(L2);


    listaEnlazadaDoble *L3 = NULL;

    L3 = add_position(L3, 0, 1);
    L3 = add_position(L3, 1, 2);
    L3 = add_position(L3, 0, 3);
    L3 = add_position(L3, 2, 4);
    L3 = remove_position(L3, 2);
    L3 = remove_position(L3, 2);

    printf("Largo = %d\n", len(L3));
    printf("posicion buscada: %d\n", search_date_position(L3, 0));
    show(L3);
    showMemory(L3);


    liberar(L1);

    liberar(L2);

    liberar(L3);

    return 0;
}