#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "All.h"

int createProf(Teacher professor[], int qtdprof, Nascimento calendario[], CPF cpf[])
{
    professor[qtdprof].id++;

    printf("digite o nome do professor: \n");
    fgets(professor[qtdprof].nameTeacher, 250, stdin);
    for (int i = 0; professor[qtdprof].nameTeacher[i] != '\0'; i++)
    {
        if (professor[qtdprof].nameTeacher[i] == '\n')
        {
            professor[qtdprof].nameTeacher[i] = '\0';
        }
    }
    printf("Criar Matricula Professor.\n");
    printf("digite o sexo do professor (M/F): \n");
    scanf(" %c", &professor[qtdprof].sexoTeacher);
    getchar();
    if (professor[qtdprof].sexoTeacher != 'M' && professor[qtdprof].sexoTeacher != 'F' && professor[qtdprof].sexoTeacher != 'f' && professor[qtdprof].sexoTeacher != 'm')
    {
        return ERRO_CADASTRO_SEXO;
    }
    printf("digite a idade do professor: \n");
    scanf("%d", &professor[qtdprof].idadeTeacher);

    printf("digite o cpf do professor: \n");
    scanf("%s", professor[qtdprof].cpfTeacher);
    getchar();
    printf("digite a data de nascimento do professor (dd/mm/aaaa): \n");
    fgets(calendario[qtdprof].data, 11, stdin);
    if (ISBIX(calendario, qtdprof) == invalido)
    {
        return ERRO_DATA_INVALIDA;
    };

    int validade = validacaodeCPF(cpf, qtdprof);
    if (validade == invalido)
    {
        printf("CPF invalido. Cadastro nao realizado.\n");
        return invalido;
    }
    printf("\n");
    return SUCESSO_CADASTRO;
}

void readProf(Teacher professor[], int qtdprof, Nascimento data[], CPF cpf[])
{

    for (int i = 0; i < qtdprof; i++)
    {
        for (int j = 0; professor[i].nameTeacher[j] != '\0'; j++)
            if (professor[i].nameTeacher[j] == '\n')
            {
                professor[i].nameTeacher[j] = '\0';
            }
    }

    if (qtdprof == 0)
    {
        printf("Nenhum professor cadastrado.\n");
        return;
    }
    for (int i = 0; i < qtdprof; i++)
    {
        if (professor[i].ativoTeacher == 1)
        {
            printf("\nNumero de id: %d", professor[i].id);
            printf("\nNome: %s", professor[i].nameTeacher);
            printf("\nSexo: %c", professor[i].sexoTeacher);
            printf("\nIdade: %d", professor[i].idadeTeacher);
            printf("\nCPF: %s\n", professor[i].cpfTeacher);
            sprintf(data[i].data, "%02d/%02d/%04d", data[i].dia, data[i].mes, data[i].ano);
            printf("Data de Nascimento: %s\n", data[i].data);
        }
    }
}

void atualizacaodeDadosProf(Teacher professor[], int qtdprof, Nascimento cal[], CPF cpf[])
{
     if (qtdprof == 0)
    {
        printf("Nenhum Professor cadastrado.\n");
        return;
    }

    printf("Funcao de atualizacao de dados do professor.\n");
    int sair = 0, opcao, chamada;
    printf("Menu de atualizacao.\n");
    printf("Selecione o professor por numero de id:\n");
    scanf("%d", &chamada);
    printf("1.atualizar nome do professor\n"
           "2. Atualizar idade do professor\n"
           "3. Atualizar sexo do professor\n"
           "4. Atualizar Data de nascimento do professor\n"
           "5. Atualizar CPF do aluno\n"
           "6. Exit\n");
    scanf("%d", &opcao);
    getchar();
    for (int i = 0; i < qtdprof; i++)
    {
        if (professor[i].id == chamada && professor[i].ativoTeacher == 1)
        {
            switch (opcao)
            {
            case 1:
                printf("Atualizar nome do Professor.\n");
                printf("Digite o novo nome: ");
                fgets(professor[i].nameTeacher, sizeof(professor[i].nameTeacher), stdin);
                getchar();
                break;
            case 2:
                printf("Atualizar idade do Professor.\n");
                printf("Digite a nova idade: ");
                scanf("%d", &professor[i].idadeTeacher);
                getchar();
                break;
            case 3:
                printf("Atualizar sexo do Professor.\n");
                printf("Digite o novo sexo (M/F): ");
                scanf(" %c", &professor[i].sexoTeacher);
                getchar();
                break;
            case 4:
                printf("Atualizar data de nascimento do Professor.\n");
                printf("Digite a nova data de nascimento (dd/mm/aaaa): ");
                fgets(cal[i].dataProfessor, sizeof(cal[i].dataProfessor), stdin);
                ISBIX(cal, i);
                break;
            case 5:
                printf("Atualizar CPF do Professor.\n");
                printf("Digite o novo CPF: ");
                scanf("%s", cpf[i].cpfProfessor);
                getchar();
                int validade = validacaodeCPF(cpf, qtdprof);
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
                break;
            }
        }
    }
}

int deletarProfessor(Teacher professor[], int qtdprof)
{
     if (qtdprof == 0)
    {
        printf("Nenhum Professor cadastrado.\n");
        return 1;
    }
    printf("Funcao deletar professor.\n");
    int id;
    printf("Digite o ID do professor a ser deletado: ");
    scanf("%d", &id);
    int achou = 0;
    if (id <= 0)
        printf("Este professor nao existe\n");

    for (int i = 0; i < qtdprof; i++)
    {
        if (professor[i].ativoTeacher == 0 && professor[i].id == id)
        {
            printf("Professor ^^%s^^ encontrado e deletado com sucesso.\n", professor[i].nameTeacher);
        }
        else if (professor[i].ativoTeacher == 0 && professor[i].id == id)
        {
            printf("Este professor nao foi encontrado.\n");
            return 0;
        }
    }
    for (int i = 0; i < qtdprof; i++)
    {
        if (professor[i].id == id)
        {
            professor[i].ativoTeacher = 0;
            for (int j = i; j < qtdprof - 1; j++)
            {
                professor[j].ativoTeacher = professor[j + 1].ativoTeacher;
                professor[j].sexoTeacher = professor[j + 1].sexoTeacher;
                professor[j].id = professor[j + 1].id;
            }
            qtdprof--;
            achou = 1;
        }
    }

    if (achou == 1)
    {
        printf("Professor encontrado.\n");
    }
    else
    {
        printf("Professor nao encontrado.\n");
        return DELETADO_COM_SUCESSO;
    }
}

void readSexProf(Teacher professor[], int qtdprof, Nascimento data[], CPF cpf[])
{
    char sexo;
    printf("Digite o sexo do professor (M/F): \n");
    scanf(" %c", &sexo);
    getchar();
    int encontrado = 0;
    if (qtdprof == 0)
    {
        printf("Nenhum Professor cadastrado.\n");
        return;
    }

    if (sexo != 'M' && sexo != 'F' && sexo != 'f' && sexo != 'm')
    {
        printf("Sexo invalido. Use M/m para masculino e F/f para feminino.\n");
        return;
    }
    for (int i = 0; i < qtdprof; i++)
    {
        if (sexo == professor[i].sexoTeacher && professor[i].ativoTeacher == 1)
        {
            printf("\nmatricula: MAT%d", professor[i].id);
            printf("\nNome: %s", professor[i].nameTeacher);
            printf("\nSexo: %c", professor[i].sexoTeacher);
            printf("\nIdade: %d", professor[i].idadeTeacher);
            printf("\nCPF: %s\n", professor[i].cpfTeacher);
            sprintf(data[i].dataProfessor, "%02d/%02d/%04d", data[i].dia, data[i].mes, data[i].ano);
            printf("Data de Nascimento: %s\n", data[i].dataProfessor);
        }
    }
}

void readOrdenadosProfessores(Teacher professor[], int qtdprof, Nascimento data[], CPF cpf[])
{
    if (qtdprof <= 0)
    {
        printf("Nenhum professor para ordenar.\n");
        return;
    }

    Teacher tempProfessor[qtdprof];
    for (int i = 0; i < qtdprof; i++)
    {
        tempProfessor[i] = professor[i];
    }

    for (int i = 0; i < qtdprof - 1; i++)
    {
        for (int j = 0; j < qtdprof - i - 1; j++)
        {

            if (tempProfessor[j].nameTeacher > tempProfessor[j + 1].nameTeacher)
            {
                Teacher temp = tempProfessor[j];
                tempProfessor[j] = tempProfessor[j + 1];
                tempProfessor[j + 1] = temp;

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
    for (int i = 0; i < qtdprof; i++)
    {
        if (professor[i].ativoTeacher == 1)
        {
            printf("\nmatricula: MAT%d", professor[i].id);
            printf("\nNome: %s", professor[i].nameTeacher);
            printf("\nSexo: %c", professor[i].sexoTeacher);
            printf("\nIdade: %d", professor[i].idadeTeacher);
            printf("\nCPF: %s\n", professor[i].cpfTeacher);
            sprintf(data[i].dataProfessor, "%02d/%02d/%04d", data[i].dia, data[i].mes, data[i].ano);
            printf("Data de Nascimento: %s\n", data[i].dataProfessor);
        }
    }
}
void buscaNomeProf(Teacher professor[], int qtdprof)
{
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

    for (int i = 0; i < qtdprof; i++)
    {
        char nomeMinusculo[255];
        int j;
        for (j = 0; professor[i].nameTeacher[j] != '\0'; j++)
            nomeMinusculo[j] = professor[i].nameTeacher[j];
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
                printf("Resultado da busca: %s\n", professor[i].nameTeacher);
                encontrou = 1;
                break;
            }
        }
    }

    if (!encontrou)
        printf("Nenhum aluno encontrado.\n");
}

void readProfDataOrdem(Teacher professor[], int qtdprof, Nascimento data[], CPF cpf[])
{

    for (int i = 0; i < qtdprof - 1; i++)
    {
        for (int j = i + 1; j < qtdprof; j++)
        {

            if (data[i].ano > data[j].ano ||
                (data[i].ano == data[j].ano && data[i].mes > data[j].mes) ||
                (data[i].ano == data[j].ano && data[i].mes == data[j].mes && data[i].dia > data[j].dia))
            {
                Nascimento tmpData = data[i];
                data[i] = data[j];
                data[j] = tmpData;

                Teacher tmpProfessor = professor[i];
                professor[i] = professor[j];
                professor[j] = tmpProfessor;

                CPF tmpCpf = cpf[i];
                cpf[i] = cpf[j];
                cpf[j] = tmpCpf;
            }
        }
    }
    for (int i = 0; i < qtdprof; i++)
    {

        if (professor[i].ativoTeacher== 1)
        {
            printf("\nmatricula: MAT%d", professor[i].id);
            printf("\nNome: %s", professor[i].nameTeacher);
            printf("\nSexo: %c", professor[i].sexoTeacher);
            printf("\nIdade: %d", professor[i].idadeTeacher);
            printf("\nCPF: %s\n", professor[i].cpfTeacher);
            sprintf(data[i].dataProfessor, "%02d/%02d/%04d", data[i].dia, data[i].mes, data[i].ano);
            printf("Data de Nascimento: %s\n", data[i].dataProfessor);
        }
    }
}