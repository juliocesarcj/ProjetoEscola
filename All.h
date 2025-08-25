#ifndef All_H
#define All_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Resultados bons Aluno
#define TAM_LISTA_ALUNO 10
#define SUCESSO_CADASTRO -1
#define SUCESSO_EXCLUSAO_ALUNO -2
#define SUCESSO_ATUALIZACAO_ALUNO -3

//Resultados ruins Aluno
#define falha -29
#define ERRO_CADASTRO_MATRICULA -30
#define ERRO_CADASTRO_SEXO -31
#define ERRO_DATA_INVALIDA -32
#define ERRO_EXCLUSAO_ALUNO -33
#define ALUNO_NAO_ENCONTRADO -34



#define valido -45
#define invalido -46
typedef struct Student{
    int id;
    int chamadaAluno;
    char nameAluno[255];
    int ativoAluno;
    char sexoAluno;
    int qtdAluno;
    int *PilhaAluno;
    int idadeAluno;
    char cpfAluno[12];
} Student;

typedef struct Teacher{
    int id;
    char nameTeacher[255];
    int ativoTeacher;
    char sexoTeacher;
    char cpfTeacher[12];
} Teacher;

typedef struct Discipline{
    int id;
    char nameDisciplina[255];
    int ativoDisciplina;
    int qtdDisciplina;
    int topDisciplina;
} Disciplina;

typedef struct Nascimento{
    char data[11];;
    int dia;
    int mes;
    int ano; 
} Nascimento;

typedef struct CPF{
    char cpf[12];
} CPF;

void atualizacaodeDados(Student aluno[], int qtdAluno, Nascimento cal[], CPF cpf[]);
int createStudent(Student aluno[], int qtdAluno, Nascimento calendario[], CPF cpf[]);
int validacaodeCPF(CPF cpf[], int qtd);
void readStudent(Student aluno[], int qtdAluno, Nascimento calendario[], CPF cpf[]);
int deletarStudent(Student aluno[], int qtdAluno);
void readSexStudent(Student aluno[], int qtdAluno, Nascimento data[], CPF cpf[]);

#endif 