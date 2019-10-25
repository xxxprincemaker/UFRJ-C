#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Funcao Limpa a tela.
void clrscr(){
    system("@cls||clear");
}

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
void menu(PESSOA agenda[], int *tam, int max);
void InserirPessoa(PESSOA agenda[], int *tam, int max);
void recebeDADOS(PESSOA agenda[], int x);
void retiraPessoa(PESSOA agenda[], int *tam);
void imprimeDados(PESSOA agenda[], int numPessoa);
void mostraDados(PESSOA pessoa);
void buscaPorMes(PESSOA agenda[],int *tam);
int encontraNome(PESSOA agenda[], int *x);
void ordenaDados(PESSOA agenda[], int *tam);




int main(){
	int npessoas, tam=0;
	
	while (1){
		printf("Digite a quantidade de pessoas:");
		scanf("%d", &npessoas);
		if (npessoas > 0 && npessoas <= 1000){
			break;
		}
	}

	PESSOA agenda[npessoas];

	clrscr();
    menu(agenda, &tam, npessoas);
    
	return 0;
}

void menu(PESSOA agenda[], int *tam, int max){
	char opcao;

	do{
		printf("\n1 - Inserir pessoa\n");	
		printf("2 - Deletar pessoa\n");
		printf("3 - Imprimir agenda\n");
		printf("4 - Buscar Aniversariantes\n");
		printf("5 - Buscar Pessoa\n");
		printf("6 - Sair\n\n");

		while(1){
			printf("Escolha uma opção: ");
			scanf(" %c", &opcao);
			
			if(opcao>='1' && opcao<='6')
				break;
			
			clrscr();
			printf("A opção não é válida!\n\n");	
		}

		switch(opcao){
			case '1':
				clrscr();
				InserirPessoa(agenda, tam, max);
				break;

			case '2':
				clrscr();
				retiraPessoa(agenda, tam);
				break;

			case '3':
				clrscr();
				imprimeDados(agenda, *tam);
				break;
			case '4':
				clrscr();
				buscaPorMes(agenda, tam);
				break;

			case '5':
				clrscr();
				encontraNome(agenda, tam);
				break;

			default:
				return;
		}
		printf("\n\n\n-------------------------------------------------------\n\n");
	}while(1);
}


void InserirPessoa(PESSOA agenda[], int *tam, int max){
	int quant, falta = max-*tam;

	while(1){
		printf("Entre com a quantidade de pessoas que deseja inserir: ");
		scanf("%d", &quant);
		
		if(quant>0 && quant<=falta)
			break;

		printf("A quantidade deve ser de 1 a %d.\n\n", falta);
	}

	recebeDADOS(agenda, quant);
	*tam += quant;
	ordenaDados(agenda, tam);
}



void recebeDADOS(PESSOA agenda[], int quant){
	int i;
	for (i = 0; i < quant; i++){
		printf("\nCONTATO %d\n", i+1);
		printf("Nome:");
		scanf(" %[^\n]s", agenda[i].nome);
		printf("E-mail:");
		scanf(" %[^\n]s", agenda[i].email);
		printf("Data de aniversario(DD MM AA):");
		//Por algum motivo estava aparecendo erros se eu coloca-se sem &.
		scanf("%d %d %d", &(agenda[i].data.dia), &(agenda[i].data.mes), &(agenda[i].data.ano));
		printf("*Telefone*\n");
		printf("DD:");
		scanf(" %[^\n]s", agenda[i].tel.ddd);
		printf("Numero:");
		scanf(" %[^\n]s", agenda[i].tel.numero);
		printf("\n*******ENDERECO*******\n");
		printf("Rua:");
		scanf(" %[^\n]s", agenda[i].endereco.rua);
		printf("Numero:");
		scanf("%d", &(agenda[i].endereco.numero));
		printf("Complemento:");
		scanf(" %[^\n]s", agenda[i].endereco.comple);
		printf("Bairro:");
		scanf(" %[^\n]s", agenda[i].endereco.bairro);
		printf("CEP:");
		scanf(" %[^\n]s", agenda[i].endereco.cep);
		printf("Cidade:");
		scanf(" %[^\n]s", agenda[i].endereco.cidade);
		printf("Estado:");
		scanf(" %[^\n]s", agenda[i].endereco.estado);
		printf("Pais:");
		scanf(" %[^\n]s", agenda[i].endereco.pais);
		printf("Observacoes:");
		scanf(" %[^\n]s", agenda[i].obs);
	}
}


void retiraPessoa(PESSOA agenda[], int *tam){
    
    int i, b = 0;
    char nomeRemover[255];

	if(*tam==0){
		printf("Não tem pessoas a serem excluídas!\n");
		return; 
	}
    
    printf("Entre com nome da pessoa para remover da Agenda: ");
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
	ordenaDados(agenda, tam);
}


void imprimeDados(PESSOA agenda[], int quant){
    int i = 0;
	if (quant != 0){
		for(i=0; i<quant; i++){
			printf("\nCONTATO %d\n\n", i+1);
			mostraDados(agenda[i]);
		}
	}else{
		printf("Digite algum contato, para exibir.\n");
	}
}

void mostraDados(PESSOA pessoa){
	printf("Nome: %s\n", pessoa.nome);
    printf("Data de aniversario: %d/%d/%d.\n", pessoa.data.dia, pessoa.data.mes, pessoa.data.ano);
    printf("Telefone: %s %s\n", pessoa.tel.ddd, pessoa.tel.numero);
    printf("E-mail: %s\n", pessoa.email);
    
    printf("\nENDERECO: \n\n");
    
    printf("Rua: %s\n", pessoa.endereco.rua);
    printf("Numero: %d\n", pessoa.endereco.numero);
    printf("Complemento: %s\n", pessoa.endereco.comple);
    printf("Bairro: %s\n", pessoa.endereco.bairro);
    printf("Cidade: %s\n", pessoa.endereco.cidade);
    printf("Estado: %s\n", pessoa.endereco.estado);
    printf("Pais: %s\n\n", pessoa.endereco.pais);
    printf("CEP: %s\n", pessoa.endereco.cep);
    
    printf("Observacoes: %s\n\n", pessoa.obs);
}

void buscaPorMes(PESSOA agenda[], int *tam){
	//Esta Funcao ira encontrar todas as pessoas que fazem aniversario no mesmo mes e dia.
	if (*tam != 0){
		int i, mesAniver, diaAniver;
		printf("Digite o dia que deseja analisar(dois digitos):");
		scanf("%d", &diaAniver);
		printf("Digite os dados do mes que deseja analisar(dois digitos):");
		scanf("%d", &mesAniver);
		for(i = 0; i < *tam; i++){
			if(agenda[i].data.mes == mesAniver && agenda[i].data.dia == diaAniver){
				imprimeDados(agenda, i);
			}
		}
	}
	else{
		printf("Por favor, preencha a agenda antes de buscar por uma pessoa.\n");
		return;
	}
}

int encontraNome(PESSOA agenda[], int *x){
	//Vou utilizar vetor pois quero percorrer a palavra.
	char nome[255];
	int i, j, aux;
	if (*x != 0){
		printf("Digite o primeiro da pessoa que deseja encontrar:");
		scanf(" %[^\n]s", nome);
		for (i = 0; i < *x; i++){
			j = 0;
			aux = 0;
			// Um laco que vai comparando letra a letra, e nao pega o espaco, ele acaba em funcao do primeiro nome.
			while (agenda[i].nome[j] == nome[j] && agenda[i].nome[j] != ' '){
				aux++;//Conta para ver quantas letras tem em comum, fazendo letra a letra
				if (j <= strlen(nome)){
					if (aux == strlen(nome)){
						//Vou colocar a funcao do felipe aqui.
						imprimeDados(agenda, i);
						return 0;
					}
				}else{
					break;
				}
				j++;
			}
		}
		printf("O nome digitado nao existe na agenda!\n");
		return 0;
	}else{
		printf("Por favor, preencha a agenda antes de buscar por uma pessoa.\n");
		return 0;
	}
	
}

void ordenaDados(PESSOA agenda[], int *tam){
	int i, j;
	PESSOA aux[*tam];

	for (i = 1; i < *tam; i++){
		for (j = 0; j < *tam - 1; j++){
			if (strcmp(agenda[j].nome, agenda[j+1].nome) > 0){
				aux[0] = agenda[j];
				agenda[j] = agenda[j+1];
				agenda[j+1] = aux[0];
			}
		}
	}
}