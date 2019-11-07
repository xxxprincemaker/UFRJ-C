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
int RecebeDADOS(PESSOA agenda[], int x, int tam);
void RetiraPessoa(PESSOA agenda[], int *tam);
void EncontraNome(PESSOA agenda[], int x);
void BuscaPorData(PESSOA agenda[], int tam);
void BuscaPorMes(int mesAniver, PESSOA agenda[], int tam);
void BuscaPorDia(int dia, int mes, PESSOA agenda[], int tam);
void ImprimeDados(PESSOA agenda[], int numPessoa);
void MostraDados(PESSOA pessoa, int opcao);
void OrdenaDados(PESSOA agenda[], int tam);

int data[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


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

	PESSOA agenda[npessoas+1];

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
				BuscaPorData(agenda, tam);
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

	if(falta==0){
		printf("A agenda está lotada!\n");
		return;
	}


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
	RecebeDADOS(agenda, quant, *tam);
	*tam += quant;
	OrdenaDados(agenda, *tam);
}


int RecebeDADOS(PESSOA agenda[], int quant, int tam){

	int i, j, dia, mes, ano, contador;
    char *d,*m,*a;

    if (!(d = (char*)malloc(2*sizeof(char)))) return 1;
    if (!(m = (char*)malloc(2*sizeof(char)))) return 1;
    if (!(a = (char*)malloc(4*sizeof(char)))) return 1;

	for(i=0; i<quant; i++){
		printf("\n\nCONTATO %d\n\n", tam+i+1);
		printf("Nome: ");
		scanf(" %[^\n]s", agenda[tam+i].nome);
		
		printf("E-mail: ");
		scanf(" %[^\n]s", agenda[tam+i].email);
		
		while(1){
			printf("-Data de aniversário(DD MM AA)-\n");
			//scanf("%d %d %d", &dia, &mes, &ano);

            printf("Dia:");
            scanf(" %[^\n]s", d);
            printf("Mes:");
            scanf(" %[^\n]s", m);
            printf("Ano:");
            scanf(" %[^\n]s", a);

            contador = 0;
            for (j = 0; j < 2; j++){
                if (isdigit(*(d+j)) == 0){
                    contador++;
                }
            }
            if (contador == 0) dia = atoi(d);
            else continue;

            contador = 0;
            for (j = 0; j < 2; j++){
                if (isdigit(*(m+j)) == 0){
                    contador++;
                }
            } 
            if (contador == 0) mes = atoi(m);
            else continue;

            contador = 0;
            for (j = 0; j < 4; j++){
                if (isdigit(*(a+j)) == 0){
                    contador++;
                }
            } 
            if (contador == 0) ano = atoi(a);
            else continue;

			if(dia>0 && mes>0 && mes<13 && ano>=0){
				if(mes!=2 && dia<=data[mes])
					break;
				if(mes==2){
					if(ano%4 && dia<=data[mes])
						break;
					if(ano%4==0 && dia<=29)
						break;
				}
			}
			printf("Data Inválida!\n\n");
		}

		agenda[tam+i].data.dia = dia;
		agenda[tam+i].data.mes = mes;
		agenda[tam+i].data.ano = ano;

		printf("\n*Telefone*\n");
		do{
			printf("DDD (2 dígitos): ");
			scanf(" %[^\n]s", agenda[tam+i].tel.ddd);
		}while(strlen(agenda[tam+i].tel.ddd)!=2);
		
		do{
			printf("Número (8/9 dígitos): ");
			scanf(" %[^\n]s", agenda[tam+i].tel.numero);
		}while(strlen(agenda[tam+i].tel.numero)<8 || strlen(agenda[tam+i].tel.numero)>9);
		
		printf("\n*******ENDEREÇO*******\n");
		printf("Rua: ");
		scanf(" %[^\n]s", agenda[tam+i].endereco.rua);
		
		printf("Número: ");
		scanf("%d", &(agenda[tam+i].endereco.numero));
		
		printf("Complemento: ");
		scanf(" %[^\n]s", agenda[tam+i].endereco.comple);
		
		printf("Bairro: ");
		scanf(" %[^\n]s", agenda[tam+i].endereco.bairro);
		
		do{
			printf("CEP (8 dígitos): ");
			scanf(" %[^\n]s", agenda[tam+i].endereco.cep);
		}while(strlen(agenda[tam+i].endereco.cep)!=8);
		
		printf("Cidade: ");
		scanf(" %[^\n]s", agenda[tam+i].endereco.cidade);
		
		do{
			printf("Estado (2 dígitos): ");
			scanf(" %[^\n]s", agenda[tam+i].endereco.estado);
		}while(strlen(agenda[tam+i].endereco.estado)!=2);
		
		printf("País: ");
		scanf(" %[^\n]s ", agenda[tam+i].endereco.pais);	

		printf("Observações: ");
		scanf(" %[^\n]s", agenda[tam+i].obs);

		if(i != quant-1)
			printf("\n\n-------------------------------------------------------\n");
	}
    return 0;
}



void RetiraPessoa(PESSOA agenda[], int *tam){
    
    int i, b = 0, flag=0;
    char nomeRemover[255];

	if(*tam==0){
		printf("Não há pessoas a serem excluídas!\n");
		return; 
	}
    
    printf("Entre com nome da pessoa que deseja remover da Agenda: ");
    scanf(" %[^\n]s", nomeRemover);
    
    for(i = 0; i < *tam; i++){
        if(strcmp(agenda[i].nome, nomeRemover)==0 || b == 1){
            flag = 1;
            agenda[i] = agenda[i + 1];
            b = 1;
        }
    }
    if(flag == 0){
    	printf("O nome informado não existe na Agenda!\n");
    	return;
    }

	PESSOA temp = {};
    agenda[*tam - 1] = temp;
	(*tam)--;
	OrdenaDados(agenda, *tam);
}


void EncontraNome(PESSOA agenda[], int tam){
	int i, quant, flag = 0;
	char nome[255];
	
	if(tam==0){
		printf("Por favor, preencha a agenda antes de buscar por uma pessoa.\n");
		return;
	}

	printf("Digite o primeiro nome das pessoas que deseja encontrar: ");
	scanf(" %s", nome);
	quant = strlen(nome);
	
	for(i=0; i<tam; i++){
		if(strncmp(nome, agenda[i].nome, quant)==0){
			if(flag==1)
				printf("\n\n-------------------------------------------------------\n");
			printf("\nCONTATO %d\n\n", i+1);
			MostraDados(agenda[i], '2');
		
			flag = 1;
		}		
	}

	if(flag==0)
		printf("O nome digitado não existe na agenda!\n");
}


void BuscaPorData(PESSOA agenda[], int tam){
	if(tam == 0){
		printf("Por favor, preencha a agenda antes de buscar por uma pessoa.\n");
		return;
	}

	int i, opcao, mesAniver, diaAniver;
	
	printf("\n1 - Aniversariantes do mês;\n");
	printf("2 - Aniversariantes do dia.\n");

	while(1){
		printf("\nEntre com a opção que deseja consultar: ");
		scanf("%d", &opcao);
		if(opcao==1 || opcao==2)
			break;
		printf("Opção inválida!\n");
	}
	printf("\n");

	while(1){
		if(opcao == 2){
			printf("Digite o dia que deseja analisar(dois dígitos): ");
			scanf("%d", &diaAniver);
		}
		printf("Digite os dados do mês que deseja analisar(dois dígitos): ");
		scanf("%d", &mesAniver);

		if(mesAniver>0 && mesAniver<13){
			if(opcao==1)
				break;
		}
		else{
			printf("Data inválida!\n\n");
			continue;
		}

		if(diaAniver>0 && 
				((mesAniver!=2 && diaAniver<=data[mesAniver]) || (mesAniver==2 && diaAniver<=29))){
			break;
		}
		printf("Data inválida!\n\n");
	}

	clrscr();

	if(opcao == 1)
		BuscaPorMes(mesAniver, agenda, tam);
	else
		BuscaPorDia(diaAniver, mesAniver, agenda, tam);
}


void BuscaPorMes(int mes, PESSOA agenda[], int tam){
	int i=0, flag=0;
	printf("\tANIVERSARIANTES DO MÊS %d:\n", mes);

	for(i = 0; i < tam; i++){
		if(agenda[i].data.mes == mes){
			if(flag==1)
				printf("\n\n-------------------------------------------------------\n");
			printf("\n\nCONTATO %d\n\n", i+1);
			MostraDados(agenda[i], 2);
			
			flag=1;
		}
	}
	if(flag==0)
		printf("\nNinguém faz aniversário no mês %d.", mes);
}


void BuscaPorDia(int dia, int mes, PESSOA agenda[], int tam){
	int i=0, flag=0;
	printf("\tANIVERSARIANTES DO DIA %d/%d:\n", dia, mes);

	for(i = 0; i < tam; i++){
		if(agenda[i].data.mes == mes && agenda[i].data.dia == dia){
			if(flag==1)
				printf("\n\n-------------------------------------------------------\n");

			printf("\n\nCONTATO %d\n\n", i+1);
			MostraDados(agenda[i], 2);
			
			flag = 1;
		}
	}

	if(flag==0)
		printf("\nNinguém faz aniversário no dia %d/%d.", dia, mes);

}

void ImprimeDados(PESSOA agenda[], int quant){
    int i = 0, opcao;

    if(quant == 0){
    	printf("Digite algum contato, para que posso ser exibido.\n");
    	return;
    }

    printf("\n1 - Imprime apenas nome, telefone e e-mail;\n");
	printf("2 - Imprime todos os dados.\n");

    while(1){
		printf("\nEscolha uma opção: ");
		scanf("%d", &opcao);

		if(opcao==1 || opcao==2)
			break;

		printf("Opção inválida!\n");

    }

    clrscr();

    printf("\tAGENDA");
	
	for(i=0; i<quant; i++){
		printf("\n\nCONTATO %d\n\n", i+1);
		MostraDados(agenda[i], opcao);
		if(i!=quant-1)
			printf("\n\n-------------------------------------------------------\n");
	}
}


void MostraDados(PESSOA pessoa, int opcao){
	printf("Nome: %s\n", pessoa.nome);
    printf("Telefone: %s %s\n", pessoa.tel.ddd, pessoa.tel.numero);
    printf("E-mail: %s\n", pessoa.email);
    if(opcao==1)
    	return;

    printf("Data de aniversário: %d/%d/%d.\n", pessoa.data.dia, pessoa.data.mes, pessoa.data.ano);
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