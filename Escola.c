    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdbool.h>
    #include "All.h"
//menu
    int main()
    {
        CPF cpfProfessor[TAM_LISTA_PROFESSOR];
        Nascimento dataProfessor[TAM_LISTA_PROFESSOR];
        CPF cpf[TAM_LISTA_ALUNO];
        Nascimento data[TAM_LISTA_ALUNO];
        Teacher professor[TAM_LISTA_PROFESSOR];
        int qtdProfessorIF = 0;
        int selecaoPrimal = 0;
        int sairprimal = 0;
        Student aluno[TAM_LISTA_ALUNO];
        int qtdAlunoIF = 0;
        Disciplina disc[TAM_LISTA_DISCIPLINA];
        int qtdd = 0;
        while (!sairprimal)
        {
            printf("Menu Principal.\n");
            printf("0. Sair Principal\n"
                "1. Menu Aluno\n"
                "2. Menu Professor\n"
                "3. Menu Disciplina\n");
            scanf("%d", &selecaoPrimal);
            getchar();

            switch (selecaoPrimal)
            {
            case 1:
            {
                int selecaoAluno = 0;
                int sairAluno = 0;
                while (!sairAluno)
                {
                    printf("Menu Aluno.\n");
                    printf("0. Voltar ao Menu Principal\n"
                        "1. Criar Aluno\n"
                        "2. Ler Aluno\n"
                        "3. Atualizar Dados do Aluno\n"
                        "4. Deletar Aluno\n"
                        "5. Buscar Aluno por Nome\n"
                        "6.aniversariantes do mes\n");
                    scanf("%d", &selecaoAluno);
                    getchar();

                    switch (selecaoAluno)
                    {
                    case 1:
                    {

                        int resultado = createStudent(aluno, qtdAlunoIF, data, cpf);
                        switch (resultado)
                        {
                        case SUCESSO_CADASTRO:
                            printf("Cadastro realizado com sucesso.\n");
                            aluno[qtdAlunoIF].chamadaAluno = qtdAlunoIF + 1;
                            aluno[qtdAlunoIF].ativoAluno = 1;
                            qtdAlunoIF++;
                            break;
                        case ERRO_CADASTRO_SEXO:
                            printf("Erro no cadastro, sexo invalido.\n");
                            printf("Sexo deve ser F/f para feminino e M/m para masculino.\n");
                            break;
                        case ERRO_CADASTRO_MATRICULA:
                            printf("Erro no cadastro, CPF invalido.\n");
                            break;
                        case ERRO_DATA_INVALIDA:
                            printf("Erro no cadastro, data invalida.\n");
                            break;
                        default:
                            printf("ERRO DESCONHECIDO.\n");
                            break;
                        }
                        break;
                    }

                    case 2:
                    {
                        int selecaoLeitura = 0;
                        int sairLeituraAluno = 0;
                        while (!sairLeituraAluno)
                        {
                            printf("Menu de Leitura de Alunos.\n");
                            printf("1. Ler todos os Alunos\n"
                                "2. Ler Alunos por sexo\n"
                                "3. Ler Alunos por data de nascimento\n"
                                "4. Ler Alunos ordenados por nome\n"
                                "0. Voltar\n");
                            scanf("%d", &selecaoLeitura);
                            getchar();

                            switch (selecaoLeitura)
                            {
                            case 1:
                            {

                                readStudent(aluno, qtdAlunoIF, data, cpf);
                                break;
                            }
                            case 2:

                                readSexStudent(aluno, qtdAlunoIF, data, cpf);
                                break;
                            case 3:
                            {
                                readStudentDataOrdem(aluno, qtdAlunoIF, data, cpf);
                                break;
                            }
                            case 4:
                                readOrdenadosStudents(aluno, qtdAlunoIF, data, cpf);
                                break;
                            case 0:
                                sairLeituraAluno = 1;
                                break;
                            default:
                                printf("Opcao invalida.\n");
                                break;
                            }
                        }
                    }
                    break;

                    case 3:
                        atualizacaodeDados(aluno, qtdAlunoIF, data, cpf);
                        break;
                    

                    case 4:
                        deletarStudent(aluno, qtdAlunoIF);
                        break;

                    case 5:
                        buscaNome(aluno, qtdAlunoIF, data, cpf);
                        break;
                    case 0:
                        sairAluno = 1;
                        break;

                    default:
                        printf("Opcao invalida.\n");
                        break;
                    }
                
                }
            }
            break;

            case 2:
            {
                printf("Menu Professor.\n");
                int sairProfessor = 0;
                int selecaoProfessor = 0;

                while (!sairProfessor)
                {
                    printf("0. Voltar\n"
                        "1. criar  Matricula do Professor\n"
                        "2. Ler Matriculas dos Professores\n"
                        "3. Atualizar Matriculas dos Professores\n"
                        "4. Deletar Matriculas dos Professores\n"
                        "5. Buscar Professor por Nome\n"
                        "6. Aniversariantes do Mes\n");
                    scanf("%d", &selecaoProfessor);
                    getchar();

                    switch (selecaoProfessor)
                    {
                        case 1:
                        {
                            printf("Criar Matricula do Professor.\n");
                        int resultadoC = createProf(professor, qtdProfessorIF, dataProfessor, cpfProfessor);
                            switch (resultadoC)
                            {
                            case SUCESSO_CADASTRO:
                                printf("Cadastro realizado com sucesso.\n");
                                professor[qtdProfessorIF].id = qtdProfessorIF + 1;
                                professor[qtdProfessorIF].ativoTeacher = 1;
                                qtdProfessorIF++;
                                break;
                            case ERRO_CADASTRO_SEXO:
                                printf("Erro no cadastro, sexo invalido.\n");
                                printf("Sexo deve ser F/f para feminino e M/m para masculino.\n");
                                break;
                            case ERRO_CADASTRO_MATRICULA:
                                printf("Erro no cadastro, CPF invalido.\n");
                                break;
                            case ERRO_DATA_INVALIDA:
                                printf("Erro no cadastro, data invalida.\n");
                                break;
                            default:
                                printf("ERRO DESCONHECIDO.\n");
                                break;
                            }
                            break;
                        }

                    case 2:
                    {
                        int selecaoLeitura = 0;
                        int sairLeituraProfessor = 0;

                        while (!sairLeituraProfessor)
                        {
                            printf("Menu de Leitura de Professores.\n");
                            printf("1. Ler todos os Professores\n"
                                "2. Ler Professores por sexo\n"
                                "3. Ler Professores por data de nascimento\n"
                                "4. Ler Professores ordenados por nome\n"
                                "5. Buscar Professor por Nome\n"
                                "0. Voltar\n");
                            scanf("%d", &selecaoLeitura);
                            getchar();

                            switch (selecaoLeitura)
                            {
                            case 1:
                            {

                                readProf(professor, qtdProfessorIF, dataProfessor, cpfProfessor);
                                break;
                            }
                            case 2:
                            {
                                readSexProf(professor, qtdProfessorIF, dataProfessor, cpfProfessor);
                                break;
                            }
                            case 3:
                            {
                                readProfDataOrdem(professor, qtdProfessorIF, dataProfessor, cpfProfessor);
                                break;
                            }
                            case 4:
                                readOrdenadosProfessores(professor, qtdProfessorIF, dataProfessor, cpfProfessor);
                                break;
                            case 0:
                                sairLeituraProfessor = 1;
                                break;
                            default:
                                printf("Opcao invalida.\n");
                                break;
                            }
                        }
                        break;
                    }
                    case 3:
                    {
                        atualizacaodeDadosProf(professor, qtdProfessorIF, dataProfessor, cpfProfessor);
                        getchar();
                        break;
                    }
                    case 4:
                    {
                        deletarProfessor(professor, qtdProfessorIF);
                        break;
                    }
                    case 5:{
                        buscaNomeProf(professor, qtdProfessorIF, dataProfessor, cpfProfessor);
                        break;
                    }
                    case 6: {
                            aniversariantesDoMes(professor, qtdProfessorIF, dataProfessor, cpfProfessor);
                            break;
                        }
                    case 0:
                        sairProfessor = 1;
                        break;

                    default:
                        printf("Opcao invalida.\n");
                        break;
                    }
                }
                break;
            }
            break;

            case 3:
            {
                printf("Menu Disciplina.\n");
                int sairDisciplina = 0;
                int selecaoDisciplina = 0;
                while (!sairDisciplina)
                {
                    printf("0. Voltar\n"
                        "1. criar Disciplina\n"
                        "2. Ler Disciplinas\n"
                        "3. Atualizar Disciplinas\n"
                        "4. Deletar Disciplinas\n"
                        "5. Matricular Aluno na Disciplina\n"
                        "6. desmatricular Aluno na Disciplina\n");
                    scanf("%d", &selecaoDisciplina);
                    getchar();
                    int qtd = 0;
                    switch (selecaoDisciplina)
                    {
                    case 1:
                    {
                        printf("Criar Disciplina.\n");
                        criarDisciplina(disc, qtdd);
                        disc[qtdd].ativoDisciplina = 1;
                        qtdd++;
                        break;
                    }

                    case 2:
                    {
                        int selecaoleituraDisciplina = 0;
                        int sairLeituraDisciplina = 0;
                        while (!sairLeituraDisciplina)
                        {
                            printf("Menu de Leitura de Disciplinas.\n");
                            printf("1. Ler todas as Disciplinas\n"
                                "2. Ler Alunos com poucas Disciplinas\n"
                                "3. Ler Turmas com mais de 40 Alunos\n"
                                "4. Ler uma Disciplina\n"
                                "0. Voltar\n");
                            scanf("%d", &selecaoleituraDisciplina);
                            getchar();

                            switch (selecaoleituraDisciplina)
                            {
                            case 1:
                            {
                                readDisciplina(disc, qtdd, aluno, professor);
                                break;
                            }
                            case 2:
                            {
                                printf("Alunos com menos de 3 Disciplinas.\n");
                                alunoEmMenosDe3(disc, aluno, qtdAlunoIF, data, cpf);
                                break;
                            }
                            case 3:
                            {
                                printf("Turmas com mais de 40 Alunos.\n");
                                turmaComMaisDe40Alunos(disc, professor, aluno, qtdAlunoIF, data, cpf);
                                break;
                            }
                            case 4:
                            {
                                lerCertaDisciplina(disc, qtdd, aluno, data, cpf);
                                break;
                            }
                            case 0:
                                sairLeituraDisciplina = 1;
                                break;
                            default:
                                printf("Opcao invalida.\n");
                                break;
                            }
                        }
                    }
                    break;

                    case 3:
                        printf("Atualizar Disciplinas.\n");
                        atualizarDisciplina(disc, qtdd, aluno, professor);
                        getchar();
                        break;

                    case 4:
                        printf("Deletar Disciplinas.\n");
                        deletarDisciplina(disc, qtdd, aluno, professor);
                        getchar();
                        break;

                    case 5:
                        printf("Matricular Aluno na Disciplina.\n");
                        matricularNaDisciplina(professor, disc, qtdd, aluno, qtdAlunoIF, qtdProfessorIF);
                        getchar();
                        break;
                    case 6:
                        printf("Desmatricular Aluno na Disciplina.\n");
                        desmatricular(aluno, disc, professor, qtdd);
                        getchar();
                        break;
                    case 0:
                        sairDisciplina = 1;
                        break;

                    default:
                        printf("Opcao invalida.\n");
                        break;
                    }
                }
            }
            break;

            case 0:
                sairprimal = 1;
                break;

            default:
                printf("Opcao invalida.\n");
                break;
            }
        }

        return 0;
    }
