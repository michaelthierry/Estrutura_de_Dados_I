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
    //criando a lista
    lista = lista_criar();
    printf("@> Lista criada\n");


    //destruindo a lista
    lista_deletar(lista);
    printf("@> Lista deletada\n");
    //fim
    return 0;
}