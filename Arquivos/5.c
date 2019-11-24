#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){

    char *nome;
    int i, qt, j;
    float *nota1, *nota2, *media;

    FILE *arquivo;

    //Ira perguntar qual a quantidade que sera utilizada
    printf("Digite a quantidade de alunos:");
    scanf("%d", &qt);

    //Define os ponteiros que irao ser usados.
    if(!(nome = (char *)calloc(qt,sizeof(char)))) return 1;
    if(!(nota1 = (float  *)calloc(qt,sizeof(float)))) return 1;
    if(!(nota2 = (float  *)calloc(qt,sizeof(float)))) return 1;
    if(!(media = (float  *)calloc(qt,sizeof(float)))) return 1;

    if((arquivo = fopen("arq1","w")) == NULL){
        printf("Nao foi possivel abrir o arquivo!");
        return 1;
    }
    
    j = 0;
    for(i = 0; i < qt; i++){
        printf("Digite o nome do aluno %d:", i+1);
        scanf(" %[^\n]s", (nome+i));
    
        printf("Nota 1 do aluno %d:", i+1);
        scanf("%f", (nota1+i));
        printf("Nota 2 do aluno %d:", i+1);
        scanf("%f", (nota2+i));

        fprintf(arquivo, "%s\n", (nome+i));
        fprintf(arquivo, "%0.2f\n", *(nota1+i));
        fprintf(arquivo, "%0.2f\n", *(nota2+i));

        j++;
    }

    //Libera os dados da memoria
    free(nome);free(nota1);free(nota2);free(media);
    //Agora ira ler os arquivos
    rewind(arquivo);
    fclose(arquivo);

    return 0;
}