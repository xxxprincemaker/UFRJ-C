#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char rua[50], bairro[50], cidade[50], estado[2], cep[9], numero[6], complemento[20];
}ENDERECO;

typedef struct{
    char nome[255], cpf[11], rg[10], sexo[1], telefone[13], salario[20], idade[3];
    ENDERECO endereco;
}CADASTRO;

void recebeDados(CADASTRO pessoa[], int x){
    short int i;
    for (i = 0; i < x; i++){
        printf("Candidato %d, digite os seguintes dados\n", i+1);
        printf("Nome:");
        scanf("%[^\n]%*c", pessoa[i].nome);
        printf("Idade:");
        scanf("%[^\n]%*c", pessoa[i].idade);
        printf("CPF:");
        scanf("%[^\n]%*c", pessoa[i].cpf);
        printf("RG:");
        scanf("%[^\n]%*c", pessoa[i].rg);
        printf("Sexo(1-Masc, 2-Fem, 3-Outr):");
        scanf("%[^\n]%*c", pessoa[i].sexo);
        printf("Salario:");
        scanf("%[^\n]%*c", pessoa[i].salario);
        printf("Telefone com DD:");
        scanf("%[^\n]%*c", pessoa[i].telefone);
        printf("\n**************************\n");
        printf("    Endereço    \n");
        printf("Rua:");
        scanf("%[^\n]%*c", pessoa[i].endereco.rua);
        printf("Numero:");
        scanf("%[^\n]%*c", pessoa[i].endereco.numero);
        printf("Complemento:");
        scanf("%[^\n]%*c", pessoa[i].endereco.complemento);
        printf("Cidade:");
        scanf("%[^\n]%*c", pessoa[i].endereco.cidade);
        printf("Estado:");
        scanf("%[^\n]%*c", pessoa[i].endereco.estado);
        printf("CEP:");
        scanf("%[^\n]%*c", pessoa[i].endereco.cep);
    }
}


void maiorIdade(CADASTRO pessoa[], int x){
    short int i;
    int maior[x], m, tam = sizeof(maior)/sizeof(int);
    maior[0] = atoi(pessoa[0].idade);
    for (i = 0; i < x; i++){
        if (atoi(pessoa[i].idade) > maior[i]){
            maior[i] = i;
        }
    }
    for (i = 0; i < tam; i++){
        printf("%s e a pessoa com maior idade.\n", pessoa[i].nome);
    }
}
void findMen(CADASTRO pessoa[], int x){
    short int i;
    
    for (i=0; i < x; i++){
        if (atoi(pessoa[i].sexo) == 1){
            printf("%s e homem!\n", pessoa[i].nome);
        }
    }
}
void maiorSalario(CADASTRO pessoa[], int x){
    short int i;
    for (i = 0; i < x; i++){
        if (atof(pessoa[i].salario) > 1000){
            printf("%s e uma das pessoas que possui o salario maior que R$1000.00\n", pessoa[i].nome);
        }
    }
}
int imprimirDados(CADASTRO pessoa[], int x){
    short int i, cont = 0;
    char rg[10];
    printf("Digite o RG que deseja encontrar:");
    fgets(rg, 10, stdin);
    for (i = 0; i < x; i++){
        if (strcmp(rg, pessoa[i].rg)==0){
            printf("O Registro geral %s, pertence a %s\n", rg, pessoa[i].nome);
            cont++;
        }
    }
    if (cont != 0){
        printf("Nao possivel encontrar o RG %s\n", rg);
    }
}

int main(void){

    int npessoas;
    printf("Digite a quantidade de pessoas que deseja cadastrar:");
    scanf("%d",&npessoas);
    setbuf(stdin, 0);

    CADASTRO pessoa[npessoas];
    recebeDados(pessoa, npessoas);
    maiorIdade(pessoa, npessoas);
    findMen(pessoa, npessoas);
    maiorSalario(pessoa, npessoas);
    imprimirDados(pessoa, npessoas);

}
