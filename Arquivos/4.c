#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 80

int main(void){

    char palavra[20];
    int i; float f;

    FILE *arquivo;
    char *nome = "Formated.txt";

    if ((arquivo = fopen(nome, "w+"))==NULL){
        printf("\n\nNao foi possivel abrir o arquivo.\n");
        return 1;
    }
    
    puts("Entre com uma palavra.");
    scanf("%s", palavra);
    puts("Entre com um numero intero.");
    scanf("%d", &i);
    puts("Entre com um numero flutuante.");
    scanf("%f", &f);

    //Escrever Dados no arquivo
    fprintf(arquivo, "%s %d %f", palavra, i, f);
    rewind(arquivo);
    printf("Agora ira ler!");

    fscanf(arquivo, "%s %d %f", palavra, &i, &f);
    printf("Palavra Lida: %s\n", palavra);
    printf("inteiro Lido: %d\n", i);
    printf("float Lido: %0.2f\n", f);

    fclose(arquivo);

    return 0;
}