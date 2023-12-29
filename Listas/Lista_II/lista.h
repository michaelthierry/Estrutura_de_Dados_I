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


#endif