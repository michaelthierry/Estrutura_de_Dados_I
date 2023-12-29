/**
 * @file lista.c
 * @author Michael Thierry (michaelthierry86@gmail.com)
 * @brief Lista Linear Dinamica Encadeada
 * @version 0.1
 * @date 2023-12-28
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Pessoa pegar_dados(){
    Pessoa pessoa;
    //Pegando informações
    printf(
        "+------------------------------------------+\n"
        "@> Digite o ID:\n"
    );
    scanf("%i", &pessoa.id);
    //Removendo o \n
    while(getchar() != '\n');
    printf("@> Digite o Nome:\n");
    
    //lendo nome pegando espaços em brancos ja que scanf nao faz.
    fgets(pessoa.nome, sizeof(pessoa.nome), stdin);
    
    printf("@> Digite a idade:\n");
    scanf("%i", &pessoa.idade);

    printf("@> Digite o peso:\n");
    scanf("%f", &pessoa.peso);

    printf(
        "+------------------------------------------+\n"
    );
    //retorna os dados
    return pessoa;
}

Lista* lista_criar(){
    //Ponteiro para o tipo lista
    Lista *lista;
    //Aloca memoria para a lista
    lista = (Lista*) malloc(sizeof(Lista));
    //Verifica se a lista foi criada;
    if(lista != NULL){
        lista->inicio = NULL;
    }
    //Retorna a referencia
    return lista;
}

void lista_deletar(Lista *lista){
    //Se existir
    if(lista != NULL){
        //Cria um elemento auxiliar
        Elemento *auxiliar;
        //Percorre a lista liberando os elementos
        while(lista->inicio != NULL){
            //Faz auxiliar pegar o inicio
            auxiliar = lista->inicio;
            //faz o inicio pegar o proximo
            lista->inicio = lista->inicio->proximo;
            //libera o auxiliar
            free(auxiliar);
        }
        //libera a lista
        free(lista);
    }
}

int lista_vazia(Lista *lista){
    //se nao existir
    if(lista == NULL){
        return -1;
    }
    //verifica se esta vazia
    if(lista->inicio == NULL){
        return 1;
    }
    return 0;
}

int lista_cheia(Lista *lista){
    return 0;
}

int lista_tamanho(Lista *lista){
    //Se nao existe
    if(lista == NULL){
        return -1;
    }
    //Conta os elementos
    Elemento *auxiliar;
    auxiliar = lista->inicio;
    int contador = 0;
    while(auxiliar != NULL){
        contador++;
        auxiliar = auxiliar->proximo;
    }
    //Retorna a quantidade
    return contador;
}

int lista_exibir(Lista *lista){
    //se nao existe
    if(lista == NULL){
        return -1;
    }
    //Cria um elemento auxiliar
    Elemento *auxiliar;
    auxiliar = lista->inicio;
    printf("@> Lista\n");
    //Percorre a lista
    int contador = 0;
    while(auxiliar != NULL){
        //Exibe informações
        printf(
            "+------------------------------------------+\n"
            "|[%02i]|ID:[%i]              \n"            
            "|    |Nome:%s"
            "|    |Idade:%i\n"
            "|    |Peso:%.2f\n"
            "+------------------------------------------+\n",
            contador+1,
            auxiliar->pessoa.id,
            auxiliar->pessoa.nome,
            auxiliar->pessoa.idade,
            auxiliar->pessoa.peso
        );
        //atualiza auxiliar e o contador
        auxiliar = auxiliar->proximo;
        contador++;
    }
    //retorna sucesso
    return 1;
}
