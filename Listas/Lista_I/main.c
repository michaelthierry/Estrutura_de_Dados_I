/**
 * @file main.c
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

int main(){

    Lista *lista; 
    int status;
    //criando a lista
    lista = lista_criar();
    printf("@> Lista criada\n");
    //obtendo informações
    status = lista_cheia(lista);
    printf("@> Lista cheia: %i\n", status);
    status = lista_vazia(lista);
    printf("@> Lista vazia: %i\n", status);
    status = lista_tamanho(lista);
    printf("@> Lista tamanho: %i\n", status);

    //destruindo a lista
    lista_deletar(lista);
    printf("@> Lista deletada\n");
    //fim
    return 0;
}