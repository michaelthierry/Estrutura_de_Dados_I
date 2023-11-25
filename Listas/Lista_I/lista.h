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

#endif