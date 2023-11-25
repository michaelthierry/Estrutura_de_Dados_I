/**
 * @file lista.c
 * @author Michael Thierry (michaelthierry86@gmail.com)
 * @brief Lista Linear Estática
 * @version 0.1
 * @date 2023-11-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Lista* lista_criar(){
    Lista *lista;

    lista = (Lista*) malloc(sizeof(Lista));

    if(lista != NULL){
        lista->quantidade = 0;
    }

    return lista;
}

void lista_deletar(Lista *lista){
    free(lista);
}

int lista_cheia(Lista *lista){
    if(lista == NULL){
        return -1;
    }

    return (lista->quantidade == MAX);
}

int lista_vazia(Lista *lista){
    if(lista == NULL){
        return -1;
    }

    return (lista->quantidade == 0);
}

int lista_tamanho(Lista *lista){
    if(lista == NULL){
        return -1;
    }
    
    return lista->quantidade;
}