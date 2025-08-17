#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "All.h"



int validacaodeCPF(Student aluno[], int qtdAluno){

    int cpf = aluno[qtdAluno].cpfAluno;
    int digito1 = atoi (aluno[0].cpfAluno);
    int digito2 = atoi (aluno[1].cpfAluno);
    int digito3 = atoi (aluno[2].cpfAluno);
    int digito4 = atoi (aluno[3].cpfAluno);
    int digito5 = atoi (aluno[4].cpfAluno);
    int digito6 = atoi (aluno[5].cpfAluno);
    int digito7 = atoi (aluno[6].cpfAluno);
    int digito8 = atoi (aluno[7].cpfAluno);
    int digito9 = atoi (aluno[8].cpfAluno)

    int digitovd = atoi (aluno[9].cpfAluno);
    int digitovd2 = atoi (aluno[10].cpfAluno);

    int multsoma = (digito1*10) + (digito2*9) + (digito3*8) + (digito4*7) + (digito5*6) + (digito6*5) + (digito7*4) + (digito8*3) + (digito9*2); 
    int primeiroresto = multsoma % 11;
    int primeiroVerificador = 11 - primeiroresto;
    int multsoma2 = (digito1*11) + (digito2*10) + (digito3*9) + (digito4*8) + (digito5*7) + (digito6*6) + (digito7*5) + (digito8*4) + (digito9*3) + (digitovd*2); 
    int segundoresto = multsoma2 % 11;
    int segundoVerificador = 11 - segundoresto;
    
    if (primeiroVerificador >= 10) {
        primeiroVerificador = 0;
    }

    if(primeiroVerificador!=0) return invalido; 

    if (segundoVerificador >= 10) {
        segundoVerificador = 0;
    }

    if(segundoVerificador!=0) return invalido;
    if (primeiroVerificador == digitovd && segundoVerificador == digitovd2) {
        printf("CPF valido.\n");
        return valido;
    } else {
        printf("CPF invalido.\n");
        return invalido;
    }
}