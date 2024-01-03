/**
 * @file lista.h
 * @author Michael Thierry (michaelthierry86@gmail.com)
 * @brief Lista Linear Estática
 * @version 0.2
 * @date 2023-11-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "pessoa.h"

#ifndef LISTA_H
#define LISTA_H

// Tamanho maximo da lista
#define MAX 10

// Estrutura da lista estatica
typedef struct lista{
    int quantidade;
    Pessoa dados[MAX];
}Lista; 

// CRIAR E DESTRUIR A LISTA

/**
 * @brief Aloca memoria para um ponteiro do tipo lista
 * 
 * @return Lista* 
 */
Lista* lista_criar();

/**
 * @brief Libera memoria alocada para uma lista
 * 
 * @param lista 
 */
void lista_deletar(Lista *lista);

// OBTER INFORMAÇOES DA LISTA

/**
 * @brief Verifica se a lista está cheia
 * 
 * @param lista ponterio do tipo lista
 * @return int -1 se a lista nao existir, 1 se estiver cheia.
 */
int lista_cheia(Lista *lista);

/**
 * @brief Verifica se a lista esta vazia
 * 
 * @param lista ponteiro do tipo lista
 * @return int  -1 se a lista nao existir, 1 se estiver vazia.
 */
int lista_vazia(Lista *lista);

/**
 * @brief Verifica o tamanho da lista
 * 
 * @param lista ponterio do tipo lista
 * @return int -1 se a lista nao existir, tamanho da lista
 */

int lista_tamanho(Lista *lista);

// INSERIR NA LISTA

/**
 * @brief Insere um novo elemento na inicio da lista
 * 
 * @param lista ponteiro do tipo lista
 * @param pessoa elemento do tipo Pessoa a ser inserido
 * @return int -1 se a lista estiver cheia, 1 se for inserido
 */
int lista_inserir_inicio(Lista *lista, Pessoa pessoa);

/**
 * @brief Inserir um elemento de forma ordenada na lista
 * 
 * @param lista ponterio do tipo lista
 * @param pessoa elemento a ser inserido
 * @return int -1 se a lista estiver cheia, 1 se for inserido
 */
int lista_inserir_ordenado(Lista *lista, Pessoa pessoa);

/**
 * @brief Insere um elemento no fim da lista
 * 
 * @param lista ponteiro do tipo lista
 * @param pessoa elemento a ser inserido
 * @return int -1 se a lista estiver cheia, 1 se for inserido
 */
int lista_inserir_fim(Lista *lista, Pessoa pessoa);

//  RREMOVER DA LISTA
/**
 * @brief Remove um elemento do inicio da lista
 * 
 * @param lista ponterio do tipo lista
 * @return int -1 se a lista estive vazia, 1 se for removido
 */
int lista_remover_inicio(Lista *lista);

/**
 * @brief Remove um elemento da lista pelo id
 * 
 * @param lista ponteiro do yipo lista
 * @param id identificador do elemento
 * @return int -1 se a lista estiver vazia, 1 se for encontrado e removido 
 */
int lista_remover_elemento(Lista *lista, int id);

/**
 * @brief Remove do fim da lista 
 * 
 * @param lista ponteiro do tipo lista
 * @return int -1 se a lista não existir, 1 se for removido 
 */
int lista_remover_fim(Lista *lista);

//  EXIBIR ELEMENTOS

/**
 * @brief Exibe a lista ao usuario
 * 
 * @param lista ponteiro da lista
 * @return int -1 se a lista nao existir
 */
int lista_exibir(Lista *lista);

// BUSCA NA LISTA

/**
 * @brief Busca por um elemento na lista
 * 
 * @param lista ponteiro para a lista
 * @param id identificador do elemento
 * @param pessoa referencia para pessoa ser armazenada
 * @return int 
 */
int lista_buscar_elemento(Lista *lista, int id, Pessoa *pessoa);

/**
 * @brief Busca por um elemento na posiçao da lista
 * 
 * @param lista ponteiro para lista
 * @param posicao indice onde se deseja procurar
 * @param pessoa referencia para retornar pessoa
 * @return int 
 */
int lista_buscar_posicao(Lista *lista, int posicao, Pessoa *pessoa);

#endif