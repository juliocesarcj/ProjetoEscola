#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "All.h"



int validacaodeCPF(CPF cpf[], int qtd){

    int digito1 =  (cpf[qtd].cpf[0]) - '0';
    int digito2 =  (cpf[qtd].cpf[1]) - '0';
    int digito3 =  (cpf[qtd].cpf[2]) - '0';
    int digito4 =  (cpf[qtd].cpf[3]) - '0';
    int digito5 =  (cpf[qtd].cpf[4]) - '0';
    int digito6 =  (cpf[qtd].cpf[5]) - '0';
    int digito7 =  (cpf[qtd].cpf[6]) - '0';
    int digito8 =  (cpf[qtd].cpf[7]) - '0';
    int digito9 =  (cpf[qtd].cpf[8]) - '0';

    int digitovd = (cpf[qtd].cpf[9]) - '0';
    int digitovd2 = (cpf[qtd].cpf[10]) - '0';

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