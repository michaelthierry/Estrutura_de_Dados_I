/**
 * @file main.c
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

void usuario();
Pessoa pegar_dados();

int main(){
    //Chama a função do usuario
    usuario();

    return 0;
}

void usuario(){
    //Criando as variaveis
    Lista *lista;
    Pessoa pessoa;
    //Mensagem para o usuario
    printf("@> Criando lista\n");
    //Tenta alocar memoria para a lista
    lista = lista_criar();
    //Verifica se a lista foi criada
    if(lista != NULL){
        //Mostrando informaçoes da lista
        printf(
            "@> Lista Criada\n"
            "@> Tipo: Lista Linear Estatica\n"
            "@> Tamanho Maximo: %i elementos\n", MAX
        );
        //Variavel de opção
        int opcao;
        do{
            //Mostrando as opções 
            printf(
                   "+------------------------------------------+\n"
                   "|               OPERACOES                  |\n"
                   "+------------------------------------------+\n"
                   "|[1] Inserir no inicio da lista            |\n"
                   "|[2] Inserir em ordem na lista (por ID)    |\n"
                   "|[3] Inserir no fim da lista               |\n"
                   "|[4] Remover do inicio da lista            |\n"
                   "|[5] Remover do meio (por ID)              |\n"
                   "|[6] Remover do fim da lista               |\n"
                   "|[7] Mostrar lista                         |\n"
                   "|[8] Consultar (por indice)                |\n"
                   "|[9] Consultar (por ID)                    |\n"
                   "|[0] Sair                                  |\n"
                   "+------------[Insira-sua-opção]------------+\n"
            );
            //Lendo do usuario
            scanf("%i", &opcao);
            //Avaliando a opcao
            switch(opcao){
                int estado, id;
                case 0:
                    break;
                case 1:
                    //Pegando informações
                    pessoa = pegar_dados();
                    //Insere na lista
                    estado = lista_inserir_inicio(lista, pessoa);
                    printf("@> Estado: %i\n", estado);
                    break;
                case 2:
                    //Pegando informações
                    pessoa = pegar_dados();
                    //Insere na lista
                    estado = lista_inserir_ordenado(lista, pessoa);
                    printf("@> Estado: %i\n", estado); 
                    break;
                case 3:
                    //Pegando informações
                    pessoa = pegar_dados();
                    //Insere na lista
                    estado = lista_inserir_fim(lista, pessoa); 
                    printf("@> Estado: %i\n", estado);
                    break;
                case 4:
                    //Remove da lista
                    estado = lista_remover_inicio(lista); 
                    printf("@> Estado: %i\n", estado);
                    break;
                case 5:
                    // Pegando o id
                    printf("@> Digite o ID da pessoa\n");
                    scanf("%i", &id);
                    //Remove da lista
                    estado = lista_remover_elemento(lista, id); 
                    printf("@> Estado: %i\n", estado);
                    break;
                case 6:
                    //Remove da lista
                    estado = lista_remover_fim(lista); 
                    printf("@> Estado: %i\n", estado);
                    break;
                case 7:
                    estado = lista_exibir(lista);
                    printf("@> Estado: %i\n", estado);
                    break;
                case 8:
                    break;
                case 9:
                    break;
                default:
                    break;
            }

        }while(opcao != 0);

    }else{
        printf("@> Erro: ao criar a lista\n");
    }
    //Destruir a lista
    lista_deletar(lista);
    printf("@> Lista Destruida\n");

}

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
