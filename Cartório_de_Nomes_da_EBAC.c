#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação em espaço e memória
#include <locale.h> // biblioteca de alocações de texto por região
#include <string.h> // biblioteca responsavel por cuidar das strings
 
int cadastro() // Função responsavel por cadastrar os usuários no sistema
{	
	setlocale(LC_ALL, "Portuguese");
	// Inicio da criação de variáveis e strings
	char arquivo[40];
	char CPF[40];
	char Nome[40];
	char Sobrenome[40];
	char Cargo[40];
	// Final da criação de variáveis e strings
	
	printf("Digite o CPF a ser cadastrado:\n"); // Coletando informações do usuário CPF
	scanf("%s", CPF); // Armazenando dentro da variável CPF
	
	strcpy(arquivo, CPF); // Responsavel por copiar os valores das strings
	
	FILE *file; // Cria o arquivo
	file = fopen(arquivo, "w"); // Cria o arquivo
	fprintf(file, CPF); // Salvo o valor da variavel
	fclose(file);  // Fecha o arquivo
	
	file = fopen(arquivo, "a"); // Atualize o arquivo com CPF
	fprintf(file, "\n"); // Separe o arquivo com espaço
	fclose(file); // Fechando o arquivo
	
	printf("Digite o nome que gostaria de cadastra:\n");// Coletando informações do usuário Nome
	scanf("%s", Nome); // Armazenando dentro da variável Nome
	
	file = fopen(arquivo, "a"); // Alterando o arquivo
	fprintf(file, Nome); // Salvo o nome no arquivo
	fclose(file); // Fechando o arquivo
	
	file = fopen(arquivo, "a"); // Alterando o arquivo
	fprintf(file, "\n"); // Separe o arquivo com espaço
	fclose(file); // Fechando o arquivo
	
	printf("Digite o Sobrenome que gostaria de cadastrar:\n"); // Coletando informação do usuário Sobrenome
	scanf("%s", Sobrenome); // Armazenando dentro da variável Sobrenome
	
	file = fopen(arquivo, "a"); // Alterando o arquivo
	fprintf(file, Sobrenome); // Salvo Sobrenome no arquivo
	fclose(file); // Fechando o arquivo
	
	file = fopen(arquivo, "a"); // Alterando o arquivo
	fprintf(file, "\n"); // Separe o arquivo com espaço
	fclose(file); // Fechando o arquivo
	
	printf("Digite o cargo da pessoa que gostaria de cadastrar:\n"); // Coletando informações do usuário Cargo
	scanf("%s", Cargo); // Armazenando na variável Cargo
	
	file = fopen(arquivo, "a"); // Alterando o arquivo
	fprintf(file, Cargo); // Salvo Cargo no arquivo
	fclose(file); // Fechando o arquivo
	
	file = fopen(arquivo, "a"); // Alterando o arquivo
	fprintf(file, "\n"); // Separando com espaço
	fclose(file); // Fechando o arquivo
	
	system("pause"); // Pausa para leitura e esperando o próximo comando
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	// Criação de variáveis
	char CPF[40];
	char Nome[40];
	char Sobrenome[40];
	char Cargo[40];
	char conteudo[200];
	
	printf("Digite o CPF da pessoa que gostaria de consulta: \n"); // Consultando nome do usuário
	scanf("%s", CPF); // Buscando pela variável CPF
	
	// Busca pelo CPF
	FILE *file;
	file = fopen(CPF, "r"); // Leitura da Variável
	
	if(file == NULL)
	{
		printf("Não foi possivel localizar o usuário, não localizado!.\n"); // Resposta para quando não encontrado o usuário
	}
	
	// Busca pela variável conteudo
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEsses são os dados do usuário:"); // Dados entregues pelos usuário
		printf("%s", conteudo);
		
		printf("\n\n");
	}
	
	system("pause"); // Pausa para leitura e esperando o próximo comando
	
}

int retirar()
{
	// Criação de variáveis
	char CPF[40];
	
	printf("Qual nome do usuário que gostaria de retirar ?:\n"); // Coletando informações do cliente
	scanf("%s",CPF); // Buscando informações pela variável CPF
	
	remove(CPF); // Função responsavel por deletar os nomes
	
	// Busca pelo CPF
	FILE *file;
	file = fopen(CPF, "r");
	
	if (file == NULL)
	{
		printf("O usuário não foi encontrado ! \n"); // Resposta para os dados entregues pelo usuário
		printf("\n");
		system("pause"); // Pausa para leitura e esperando o próximo comando		
	}
	
}



int main() // começo do menu
{
	int opcao=0;//Definindo variáveis
	int laco=1;// Definindo repetição
	
	for(laco=1;laco=1;)// Informação de repetição
	{
	
		system("cls"); // Responsável por limpar a tela
	
		setlocale(LC_ALL, "Portuguese");// Inicio do Menu
		printf("### Cartório de Nomes da EBAC ### \n\n"); // Titulo
		printf("Escolha as opções do menu: \n\n"); // Orientação para o usuário
		printf("\t1 - Cadastrar nomes\n"); //opção 1
		printf("\t2 - Consultar nomes\n"); //opção 2
		printf("\t3 - Retirar nomes\n\n"); //opção 3
		printf("Opção:");
		
		scanf("%d" , &opcao);// Armazenamento e escolha do usuário
		
		system("cls"); // Responsável por limpar a tela
		
		switch(opcao)// Inicio da seleção
		{
			case 1: //opção 1
			cadastro();
			break;
			
			case 2: //opção 2
			consulta();
			break;
			
			case 3: //opção 3
			retirar();
			break;
			
			case 4: //opção 4
			printf("Obrigado, até logo!");
			return 0;
			break;
			
			default: // Quando não há opção valida
			printf("Esta opção não está disponivel. Selecione algumas das 3 acima !\n"); // Resposta para quando a opção não é valida
			system("pause"); // Pausa para leitura e esperando o próximo comando
			// Fim da seleção
		}
	}
} 
