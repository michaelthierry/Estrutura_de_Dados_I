/**
 * @file lista.h
 * @author Michael Thierry (michaelthierry86@gmail.com)
 * @brief Lista Linear Dinamica Encadeada
 * @version 0.1
 * @date 2023-12-28
 * 
 * @copyright Copyright (c) 2023
 * 
 */

//Definindo diretivas e macros
#ifndef LISTA_H
#define LISTA_H

//Tipo de dado que a lista guarda
typedef struct pessoa{
    int id;
    char nome[30];
    int idade;
    float peso;
}Pessoa;

//Estrutura dos elementos da lista
typedef struct elemento{
    Pessoa pessoa;
    struct elemento *proximo;
}Elemento;

//Estrutura da lista
typedef struct lista{
    Elemento *inicio;
}Lista;


/**
 * @brief Pegada os dados de uma pessoa
 * 
 * @return Pessoa um elemento do tipo pessoa
 */
Pessoa pegar_dados();

//CRIAR E DELETAR A LISTA   
/**
 * @brief Aloca memoria para uma lista
 * 
 * @return Lista* 
 */
Lista* lista_criar();

/**
 * @brief Desaloca memoria para uma lista
 * 
 * @param lista é a referencia da lista
 */
void lista_deletar(Lista *lista);

//INFORMAÇÕES DA LISTA
/**
 * @brief Informa se a lista esta vazia
 * 
 * @param lista referencia da lista
 * @return int -1 nao existe, 1 esta vazia, 0 nao esta vazia
 */
int lista_vazia(Lista *lista);
/**
 * @brief Informa se a lista esta cheia
 * 
 * @param lista referencia para a lista
 * @return int sempre 0
 */
int lista_cheia(Lista *lista);
/**
 * @brief Informa quantos elemento existem na lista
 * 
 * @param lista referencia para a lista
 * @return int -1 se a lista nao existir
 */
int lista_tamanho(Lista *lista);
/**
 * @brief Exibe os elementos da lista
 * 
 * @param lista Referecncia para a lista
 * @return int 
 */
int lista_exibir(Lista *lista);

#endif