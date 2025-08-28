#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "All.h"

int criarDisciplina(Disciplina disciplina[], int qtd)
{
    printf("digite o nome da disciplina: \n");
    fgets(disciplina[qtd].disciplina, 250, stdin);
    for (int i = 0; disciplina[qtd].disciplina[i] != '\0'; i++)
    {
        if (disciplina[qtd].disciplina[i] == '\n')
        {
            disciplina[qtd].disciplina[i] = '\0';
        }
    }   
    printf("digite o codigo da disciplina: \n");
    scanf("%d", &disciplina[qtd].codigo);
    getchar();
    printf("digite o semestre da disciplina: \n");
    scanf("%d", &disciplina[qtd].semestre);
    getchar();
    printf("Disciplina criada com sucesso.\n");
    return SUCESSO_CADASTRO;
}

int matricularNaDisciplina(Teacher professor[], Disciplina disciplina[], int qtdDisciplina, Student aluno[])
{
    char alunoID[255];
    int cod;
    char professorID[255];
    int professorI;
    for (int i = 0; i < qtdDisciplina; i++)
    {
        for (int j = 0; j < qtdDisciplina; j++)
        {
            alunoID[i] = aluno[i].nameAluno[j];
            professorID[i] = professor[i].nameTeacher[j];
        }
    }

    int id;
    printf("Digite o codigo da disciplina: \n");
    scanf("%d", &cod);
    getchar();  
    printf("Digite o numero de chamada do aluno: \n");
    scanf("%d", &id);
    getchar();
    printf("Digite o numero de chamada do professor: \n");
    scanf("%d", &professorI);
    int achou = 0;
    for(achou=0; achou < qtdDisciplina; achou++){
        if(cod == disciplina[achou].codigo){
            printf("Disciplina encontrada.\n");
        } else {
            printf("Disciplina nao encontrada.\n");
            return falha;
        }
    }
printf("disciplina id %d", achou);
    for(int i = 0; i < qtdDisciplina; i++){
        if(id == alunoID[i] && disciplina[achou].codigo==id){
            for(int j = 0; j < qtdDisciplina; j++){
            disciplina[i].qtdAlunos[j] = alunoID[j];
            disciplina[achou].codigo = aluno[i].id;
            }
            printf("Aluno matriculado com sucesso.\n");
            disciplina[i].ativoNaDisciplinaaluno = 1;
        }
    
        if(professorI == professorID[i]){
            disciplina[i].professor = professorID[i];
            printf("Professor atribuido com sucesso.\n");
            disciplina[i].ativoNaDisciplinaprofessor = 1;
        }
    }
}
void readDisciplina(Disciplina disciplina[], int qtd, Student aluno[], Teacher professor[])
{
    if (qtd == 0)
    {
        printf("Nenhuma disciplina cadastrada.\n");
        return;
    }
    for (int i = 0; i < qtd; i++)
    {
        if (disciplina[i].ativoDisciplina == 1)
        {
            printf("=========DISCIPLINAS=========\n");
            printf("Codigo: %d\n", disciplina[i].codigo);
            printf("Nome da Disciplina: %s\n", disciplina[i].disciplina);
            printf("Quantidade de Alunos: %d\n", disciplina[i].qtd);
            printf("ID do Professor: %d\n", disciplina[i].professor);
            printf("Semestre: %d\n", disciplina[i].semestre);
            for (int j = 0; j < disciplina[i].qtd; j++)
            {
            printf("=========PROFESSORES=========\n");
                if(professor[i].id != 0 && professor[i].ativoTeacher == 1){
                    printf("Professor ID: %d\n", disciplina[i].professor);
                    printf("Nome do Professor: %s\n", professor[i].nameTeacher);
                }
            printf("==========ALUNOS=========\n");
                if (disciplina[i].qtdAlunos[j] != 0 && aluno[i].ativoAluno == 1)
                {
                    printf("Aluno ID: %d\n", aluno[i].chamadaAluno);
                    printf("Nome do Aluno: %s\n", aluno[i].nameAluno);
                }
            }
        }
    }
}
int desmatricular(Student aluno[], Disciplina Disciplina[], Teacher professor[], int qtdd)
{
 
    printf("deseja desmatricular um aluno ou professor\n"
              "1. Aluno\n"
              "2. Professor\n");
              int escolha;
    scanf("%d", &escolha);
    if(escolha==1){
    printf("digite o numero da chamada do aluno que deseja desmatricular: \n");
    int id;
    scanf("%d", &id);
    getchar();
    for (int i = 0; i < qtdd; i++)
    {
        if (aluno[i].chamadaAluno == id && aluno[i].ativoAluno == 1)
        {
            printf("Aluno %s desmatriculado com sucesso.\n", aluno[i].nameAluno);
            Disciplina[i].ativoNaDisciplinaaluno = 0;
            return SUCESSO_CADASTRO;
        }
    }
}else{
    printf("digite o id do professor que deseja desmatricular: \n");
    int id;
    scanf("%d", &id);
    getchar();
    for (int i = 0; i < qtdd; i++)
    {
        if (professor[i].id == id && professor[i].ativoTeacher == 1)
        {
            printf("Professor %s desmatriculado com sucesso.\n", professor[i].nameTeacher);
            Disciplina[i].ativoNaDisciplinaprofessor = 0;
            return SUCESSO_CADASTRO;
        }
    }
}
    return 0;
}