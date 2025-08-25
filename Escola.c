#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "All.h"

int menu()
{
    int selecaoPrimal;
    printf("Menu Principal.\n");
    printf("0. Sair Principal\n"
           "1. Menu Aluno\n"
           "2. Menu Professor\n"
           "3. Menu Disciplina\n");
    scanf("%d", &selecaoPrimal);
    return selecaoPrimal;
}

int main()
{
    int selecaoPrimal = 0;
    Student aluno[TAM_LISTA_ALUNO];
    int qtdAlunoIF = 0;

    while (!selecaoPrimal)
    {
        selecaoPrimal = menu();
        switch (selecaoPrimal)
        {
        case 0:
            printf("Saindo em 3... 2... 1...\n");
            break;
        case 1:
        {
            int selecaoAluno = 0;
            int sair = 0;
            while (!sair)
            {
                printf("Menu Aluno.\n");
                printf("0. Voltar ao Menu Principal\n"
                       "1. Criar Aluno\n"
                       "2. Ler Aluno\n"
                       "3. Atualizar Dados do Aluno\n"
                       "4. Deletar Aluno\n");
                scanf("%d", &selecaoAluno);
                getchar();

                switch (selecaoAluno)
                {
                case 1:
                {
                    Nascimento data[TAM_LISTA_ALUNO];
                    CPF cpf[TAM_LISTA_ALUNO];
                    int resultado = createStudent(aluno, qtdAlunoIF, data, cpf);
                    switch (resultado)
                    {
                    case SUCESSO_CADASTRO:
                        printf("Cadastro realizado com sucesso.\n");
                        aluno[qtdAlunoIF].chamadaAluno=qtdAlunoIF+1;
                        aluno[qtdAlunoIF].ativoAluno=1;
                        qtdAlunoIF++;
                        break;
                    case ERRO_CADASTRO_SEXO:
                        printf("Erro no cadastro, sexo invalido.\n");
                        printf("Sexo deve ser F/f para feminino e M/m para masculino.\n");
                        break;
                    case ERRO_CADASTRO_MATRICULA:
                        printf("Erro no cadastro, CPF invalido.\n");
                        break;
                    case ERRO_DATA_INVALIDA:
                        printf("Erro no cadastro, data invalida.\n");
                        break;
                    default:
                    printf("ERRO DESCONHECIDO.\n");
                        break;
                    }
                    break;
                }
                case 2:
                {
                    int selecaoLeitura = 0;
                    int sairLeitura = 0;
                    while (!sairLeitura)
                    {
                        printf("Menu de Leitura de Alunos.\n");
                        printf("1. Ler todos os Alunos\n"
                               "2. Ler Alunos por sexo\n"
                               "3. Ler Alunos por data de nascimento\n"
                               "4. Ler Alunos ordenados por nome\n"
                               "0. Voltar\n");
                        scanf("%d", &selecaoLeitura);
                        getchar();
                        switch (selecaoLeitura)
                        {
                        case 1:
                        Nascimento data[11];
                        CPF cpf[12];
                            readStudent(aluno, qtdAlunoIF, data, cpf);
                            break;
                        case 2:
                        {
                            printf("Digite o sexo para busca (M/F): ");
                            char sexo;
                            scanf(" %c", &sexo);
                            getchar();
                            // readSexStudent(aluno, qtdAlunoIF, sexo);
                            break;
                        }
                        case 3:
                        {
                            Nascimento data[12];
                            // readDataStudent(aluno, qtdAlunoIF, data);
                            break;
                        }
                        case 4:
                            // readOrdenadosStudants(aluno, qtdAlunoIF);
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

                    Nascimento data[11];
                    CPF cpf[12];
                    atualizacaodeDados(aluno, qtdAlunoIF, data, cpf);
                    getchar();
                    break;
                case 4:
                    deletarStudent(aluno, qtdAlunoIF);
                    break;
                case 0:
                    sair = 1;
                    break;
                default:
                    printf("Opcao invalida.\n");
                    break;
                
            
            break;
        
        // case 2:
        // {
        //     printf("Menu Professor.\n");
        //     int sairProfessor = 0;
        //     int selecaoProfessor = 0;
        //     while (!sairProfessor)
        //     {
        //         printf("0. Voltar\n"
        //                "1. criar  Matricula do Professor\n"
        //                "2. Ler Matriculas dos Professores\n"
        //                "3. Atualizar Matriculas dos Professores\n"
        //                "4. Deletar Matriculas dos Professores\n");
        //         scanf("%d", &selecaoProfessor);
        //         getchar();
        //         switch (selecaoProfessor)
        //         {
        //         case 1:
        //             Teacher professor[TAM_LISTA_PROFESSOR];
        //             Nascimento data[TAM_LISTA_PROFESSOR];
        //             CPF cpf[TAM_LISTA_PROFESSOR];
        //             int qtd;
        //             printf("Criar Matricula do Professor.\n");
        //             creatTeacher(professor, qtd, data, cpf);
        //             qtd++;
        //             break;
        //         case 2:
        //         {
        //             printf("Ler Matriculas dos Professores: ");
        //             int selecaoLeitura = 0;
        //             while (!selecaoLeitura)
        //             {
        //                 printf("Menu de Leitura de Professores.\n");
        //                 printf("1. Ler todos os Professores\n"
        //                        "2. Ler Professores por sexo\n"
        //                        "3. Ler Professores por data de nascimento\n"
        //                        "4. Ler Professores ordenados por nome\n"
        //                        "0. Voltar\n");
        //                 scanf("%d", &selecaoLeitura);
        //                 getchar();
        //                 switch (selecaoLeitura)
        //                 {
        //                 case 1:
        //                     Teacher professor[TAM_LISTA_PROFESSOR];
        //                     Nascimento data[TAM_LISTA_PROFESSOR];
        //                     CPF cpf[TAM_LISTA_PROFESSOR];
        //                     int qtd;
        //                     readTeacher(professor, qtd, data, cpf);
        //                     break;
        //                 case 2:
        //                 {
        //                     char sexo;
        //                     readSexTeacher(professor, qtd, sexo, data, cpf);
        //                     break;
        //                 }
        //                 case 3:
        //                 {
        //                     Nascimento data[11];
        //                     readDataTeacher(professor, qtd, data, cpf);

        //                     break;
        //                 }
        //                 case 4:
        //                     readOrdenadosTeachers(professor, qtd, data, cpf);
        //                     break;
        //                 case 0:
        //                     sairProfessor = 1;
        //                     break;
        //                 default:
        //                     printf("Opcao invalida.\n");
        //                     break;
        //                 }
        //             }
        //         }
        //         break;
        //         }
        //     }
        // }
        // case 3:
        //     printf("Menu Disciplina.\n");
        //     int sairDisciplina = 0;
        //     int selecaoDisciplina = 0;
        //     while (!sairDisciplina)
        //     {
        //         printf("0. Voltar\n"
        //                "1. criar Disciplina\n"
        //                "2. Ler Disciplinas\n"
        //                "3. Atualizar Disciplinas\n"
        //                "4. Deletar Disciplinas\n");
        //         scanf("%d", &selecaoDisciplina);
        //         getchar();
        //         switch (selecaoDisciplina)
        //         {
        //         case 1:
        //             Disciplina disc[TAM_LISTA_DISCIPLINA];
        //             int qtd;
        //             printf("Criar Disciplina.\n");
        //             criarDisciplina(disc, qtd);
        //             break;
        //         case 2:
        //         {
        //             int selecaoleituraDisciplina = 0;
        //             while (!sairDisciplina)
        //             {
        //                 printf("Menu de Leitura de Disciplinas.\n");
        //                 printf("1. Ler todas as Disciplinas\n"
        //                        "2. Ler Alunos com poucas Disciplinas\n"
        //                        "3. Ler Turmas com mais de 40 Alunos\n"
        //                        "0. Voltar\n");
        //                 scanf("%d", &selecaoleituraDisciplina);
        //                 getchar();
        //                 switch (selecaoleituraDisciplina)
        //                 {
        //                 case 1:
        //                     readDisciplina(disc, qtd);
        //                     break;
        //                 case 2:
        //                     printf("Alunos com menos de 3 Disciplinas.\n");
        //                     Student aluno[TAM_LISTA_ALUNO];
        //                     Nascimento DATA[TAM_LISTA_ALUNO];
        //                     CPF cpf[TAM_LISTA_ALUNO];
        //                     int qtdAlunoIF;
        //                     alunoEmMenosDe3(disc, aluno, qtdAlunoIF, DATA, cpf);
        //                     break;
        //                 case 3:
        //                     printf("Turmas com mais de 40 Alunos.\n");
        //                     Student aluno2[TAM_LISTA_ALUNO];
        //                     Nascimento DATA2[TAM_LISTA_ALUNO];
        //                     CPF cpf2[TAM_LISTA_ALUNO];
        //                     int qtdAlunoIF2;
        //                     turmaComMaisDe40Alunos(disc, aluno2, qtdAlunoIF2, DATA2, cpf2);
        //                     break;
        //                 case 0:
        //                     sairDisciplina = 1;
        //                     break;
        //                 default:
        //                     printf("Opcao invalida.\n");
        //                     break;
        //                 }
        //             }
        //             break;
        //         }
        //         case 3:
        //             printf("Atualizar Disciplinas.\n");
        //             break;
        //         case 4:
        //             printf("Deletar Disciplinas.\n");
        //             break;
        //         case 0:
        //             sairDisciplina = 1;
        //             break;
        //         default:
        //             printf("Opcao invalida.\n");
        //             break;
        }
    }
        break;
        default:
            printf("Opcao invalida.\n");
            break;
}
}
    }
return 0;
}
