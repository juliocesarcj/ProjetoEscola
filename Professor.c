#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "All.h"

int createProf(Teacher p[], int qtd, Nascimento calendario[], CPF cpf[])
{

    printf("digite o nome do professor: \n");
    fgets(p[qtd].nameTeacher, sizeof(p[qtd].nameTeacher), stdin);
    for (int i = 0; p[qtd].nameTeacher[i] != '\0'; i++)
    {
        if (p[qtd].nameTeacher[i] == '\n')
        {
            p[qtd].nameTeacher[i] = '\0';
        }
    }
    printf("digite o sexo do professor (M/F): \n");
    scanf(" %c", &p[qtd].sexoTeacher);
    if (p[qtd].sexoTeacher >= 'A' && p[qtd].sexoTeacher <= 'Z')
        p[qtd].sexoTeacher += 32;
    getchar();

    if (p[qtd].sexoTeacher != 'f' && p[qtd].sexoTeacher != 'm')
        return ERRO_CADASTRO_SEXO;
    printf("digite a idade do professor: \n");
    scanf("%d", &p[qtd].idadeTeacher);
    getchar();

    printf("digite o cpf do professor: \n");
    fgets(cpf[qtd].cpfProfessor, sizeof(cpf[qtd].cpfProfessor), stdin);
    if (validacaodeCPFP(cpf, qtd) == invalido)
        return invalido;

    printf("digite a data de nascimento do professor (dd/mm/aaaa): \n");
    fgets(calendario[qtd].dataProfessor, sizeof(calendario[qtd].dataProfessor), stdin);
    if (ISBIXP(calendario, qtd) == ERRO_DATA_INVALIDA)
        return ERRO_DATA_INVALIDA;
    printf("mes %d\n", calendario[0].mesP);
    return SUCESSO_CADASTRO;
}
void readProf(Teacher p[], int qtd, Nascimento data[], CPF cpf[])
{
    Teacher tempo[TAM_LISTA_ALUNO];
    Nascimento tempData[TAM_LISTA_ALUNO];
    CPF tempCpf[TAM_LISTA_ALUNO];

    for (int i = 0; i < qtd; i++)
    {
        tempo[i] = p[i];
        tempData[i] = data[i];
        tempCpf[i] = cpf[i];
    }
    if (qtd == 0)
    {
        printf("Nenhum aluno cadastrado.\n");
        return;
    }
    for (int i = 0; i < qtd; i++)
    {
        if (p[i].ativoTeacher == 1)
        {
            printf("\nmatricula: MATricula %d", tempo[i].id);
            printf("\nNome: %s", tempo[i].nameTeacher);
            printf("\nSexo: %c", tempo[i].sexoTeacher);
            printf("\nIdade: %d", tempo[i].idadeTeacher);
            printf("\nCPF: %s\n", tempCpf[i].cpfProfessor);
            sprintf(tempData[i].dataProfessor, "%02d/%02d/%04d", tempData[i].dia, tempData[i].mes, tempData[i].ano);
            printf("Data de Nascimento: %s\n", tempData[i].dataProfessor);
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

    int opcao, id;
    printf("Funcao de atualizacao de dados do professor.\n");
    printf("Selecione o professor por numero de id:\n");
    scanf("%d", &id);
    getchar();
    printf("1. atualizar nome do professor\n"
           "2. Atualizar idade do professor\n"
           "3. Atualizar sexo do professor\n"
           "4. Atualizar Data de nascimento do professor\n"
           "5. Atualizar CPF do professor\n");
    scanf("%d", &opcao);
    getchar();

    for (int i = 0; i < qtdprof; i++)
    {
        if (professor[i].id == id && professor[i].ativoTeacher == 1)
        {
            switch (opcao)
            {
            case 1:
                printf("Atualizar nome do Professor.\n");
                printf("Digite o novo nome: ");
                fgets(professor[i].nameTeacher, sizeof(professor[i].nameTeacher), stdin);
                for (int j = 0; professor[i].nameTeacher[j] != '\0'; j++)
                    if (professor[i].nameTeacher[j] == '\n')
                        professor[i].nameTeacher[j] = '\0';
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
                if (professor[i].sexoTeacher >= 'A' && professor[i].sexoTeacher <= 'Z')
                    professor[i].sexoTeacher += 32;
                getchar();
                break;
            case 4:
                printf("Atualizar data de nascimento do Professor.\n");
                printf("Digite a nova data de nascimento (dd/mm/aaaa): ");
                fgets(cal[i].dataProfessor, sizeof(cal[i].dataProfessor), stdin);
                for (int j = 0; cal[i].dataProfessor[j] != '\0'; j++)
                    if (cal[i].data[j] == '\n')
                        cal[i].data[j] = '\0';
                switch (ISBIXP(cal, i))
                {
                case invalido:
                    printf("Data invalida. Atualizacao nao realizada.\n");
                    break;
                case valido:
                    printf("Data atualizada: %s\n", cal[i].dataProfessor);
                    break;
                }
                break;
            case 5:
                printf("Atualizar CPF do Professor.\n");
                printf("Digite o novo CPF: ");
                fgets(cpf[i].cpf, sizeof(cpf[i].cpfProfessor), stdin);
                for (int j = 0; cpf[i].cpfProfessor[j] != '\0'; j++)
                    if (cpf[i].cpfProfessor[j] == '\n')
                        cpf[i].cpfProfessor[j] = '\0';
                if (validacaodeCPF(cpf, i) == valido)
                    printf("CPF atualizado com sucesso.\n");
                else
                    printf("CPF invalido. Atualizacao nao realizada.\n");
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

    int id, achou = 0;
    printf("Digite o ID do professor a ser deletado: ");
    scanf("%d", &id);

    if (id <= 0)
    {
        printf("Este professor nao existe\n");
        return 0;
    }

    for (int i = 0; i < qtdprof; i++)
    {
        if (professor[i].id == id && professor[i].ativoTeacher == 1)
        {
            professor[i].ativoTeacher = 0;
            achou = 1;
            printf("Professor ^^%s^^ deletado com sucesso.\n", professor[i].nameTeacher);
        }
    }

    if (!achou)
        printf("Professor nao encontrado.\n");

    return DELETADO_COM_SUCESSO;
}

void readSexProf(Teacher professor[], int qtdprof, Nascimento data[], CPF cpf[])
{
    char sexo;
    printf("Digite o sexo do professor (M/F): \n");
    scanf(" %c", &sexo);
    if (sexo >= 'A' && sexo <= 'Z')
        sexo += 32;
    getchar();

    if (qtdprof == 0)
    {
        printf("Nenhum Professor cadastrado.\n");
        return;
    }
    if (sexo != 'f' && sexo != 'm')
    {
        printf("Sexo invalido. Use M/m para masculino e F/f para feminino.\n");
        return;
    }

    for (int i = 0; i < qtdprof; i++)
    {
        if (professor[i].sexoTeacher == sexo && professor[i].ativoTeacher == 1)
        {
            printf("\nmatricula: %d", professor[i].id);
            printf("\nNome: %s", professor[i].nameTeacher);
            printf("\nSexo: %c", professor[i].sexoTeacher);
            printf("\nIdade: %d", professor[i].idadeTeacher);
            printf("\nCPF: %s\n", cpf[i].cpfProfessor);
            sprintf(data[i].dataProfessor, "%02d/%02d/%04d", data[i].dia, data[i].mes, data[i].ano);
            printf("Data de Nascimento: %s\n", data[i].dataProfessor);
        }
    }
}

void readOrdenadosProfessores(Teacher professor[], int qtdprof, Nascimento data[], CPF cpf[])
{
    Teacher tempProf[TAM_LISTA_ALUNO];
    Nascimento tempData[TAM_LISTA_ALUNO];
    CPF tempCpf[TAM_LISTA_ALUNO];

    for (int i = 0; i < qtdprof; i++)
    {
        tempProf[i] = professor[i];
        tempData[i] = data[i];
        tempCpf[i] = cpf[i];
    }

    if (qtdprof <= 0)
    {
        printf("Nenhum professor para ordenar.\n");
        return;
    }

    for (int i = 0; i < qtdprof - 1; i++)
    {
        for (int j = 0; j < qtdprof - i - 1; j++)
        {
            if (strcmp(tempProf[j].nameTeacher, tempProf[j + 1].nameTeacher) > 0)
            {
                Teacher tmpProf = tempProf[j];
                tempProf[j] = tempProf[j + 1];
                tempProf[j + 1] = tmpProf;

                Nascimento tmpData = tempData[j];
                tempData[j] = tempData[j + 1];
                tempData[j + 1] = tmpData;

                CPF tmpCpf = tempCpf[j];
                tempCpf[j] = tempCpf[j + 1];
                tempCpf[j + 1] = tmpCpf;
            }
        }
    }

    printf("Lista de Professores Ordenados por Nome:\n");
    for (int i = 0; i < qtdprof; i++)
    {
        if (professor[i].ativoTeacher == 1)
        {
            printf("\nmatricula: %d", tempProf[i].id);
            printf("\nNome: %s", tempProf[i].nameTeacher);
            printf("\nSexo: %c", tempProf[i].sexoTeacher);
            printf("\nIdade: %d", tempProf[i].idadeTeacher);
            printf("\nCPF: %s\n", tempCpf[i].cpfProfessor);
            sprintf(tempData[i].dataProfessor, "%02d/%02d/%04d", tempData[i].dia, tempData[i].mes, tempData[i].ano);
            printf("Data de Nascimento: %s\n", tempData[i].dataProfessor);
        }
    }
}

void buscaNomeProf(Teacher professor[], int qtdprof, Nascimento data[], CPF cpf[])
{
    Teacher tempProf[TAM_LISTA_ALUNO];
    Nascimento tempData[TAM_LISTA_ALUNO];
    CPF tempCpf[TAM_LISTA_ALUNO];

    for (int i = 0; i < qtdprof; i++)
    {
        tempProf[i] = professor[i];
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
            if (achou && professor[i].ativoTeacher == 1)
            {
                printf("Resultado da busca: %s\n", professor[i].nameTeacher);
                printf("\n");
                printf("\nmatricula: %d", tempProf[i].id);
                printf("\nNome: %s", tempProf[i].nameTeacher);
                printf("\nSexo: %c", tempProf[i].sexoTeacher);
                printf("\nIdade: %d", tempProf[i].idadeTeacher);
                printf("\nCPF: %s\n", tempCpf[i].cpfProfessor);
                sprintf(tempData[i].dataProfessor, "%02d/%02d/%04d", tempData[i].dia, tempData[i].mes, tempData[i].ano);
                printf("Data de Nascimento: %s\n", tempData[i].dataProfessor);
                encontrou = 1;
                break;
            }
        }
    }

    if (!encontrou)
        printf("Nenhum professor encontrado.\n");
}

void readProfDataOrdem(Teacher professor[], int qtdprof, Nascimento data[], CPF cpf[])
{
    Teacher tempProf[TAM_LISTA_ALUNO];
    Nascimento tempData[TAM_LISTA_ALUNO];
    CPF tempCpf[TAM_LISTA_ALUNO];

    for (int i = 0; i < qtdprof; i++)
    {
        tempProf[i] = professor[i];
        tempData[i] = data[i];
        tempCpf[i] = cpf[i];
    }

    for (int i = 0; i < qtdprof - 1; i++)
    {
        for (int j = i + 1; j < qtdprof; j++)
        {
            if (tempData[i].ano > tempData[j].ano ||
                (tempData[i].ano == tempData[j].ano && tempData[i].mes > tempData[j].mes) ||
                (tempData[i].ano == tempData[j].ano && tempData[i].mes == tempData[j].mes && tempData[i].dia > tempData[j].dia))
            {
                Teacher tmpProf = tempProf[i];
                tempProf[i] = tempProf[j];
                tempProf[j] = tmpProf;

                Nascimento tmpData = tempData[i];
                tempData[i] = tempData[j];
                tempData[j] = tmpData;

                CPF tmpCpf = tempCpf[i];
                tempCpf[i] = tempCpf[j];
                tempCpf[j] = tmpCpf;
            }
        }
    }

    for (int i = 0; i < qtdprof; i++)
    {
        if (professor[i].ativoTeacher == 1)
        {
            printf("\nmatricula: %d", tempProf[i].id);
            printf("\nNome: %s", tempProf[i].nameTeacher);
            printf("\nSexo: %c", tempProf[i].sexoTeacher);
            printf("\nIdade: %d", tempProf[i].idadeTeacher);
            printf("\nCPF: %s\n", tempCpf[i].cpfProfessor);
            sprintf(tempData[i].dataProfessor, "%02d/%02d/%04d", tempData[i].dia, tempData[i].mes, tempData[i].ano);
            printf("Data de Nascimento: %s\n", tempData[i].dataProfessor);
        }
    }
}
