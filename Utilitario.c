#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "All.h"



int validacaodeCPF(Student aluno){
    int cpf;
   cpf = atoi(aluno.cpfAluno);
    int digito1 = (cpf / 10000000000)%10;
    int digito2 = (cpf / 1000000000)%10;
    int digito3 = (cpf / 100000000)%10;
    int digito4 = (cpf / 10000000)%10;
    int digito5 = (cpf / 1000000)%10;
    int digito6 = (cpf / 100000)%10;
    int digito7 = (cpf / 10000)%10;
    int digito8 = (cpf / 1000)%10;
    int digito9 = (cpf / 100)%10;

    int digitovd = (cpf / 10)%10;
    int digitovd2 = (cpf % 10);

    int multsoma = (digito1*10) + (digito2*9) + (digito3*8) + (digito4*7) + (digito5*6) + (digito6*5) + (digito7*4) + (digito8*3) + (digito9*2); 
    int primeiroresto = multsoma % 11;
    int primeiroVerificador = 11 - primeiroresto;
    int multsoma2 = (digito1*11) + (digito2*10) + (digito3*9) + (digito4*8) + (digito5*7) + (digito6*6) + (digito7*5) + (digito8*4) + (digito9*3) + (digitovd*2); 
    int segundoresto = multsoma2 % 11;
    int segundoVerificador = 11 - segundoresto;

    if (primeiroVerificador == digitovd && segundoVerificador == digitovd2) {
        printf("CPF valido.\n");
        return valido;
    } else {
        printf("CPF invalido.\n");
        return 1;
    }
}