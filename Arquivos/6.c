#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){

    char nome[50];
    int i, qt;
    float nota1, nota2, media;
    FILE *arquivo;


    if((arquivo = fopen("arq1","r")) == NULL){
        printf("Nao foi possivel abrir o arquivo!");
        return 1;
    }

    i = 0;

    while(!feof(arquivo)){

        
        fscanf(arquivo, "%f", (nota1));
        fscanf(arquivo, "%f", (nota2));
        (media) = nota1 + nota2;
        if (media >= 7){
            printf("O Aluno %s esta na media", (nome));
        }
        i++;
    }

}