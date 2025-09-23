#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "All.h"

int createStudent(Student aluno[], int qtdAluno, Nascimento calendario[], CPF cpf[])
{
    aluno[qtdAluno].id = 20251 + qtdAluno;

    printf("Criar Matricula Aluno.\n");

    printf("digite o nome do aluno: \n");
    fgets(aluno[qtdAluno].nameAluno, 250, stdin);
    for (int i = 0; aluno[qtdAluno].nameAluno[i] != '\0'; i++)
    {
        if (aluno[qtdAluno].nameAluno[i] == '\n')
        {
            aluno[qtdAluno].nameAluno[i] = '\0';
        }
    }
    printf("digite o sexo do aluno (M/F): \n");
    scanf(" %c", &aluno[qtdAluno].sexoAluno);
    if (aluno[qtdAluno].sexoAluno >= 'A' && aluno[qtdAluno].sexoAluno <= 'Z')
        aluno[qtdAluno].sexoAluno += 32;
    getchar();

    if (aluno[qtdAluno].sexoAluno != 'f' && aluno[qtdAluno].sexoAluno != 'm')
        return ERRO_CADASTRO_SEXO;
    printf("digite a idade do aluno: \n");
    scanf("%d", &aluno[qtdAluno].idadeAluno);
    getchar();

    printf("digite o cpf do aluno: \n");
    fgets(cpf[qtdAluno].cpf, 16, stdin);
    if (validacaodeCPF(cpf, qtdAluno) == invalido)
        return invalido;

    printf("digite a data de nascimento do aluno (dd/mm/aaaa): \n");
    fgets(calendario[qtdAluno].data, 11, stdin);
    if (ISBIX(calendario, qtdAluno) == ERRO_DATA_INVALIDA)
        return ERRO_DATA_INVALIDA;
    return SUCESSO_CADASTRO;
}

void readStudent(Student aluno[], int qtdAluno, Nascimento data[], CPF cpf[])
{
    Student tempAluno[TAM_LISTA_ALUNO];
    Nascimento tempData[TAM_LISTA_ALUNO];
    CPF tempCpf[TAM_LISTA_ALUNO];

    for (int i = 0; i < qtdAluno; i++)
    {
        tempAluno[i] = aluno[i];
        tempData[i] = data[i];
        tempCpf[i] = cpf[i];
    }

    if (qtdAluno == 0)
    {
        printf("Nenhum aluno cadastrado.\n");
        return;
    }
    for (int i = 0; i < qtdAluno; i++)
    {
        if (aluno[i].ativoAluno == 1)
        {
            printf("\nNumero de Chamada: %d", tempAluno[i].chamadaAluno);
            printf("\nmatricula: MAT%d", tempAluno[i].id);
            printf("\nNome: %s", tempAluno[i].nameAluno);
            printf("\nSexo: %c", tempAluno[i].sexoAluno);
            printf("\nIdade: %d", tempAluno[i].idadeAluno);
            printf("\nCPF: %s\n", tempCpf[i].cpf);
            sprintf(tempData[i].data, "%02d/%02d/%04d", tempData[i].dia, tempData[i].mes, tempData[i].ano);
            printf("Data de Nascimento: %s\n", tempData[i].data);
        }
    }
}

void atualizacaodeDados(Student aluno[], int qtdAluno, Nascimento cal[], CPF cpf[])
{
    printf("Funcao de atualizacao de dados do aluno.\n");
    int opcao, chamada;
    printf("Menu de atualizacao:\n");
    printf("Selecione o aluno por numero de chamada:\n");
    scanf("%d", &chamada);
    printf("1. atualizar nome do aluno\n"
           "2. Atualizar idade do aluno\n"
           "3. Atualizar sexo do aluno\n"
           "4. Atualizar Data de nascimento do aluno\n"
           "5. Atualizar CPF do aluno\n");
    scanf("%d", &opcao);
    for (int i = 0; i < qtdAluno; i++)
    {
        if (aluno[i].chamadaAluno == chamada && aluno[i].ativoAluno == 1)
        {
            switch (opcao)
            {
            case 1:
                getchar();
                printf("Atualizar nome do Aluno.\n");
                printf("Digite o novo nome: ");
                fgets(aluno[i].nameAluno, sizeof(aluno[i].nameAluno), stdin);
                for (int j = 0; aluno[i].nameAluno[j] != '\0'; j++)
                {
                    if (aluno[i].nameAluno[j] == '\n')
                    {
                        aluno[i].nameAluno[j] = '\0';
                    }
                }
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
                getchar();
                printf("Atualizar data de nascimento do Aluno.\n");
                printf("Digite a nova data de nascimento (dd/mm/aaaa): ");
                fgets(cal[i].data, sizeof(cal[i].data), stdin);
                for (int j = 0; cal[i].data[j] != '\0'; j++)
                {
                    if (cal[i].data[j] == '\n')
                    {
                        cal[i].data[j] = '\0';
                    }
                }
                if (ISBIX(cal, i) == invalido)
                    printf("Data invalida. Atualizacao nao realizada.\n");
                else
                    printf("Data atualizada: %s\n", cal[i].data);
                break;
            case 5:
                getchar();
                printf("Atualizar CPF do Aluno.\n");
                printf("Digite o novo CPF: ");
                fgets(cpf[i].cpf, sizeof(cpf[i].cpf), stdin);
                for (int j = 0; cpf[i].cpf[j] != '\0'; j++)
                {
                    if (cpf[i].cpf[j] == '\n')
                    {
                        cpf[i].cpf[j] = '\0';
                    }
                }
                if (validacaodeCPF(cpf, i))
                {
                    printf("CPF atualizado com sucesso.\n");
                }
                else
                {
                    printf("CPF invalido.\nAtualizacao nao realizada.\n");
                }
                break;
            default:
                printf("Opcao invalida, tente novamente.\n");
                break;
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

    for (int i = 0; i < qtdAluno; i++)
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
        return DELETADO_COM_SUCESSO;
    }
}

void readSexStudent(Student aluno[], int qtdAluno, Nascimento data[], CPF cpf[])
{
    Student tempAluno[TAM_LISTA_ALUNO];
    Nascimento tempData[TAM_LISTA_ALUNO];
    CPF tempCpf[TAM_LISTA_ALUNO];
    char sexo;

    for (int i = 0; i < qtdAluno; i++)
    {
        tempAluno[i] = aluno[i];
        tempData[i] = data[i];
        tempCpf[i] = cpf[i];
    }

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
        if (sexo == tempAluno[i].sexoAluno && tempAluno[i].ativoAluno == 1)
        {
            printf("\nNumero de Chamada: %d", tempAluno[i].chamadaAluno);
            printf("\nmatricula: MAT%d", tempAluno[i].id);
            printf("\nNome: %s", tempAluno[i].nameAluno);
            printf("\nSexo: %c", tempAluno[i].sexoAluno);
            printf("\nIdade: %d", tempAluno[i].idadeAluno);
            printf("\nCPF: %s\n", tempCpf[i].cpf);
            sprintf(tempData[i].data, "%02d/%02d/%04d", tempData[i].dia, tempData[i].mes, tempData[i].ano);
            printf("Data de Nascimento: %s\n", tempData[i].data);
        }
    }
}

void readOrdenadosStudents(Student aluno[], int qtdAluno, Nascimento data[], CPF cpf[])
{
    Student tempAluno[TAM_LISTA_ALUNO];
    Nascimento tempData[TAM_LISTA_ALUNO];
    CPF tempCpf[TAM_LISTA_ALUNO];
    for (int i = 0; i < qtdAluno; i++)
    {
        tempAluno[i] = aluno[i];
        tempData[i] = data[i];
        tempCpf[i] = cpf[i];
    }
    if (qtdAluno <= 0)
    {
        printf("Nenhum aluno para ordenar.\n");
        return;
    }
    int k = 1;
    for (int i = 0; i < qtdAluno; i++)
    {
        for (int j = 0; j < qtdAluno - i - 1; j++)
        {
            if (strcmp(tempAluno[j].nameAluno, tempAluno[j + 1].nameAluno) > 0)
            {
                Student timeAluno = tempAluno[j];
                tempAluno[j] = tempAluno[j + 1];
                tempAluno[j + 1] = timeAluno;

                Nascimento timeData = tempData[j];
                tempData[j] = tempData[j + 1];
                tempData[j + 1] = timeData;

                CPF timeCpf = tempCpf[j];
                tempCpf[j] = tempCpf[j + 1];
                tempCpf[j + 1] = timeCpf;
            }
        }
    }

    printf("Lista de Alunos Ordenados por Nome:\n");
    for (int i = 0; i < qtdAluno; i++)
    {
        if (aluno[i].ativoAluno == 1)
        {
            printf("\nNumero de Chamada: %d", tempAluno[i].chamadaAluno);
            printf("\nmatricula: MAT%d", tempAluno[i].id);
            printf("\nNome: %s", tempAluno[i].nameAluno);
            printf("\nSexo: %c", tempAluno[i].sexoAluno);
            printf("\nIdade: %d", tempAluno[i].idadeAluno);
            printf("\nCPF: %s\n", tempCpf[i].cpf);
            sprintf(tempData[i].data, "%02d/%02d/%04d", tempData[i].dia, tempData[i].mes, tempData[i].ano);
            printf("Data de Nascimento: %s\n", tempData[i].data);
        }
    }
}
void buscaNome(Student aluno[], int qtdAluno, Nascimento data[], CPF cpf[])
{
    Student tempAluno[TAM_LISTA_ALUNO];
    Nascimento tempData[TAM_LISTA_ALUNO];
    CPF tempCpf[TAM_LISTA_ALUNO];

    for (int i = 0; i < qtdAluno; i++)
    {
        tempAluno[i] = aluno[i];
        tempData[i] = data[i];
        tempCpf[i] = cpf[i];
    }
    char Busca[255];
    printf("Digite uma busca:\n");
    fgets(Busca, sizeof(Busca), stdin);

    for (int i = 0; Busca[i] != '\0'; i++)
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
            if (achou && aluno[i].ativoAluno == 1)
            {
            printf("Resultado da busca: %s\n", aluno[i].nameAluno);
            printf("\n");
            printf("\nNumero de Chamada: %d", tempAluno[i].chamadaAluno);
            printf("\nmatricula: MAT%d", tempAluno[i].id);
            printf("\nNome: %s", tempAluno[i].nameAluno);
            printf("\nSexo: %c", tempAluno[i].sexoAluno);
            printf("\nIdade: %d", tempAluno[i].idadeAluno);
            printf("\nCPF: %s\n", tempCpf[i].cpf);
            sprintf(tempData[i].data, "%02d/%02d/%04d", tempData[i].dia, tempData[i].mes, tempData[i].ano);
            printf("Data de Nascimento: %s\n", tempData[i].data);
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
    Student tempAluno[TAM_LISTA_ALUNO];
    Nascimento tempData[TAM_LISTA_ALUNO];
    CPF tempCpf[TAM_LISTA_ALUNO];

    for (int i = 0; i < qtdAluno; i++)
    {
        tempAluno[i] = aluno[i];
        tempData[i] = data[i];
        tempCpf[i] = cpf[i];
    }

    for (int i = 0; i < qtdAluno - 1; i++)
    {
        for (int j = i + 1; j < qtdAluno; j++)
        {

            if (tempData[i].ano > tempData[j].ano ||
                (tempData[i].ano == tempData[j].ano && tempData[i].mes > tempData[j].mes) ||
                (tempData[i].ano == tempData[j].ano && tempData[i].mes == tempData[j].mes && tempData[i].dia > tempData[j].dia))
            {
                Student tmpAluno = tempAluno[i];
                tempAluno[i] = tempAluno[j];
                tempAluno[j] = tmpAluno;

                Nascimento tmpData = tempData[i];
                tempData[i] = tempData[j];
                tempData[j] = tmpData;

                CPF tmpCpf = tempCpf[i];
                tempCpf[i] = tempCpf[j];
                tempCpf[j] = tmpCpf;
            }
        }
    }

    for (int i = 0; i < qtdAluno; i++)
    {

        if (aluno[i].ativoAluno == 1)
        {
            printf("\nNumero de Chamada: %d", tempAluno[i].chamadaAluno);
            printf("\nmatricula: MAT%d", tempAluno[i].id);
            printf("\nNome: %s", tempAluno[i].nameAluno);
            printf("\nSexo: %c", tempAluno[i].sexoAluno);
            printf("\nIdade: %d", tempAluno[i].idadeAluno);
            printf("\nCPF: %s\n", tempCpf[i].cpf);
            sprintf(tempData[i].data, "%02d/%02d/%04d", tempData[i].dia, tempData[i].mes, tempData[i].ano);
            printf("Data de Nascimento: %s\n", tempData[i].data);
        }
    }
}
