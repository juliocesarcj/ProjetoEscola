#ifndef Estudante_H
#define Estudante_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Disciplina.h"
#include "Escola.h"
#include "Professor.h"
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
#endif