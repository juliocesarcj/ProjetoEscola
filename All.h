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
    int semestre;
    int ativoNaDisciplinaaluno;
    int ativoNaDisciplinaprofessor;
    int codProf[50];
    int codAluno[60];
    int qtdAluno;
    int qtdPro;
} Disciplina;

typedef struct Nascimento{
    char data[12];
    int dia;
    int mes;
    int ano; 
    int diaP;
    int mesP;
    int anoP; 
    char dataProfessor[12];
} Nascimento;

typedef struct CPF{
    char cpf[16];
    char cpfProfessor[16];
} CPF;

//ALUNO
int createStudent(Student aluno[], int qtdAluno, Nascimento calendario[], CPF cpf[]);
void readStudent(Student aluno[], int qtdAluno, Nascimento calendario[], CPF cpf[]);
void atualizacaodeDados(Student aluno[], int qtdAluno, Nascimento cal[], CPF cpf[]);
int deletarStudent(Student aluno[], int qtdAluno);
void readSexStudent(Student aluno[], int qtdAluno, Nascimento data[], CPF cpf[]);
void buscaNome(Student aluno[], int qtdAluno, Nascimento data[], CPF cpf[]);
void readStudentDataOrdem(Student aluno[], int qtdAluno, Nascimento data[], CPF cpf[]);
int copia(Student origin[], Nascimento calendario[], CPF cpf[], int qtdAluno);
void readOrdenadosStudents(Student aluno[], int qtdAluno, Nascimento data[], CPF cpf[]);
int LetraCompare(Student Letra[], int qtdAluno);
//geral
int validacaodeCPF(CPF cpf[], int qtd);
int ISBIX(Nascimento data[], int qtd);
int ISBIXP(Nascimento data[], int qtd);
int desmatricular(Student aluno[], Disciplina Disciplina[], Teacher professor[], int qtdd);

//DISCIPLINA
void readDisciplina(Disciplina disciplina[], int qtd, Student aluno[], Teacher professor[]);
int criarDisciplina(Disciplina disciplina[], int qtd);
int matricularNaDisciplina(Teacher professor[], Disciplina disciplina[], int qtdDisciplina, Student aluno[], int qtdAluno, int qtdProfessor);
int alunoEmMenosDe3(Disciplina disc[],Student aluno[], int qtdAlunoIF, Nascimento DATA[], CPF cpf[]);
int turmaComMaisDe40Alunos(Disciplina disc[], Teacher pro[], Student aluno[], int qtdAluno, Nascimento DATA[], CPF cpf[]);
void lerCertaDisciplina(Disciplina disciplina[], int qtd, Student aluno[], Nascimento data[], CPF cpf[]);
int deletarDisciplina(Disciplina disc[], int qtd, Student aluno[], Teacher professor[]);
int atualizarDisciplina(Disciplina disc[], int qtd, Student aluno[], Teacher professor[]);
//PROFESSOR
int createProf(Teacher professor[], int qtdprof, Nascimento calendario[], CPF cpf[]);
void readProf(Teacher professor[], int qtdprof, Nascimento calendario[], CPF cpf[]);
int deletarProfessor(Teacher professor[], int qtdprof);
void atualizacaodeDadosProf(Teacher professor[], int qtdprof, Nascimento cal[], CPF cpf[]);
void readSexProf(Teacher professor[], int qtdprof, Nascimento data[], CPF cpf[]);
void readOrdenadosProfessores(Teacher professor[], int qtdprof, Nascimento data[], CPF cpf[]);
void readProfDataOrdem(Teacher professor[], int qtdprof, Nascimento data[], CPF cpf[]);
void buscaNomeProf(Teacher professor[], int qtdprof, Nascimento data[], CPF cpf[]);
int validacaodeCPFP(CPF cpf[], int qtd);
void aniversariantesDoMes(Teacher pro[], int qtdprof, Nascimento data[], CPF cpf[]);
#endif