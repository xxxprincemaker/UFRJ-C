/* 10.2: Considerando a mesma estrutura do exercício anterior, escreva um pro-
grama que leia os dados de 100 clientes e imprima:
• quantos clientes têm renda mensal acima da média;
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct DATA{
    int dia, mes, ano;
}DATA ;

typedef struct _EMPREGADO{
    char nome[50];
    float renda, media;
    char carro;
    DATA birth;

}EMPREGADO ;

void pega_dados(EMPREGADO *colaborador, int funcionarios){
    int i;
    char linha[40];
    for (i = 0; i < funcionarios; i++){
        printf("Nome:");
        fgets((colaborador+i)->nome, 39,stdin);
        printf("Salario:");
        fgets(linha,39,stdin);
        sscanf(linha, "%f", &((colaborador+i)->renda));
    }
}

float media (EMPREGADO *colaborador, int funcionario, int *acima){
    float media = 0.0;
    int i;
    float aux;

    for (i = 0; i < funcionario; i++){
        media += (colaborador+i)->renda;
    }
    media = media / funcionario;
    for (i = 0; i < funcionario; i++){

        aux = ((colaborador+i)->renda);

        if (aux > media){
            *(acima) + 1;
        }
    }
    return media;
}   

int main(void){

    int i, funcionario, acima = 0;
    char linha[40];

    EMPREGADO *colaborador;

    printf("Digite o numero de funcionario:");
    fgets(linha,39,stdin);
    sscanf(linha, "%d", &funcionario);
    if (!(colaborador = (EMPREGADO*)malloc(funcionario*sizeof(EMPREGADO)))){
        exit(1);
    }

    //Armazena os dados
    pega_dados(colaborador, funcionario);
    //Imprime os dados.
    printf("Salario Medio: %.2f\n", media(colaborador, funcionario, &acima));
    printf("Quantidade de colaboradores com salario acima da media: %d\n", acima);

    return 0;
}