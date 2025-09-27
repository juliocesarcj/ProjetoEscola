#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "All.h"

int validacaodeCPF(CPF cpf[], int qtd)
{
    for (int i = 0; cpf[qtd].cpf[i] != '\0'; i++)
    {
        if (cpf[qtd].cpf[i] == '\n')
        {
            cpf[qtd].cpf[i] = '\0';
        }
    }
    for (int i = 0; cpf[qtd].cpf[i] != '\0'; i++)
    {
        if (cpf[qtd].cpf[i] == '.' || cpf[qtd].cpf[i] == '-')
        {
            for (int j = i; cpf[qtd].cpf[j] != '\0'; j++)
            {
                cpf[qtd].cpf[j] = cpf[qtd].cpf[j + 1];
            }
        }
    }
    int digito1 = (cpf[qtd].cpf[0]) - '0';
    int digito2 = (cpf[qtd].cpf[1]) - '0';
    int digito3 = (cpf[qtd].cpf[2]) - '0';
    int digito4 = (cpf[qtd].cpf[3]) - '0';
    int digito5 = (cpf[qtd].cpf[4]) - '0';
    int digito6 = (cpf[qtd].cpf[5]) - '0';
    int digito7 = (cpf[qtd].cpf[6]) - '0';
    int digito8 = (cpf[qtd].cpf[7]) - '0';
    int digito9 = (cpf[qtd].cpf[8]) - '0';

    int digitovd = (cpf[qtd].cpf[9]) - '0';
    int digitovd2 = (cpf[qtd].cpf[10]) - '0';
    int multsoma = (digito1 * 10) + (digito2 * 9) + (digito3 * 8) + (digito4 * 7) + (digito5 * 6) + (digito6 * 5) + (digito7 * 4) + (digito8 * 3) + (digito9 * 2);
    int primeiroresto = multsoma % 11;
    if (primeiroresto < 2) {
        multsoma = 0;
    } else {
        multsoma = 11 - primeiroresto;
    }
    int multsoma2 = (digito1 * 11) + (digito2 * 10) + (digito3 * 9) + (digito4 * 8) + (digito5 * 7) + (digito6 * 6) + (digito7 * 5) + (digito8 * 4) + (digito9 * 3) + (digitovd * 2);
    int segundoresto = multsoma2 % 11;
    if (segundoresto < 2) {
        multsoma2 = 0;
    } else {
        multsoma2 = 11 - segundoresto;
    }

    if (multsoma == digitovd && multsoma2 == digitovd2)
    {
        return valido;
    }else{
        return invalido;
    }
}

int ISBIX(Nascimento data[], int qtd)
{
    for (int i = 0; data[qtd].data[i] != '\0'; i++)
    {
        if (data[qtd].data[i] == '\n')
        {
            data[qtd].data[i] = '\0';
        }
    }

    int dia, mes, ano;
    sscanf(data[qtd].data, "%d/%d/%d", &dia, &mes, &ano);
    data[qtd].dia = dia;
    data[qtd].mes = mes;
    data[qtd].ano = ano;
    if (data[qtd].ano < 100)
    {
        if (data[qtd].ano >= 26)
        {
            data[qtd].ano += 1900;
        }
        else
        {
            data[qtd].ano += 2000;
        }
    }

    if (data[qtd].ano > 2025)
    {
        return invalido;
    }

    int bix = ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0));

    switch (data[qtd].mes)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if (data[qtd].dia > 31)
            return invalido;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if (data[qtd].dia > 30)
            return invalido;
        break;
    case 2:
        if ((bix && data[qtd].dia > 29) || (!bix && data[qtd].dia > 28))
            return invalido;
        break;
    default:
        return invalido;
    }
    return valido;
}





int validacaodeCPFP(CPF cpf[], int qtd)
{
    for (int i = 0; cpf[qtd].cpfProfessor[i] != '\0'; i++)
    {
        if (cpf[qtd].cpfProfessor[i] == '\n')
        {
            cpf[qtd].cpfProfessor[i] = '\0';
        }
    }
    for (int i = 0; cpf[qtd].cpfProfessor[i] != '\0'; i++)
    {
        if (cpf[qtd].cpfProfessor[i] == '.' || cpf[qtd].cpfProfessor[i] == '-')
        {
            for (int j = i; cpf[qtd].cpfProfessor[j] != '\0'; j++)
            {
                cpf[qtd].cpfProfessor[j] = cpf[qtd].cpfProfessor[j + 1];
            }
        }
    }
    int digito1 = (cpf[qtd].cpfProfessor[0]) - '0';
    int digito2 = (cpf[qtd].cpfProfessor[1]) - '0';
    int digito3 = (cpf[qtd].cpfProfessor[2]) - '0';
    int digito4 = (cpf[qtd].cpfProfessor[3]) - '0';
    int digito5 = (cpf[qtd].cpfProfessor[4]) - '0';
    int digito6 = (cpf[qtd].cpfProfessor[5]) - '0';
    int digito7 = (cpf[qtd].cpfProfessor[6]) - '0';
    int digito8 = (cpf[qtd].cpfProfessor[7]) - '0';
    int digito9 = (cpf[qtd].cpfProfessor[8]) - '0';

    int digitovd = (cpf[qtd].cpfProfessor[9]) - '0';
    int digitovd2 = (cpf[qtd].cpfProfessor[10]) - '0';
    int multsoma = (digito1 * 10) + (digito2 * 9) + (digito3 * 8) + (digito4 * 7) + (digito5 * 6) + (digito6 * 5) + (digito7 * 4) + (digito8 * 3) + (digito9 * 2);
    int primeiroresto = multsoma % 11;
    if (primeiroresto < 2) {
        multsoma = 0;
    } else {
        multsoma = 11 - primeiroresto;
    }
    int multsoma2 = (digito1 * 11) + (digito2 * 10) + (digito3 * 9) + (digito4 * 8) + (digito5 * 7) + (digito6 * 6) + (digito7 * 5) + (digito8 * 4) + (digito9 * 3) + (digitovd * 2);
    int segundoresto = multsoma2 % 11;
    if (segundoresto < 2) {
        multsoma2 = 0;
    } else {
        multsoma2 = 11 - segundoresto;
    }

    if (multsoma == digitovd && multsoma2 == digitovd2)
    {
        return valido;
    }else{
        return invalido;
    }
}

int ISBIXP(Nascimento data[], int qtd)
{
    for (int i = 0; data[qtd].dataProfessor[i] != '\0'; i++)
    {
        if (data[qtd].dataProfessor[i] == '\n')
        {
            data[qtd].dataProfessor[i] = '\0';
        }
    }

    int dia, mes, ano;
    sscanf(data[qtd].dataProfessor, "%d/%d/%d", &dia, &mes, &ano);
    data[qtd].diaP = dia;
    data[qtd].mesP = mes;
    data[qtd].anoP = ano;
    if (data[qtd].anoP < 100)
    {
        if (data[qtd].anoP >= 26)
        {
            data[qtd].anoP += 1900;
        }
        else
        {
            data[qtd].anoP += 2000;
        }
    }

    if (data[qtd].anoP > 2025)
    {
        return invalido;
    }

    int bix = ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0));

    switch (data[qtd].mesP)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if (data[qtd].diaP > 31)
            return invalido;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if (data[qtd].diaP > 30)
            return invalido;
        break;
    case 2:
        if ((bix && data[qtd].diaP > 29) || (!bix && data[qtd].diaP > 28))
            return invalido;
        break;
    default:
        return invalido;
    }
    printf("mes %d\n", data[0].mesP);
    return valido;
}
//aniversario professor
void aniversariantesDoMes(Teacher pro[], int qtdprof, Nascimento dataP[], CPF cpfP[]) {
    if (qtdprof <= 0) {
        printf("Nenhum professor cadastrado.\n");
        return;
    }


    Teacher tempP[TAM_LISTA_ALUNO];
    Nascimento tempData[TAM_LISTA_ALUNO];
    CPF tempCpf[TAM_LISTA_ALUNO];

    for (int i = 0; i < qtdprof; i++) {
        tempP[i] = pro[i];
        tempData[i] = dataP[i];
        tempCpf[i] = cpfP[i];
    }

    int mes;
    printf("Digite o mes que deseja buscar aniversariantes (1-12): \n");
    scanf("%d", &mes);
    getchar();

    if (mes < 1 || mes > 12) {
        printf("Mes invalido. Use um valor entre 1 e 12.\n");
        return;
    }

    int encontrou = 0;
    for (int i = 0; i < qtdprof; i++) {
        if (tempData[i].mesP == mes && tempP[i].ativoTeacher == 1) {
            encontrou = 1;
            printf("\n--- Aniversariante do Mes %d ---\n", mes);
            printf("Matricula: MAT%d\n", tempP[i].id);
            printf("Nome: %s\n", tempP[i].nameTeacher);
            printf("Sexo: %c\n", tempP[i].sexoTeacher);
            printf("Idade: %d\n", tempP[i].idadeTeacher);
            printf("CPF: %s\n", tempCpf[i].cpfProfessor);
            printf("Data de Nascimento: %02d/%02d/%04d\n",
                   tempData[i].diaP, tempData[i].mesP, tempData[i].anoP);
        }
    }

    if (!encontrou)
        printf("Nao ha aniversariantes no mes %d.\n", mes);
}