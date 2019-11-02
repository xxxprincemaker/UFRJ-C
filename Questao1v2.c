#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char rua[50], bairro[50], cep[9];  
	char cidade[50], estado[3];
}ENDERECO;

typedef struct{
    char nome[255], rg[10], cpf[12];
	char telefone[13], sexo, est_civil;
	char idade[4];
	float salario; 
    ENDERECO endereco;
}CADASTRO;

void recebeDados(CADASTRO pessoa[], int quant);
void maiorIdade(CADASTRO pessoa[], int quant);
void findMen(CADASTRO pessoa[], int quant);
void maiorSalario(CADASTRO pessoa[], int quant);
int imprimirDados(CADASTRO pessoa[], int quant);
void mostraDados(CADASTRO pessoa);

int main(void){
    int npessoas;
	system("@cls||clear");
    do{
    	printf("Digite a quantidade de pessoas que deseja cadastrar: ");
    	scanf("%d", &npessoas);
    	
    	if(npessoas > 0 && npessoas <= 1000)
    		break;
    	
		printf("A quantidade de pessoas deve ser de 1 a 1000.\n\n");
	}while(1);
    
	CADASTRO pessoa[npessoas];
    
	recebeDados(pessoa, npessoas);
	printf("\n");
    maiorIdade(pessoa, npessoas);
    printf("\n");
	findMen(pessoa, npessoas);
    printf("\n");
	maiorSalario(pessoa, npessoas);
    printf("\n");
	imprimirDados(pessoa, npessoas);
	
	return 0;
}

void recebeDados(CADASTRO pessoa[], int quant){
    int i, j, flag;
    for (i = 0; i < quant; i++){
        printf("\nCandidato %d, digite os seguintes dados:\n\n", i+1);
        printf("Nome: ");
        scanf(" %[^\n]s", pessoa[i].nome);
        
		do{
			printf("Idade: ");
        	scanf(" %[^\n]s", pessoa[i].idade);
			/* for(j=0; pessoa[i].idade[j]!='\0'; j++){
				if(pessoa[i].idade[j]<'0' || pessoa[i].idade[j]>'9')){
					break;
				}
			}*/
			quant= atoi(pessoa[i].idade);
			strcpy(pessoa[i].idade, itoa(quant));
		}while(pessoa[i].idade[0]=='\0' || strlen(pessoa[i].idade)>3);
        
		do{
			printf("CPF (11 dígitos): ");
			scanf(" %[^\n]s", pessoa[i].cpf);
		}while(strlen(pessoa[i].cpf)!=11);
        
		do{
			printf("RG (9 dígitos): ");
        	scanf(" %[^\n]s", pessoa[i].rg);
		}while(strlen(pessoa[i].rg)!=9);
        
		do{
			printf("Sexo (1-Masculino, 2-Feminino, 3-Outros): ");
	        scanf(" %c", &pessoa[i].sexo);
		}while(pessoa[i].sexo<'1' || pessoa[i].sexo>'3');
        
        do{
	        printf("Estado Civil (1-Solteiro(a), 2-Casado(a), 3-Separado(a), 4-Divorciado(a), 5-Viuvo(a)): ");
	        scanf(" %c", &pessoa[i].est_civil);
		}while(pessoa[i].est_civil<'1' || pessoa[i].est_civil>'5');
        
		do{
			printf("Salário: ");
	        scanf("%f", &pessoa[i].salario);
		}while(pessoa[i].salario<0);
        
		printf("Telefone com DDD: ");
        scanf(" %[^\n]s", pessoa[i].telefone);
        
        printf("\n**************************\n");
        printf("    ENDEREÇO    \n");
        printf("\nRua: ");
        scanf(" %[^\n]s", pessoa[i].endereco.rua);
        
        printf("Bairro: ");
        scanf(" %[^\n]s", pessoa[i].endereco.bairro);
        
		printf("Cidade: ");
        scanf(" %[^\n]s", pessoa[i].endereco.cidade);
        
		do{
			printf("Estado (2 dígitos): ");
        	scanf(" %[^\n]s", pessoa[i].endereco.estado);
		}while(strlen(pessoa[i].endereco.estado)!=2);
        
		do{
			printf("CEP (8 dígitos): ");
        	scanf(" %[^\n]s", pessoa[i].endereco.cep);
        }while(strlen(pessoa[i].endereco.cep)!=8);
		
		printf("\n--------------------------------------------------------\n");
    }
}

void maiorIdade(CADASTRO pessoa[], int quant){
    int i;
    int maior, m=0;
   	maior = pessoa[0].idade;
   	
    for (i=1; i < quant; i++){
        if (maior < pessoa[i].idade){
            maior = pessoa[i].idade;
        	m = i;
		}
    }
    
	printf("%s é a pessoa com maior idade.\n", pessoa[m].nome);
}

void findMen(CADASTRO pessoa[], int quant){
    int i, flag=0;
    for (i=0; i<quant; i++){
        if (pessoa[i].sexo == '1'){
			printf("%s é homem!\n", pessoa[i].nome);
        	flag = 1;
		}
    }
    
    if(flag==0)
    	printf("Não há homens!\n");
}

void maiorSalario(CADASTRO pessoa[], int quant){
    int i, flag=0;
    for (i = 0; i < quant; i++){
       if (pessoa[i].salario > 1000){
            printf("%s possui salário maior que R$1000.00\n", pessoa[i].nome);
        	flag = 1;
		}
    }
    
    if(flag==0)
    	printf("Não há pessoas com salário maior que R$1000.00\n");
}

int imprimirDados(CADASTRO pessoa[], int quant){
    int i;
    char rg[10];
	while(1){
		printf("Digite o RG que deseja encontrar: ");
    	scanf(" %[^\n]s", rg);
    
		for(i=0; i<quant; i++){
        	if(strcmp(rg, pessoa[i].rg)==0){
        	    printf("\nDados da pessoa com o Registro Geral desejado:\n");
         		mostraDados(pessoa[i]);   
            	return 1;
        	}
    	}
    
		printf("Não foi possível encontrar o RG %s.\n\n", rg);
	}
    
    return 0;
}

void mostraDados(CADASTRO pessoa){
	printf("Nome: %s\n", pessoa.nome);
	printf("Idade: %d\n", pessoa.idade);
	printf("CPF: %s\n", pessoa.cpf);
	printf("RG: %s\n", pessoa.rg);
	
	printf("Sexo: ");
	switch(pessoa.sexo){
		case '1':
			printf("Masculino\n");
			break;
		case '2':
			printf("Feminino\n");
			break;
		default:
			printf("Outros\n");
	}
    
	printf("Estado Civil: ");
	switch(pessoa.est_civil){
		case '1':
			printf("Solteiro(a)\n");
			break;
		case '2':
			printf("Casado(a)\n");
			break;
		case '3':
			printf("Separado(a)\n");
			break;
		case '4':
			printf("Divorciado(a)\n");
			break;
		default:
			printf("Viúvo(a)\n");
	}
	
	printf("Salário: %.2f\n", pessoa.salario);
	printf("Telefone com DDD: %s\n", pessoa.telefone);
    
    
    printf("\n**************************\n");
    printf("ENDEREÇO");
	printf("\n**************************\n\n");

    printf("Rua: %s\n", pessoa.endereco.rua);
    printf("Bairro: %s\n", pessoa.endereco.bairro);
	printf("Cidade: %s\n", pessoa.endereco.cidade);
	printf("Estado: %s\n", pessoa.endereco.estado);
	printf("CEP: %s\n", pessoa.endereco.cep);
}