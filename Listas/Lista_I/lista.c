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
    //declara ponteiro do tipo lista
    Lista *lista;
    //tenta alocar memoria
    lista = (Lista*) malloc(sizeof(Lista));
    //verifica se foi alocado
    if(lista != NULL){
        //inicia quantidade
        lista->quantidade = 0;
    }
    //retorna o ponteiro
    return lista;
}

void lista_deletar(Lista *lista){
    //libera memoria da lista
    free(lista);
}

int lista_cheia(Lista *lista){
    //verifica se a lista existe
    if(lista == NULL){
        return -1;
    }
    //retorna a verificação da lista
    return (lista->quantidade == MAX);
}

int lista_vazia(Lista *lista){
    //verifica se a lista existe
    if(lista == NULL){
        return -1;
    }
    //retorna a verificação da lista
    return (lista->quantidade == 0);
}

int lista_tamanho(Lista *lista){
    //verifica se a lista existe
    if(lista == NULL){
        return -1;
    }
    //retorna a quantidade
    return lista->quantidade;
}

int lista_inserir_inicio(Lista *lista, Pessoa pessoa){
    //verifica se a lista esta cheia
    if(lista_cheia(lista)){
        return -1;
    }
    //declara indice
    int indice;
    //move todos os elementos uma casa para frente
    for(indice = lista->quantidade - 1; indice >= 0; indice--){
        lista->dados[indice + 1] = lista->dados[indice];
    }    
    //adiciona o elemento no inicio
    lista->dados[0] = pessoa;
    lista->quantidade++;
    //retorna sucesso
    return 1;
}

int lista_inserir_ordenado(Lista *lista, Pessoa pessoa){
    //verifica se a lista esta cheia
    if(lista_cheia(lista)){
        return -1;
    }
    //Percorre a lista até encontra a posicao certa
    int posicao, indice = 0;
    while((indice < lista->quantidade) && (lista->dados[indice].id < pessoa.id)){
        indice++;
    }
    //Move todos da posição encontrada para a direita
    for(posicao = lista->quantidade - 1; posicao >= indice; posicao--){
        lista->dados[posicao + 1] = lista->dados[posicao];
    }
    //Insere o elemento no local e atualiza quantidade
    lista->dados[indice] = pessoa;
    lista->quantidade++;
    //retorna sucesso
    return 1;
}

int lista_inserir_fim(Lista *lista, Pessoa pessoa){
    //verifica se a lista existe
    if(lista_cheia(lista)){
        return -1;
    }
    //adiciona o elemento no final
    lista->dados[lista->quantidade] = pessoa;
    //atualiza quantidade
    lista->quantidade++;
    //retorna sucesso
    return 1;
}

int lista_remover_inicio(Lista *lista){
    //Verifica se a lista esta vazia
    if(lista_vazia(lista)){
        return -1;
    }
    int indice;
    //Move todos os elementos um posição anterior
    for(indice = 0; indice < lista->quantidade - 1; indice++){
        lista->dados[indice] = lista->dados[indice + 1];
    }
    //Decrementa a quantidade
    lista->quantidade--;
    //Status sucesso
    return 1;
}

int lista_remover_elemento(Lista *lista, int id){
    //Verifique se a lista esta vazia
    if(lista_vazia(lista)){
        return -1;
    }
    int posicao, indice = 0;
    //Percorre a lista procurando pelo elemento
    while((indice < lista->quantidade) && (lista->dados[indice].id != id)){
        indice++;
    }
    //Verifica se encontrou
    if(indice == lista->quantidade){
        return -1;
    }
    //Move os elementos uma posiçao para a esquerda
    for(posicao = indice; posicao < lista->quantidade - 1; posicao++){
        lista->dados[posicao] = lista->dados[posicao + 1];
    }
    //Decrementa quantidade
    lista->quantidade--;
    //Retorna sucesso
    return 1;
}

int lista_remover_fim(Lista *lista){
    //Verifica se a lista esta vazia
    if(lista_vazia(lista)){
        return -1;
    }
    //Apenas decrementa a quantidade
    lista->quantidade--;
    //Retorna sucesso
    return 1;
}

int lista_exibir(Lista *lista){
    //verifica se alista existe
    if(lista == NULL){
        return -1;
    }
    //Exibe os elementos
    int iterador = 0;
    printf("@> Lista\n");
    while(iterador < lista->quantidade){
        printf(
            "+------------------------------------------+\n"
            "|[%02i]|ID:[%i]              \n"            
            "|    |Nome:%s"
            "|    |Idade:%i\n"
            "|    |Peso:%.2f\n"
            "+------------------------------------------+\n",
            iterador+1,
            lista->dados[iterador].id,
            lista->dados[iterador].nome,
            lista->dados[iterador].idade,
            lista->dados[iterador].peso
        );
        iterador++;
    }
    //Retorna 1
    return 1;
}

int lista_buscar_elemento(Lista *lista, int id, Pessoa *pessoa){
    //Verifica se a lista existe
    if(lista == NULL || lista_vazia(lista)){
        return -1;
    }
    //Tenta encontra o elemento
    int indice = 0;
    while((indice < lista->quantidade) && (lista->dados[indice].id != id)){
        indice++;
    }
    //verifica se econtrou
    if(indice == lista->quantidade){
        return -1;
    }
    //se encontrou
    *pessoa = lista->dados[indice];
    //retorna sucesso
    return 1;
}

int lista_buscar_posicao(Lista *lista, int posicao, Pessoa *pessoa){
     //Verifica se a lista existe
    if(lista == NULL){
        return -1;
    }
    //Verifica se a busca é possivel
    if(posicao <= 0 || posicao > lista->quantidade){
        return -1;
    }
    //Recebe o elemento da posição diretamente
    *pessoa = lista->dados[posicao - 1];
    //Retorna sucesso
    return 1;
}
