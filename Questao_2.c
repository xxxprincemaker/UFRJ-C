#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ENDERECO{
	char rua[100], comple[30], bairro[50], cep[10];
	char cidade[50], estado[3], pais[50];
	int numero;  
} END;

typedef struct TELEFONE{ 
	char ddd[3], numero[10];
} TEL;

typedef struct DATA_ANIVERSARIO{
	int dia, mes, ano; 
} DATA;

typedef struct{
	char nome[255], email[50], obs[500];
	END endereco;
	TEL tel;
	DATA data;
}PESSOA;


/*Prototipos de Funcao*/
void clrscr();
void menu(PESSOA agenda[], int max);
void InserePessoa(PESSOA agenda[], int *tam, int max);
void RecebeDADOS(PESSOA agenda[], int x);
void RetiraPessoa(PESSOA agenda[], int *tam);
void EncontraNome(PESSOA agenda[], int x);
void BuscaPorMes(PESSOA agenda[],int tam);
void ImprimeDados(PESSOA agenda[], int numPessoa);
void MostraDados(PESSOA pessoa);
void OrdenaDados(PESSOA agenda[], int tam);



int main(){
	int npessoas;
	
	clrscr();
	while(1){
		printf("Digite a quantidade de pessoas: ");
		scanf("%d", &npessoas);
		
		if(npessoas > 0 && npessoas <= 100)
			break;

		printf("A quantidade deve ser de 1 a 100.\n\n");
	}

	PESSOA agenda[npessoas];

	clrscr();
    menu(agenda, npessoas);

    printf("O sistema se encerrou.\n");
    printf("Agradecemos a preferência! :)\n\n");
	return 0;
}


//Funcao Limpa a tela.
void clrscr(){
    system("@cls||clear");
}


void menu(PESSOA agenda[], int max){
	int tam = 0;
	char opcao;

	do{
		printf("\n1 - Inserir Pessoa\n");	
		printf("2 - Deletar Pessoa\n");
		printf("3 - Buscar Pessoa\n");
		printf("4 - Buscar Aniversariantes\n");
		printf("5 - Imprimir Agenda\n");
		printf("6 - Sair\n\n");

		while(1){
			printf("Escolha uma opção: ");
			scanf(" %c", &opcao);
			
			if(opcao>='1' && opcao<='6')
				break;
			
			printf("A opção não é válida!\n\n");	
		}

		clrscr();
		switch(opcao){
			case '1':
				InserePessoa(agenda, &tam, max);
				break;

			case '2':
				RetiraPessoa(agenda, &tam);
				break;

			case '3':
				EncontraNome(agenda, tam);
				break;

			case '4':
				BuscaPorMes(agenda, tam);
				break;
			
			case '5':
				ImprimeDados(agenda, tam);
				break;

			default:
				return;
		}

		printf("\n\n\n-------------------------------------------------------\n\n");
	}while(1);
}


void InserePessoa(PESSOA agenda[], int *tam, int max){
	int quant, falta = max-*tam;

	while(1){
		printf("Entre com a quantidade de pessoas que deseja inserir: ");
		scanf("%d", &quant);
		
		if(quant>0 && quant<=falta)
			break;
		
		if(falta==1){
			printf("Só mais uma pessoa pode ser adicionada.\n\n");	
			continue;
		}
		printf("A quantidade deve ser de 1 a %d.\n\n", falta);
	}

	clrscr();
	RecebeDADOS(agenda, quant);
	*tam += quant;
	OrdenaDados(agenda, *tam);
}


void RecebeDADOS(PESSOA agenda[], int quant){
	int i;
	for(i=0; i<quant; i++){
		printf("\nCONTATO %d\n", i+1);
		printf("Nome: ");
		scanf(" %[^\n]s", agenda[i].nome);
		
		printf("E-mail: ");
		scanf(" %[^\n]s", agenda[i].email);
		
		printf("Data de aniversário(DD MM AA): ");
		scanf("%d %d %d", &(agenda[i].data.dia), &(agenda[i].data.mes), &(agenda[i].data.ano));
		
		printf("\n*Telefone*\n");
		printf("DD: ");
		scanf(" %[^\n]s", agenda[i].tel.ddd);
		
		printf("Número: ");
		scanf(" %[^\n]s", agenda[i].tel.numero);
		
		printf("\n*******ENDEREÇO*******\n");
		printf("Rua: ");
		scanf(" %[^\n]s", agenda[i].endereco.rua);
		
		printf("Número: ");
		scanf("%d", &(agenda[i].endereco.numero));
		
		printf("Complemento: ");
		scanf(" %[^\n]s", agenda[i].endereco.comple);
		
		printf("Bairro: ");
		scanf(" %[^\n]s", agenda[i].endereco.bairro);
		
		printf("CEP: ");
		scanf(" %[^\n]s", agenda[i].endereco.cep);
		
		printf("Cidade: ");
		scanf(" %[^\n]s", agenda[i].endereco.cidade);
		
		printf("Estado: ");
		scanf(" %[^\n]s", agenda[i].endereco.estado);
		
		printf("País: ");
		scanf(" %[^\n]s ", agenda[i].endereco.pais);	

		printf("Observações: ");
		scanf(" %[^\n]s", agenda[i].obs);

		if(i != quant-1)
			printf("\n\n-------------------------------------------------------\n");
	}
}


void RetiraPessoa(PESSOA agenda[], int *tam){
    
    int i, b = 0;
    char nomeRemover[255];

	if(*tam==0){
		printf("Não há pessoas a serem excluídas!\n");
		return; 
	}
    
    printf("Entre com nome da pessoa que deseja remover da Agenda: ");
    scanf(" %[^\n]s", nomeRemover);
    
    for(i = 0; i < *tam - 1; i++){
        if(strcmp(agenda[i].nome, nomeRemover)==0 || b == 1){
            agenda[i] = agenda[i + 1];
            b = 1;
        }
    }
	PESSOA temp = {};
    agenda[*tam - 1] = temp;
	(*tam)--;
	OrdenaDados(agenda, *tam);
}


void EncontraNome(PESSOA agenda[], int tam){
	int i, quant;
	char nome[255];
	
	if(tam==0){
		printf("Por favor, preencha a agenda antes de buscar por uma pessoa.\n");
		return;
	}

	printf("Digite o primeiro nome da pessoa que deseja encontrar: ");
	scanf(" %s", nome);
	quant = strlen(nome);
	
	for(i=0; i<tam; i++){
		if(strncmp(nome, agenda[i].nome, quant)==0){
			printf("\n");
			MostraDados(agenda[i]);
			return;
		}
	}

	printf("O nome digitado não existe na agenda!\n");
}


void BuscaPorMes(PESSOA agenda[], int tam){
	//Esta Funcao ira encontrar todas as pessoas que fazem aniversario no mesmo mes e dia.
	if (tam != 0){
		int i, mesAniver, diaAniver;
		printf("Digite o dia que deseja analisar(dois dígitos): ");
		scanf("%d", &diaAniver);
		printf("Digite os dados do mês que deseja analisar(dois dígitos): ");
		scanf("%d", &mesAniver);
		for(i = 0; i < tam; i++){
			if(agenda[i].data.mes == mesAniver && agenda[i].data.dia == diaAniver){
				ImprimeDados(agenda, i);
			}
		}
	}
	else{
		printf("Por favor, preencha a agenda antes de buscar por uma pessoa.\n");
		return;
	}
}


void ImprimeDados(PESSOA agenda[], int quant){
    int i = 0;
	if(quant != 0){
		for(i=0; i<quant; i++){
			printf("\nCONTATO %d\n\n", i+1);
			MostraDados(agenda[i]);
		}
	}else{
		printf("Digite algum contato, para exibir.\n");
	}
}


void MostraDados(PESSOA pessoa){
	printf("Nome: %s\n", pessoa.nome);
    printf("Data de aniversário: %d/%d/%d.\n", pessoa.data.dia, pessoa.data.mes, pessoa.data.ano);
    printf("Telefone: %s %s\n", pessoa.tel.ddd, pessoa.tel.numero);
    printf("E-mail: %s\n", pessoa.email);
    
    printf("\nENDEREÇO: \n\n");
    
    printf("Rua: %s\n", pessoa.endereco.rua);
    printf("Número: %d\n", pessoa.endereco.numero);
    printf("Complemento: %s\n", pessoa.endereco.comple);
    printf("Bairro: %s\n", pessoa.endereco.bairro);
    printf("Cidade: %s\n", pessoa.endereco.cidade);
    printf("Estado: %s\n", pessoa.endereco.estado);
    printf("País: %s\n\n", pessoa.endereco.pais);
    printf("CEP: %s\n", pessoa.endereco.cep);
    
    printf("Observações: %s\n\n", pessoa.obs);
}


void OrdenaDados(PESSOA agenda[], int tam){
	int i, j;
	PESSOA aux[tam];

	for(i = 1; i < tam; i++){
		for(j = 0; j < tam - 1; j++){
			if(strcmp(agenda[j].nome, agenda[j+1].nome) > 0){
				aux[0] = agenda[j];
				agenda[j] = agenda[j+1];
				agenda[j+1] = aux[0];
			}
		}
	}
}