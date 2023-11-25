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
    Pessoa p;
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
    //inserindo no inicio
    p.id = 10;
    status = lista_inserir_inicio(lista, p);
    printf("@> inserido no inicio: %i\n", status);
    //inserindo no fim
    p.id = 30;
    status = lista_inserir_inicio(lista, p);
    printf("@> inserido no fim: %i\n", status);
    //inserindo em ordem
    p.id = 20;
    status = lista_inserir_inicio(lista, p);
    printf("@> inserido em ordem: %i\n", status);


    //destruindo a lista
    lista_deletar(lista);
    printf("@> Lista deletada\n");
    //fim
    return 0;
}