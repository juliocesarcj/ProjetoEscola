#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "All.h"

int createStudent(Student aluno[], int qtdAluno, Nascimento data[], CPF cpf[])
{
    aluno[qtdAluno].id = 2025003 + qtdAluno;

    printf("Criar Matricula Aluno.\n");
    fgets(aluno[qtdAluno].nameAluno, 250, stdin);

    printf("digite o sexo do aluno (M/F): \n");
    scanf(" %c", &aluno[qtdAluno].sexoAluno);
    getchar();
    if (aluno[qtdAluno].sexoAluno != 'M' && aluno[qtdAluno].sexoAluno != 'F' && aluno[qtdAluno].sexoAluno != 'f' && aluno[qtdAluno].sexoAluno != 'm')
    {
        return ERRO_CADASTRO_SEXO;
    }
    printf("digite a idade do aluno: \n");
    scanf("%d", &aluno[qtdAluno].idadeAluno);

    printf("digite o cpf do aluno: \n");
    scanf("%s", aluno[qtdAluno].cpfAluno);
    getchar();
    int validade = validacaodeCPF(cpf, qtdAluno);
    if (validade == valido)
    {
        return falha;
    }
    else
    {
        return falha;
    }
    printf("digite data de nascimento\n");
    scanf("%d/%d/%d", &data[qtdAluno].dia, &data[qtdAluno].mes, &data[qtdAluno].ano);
    sprintf(data[qtdAluno].data, "%02d/%02d/%04d", data[qtdAluno].dia, data[qtdAluno].mes, data[qtdAluno].ano);

    printf("digite o nome do aluno: \n");
    fgets(aluno[qtdAluno].nameAluno, 250, stdin);
    while(aluno[qtdAluno].nameAluno[0] == '\n'){
    if(aluno[qtdAluno].nameAluno[0] == '\n'){
        aluno[qtdAluno].nameAluno[0] = '\0';
    }
}
    aluno[qtdAluno].chamadaAluno = qtdAluno + 1;
    return SUCESSO_CADASTRO;
}

void readStudent(Student aluno[], int qtdAluno)
{
    printf("entrou na funcao\n%d", qtdAluno);
    for (int i = 0; i < qtdAluno; i++)
    {
        printf("\nNumero de Chamada: %d", aluno[i].chamadaAluno);
        printf("\nmatricula: MAT%d", aluno[i].id);
        printf("\nNome: %s", aluno[i].nameAluno);
        printf("\nSexo: %c", aluno[i].sexoAluno);
        printf("\nIdade: %d", aluno[i].idadeAluno);
        printf("\nCPF: %s\n", aluno[i].cpfAluno);
        aluno[i].chamadaAluno++;
    }
}

void atualizacaodeDados(Student aluno[], int qtdAluno)
{
    printf("Funcao de atualizacao de dados do aluno.\n");
    int sair = 0, opcao, chamada;
    while (!sair)
    {
        printf("Menu de atualizacao.\n");
        printf("Selecione o aluno por numero de chamada:\n");
        scanf("%d", &chamada);
        printf("atualizar nome do aluno"
               "1. Atualizar idade do aluno\n"
               "2. Atualizar sexo do aluno\n"
               "3. Atualizar CPF do aluno\n"
               "4. Exit\n");
        scanf("%d", &opcao);     
             for (int i = 0; i < qtdAluno; i++)
            {
                if (aluno[i].chamadaAluno == chamada)
                {     
                    switch (opcao)
                    {
                    case 1:
                        printf("Atualizar nome do Aluno.\n");
                        printf("Digite o novo nome: ");
                        fgets(aluno[i].nameAluno, 255, stdin);
                        break;
                    case 2:
                        printf("Atualizar idade do Aluno.\n");
                        printf("Digite a nova idade: ");
                        scanf("%d", &aluno[i].idadeAluno);
                        getchar();
                        break;
                    case 3:
                        printf("Atualizar sexo do Aluno.\n");
                        printf("Digite o novo sexo (M/F): ");
                        scanf(" %c", &aluno[i].sexoAluno);
                        getchar();
                        break;
                    case 4:
                        printf("Atualizar CPF do Aluno.\n");
                        printf("Digite o novo CPF: ");
                        scanf("%s", aluno[i].cpfAluno);
                        getchar();
                        int validade = validacaodeCPF(aluno, qtdAluno);
                         if (validade == valido)
                        {
                            printf("CPF atualizado com sucesso.\n");
                        }
                        else
                        {
                            printf("CPF invalido. Atualizacao nao realizada.\n");
                        }
                        break;
                    case 0:
                        sair = 1;
                        break;
                    default:
                        printf("Opcao invalida, tente novamente.\n");
                    }
                }
            }
    }
}

int deletarStudent(Student aluno[], int qtdAluno)
{
    printf("Funcao deletar aluno.\n");
    int chamada;
    printf("Digite o numero de chamada do aluno a ser deletado: ");
    scanf("%d", &chamada);
    for (int i = 0; i < qtdAluno; i++)
    {
        if (aluno[i].ativoAluno == 1 && aluno[i].chamadaAluno == chamada)
        {
            aluno[i].ativoAluno = 0;
        }
    }
}

void readSexStudent(Student aluno[], int qtdAluno, char sexo)
{
    for (int i = 0; i < qtdAluno; i++)
    {
        if (aluno[i].sexoAluno == sexo && aluno[i].ativoAluno == 1)
        {
            printf("\nNumero de Chamada: %d", aluno[i].chamadaAluno);
            printf("\nmatricula: MAT%d", aluno[i].id);
            printf("\nNome: %s", aluno[i].nameAluno);
            printf("\nSexo: %c", aluno[i].sexoAluno);
            printf("\nIdade: %d", aluno[i].idadeAluno);
            printf("\nCPF: %s\n", aluno[i].cpfAluno);
        }
    }
}
void readDataStudent(Student aluno[], int qtdAluno,Nascimento dataAluno[], CPF cpf[], char data[])
{
    for (int i = 0; i < qtdAluno; i++)
    {
        if (strcmp(dataAluno[i].data, data) == 0 && aluno[i].ativoAluno == 1)
        {
            printf("\nNumero de Chamada: %d", aluno[i].chamadaAluno);
            printf("\nmatricula: MAT%d", aluno[i].id);
            printf("\nNome: %s", aluno[i].nameAluno);
            printf("\nSexo: %c", aluno[i].sexoAluno);
            printf("\nIdade: %d", aluno[i].idadeAluno);
            printf("\nCPF: %s\n", aluno[i].cpfAluno);
        }
    }
}

void readOrdenadosStudants(Student aluno[], int qtdAluno)
{
    char vetor[255];
    for(int i=0; i<qtdAluno; i++){
        vetor[i] = aluno[i].nameAluno;
    }
    char aux;
    for (int i = 0; i < qtdAluno - 1; i++)
    {
        for (int j = i + 1; j < qtdAluno; j++)
        {
            if (strcmp(aluno[i].nameAluno, aluno[j].nameAluno) > 0)
            {
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
}