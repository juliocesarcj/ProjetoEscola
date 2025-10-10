#ifndef Escola_H
#define Escola_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Disciplina.h"
#include "Professor.h"
#include "Estudante.h"
#define TAM_LISTA_PROFESSOR 10
// Resultados bons Aluno
#define TAM_LISTA_ALUNO 3
#define SUCESSO_CADASTRO -1
#define SUCESSO_EXCLUSAO_ALUNO -2
#define SUCESSO_ATUALIZACAO_ALUNO -3

// Resultados ruins Aluno
#define falha -29
#define ERRO_CADASTRO_MATRICULA -30
#define ERRO_CADASTRO_SEXO -31
#define ERRO_DATA_INVALIDA -32
#define ERRO_EXCLUSAO_ALUNO -33
#define ALUNO_NAO_ENCONTRADO -34

#define DELETADO_COM_SUCESSO -50

#define TAM_LISTA_DISCIPLINA 66
#define valido -45
#define invalido -46

typedef struct Nascimento
{
    char data[12];
    int dia;
    int mes;
    int ano;
    int diaP;
    int mesP;
    int anoP;
    char dataProfessor[12];
} Nascimento;

typedef struct CPF
{
    char cpf[16];
    char cpfProfessor[16];
} CPF;

// geral
int validacaodeCPF(CPF cpf[], int qtd);
int ISBIX(Nascimento data[], int qtd);
int ISBIXP(Nascimento data[], int qtd);
int desmatricular(Student aluno[], Disciplina Disciplina[], Teacher professor[], int qtdd);



#endif