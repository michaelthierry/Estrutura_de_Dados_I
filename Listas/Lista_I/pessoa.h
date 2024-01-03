/**
 * @file pessoa.h
 * @author Michael Thierry (michaelthierry86@gmail.com)
 * @brief Tipo de dados Pessoa
 * @version 0.1
 * @date 2024-01-02
 * 
 * @copyright Copyright (c) 2024
 * 
 */

//definindo as macros
#ifndef PESSOA_H
#define PESSOA_H

//definindo o tipo pessoa
typedef struct pessoa{
    int id;
    char nome[50];
    int idade;
    float peso;
}Pessoa;

//declarando funções

/**
 * @brief Cria um elemento pessoa e atribui os valores passado pelo usuário a ele.
 * A seguir retorna o elemento criado.
 * @return Pessoa 
 */
Pessoa pegar_dados();

/**
 * @brief Exibe as informações da pessoa passada
 * 
 * @param pessoa referencia de uma pessoa
 */
void exibir_dados(Pessoa *pessoa);

#endif