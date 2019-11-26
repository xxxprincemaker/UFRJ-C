#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct _NOTA{
    float n1,n2;
} NOTA;


typedef struct _ALUNO{
    int id;
    char nome[50];
    NOTA *nota;
} ALUNO;


int main(void){

    ALUNO *cadastro;
    if(!(cadastro = (ALUNO*)malloc(3*sizeof(ALUNO)))) return 1;
    if(!((cadastro->nota) = (ALUNO*)malloc(3*sizeof(ALUNO)))) return 1;

    scanf("%f", cadastro->nota->n1);
    scanf("%f", cadastro->nota->n2);


    return 0;
}