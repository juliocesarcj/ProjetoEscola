#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "All.h"

int menu()
{
    int selecaoPrimal;
    printf("Menu Principal.\n");
    printf("0. Exit\n"
           "1. Criar\n"
           "2. Ler\n"
           "3. atualizar\n"
           "4. Deletar\n");
    scanf("%d", &selecaoPrimal);
    if (selecaoPrimal == 0)
    {
        exit(1);
    }
    return selecaoPrimal;
}

int main()
{
    int volte = 0;
    int sairprimal = 0;
    Student aluno[TAM_LISTA_ALUNO];
    int selecaoPrimal = 0;
    selecaoPrimal = menu();
    int sair = 0;
    int qtdAlunoIF = 0;
    Nascimento calendario[11];
    int sairDeletar = 0;
    int sairLeitura = 0;
    int quinse = 0;
    int quase;

    while (!sairprimal)
    {
        switch (selecaoPrimal)
        {
        case 0:
        {
            sairprimal = 1;
            break;
        }
        case 1:
        {
            int selecao;
            int sair = 0;
            while (!sair)
            {
                printf("Menu de criacao.\n");
                printf("Menu:\n"
                       "0. Exit\n"
                       "1. Criar Matricula Aluno\n"
                       "2. Criar Matricula Professor\n"
                       "3. Criar Disciplina\n"
                       "4. Menu Principal\n");
                scanf("%d", &selecao);
                switch (selecao)
                {
                case 0:
                {
                    sair = menu();
                    break;
                }
                case 1:
                {
                    volte = createStudent(aluno, qtdAlunoIF, calendario);

                    switch (volte)
                    {
                    case SUCESSO_CADASTRO:
                        printf("Cadastro realizado com sucesso.\n");
                        qtdAlunoIF++;
                        break;

                    case ERRO_CADASTRO_SEXO:
                        printf("Erro no cadastro, sexo invalido.\n");
                        printf("sexo deve ser F/f para feminino e M/m para masculino.\n");
                        break;
                    }
                    break;
                }
                case 2:
                {
                    printf("Criar Matricula Professor.\n");
                    break;
                }
                case 3:
                {
                    printf("Criar Disciplina.\n");
                    break;
                }
                case 4:
                {
                    sair = menu();
                    break;
                }
                default:
                {
                    printf("Opcao invalida.\n");
                    break;
                }
                }
            }
            break;
        }

        case 2:
        {
            while (!sairLeitura)
            {
                printf("Menu de leitura.\n");
                printf("1. Ler Matricula Aluno\n"
                       "2. Ler Matricula Professor\n"
                       "3. Ler Disciplina\n"
                       "0. Exit\n");
                scanf("%d", &quinse);
                switch (quinse)
                {
                case 1:
                    printf("Ler Matricula Aluno.\n");
                    readStudent(aluno, qtdAlunoIF, calendario);
                    break;
                case 2:
                    printf("Ler Matricula Professor.\n");
                    break;
                case 3:
                    printf("Ler Disciplina.\n");
                    break;
                case 0:
                    sairLeitura = 1;
                    break;
                default:
                    printf("Opcao invalida.\n");
                    break;
                }
            }
            break;
        }

        case 3:
        {
            int sairAtt = 0;
            while (!sairAtt)
            {
                printf("Menu de atualizacao.\n");
                printf("Menu:\n"
                       "0. Exit\n"
                       "1. Atualizar Matricula Aluno\n"
                       "2. Atualizar Matricula Professor\n"
                       "3. Atualizar Disciplina\n");
                scanf("%d", &quase);
                switch (quase)
                {
                case 0:
                    sairAtt = 1;
                    break;
                case 1:
                    printf("Atualizar Matricula Aluno.\n");
                    atualizacaodeDados(aluno, qtdAlunoIF, calendario);
                    break;
                case 2:
                    printf("Atualizar Matricula Professor.\n");
                    break;
                case 3:
                    printf("Atualizar Disciplina.\n");
                    break;
                default:
                    printf("Opcao invalida.\n");
                    break;
                }
            }
            break;
        }

        case 4:
        {
            while (!sairDeletar)
            {
                printf("Menu de deletar.\n");
                printf("1. Deletar Matricula Aluno\n"
                       "2. Deletar Matricula Professor\n"
                       "3. Deletar Disciplina\n"
                       "0. Exit\n");
                scanf("%d", &quase);
                switch (quase)
                {
                case 1:
                    printf("Deletar Matricula Aluno.\n");
                    deletarStudent(aluno, qtdAlunoIF);
                    break;
                case 2:
                    printf("Deletar Matricula Professor.\n");
                    break;
                case 3:
                    printf("Deletar Disciplina.\n");
                    break;
                case 0:
                    sairDeletar = 1;
                    break;
                default:
                    printf("Opcao invalida.\n");
                    break;
                }
            }
            break;
        }

        default:
            printf("Opcao invalida.\n");
            break;
        }
    }

    return 0;
}
