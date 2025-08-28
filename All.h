#ifndef All_H
#define All_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_LISTA_PROFESSOR 10
//Resultados bons Aluno
#define TAM_LISTA_ALUNO 3
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

#define DELETADO_COM_SUCESSO -50

#define TAM_LISTA_DISCIPLINA 66
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
    int idadeTeacher;
} Teacher;

typedef struct Discipline{
    int codigo;
    char disciplina[255];
    int ativoDisciplina;
    int qtd;
    int professor;
    int qtdAlunos[40];
    int semestre;
    int ativoNaDisciplinaaluno;
    int ativoNaDisciplinaprofessor;
} Disciplina;

typedef struct Nascimento{
    char data[11];
    int dia;
    int mes;
    int ano; 
    int formatada[15];
    char dataProfessor[11];
} Nascimento;

typedef struct CPF{
    char cpf[12];
    char cpfProfessor[12];
} CPF;

//ALUNO
int createStudent(Student aluno[], int qtdAluno, Nascimento calendario[], CPF cpf[]);
void readStudent(Student aluno[], int qtdAluno, Nascimento calendario[], CPF cpf[]);
void atualizacaodeDados(Student aluno[], int qtdAluno, Nascimento cal[], CPF cpf[]);
int deletarStudent(Student aluno[], int qtdAluno);
int validacaodeCPF(CPF cpf[], int qtd);
void readSexStudent(Student aluno[], int qtdAluno, Nascimento data[], CPF cpf[]);
void readOrdenadosStudants(Student aluno[], int qtdAluno, Nascimento data[], CPF cpf[]);
void buscaNome(Student aluno[], int qtdAluno);
int ISBIX(Nascimento data[], int qtd);
void readStudentDataOrdem(Student aluno[], int qtdAluno, Nascimento data[], CPF cpf[]);

//DISCIPLINA
void readDisciplina(Disciplina disciplina[], int qtd, Student aluno[], Teacher professor[]);
int criarDisciplina(Disciplina disciplina[], int qtd);
int matricularNaDisciplina(Teacher professor[], Disciplina disciplina[], int qtdDisciplina, Student aluno[]);


//PROFESSOR
int createProf(Teacher professor[], int qtdprof, Nascimento calendario[], CPF cpf[]);
void readProf(Teacher professor[], int qtdprof, Nascimento calendario[], CPF cpf[]);
int deletarProfessor(Teacher professor[], int qtdprof);
void atualizacaodeDadosProf(Teacher professor[], int qtdprof, Nascimento cal[], CPF cpf[]);

void readSexProf(Teacher professor[], int qtdprof, Nascimento data[], CPF cpf[]);
void readOrdenadosProfessores(Teacher professor[], int qtdprof, Nascimento data[], CPF cpf[]);
void readProfDataOrdem(Teacher professor[], int qtdprof, Nascimento data[], CPF cpf[]);
void buscaNomeProf(Teacher professor[], int qtdprof);
#endif