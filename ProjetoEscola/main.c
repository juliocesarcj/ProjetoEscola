#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "All.h"
int menu()
{
    int selecao;
    printf("Menu Principal.\n");
    printf("0. Exit\n"
           "1. Criar\n"
           "2. Ler\n"
           "3. atualizar\n"
           "4. Deletar\n");
    scanf("%d", &selecao);
    return selecao;
}
int main()
{
    Student *Pilha = NULL;
    int bise = 0;
    int qtdAluno = 1;
    int sair = 0;
    Pilha = (Student *)malloc(qtdAluno * sizeof(Student));
    if (Pilha == NULL)
    {
        printf("Memory allocation fail.\n");
        return -1;
    }
    else
    {
        Pilha->id = 0;
        Pilha->ativoAluno = 0;
        Pilha->qtdAluno = 0;
        Pilha->sexoAluno = ' ';
        Pilha->topAluno = Pilha->qtdAluno;
        Pilha->idadeAluno = 0;
    }
    int selecao = menu();
    while (!sair)
    {
        switch (selecao)
        {
        case 0:
            sair = 1;
            break;
        case 1:
         int ExitAluno = 0;


    while (!ExitAluno)
    {
        printf("Menu de criacao.\n");
        printf("Menu:\n"
               "0. Exit\n"
               "1. Criar Matricula Aluno\n"
               "2. Criar Matricula Professor\n"
               "3. Criar Disciplina\n");
        scanf("%d", &bise);
        switch (bise)
        {
        case 1:
            printf("Criar Matricula Aluno.\n");
            printf("digite o nome do aluno: \n");
            scanf("%s", Pilha->nameAluno);
            getchar();
            printf("digite o sexo do aluno: \n");
            scanf(" %c", &Pilha->sexoAluno);
            getchar();
            printf("digite a idade do aluno: \n");
            scanf("%d", &Pilha->idadeAluno);
            printf("digite o cpf do aluno: \n");
            scanf("%s", Pilha->cpfAluno);
            getchar();
            createStudent(Pilha);
            break;
                
        case 2:
            printf("Criar Matricula Professor.\n");
            int sairAtt = 0;
    int quase = 0;
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

        case 1:
            printf("Atualizar Matricula Aluno.\n");
            break;
        case 2:
            printf("Atualizar Matricula Professor.\n");
            break;
        case 3:
            printf("Atualizar Disciplina.\n");
            break;
        case 0:
            sairAtt = 1;
            break;
        default:
            printf("Opcao invalida.\n");
            break;
        }
    }
            break;
        case 3:
            printf("Criar Disciplina.\n");

            break;
        case 0:
            ExitAluno = 1;
            break;
        default:
            printf("Opcao invalida.\n");
        }
}
        break;
        }
    }
   
   
    
    int sairDeletar = 0;
    int quinse = 0;
    while (!sairDeletar)
    {
        printf("Menu de deletar.\n");
        printf("1. Deletar Matricula Aluno\n"
               "2. Deletar Matricula Professor\n"
               "3. Deletar Disciplina\n"
               "0. Exit\n");
        switch (quinse)
        {

        case 1:
            printf("Deletar Matricula Aluno.\n");
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
}
