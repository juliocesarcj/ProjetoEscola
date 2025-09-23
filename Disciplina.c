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

int matricularNaDisciplina(Teacher professor[], Disciplina disciplina[], int qtdDisciplina, Student aluno[], int qtdAluno, int qtdProfessor)
{
    int codDisc, idAluno, idProfessor;

    printf("Digite o codigo da disciplina: \n");
    scanf("%d", &codDisc);
    getchar();

    printf("Digite o numero de chamada do aluno: \n");
    scanf("%d", &idAluno);
    getchar();

    printf("Digite o numero de chamada do professor: \n");
    scanf("%d", &idProfessor);
    getchar();

    int achouDisc = -1;
    for (int i = 0; i < qtdDisciplina; i++)
    {
        if (disciplina[i].codigo == codDisc)
        {
            achouDisc = i;
            break;
        }
    }

    if (achouDisc == -1)
    {
        printf("Disciplina nao encontrada.\n");
        return falha;
    }
    int achouA = -1;
    for (int i = 0; i < qtdAluno; i++)
    {
        if (aluno[i].chamadaAluno == idAluno)
        {
            achouA = i;
            break;
        }
    }

    if (achouA == -1)
    {
        printf("Aluno nao encontrado.\n");
        return ALUNO_NAO_ENCONTRADO;
    }

    int qtdAtualAlunos = disciplina[achouDisc].qtd;
    disciplina[achouDisc].codAluno[qtdAtualAlunos] = aluno[achouA].id;
    disciplina[achouDisc].qtd++;
    disciplina[achouDisc].ativoNaDisciplinaaluno = 1;
    printf("Aluno %s matriculado com sucesso.\n", aluno[achouA].nameAluno);
    int achouP = -1;
    for (int i = 0; i < qtdProfessor; i++)
    {
        if (professor[i].id == idProfessor)
        {
            achouP = i;
            break;
        }
    }

    if (achouP == -1)
    {
        printf("Professor nao encontrado.\n");
        return falha;
    }

    disciplina[achouDisc].professor = professor[achouP].id;
    disciplina[achouDisc].codProf[0] = professor[achouP].id;
    disciplina[achouDisc].ativoNaDisciplinaprofessor = 1;
    disciplina[achouDisc].qtdAluno++;
    disciplina[achouDisc].qtdPro++;
    printf("Professor %s atribuido com sucesso.\n", professor[achouP].nameTeacher);

    return SUCESSO_CADASTRO;
}

void readDisciplina(Disciplina disc[], int qtd, Student aluno[], Teacher professor[])
{
    Disciplina disciplina[TAM_LISTA_ALUNO];
    for (int i = 0; i < qtd; i++)
    {
        disciplina[i] = disc[i];
    }
    if (qtd == 0)
    {
        printf("Nenhuma disciplina cadastrada.\n");
        return;
    }
    for (int i = 0; i < qtd; i++)
    {
        if (disciplina[i].ativoDisciplina == 1 && aluno)
        {
            printf("DISCIPLINAS\n");
            printf("Codigo: %d\n", disciplina[i].codigo);
            printf("Nome da Disciplina: %s\n", disciplina[i].disciplina);
            printf("Quantidade de Alunos: %d\n", disciplina[i].qtdAluno);
            printf("ID do Professor: %d\n", disciplina[i].professor);
            printf("Semestre: %d\n", disciplina[i].semestre);
            for (int j = 0; j < disciplina[i].qtd; j++)
            {
                printf("PROFESSORES\n");
                if (professor[i].id != 0 && professor[i].ativoTeacher == 1)
                {
                    printf("Professor ID: %d\n", disciplina[i].professor);
                    printf("Nome do Professor: %s\n", professor[i].nameTeacher);
                }
                printf("ALUNOS\n");
                if (disciplina[i].codAluno[j] != 0 && aluno[i].ativoAluno == 1)
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
    if (escolha == 1)
    {
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
                Disciplina[i].qtdAluno --;
                return SUCESSO_CADASTRO;
            }            if (aluno[i].chamadaAluno == id && aluno[i].ativoAluno == 1)
            {
                printf("Professor %s desmatriculado com sucesso.\n", aluno[i].nameAluno);
                Disciplina[i].ativoNaDisciplinaprofessor = 0;
                Disciplina[i].qtdPro--;   
                return SUCESSO_CADASTRO;
            }
        }
        for(int i = 0; i < qtdd; i++)
        {
            Disciplina[i] = Disciplina[i+1];
        }
    }
    else
    {
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

int alunoEmMenosDe3(Disciplina disc[], Student aluno[], int qtdAluno, Nascimento DATA[], CPF cpf[])
{
    Student tempAluno[TAM_LISTA_ALUNO];
    Nascimento tempData[TAM_LISTA_ALUNO];
    CPF tempCpf[TAM_LISTA_ALUNO];

    for (int i = 0; i < qtdAluno; i++)
    {
        tempAluno[i] = aluno[i];
        tempData[i] = DATA[i];
        tempCpf[i] = cpf[i];
    }
    int cont = 0;
    for (int i = 0; i < qtdAluno; i++)
    {
        cont = 0;
        for (int j = 0; j < disc[i].qtd; j++)
        {
            if (disc[i].codAluno[j] == aluno[i].id && aluno[i].ativoAluno == 1)
            {
                cont++;
            }
        }
        if (cont < 2 && aluno[i].ativoAluno == 1)
        {
            printf("Aluno: %s, Numero de Chamada: %d, Quantidade de Disciplinas: %d\n", aluno[i].nameAluno, aluno[i].chamadaAluno, cont);
            printf("\nNumero de Chamada: %d", tempAluno[i].chamadaAluno);
            printf("\nmatricula: MAT%d", tempAluno[i].id);
            printf("\nNome: %s", tempAluno[i].nameAluno);
            printf("\nSexo: %c", tempAluno[i].sexoAluno);
            printf("\nIdade: %d", tempAluno[i].idadeAluno);
            printf("\nCPF: %s\n", tempCpf[i].cpf);
            sprintf(tempData[i].data, "%02d/%02d/%04d", tempData[i].dia, tempData[i].mes, tempData[i].ano);
            printf("Data de Nascimento: %s\n", tempData[i].data);
        }
    }
}

int turmaComMaisDe40Alunos(Disciplina disc[], Teacher pro[], Student aluno[], int qtdAluno, Nascimento DATA[], CPF cpf[])
{
    printf("Disciplinas com mais de 40 alunos:\n");
    int encontrou = 0;
    for (int i = 0; i < TAM_LISTA_DISCIPLINA; i++)
    {
        if (disc[i].qtd > 1 && disc[i].ativoDisciplina == 1)
        {
            encontrou = 1;
            printf("\nDisciplina com %d alunos\n", disc[i].qtd);
            printf("Codigo: %d\n", disc[i].codigo);
            printf("Nome: %s\n", disc[i].disciplina);
            printf("Semestre: %d\n", disc[i].semestre);
            printf("Quantidade de alunos: %d\n", disc[i].qtdAluno);
            int professorEncontrado = 0;
            for (int j = 0; j < TAM_LISTA_PROFESSOR; j++)
            {
                if (pro[j].ativoTeacher == 1 && pro[j].id == disc[i].professor)
                {
                    printf("Professor: %s (ID: %d)\n", pro[j].nameTeacher, pro[j].id);
                    professorEncontrado = 1;
                    break;
                }
            }
            
            if (!professorEncontrado)
                printf("Professor: Nao atribuido\n");
        }
    }

    if (!encontrou)
        printf("Nenhuma disciplina com mais de 40 alunos encontrada.\n");

    return SUCESSO_CADASTRO;
}

void lerCertaDisciplina(Disciplina disciplina[], int qtd, Student aluno[], Nascimento data[], CPF cpf[])
{
    Student tempAluno[TAM_LISTA_ALUNO];
    Nascimento tempData[TAM_LISTA_ALUNO];
    CPF tempCpf[TAM_LISTA_ALUNO];
    Disciplina tempDisciplina[TAM_LISTA_ALUNO];
    for (int i = 0; i < qtd; i++)
    {
        tempAluno[i] = aluno[i];
        tempData[i] = data[i];
        tempCpf[i] = cpf[i];
        tempDisciplina[i] = disciplina[i];
    }
    if (qtd == 0)
    {
        printf("Nenhuma disciplina cadastrada.\n");
        return;
    }
    int cod;
    printf("Digite o codigo da disciplina: \n");
    scanf("%d", &cod);
    getchar();
    for (int i = 0; i < qtd; i++)
    {
        if (disciplina[i].codigo == cod && disciplina[i].ativoDisciplina == 1)
        {
            printf("DISCIPLINAS\n");
            printf("Codigo: %d\n", disciplina[i].codigo);
            printf("Nome da Disciplina: %s\n", disciplina[i].disciplina);
            printf("Quantidade de Alunos: %d\n", disciplina[i].qtd);
            printf("ID do Professor: %d\n", disciplina[i].professor);
            printf("Semestre: %d\n", disciplina[i].semestre);
            printf("alunos\n");
            printf("\nNumero de Chamada: %d", tempAluno[i].chamadaAluno);
            printf("\nmatricula: MAT%d", tempAluno[i].id);
            printf("\nNome: %s", tempAluno[i].nameAluno);
            printf("\nSexo: %c", tempAluno[i].sexoAluno);
            printf("\nIdade: %d", tempAluno[i].idadeAluno);
            printf("\nCPF: %s\n", tempCpf[i].cpf);
            sprintf(tempData[i].data, "%02d/%02d/%04d", tempData[i].dia, tempData[i].mes, tempData[i].ano);
            printf("Data de Nascimento: %s\n", tempData[i].data);
        }
    }
}

int deletarDisciplina(Disciplina disc[], int qtd, Student aluno[], Teacher professor[])
{
    int cod;
    printf("Digite o codigo da disciplina que deseja deletar: \n");
    scanf("%d", &cod);
    getchar();
    for (int i = 0; i < qtd; i++)
    {
        if (disc[i].codigo == cod && disc[i].ativoDisciplina == 1)
        {
            disc[i].ativoDisciplina = 0;
            printf("Disciplina %s deletada com sucesso.\n", disc[i].disciplina);
            return SUCESSO_CADASTRO;
        }
    }
    printf("Disciplina nao encontrada.\n");
    return falha;
}

int atualizarDisciplina(Disciplina disc[], int qtd, Student aluno[], Teacher professor[])
{
    int cod;
    printf("Digite o codigo da disciplina que deseja atualizar: \n");
    scanf("%d", &cod);
    getchar();
    for (int i = 0; i < qtd; i++)
    {
        if (disc[i].codigo == cod && disc[i].ativoDisciplina == 1)
        {
            printf("Digite o novo nome da disciplina: \n");
            fgets(disc[i].disciplina, 250, stdin);
            for (int j = 0; disc[i].disciplina[j] != '\0'; j++)
            {
                if (disc[i].disciplina[j] == '\n')
                {
                    disc[i].disciplina[j] = '\0';
                }
            }
            printf("Digite o novo semestre da disciplina: \n");
            scanf("%d", &disc[i].semestre);
            getchar();
            printf("Disciplina atualizada com sucesso.\n");
            return SUCESSO_CADASTRO;
        }
    }
    printf("Disciplina nao encontrada.\n");
    return falha;
}