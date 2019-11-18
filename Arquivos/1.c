#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Cursor que ira percorrer cada letra do arquivo.
int main(){

    int c;
    //Arquivo d a ser lido.
    FILE *arquivo;
    //Abre Arquivo do diretorio escolhido.
    arquivo = fopen("arquivo.txt", "r");
    //checar se foi encontrado
    if (arquivo){
        while ((c = getc(arquivo)) != EOF){

        }
        //Fecha arquivo.
        fclose(arquivo);
    }

    return 0;
}