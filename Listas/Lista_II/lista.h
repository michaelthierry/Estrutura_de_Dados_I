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

//INSERÇÔES NA LISTA
/**
 * @brief Insere um elemento no incio da lista
 * 
 * @param lista Referencia para a lista
 * @param pessoa Elemento a ser inserido
 * @return int 
 */
int lista_inserir_inicio(Lista *lista, Pessoa pessoa);
/**
 * @brief Insere um elemento de forma ordenada na lista
 * 
 * @param lista Referencia para a lista
 * @param pessoa elemento a ser inserido
 * @return int 
 */
int lista_inserir_ordenado(Lista *lista, Pessoa pessoa);
/**
 * @brief Insere um elemento no fim da lista
 * 
 * @param lista referencia para a lista
 * @param pessoa elemento a ser inserido
 * @return int 
 */
int lista_inserir_fim(Lista *lista, Pessoa pessoa);

//REMOVER DA LISTA
/**
 * @brief Remove o primeiro elemento da lista
 * 
 * @param lista ponterio para a lista 
 * @return int 
 */
int lista_remover_inicio(Lista *lista);
/**
 * @brief Procura um elemento na lista e o remove
 * 
 * @param lista ponteiro para a lista
 * @param pessoa elemento a ser procurado
 * @return int 
 */
int lista_remover_elemento(Lista *lista, int id);
/**
 * @brief Remove o ultimo elemento da lista
 * 
 * @param lista ponteiro para a lista
 * @return int 
 */
int lista_remover_fim(Lista *lista);

//BUSCA NA LISTA
/**
 * @brief Busca um elemeto da lista e o atribui a referencia se existir
 * 
 * @param lista ponteiro para lista
 * @param id identidicador do elemento
 * @param pessoa referencia para atribuir o elemento
 * @return int 
 */
int lista_buscar_elemento(Lista *lista, int id, Pessoa *pessoa);
/**
 * @brief Busca por um elemento em uma determinada posicao da lista e o atribui a referencia se existir.
 * 
 * @param lista referencia para a lista
 * @param posicao posição da lista para fazer a busca
 * @param pessoa referencia para atribuir o elemento
 * @return int 
 */
int lista_buscar_posicao(Lista *lista, int posicao, Pessoa *pessoa);

#endif