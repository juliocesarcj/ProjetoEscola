#include <stdio.h>
#include <stdlib.h>
#include <string.h>






typedef struct Student{
    int id;
    char nameAluno[255];
    int ativoAluno;
    int qtdAluno;
    char sexoAluno;
    int *PilhaAluno;
    int topAluno;
    int idadeAluno;
    char cpfAluno[12];
} Student;

typedef struct Teacher{
    int id;
    char nameTeacher[255];
    int ativoTeacher;
    int qtdTeacher;
    char sexoTeacher;
    int *PilhaTeacher;
    int topTeacher;
    char cpfTeacher[12];
} Teacher;

typedef struct Discipline{
    int id;
    char nameDisciplina[255];
    int ativoDisciplina;
    int qtdDisciplina;
    int *PilhaDisciplina;
    int topDisciplina;
} Disciplina;

typedef struct Date{
    int dia;
    int mes;
    int ano;
} Date;

typedef struct HeadStudente{
    Student *Head;
}HeadStudent;

typedef struct HeadTeacher{
    Teacher *HeadTeacher;
}HeadTeacher;

typedef struct HeadDiscipline{
    Disciplina *HeadDiscipline;
}HeadDiscipline;

void createStudent(Student *Pilha);
void init_student(Student *Pilha);
void readStudent(Student *Pilha);