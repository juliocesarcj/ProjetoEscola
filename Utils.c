#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "All.h"

int validacaoData(Nascimento calendario[], int qtdAluno)
{
    char dia[3];
    char mes[3];
    char ano[5];

    dia[3] = '\0';
    mes[3] = '\0';
    ano[5] = '\0';
    strncpy(dia, calendario[qtdAluno].data, 2);
    strncpy(mes, calendario[qtdAluno].data + 3, 2);
    strncpy(ano, calendario[qtdAluno].data + 6, 4);
    int Dint = atoi(dia);
    int Mint = atoi(mes);
    int Aint = atoi(ano);
    printf("%d/%d/%d", calendario[qtdAluno].dia, calendario[qtdAluno].mes, calendario[qtdAluno].ano);

    if (Dint < 1 || Dint > 31)
    {
        printf("Data invalida.\n");
        return ERRO_DATA_INVALIDA;
    }
    if (Mint < 1 || Mint > 12)
    {
        printf("Data invalida.\n");
        return ERRO_DATA_INVALIDA;
    }
    switch (Mint)
    {
    case 2:
        if (Dint == 29 && (Aint % 4 != 0))
        {
            printf("Data invalida.\n");
            return ERRO_DATA_INVALIDA;
        }
        if (Dint > 28)
        {
            printf("Data invalida.\n");
            return ERRO_DATA_INVALIDA;
        }

        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if (Dint > 30)
        {
            printf("Data invalida.\n");
            return ERRO_DATA_INVALIDA;
        }
        break;
    default:
        break;
    }
}

int validacaodeCPF(Student aluno[], int qtdAluno)
{

    int digito1 = (aluno[qtdAluno].cpfAluno[0] - '0');
    int digito2 = (aluno[qtdAluno].cpfAluno[1] - '0');
    int digito3 = (aluno[qtdAluno].cpfAluno[2] - '0');
    int digito4 = (aluno[qtdAluno].cpfAluno[3] - '0');
    int digito5 = (aluno[qtdAluno].cpfAluno[4] - '0');
    int digito6 = (aluno[qtdAluno].cpfAluno[5] - '0');
    int digito7 = (aluno[qtdAluno].cpfAluno[6] - '0');
    int digito8 = (aluno[qtdAluno].cpfAluno[7] - '0');
    int digito9 = (aluno[qtdAluno].cpfAluno[8] - '0');

    int digitovd = (aluno[qtdAluno].cpfAluno[9] - '0');
    int digitovd2 = (aluno[qtdAluno].cpfAluno[10] - '0');

    int multsoma = (digito1 * 10) + (digito2 * 9) + (digito3 * 8) + (digito4 * 7) + (digito5 * 6) + (digito6 * 5) + (digito7 * 4) + (digito8 * 3) + (digito9 * 2);
    int primeiroresto = multsoma % 11;
    int primeiroVerificador = 11 - primeiroresto;
    int multsoma2 = (digito1 * 11) + (digito2 * 10) + (digito3 * 9) + (digito4 * 8) + (digito5 * 7) + (digito6 * 6) + (digito7 * 5) + (digito8 * 4) + (digito9 * 3) + (primeiroVerificador * 2);
    int segundoresto = multsoma2 % 11;
    int segundoVerificador = 11 - segundoresto;

    if (primeiroVerificador >= 10)
    {
        primeiroVerificador = 0;
    }

    if (segundoVerificador >= 10)
    {
        segundoVerificador = 0;
    }
    if (primeiroVerificador != digitovd && segundoVerificador != digitovd2)
    {
        printf("CPF invalido.\n");
        return invalido;
    }
}