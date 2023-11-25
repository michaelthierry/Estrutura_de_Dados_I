/**
 * @file lista.h
 * @author Michael Thierry (michaelthierry86@gmail.com)
 * @brief Lista Linear Estática
 * @version 0.1
 * @date 2023-11-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef LISTA_H
#define LISTA_H

// Tamanho maximo da lista
#define MAX 10

// Tipo de dados que a lista guarda
typedef struct pessoa{
    int id;
    char nome[30];
    int idade;
    float peso;
}Pessoa;

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


#endif