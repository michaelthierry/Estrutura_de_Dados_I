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

    return 0;
}

void lista_deletar(Lista *lista){
    free(lista);
}