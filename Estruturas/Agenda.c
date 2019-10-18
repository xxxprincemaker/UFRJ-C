#include<stdio.h>
#include<string.h>

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
void recebeDADOS(PESSOA agenda[], int x);
void imprimeDados(PESSOA agenda[], int numPessoa);
void buscaPorMes(PESSOA agenda[],int tam);
int encontraNome(PESSOA agenda[], int x);
void retiraPessoa(PESSOA agenda[], int x);

int main(){
	/*Chamadas de Funcao*/
	
	int npessoas;
	
	while (1){
		printf("Digite a quantiade de pessoas:");
		scanf("%d", &npessoas);
		if (npessoas <= 1000 || npessoas <= 0){
			break;
		}
	}

	PESSOA agenda[npessoas];
    
	recebeDADOS(agenda, npessoas);
	encontraNome(agenda, npessoas);
	buscaPorMes(agenda, npessoas);
    retiraPessoa(agenda,npessoas);
    
	return 0;
}

void recebeDADOS(PESSOA agenda[], int x){
	int i;
	for (i = 0; i < x; i++){
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

void imprimeDados(PESSOA agenda[], int numPessoa){
    int i = numPessoa;
    printf("\nCONTATO %d\n\n", numPessoa+1);
    
    printf("Nome: %s\n", agenda[i].nome);
    printf("Data de aniversario: %d/%d/%d.\n", agenda[i].data.dia, agenda[i].data.mes, agenda[i].data.ano);
    printf("Telefone: %s %s\n", agenda[i].tel.ddd, agenda[i].tel.numero);
    printf("E-mail: %s\n", agenda[i].email);
    
    printf("\nENDERECO: \n\n");
    
    printf("Rua: %s\n", agenda[i].endereco.rua);
    printf("Numero: %d\n", agenda[i].endereco.numero);
    printf("Complemento: %s\n", agenda[i].endereco.comple);
    printf("Bairro: %s\n", agenda[i].endereco.bairro);
    printf("Cidade: %s\n", agenda[i].endereco.cidade);
    printf("Estado: %s\n", agenda[i].endereco.estado);
    printf("Pais: %s\n\n", agenda[i].endereco.pais);
    printf("CEP: %s\n", agenda[i].endereco.cep);
    
    printf("Observacoes: %s\n\n", agenda[i].obs);
}

void buscaPorMes(PESSOA agenda[], int tam){
    int i, mesAniver, diaAniver;
	printf("Digite o dia que deseja analisar(dois digitos):");
	scanf("%d", &diaAniver);
	printf("Digite os dados do mes que deseja analisar(dois digitos):");
	scanf("%d", &mesAniver);
    for(i = 0; i < tam; i++){
        if(agenda[i].data.mes == mesAniver && agenda[i].data.dia == diaAniver){
            imprimeDados(agenda, i);
        }
    }
}

int encontraNome(PESSOA agenda[], int x){
	//Vou utilizar vetor pois quero percorrer a palavra.
	char nome[255];
	int i, j, aux;
	printf("Digite o primeiro da pessoa que deseja encontrar:");
	scanf(" %[^\n]s", &nome);
	for (i = 0; i < x; i++){
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
}

void retiraPessoa(PESSOA agenda[], int x){
    
    int i, b = 0;
    char nomeRemover;
    
    printf("Entre com nome da pessoa para remover da Agenda: ");
    scanf(" [^\n]s", nomeRemover);
    
    for(i = 0; i < x - 1; i++){
        if(agenda[i].nome == nomeRemover || b = 1){
            agenda[i] = agenda[i + 1];
            b = 1;
        }
    }
    agenda[x - 1] = NULL;
}