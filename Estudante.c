#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "All.h"

int createStudent(Student aluno[], int qtdAluno, Nascimento calendario[], CPF cpf[])
{
    aluno[qtdAluno].id = 2025003 + qtdAluno;

    printf("digite o nome do aluno: \n");
    fgets(aluno[qtdAluno].nameAluno, 250, stdin);
    for (int i = 0; aluno[qtdAluno].nameAluno[i] != '\0'; i++)
    {
        if (aluno[qtdAluno].nameAluno[i] == '\n')
        {
            aluno[qtdAluno].nameAluno[i] = '\0';
        }
    }
    printf("Criar Matricula Aluno.\n");
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
    printf("digite a data de nascimento do aluno (dd/mm/aaaa): \n");
    fgets(calendario[qtdAluno].data, 11, stdin);
    if (ISBIX(calendario, qtdAluno) == invalido)
    {
        return ERRO_DATA_INVALIDA;
    };

    int validade = validacaodeCPF(cpf, qtdAluno);
    if (validade == invalido)
    {
        printf("CPF invalido. Cadastro nao realizado.\n");
        return invalido;
    }
    printf("\n");
    return SUCESSO_CADASTRO;
}

void readStudent(Student aluno[], int qtdAluno, Nascimento data[], CPF cpf[])
{
    if (qtdAluno == 0)
    {
        printf("Nenhum aluno cadastrado.\n");
        return;
    }
    for (int i = 0; i < qtdAluno; i++)
    {
        if (aluno[i].ativoAluno == 1)
        {
            printf("\nNumero de Chamada: %d", aluno[i].chamadaAluno);
            printf("\nmatricula: MAT%d", aluno[i].id);
            printf("\nNome: %s", aluno[i].nameAluno);
            printf("\nSexo: %c", aluno[i].sexoAluno);
            printf("\nIdade: %d", aluno[i].idadeAluno);
            printf("\nCPF: %s\n", aluno[i].cpfAluno);
            sprintf(data[i].data, "%02d/%02d/%04d", data[i].dia, data[i].mes, data[i].ano);
            printf("Data de Nascimento: %s\n", data[i].data);
            aluno[i].chamadaAluno++;
        }
    }
}

void atualizacaodeDados(Student aluno[], int qtdAluno, Nascimento cal[], CPF cpf[])
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
               "2. Atualizar idade do aluno\n"
               "3. Atualizar Data de nascimento do aluno\n"
               "4. Atualizar CPF do aluno\n"
               "0. Exit\n");
        scanf("%d", &opcao);
        for (int i = 0; i < qtdAluno; i++)
        {
            if (aluno[i].chamadaAluno == chamada && aluno[i].ativoAluno == 1)
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
                    printf("Atualizar data de nascimento do Aluno.\n");
                    printf("Digite a nova data de nascimento (dd/mm/aaaa): ");
                    fgets(cal[i].data, 11, stdin);
                    int diabi = atoi(cal[i].data);
                    if (diabi == ERRO_DATA_INVALIDA)
                    case 5:
                        printf("Atualizar CPF do Aluno.\n");
                    printf("Digite o novo CPF: ");
                    scanf("%s", aluno[i].cpfAluno);
                    getchar();
                    int validade = validacaodeCPF(cpf, qtdAluno);
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
    chamada + 1;
    int achou = 0;
    if (chamada <= 0)
        printf("Este aluno nao existe\n");
    
        for(int i = 0; i < qtdAluno; i++)
        {
            if (aluno[i].ativoAluno == 1 && aluno[i].chamadaAluno == chamada)
            {
                printf("Aluno ^^%s^^ encontrado e deletado com sucesso.\n", aluno[i].nameAluno);
            }
            else if (aluno[i].ativoAluno == 0 && aluno[i].chamadaAluno == chamada)
            {
                printf("Este aluno nao foi encontrado.\n");
                return 0;
            }
        }
    for (int i = 0; i < qtdAluno; i++)
    {
        if (aluno[i].chamadaAluno == chamada)
        {
            aluno[i].ativoAluno = 0;
            for (int j = i; j < qtdAluno - 1; j++)
            {
                aluno[j].ativoAluno = aluno[j + 1].ativoAluno;
                aluno[j].sexoAluno = aluno[j + 1].sexoAluno;
                aluno[j].id = aluno[j + 1].id;
            }
            qtdAluno--;
            achou = 1;
        }
    }

    if (achou == 1)
    {
        printf("Aluno encontrado.\n");
    }
    else
    {
        printf("Aluno nao encontrado.\n");
        return 0;
    }
}

void readSexStudent(Student aluno[], int qtdAluno, Nascimento data[], CPF cpf[])
{
    char sexo;
    printf("Digite o sexo do aluno (M/F): \n");
    scanf(" %c", &sexo);
    getchar();
    int encontrado = 0;
    if (qtdAluno == 0)
    {
        printf("Nenhum aluno cadastrado.\n");
        return;
    }

    if (sexo != 'M' && sexo != 'F' && sexo != 'f' && sexo != 'm')
    {
        printf("Sexo invalido. Use M/m para masculino e F/f para feminino.\n");
        return;
    }
    for (int i = 0; i < qtdAluno; i++)
    {
         if (sexo == aluno[i].sexoAluno && aluno[i].ativoAluno == 1)
        {
            printf("\nNumero de Chamada: %d", aluno[i].chamadaAluno);
            printf("\nmatricula: MAT%d", aluno[i].id);
            printf("\nNome: %s", aluno[i].nameAluno);
            printf("\nSexo: %c", aluno[i].sexoAluno);
            printf("\nIdade: %d", aluno[i].idadeAluno);
            printf("\nCPF: %s\n", aluno[i].cpfAluno);
            sprintf(data[i].data, "%02d/%02d/%04d", data[i].dia, data[i].mes, data[i].ano);
            printf("Data de Nascimento: %s\n", data[i].data);
            aluno[i].chamadaAluno++;
        }
    }
}

void readOrdenadosStudants(Student aluno[], int qtdAluno, Nascimento data[], CPF cpf[])
{
    if (qtdAluno <= 0)
    {
        printf("Nenhum aluno para ordenar.\n");
        return;
    }

    Student tempAluno[qtdAluno];
    for (int i = 0; i < qtdAluno; i++)
    {
        tempAluno[i] = aluno[i];
    }

    for (int i = 0; i < qtdAluno - 1; i++)
    {
        for (int j = 0; j < qtdAluno - i - 1; j++)
        {

            if (tempAluno[j].nameAluno > tempAluno[j + 1].nameAluno)
            {
                Student temp = tempAluno[j];
                tempAluno[j] = tempAluno[j + 1];
                tempAluno[j + 1] = temp;

                CPF tempCpf = cpf[j];
                cpf[j] = cpf[j + 1];
                cpf[j + 1] = tempCpf;

                Nascimento tempData = data[j];
                data[j] = data[j + 1];
                data[j + 1] = tempData;
            }
        }
    }

    printf("Lista de Alunos Ordenados por Nome:\n");
    for (int i = 0; i < qtdAluno; i++)
    {
         if (aluno[i].ativoAluno == 1)
        {
            printf("\nNumero de Chamada: %d", aluno[i].chamadaAluno);
            printf("\nmatricula: MAT%d", aluno[i].id);
            printf("\nNome: %s", aluno[i].nameAluno);
            printf("\nSexo: %c", aluno[i].sexoAluno);
            printf("\nIdade: %d", aluno[i].idadeAluno);
            printf("\nCPF: %s\n", aluno[i].cpfAluno);
            sprintf(data[i].data, "%02d/%02d/%04d", data[i].dia, data[i].mes, data[i].ano);
            printf("Data de Nascimento: %s\n", data[i].data);
            aluno[i].chamadaAluno++;
        }
    }
}
void buscaNome(Student aluno[], int qtdAluno)
{
    char Busca[255];
    printf("Digite uma busca:\n");
    fgets(Busca, sizeof(Busca), stdin);
    
    for(int i = 0; Busca[i] != '\0'; i++)
        if (Busca[i] == '\n')
            Busca[i] = '\0';

    for (int i = 0; Busca[i]; i++)
        if (Busca[i] >= 'A' && Busca[i] <= 'Z')
            Busca[i] += 32;

    int encontrou = 0;

    for (int i = 0; i < qtdAluno; i++)
    {
        char nomeMinusculo[255];
        int j;
        for (j = 0; aluno[i].nameAluno[j] != '\0'; j++)
            nomeMinusculo[j] = aluno[i].nameAluno[j];
        nomeMinusculo[j] = '\0';

        for (j = 0; nomeMinusculo[j] != '\0'; j++)
            if (nomeMinusculo[j] >= 'A' && nomeMinusculo[j] <= 'Z')
                nomeMinusculo[j] += 32;

        int k, achou;
        for (k = 0; nomeMinusculo[k] != '\0'; k++)
        {
            achou = 1;
            for (int l = 0; Busca[l] != '\0'; l++)
            {
                if (nomeMinusculo[k + l] != Busca[l])
                {
                    achou = 0;
                    break;
                }
            }
            if (achou)
            {
                printf("Resultado da busca: %s\n", aluno[i].nameAluno);
                encontrou = 1;
                break;
            }
        }
    }

    if (!encontrou)
        printf("Nenhum aluno encontrado.\n");
}

void readStudentDataOrdem(Student aluno[], int qtdAluno, Nascimento data[], CPF cpf[])
{

    for (int i = 0; i < qtdAluno - 1; i++)
    {
        for (int j = i + 1; j < qtdAluno; j++)
        {

            if (data[i].ano > data[j].ano ||
                (data[i].ano == data[j].ano && data[i].mes > data[j].mes) ||
                (data[i].ano == data[j].ano && data[i].mes == data[j].mes && data[i].dia > data[j].dia))
            {
                Nascimento tmpData = data[i];
                data[i] = data[j];
                data[j] = tmpData;

                Student tmpAluno = aluno[i];
                aluno[i] = aluno[j];
                aluno[j] = tmpAluno;

                CPF tmpCpf = cpf[i];
                cpf[i] = cpf[j];
                cpf[j] = tmpCpf;
            }
        }
    }
    for (int i = 0; i < qtdAluno; i++)
    {
       
    if (aluno[i].ativoAluno == 1)
        {
            printf("\nNumero de Chamada: %d", aluno[i].chamadaAluno);
            printf("\nmatricula: MAT%d", aluno[i].id);
            printf("\nNome: %s", aluno[i].nameAluno);
            printf("\nSexo: %c", aluno[i].sexoAluno);
            printf("\nIdade: %d", aluno[i].idadeAluno);
            printf("\nCPF: %s\n", aluno[i].cpfAluno);
            sprintf(data[i].data, "%02d/%02d/%04d", data[i].dia, data[i].mes, data[i].ano);
            printf("Data de Nascimento: %s\n", data[i].data);
            aluno[i].chamadaAluno++;
        }
    }
}