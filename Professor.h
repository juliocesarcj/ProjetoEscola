#ifndef Professor_H
#define Professor_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Disciplina.h"
#include "Escola.h"
#include "Estudante.h"
typedef struct Teacher{
    int id;
    char nameTeacher[255];
    int ativoTeacher;
    char sexoTeacher;
    char cpfTeacher[12];
    int idadeTeacher;
} Teacher;

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