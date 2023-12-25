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
// Mensagens
#define SUCESSO "@> SUCESSO: "
#define FALHA "@> FALHA: "
// Codigo de Operações
#define INSERIR 1
#define REMOVER 2

void usuario();
void validar_operacao(int valida, int estado);
void validar_busca(int valida, Pessoa pessoa);

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
            "@> Lista Criada \n"
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
                int estado, indice, id;
                case 0:
                    break;
                case 1:
                    //Pegando informações
                    pessoa = pegar_dados();
                    //Insere na lista
                    estado = lista_inserir_inicio(lista, pessoa);
                    //verificar operação
                    validar_operacao(estado, INSERIR);
                    break;
                case 2:
                    //Pegando informações
                    pessoa = pegar_dados();
                    //Insere na lista
                    estado = lista_inserir_ordenado(lista, pessoa);
                    //verificar operação
                    validar_operacao(estado, INSERIR);
                    break;
                case 3:
                    //Pegando informações
                    pessoa = pegar_dados();
                    //Insere na lista
                    estado = lista_inserir_fim(lista, pessoa); 
                    //verificar operação
                    validar_operacao(estado, INSERIR);
                    break;
                case 4:
                    //Remove da lista
                    estado = lista_remover_inicio(lista); 
                    //verificar operação
                    validar_operacao(estado, REMOVER);
                    break;
                case 5:
                    // Pegando o id
                    printf("@> Digite o ID da pessoa\n");
                    scanf("%i", &id);
                    //Remove da lista
                    estado = lista_remover_elemento(lista, id); 
                    //verificar operação
                    validar_operacao(estado, REMOVER);
                    break;
                case 6:
                    //Remove da lista
                    estado = lista_remover_fim(lista); 
                    //verificar operação
                    validar_operacao(estado, REMOVER);
                    break;
                case 7:
                    estado = lista_exibir(lista);
                    printf("@> Estado: %i\n", estado);
                    break;
                case 8:
                    printf("@> Digite o indice:\n");
                    scanf("%i", &indice);
                    estado = lista_buscar_posicao(lista, indice, &pessoa);
                    // verificar operação
                    validar_busca(estado, pessoa);
                    break;
                case 9:
                    printf("@> Digite o ID:\n");
                    scanf("%i", &id);
                    estado = lista_buscar_elemento(lista, id, &pessoa);
                    // verificar operação
                    validar_busca(estado, pessoa);
                    break;
                default:
                    printf("@> Opção Invalida\n");
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

void validar_operacao(int valida, int codigo){
    switch(codigo){
        case 1:
            if(valida > 0){
                printf(SUCESSO "Ao inserir na lista\n");
            }else{
                printf(FALHA "Ao inserir na lista\n");
            }
            break;
        case 2:
            if(valida > 0){
                printf(SUCESSO "ao remover da lista\n");
            }else{
                printf(FALHA "Ao remover da lista\n");
            }
            break;
        default:
            printf(FALHA "Código invalido\n");
            break;
    }
}

void validar_busca(int valida, Pessoa pessoa){
    if(valida > 0){
        printf(SUCESSO "Elemento encontrado\n");
        printf("@> Elemento:\nID:[%d]\nNome:[%s]\n", pessoa.id, pessoa.nome);
    }else{
        printf(FALHA "Elemento nao encontrado\n");
    }
}
