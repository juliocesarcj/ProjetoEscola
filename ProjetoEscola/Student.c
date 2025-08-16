#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "All.h"


void createStudent(Student *Pilha){
    Pilha->ativoAluno = 1;
    Pilha->qtdAluno++;
    Pilha->id++;
    Pilha->topAluno++;
    printf("Aluno criado com sucesso!\n");
}
void readStudent(Student *Pilha){
    if (Pilha == NULL || Pilha->qtdAluno == 0) {
        printf("Sem estudantes cadastrados.\n");
        return;
    }
    if(Pilha->ativoAluno == 1){
        printf("ID: %d\n", Pilha->id);
        printf("Name: %s\n", Pilha->nameAluno);
        printf("Sexo: %c\n", Pilha->sexoAluno);
        printf("Idade: %d\n", Pilha->idadeAluno);
        printf("CPF: %s\n", Pilha->cpfAluno);
    } else {
        printf("Lista vazia\n");
        return;
    }
}