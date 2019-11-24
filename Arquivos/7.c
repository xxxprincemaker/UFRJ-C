#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _ALUNO{
    char nome[50];
    float nota1, nota2;
} ALUNO;

int main(void){
    int i;
    FILE *arquivo;
    ALUNO *cadastro;
    if(!(cadastro = (ALUNO*)malloc(3*sizeof(ALUNO)))) return 1;

    for(i = 0; i < 3; i++){
        printf("Nome:");
        scanf(" %[^\n]s", &((cadastro+i)->nome));
        printf("Nota 1:");
        scanf("%f", &((cadastro+i)->nota1));
        printf("Nota 2:");
        scanf("%f", &((cadastro+i)->nota2));
    }
    for (i = 0; i < 3; i++){
        printf("Nome: %s\n", ((cadastro+i)->nome));
        printf("Nota 1: %f\n", ((cadastro+i)->nota1));
        printf("Nota 1: %f\n", ((cadastro+i)->nota1));
    }
    
    return 0;
}