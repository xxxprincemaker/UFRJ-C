#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){

    char c;

    FILE *arquivo;
    if(!(arquivo = fopen("arquivo.txt","w"))){
        fprintf(stderr, "Erro ao abrir o arquivo.txt.");
        return 1;
    }else{
        int crt;
        for(crt = 33; crt <= 126; crt++) fputc(crt, arquivo);
        
        rewind(arquivo);
        c = fgetc(arquivo);
        while (!feof(arquivo)){
            putchar(c);
            c = fgetc(arquivo);
        }
    }

    fclose(arquivo);

    return 0;
}
