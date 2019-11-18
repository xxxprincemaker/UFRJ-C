#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 80

int main(void){

    char linha[MAX];
    int c;
    char *string = "texto.txt";

    FILE *arquivo;
    if(!(arquivo = fopen(string,"w"))){
        fprintf(stderr, "Erro ao abrir o arquivo.txt.");
        return 1;
    }

    //Escrita de Caracteres.
    c = 0;
    fgets(linha, MAX,stdin);
    while(c < 3){
        fputs(linha,arquivo);
        fgets(linha,MAX,stdin);
        c++;
    }
    rewind(arquivo);
    printf("Escreveu, agora ler.");
    fgets(linha,MAX,arquivo);
    while(!feof(arquivo)){
        puts(linha);
        fgets(linha,MAX,arquivo);
    }

    fclose(arquivo);

    return 0;
}
