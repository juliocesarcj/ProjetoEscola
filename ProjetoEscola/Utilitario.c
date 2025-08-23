#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "All.h"



int validacaodeCPF(CPF cpf[], int qtdAluno){

   
    int digito1 = atoi (cpf[0].cpf);
    int digito2 = atoi (cpf[1].cpf);
    int digito3 = atoi (cpf[2].cpf);
    int digito4 = atoi (cpf[3].cpf);
    int digito5 = atoi (cpf[4].cpf);
    int digito6 = atoi (cpf[5].cpf);
    int digito7 = atoi (cpf[6].cpf);
    int digito8 = atoi (cpf[7].cpf);
    int digito9 = atoi (cpf[8].cpf);

    int digitovd = atoi (cpf[9].cpf);
    int digitovd2 = atoi (cpf[10].cpf);

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