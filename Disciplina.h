#ifndef Disciplina_H
#define Disciplina_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Escola.h"
#include "Professor.h"
#include "Estudante.h"

typedef struct Discipline
{
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

// DISCIPLINA
void readDisciplina(Disciplina disciplina[], int qtd, Student aluno[], Teacher professor[]);
int criarDisciplina(Disciplina disciplina[], int qtd);
int matricularNaDisciplina(Teacher professor[], Disciplina disciplina[], int qtdDisciplina, Student aluno[], int qtdAluno, int qtdProfessor);
int alunoEmMenosDe3(Disciplina disc[], Student aluno[], int qtdAlunoIF, Nascimento DATA[], CPF cpf[]);
int turmaComMaisDe40Alunos(Disciplina disc[], Teacher pro[], Student aluno[], int qtdAluno, Nascimento DATA[], CPF cpf[]);
void lerCertaDisciplina(Disciplina disciplina[], int qtd, Student aluno[], Nascimento data[], CPF cpf[]);
int deletarDisciplina(Disciplina disc[], int qtd, Student aluno[], Teacher professor[]);
int atualizarDisciplina(Disciplina disc[], int qtd, Student aluno[], Teacher professor[]);
#endif