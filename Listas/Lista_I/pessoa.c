/**
 * @file pessoa.c
 * @author Michael Thierry (michaelthierry86@gmail.com)
 * @brief Tipo de dados Pessoa
 * @version 0.1
 * @date 2024-01-02
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>
#include "pessoa.h"

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

void exibir_dados(Pessoa *pessoa){
    if(pessoa == NULL){
        printf("Erro: Pessoa Null");
    }else{
        printf(
            "+------------------------------------------+\n"
            "|    |ID:[%i]\n"            
            "|    |Nome:%s"
            "|    |Idade:%i\n"
            "|    |Peso:%.2f\n"
            "+------------------------------------------+\n",
            pessoa->id,
            pessoa->nome,
            pessoa->idade,
            pessoa->peso
        );
    }
}
