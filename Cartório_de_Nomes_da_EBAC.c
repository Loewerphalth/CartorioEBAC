#include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o em espa�o e mem�ria
#include <locale.h> // biblioteca de aloca��es de texto por regi�o
#include <string.h> // biblioteca responsavel por cuidar das strings
 
int cadastro() // Fun��o responsavel por cadastrar os usu�rios no sistema
{	
	setlocale(LC_ALL, "Portuguese");
	// Inicio da cria��o de vari�veis e strings
	char arquivo[40];
	char CPF[40];
	char Nome[40];
	char Sobrenome[40];
	char Cargo[40];
	// Final da cria��o de vari�veis e strings
	
	printf("Digite o CPF a ser cadastrado:\n"); // Coletando informa��es do usu�rio CPF
	scanf("%s", CPF); // Armazenando dentro da vari�vel CPF
	
	strcpy(arquivo, CPF); // Responsavel por copiar os valores das strings
	
	FILE *file; // Cria o arquivo
	file = fopen(arquivo, "w"); // Cria o arquivo
	fprintf(file, CPF); // Salvo o valor da variavel
	fclose(file);  // Fecha o arquivo
	
	file = fopen(arquivo, "a"); // Atualize o arquivo com CPF
	fprintf(file, "\n"); // Separe o arquivo com espa�o
	fclose(file); // Fechando o arquivo
	
	printf("Digite o nome que gostaria de cadastra:\n");// Coletando informa��es do usu�rio Nome
	scanf("%s", Nome); // Armazenando dentro da vari�vel Nome
	
	file = fopen(arquivo, "a"); // Alterando o arquivo
	fprintf(file, Nome); // Salvo o nome no arquivo
	fclose(file); // Fechando o arquivo
	
	file = fopen(arquivo, "a"); // Alterando o arquivo
	fprintf(file, "\n"); // Separe o arquivo com espa�o
	fclose(file); // Fechando o arquivo
	
	printf("Digite o Sobrenome que gostaria de cadastrar:\n"); // Coletando informa��o do usu�rio Sobrenome
	scanf("%s", Sobrenome); // Armazenando dentro da vari�vel Sobrenome
	
	file = fopen(arquivo, "a"); // Alterando o arquivo
	fprintf(file, Sobrenome); // Salvo Sobrenome no arquivo
	fclose(file); // Fechando o arquivo
	
	file = fopen(arquivo, "a"); // Alterando o arquivo
	fprintf(file, "\n"); // Separe o arquivo com espa�o
	fclose(file); // Fechando o arquivo
	
	printf("Digite o cargo da pessoa que gostaria de cadastrar:\n"); // Coletando informa��es do usu�rio Cargo
	scanf("%s", Cargo); // Armazenando na vari�vel Cargo
	
	file = fopen(arquivo, "a"); // Alterando o arquivo
	fprintf(file, Cargo); // Salvo Cargo no arquivo
	fclose(file); // Fechando o arquivo
	
	file = fopen(arquivo, "a"); // Alterando o arquivo
	fprintf(file, "\n"); // Separando com espa�o
	fclose(file); // Fechando o arquivo
	
	system("pause"); // Pausa para leitura e esperando o pr�ximo comando
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	// Cria��o de vari�veis
	char CPF[40];
	char Nome[40];
	char Sobrenome[40];
	char Cargo[40];
	char conteudo[200];
	
	printf("Digite o CPF da pessoa que gostaria de consulta: \n"); // Consultando nome do usu�rio
	scanf("%s", CPF); // Buscando pela vari�vel CPF
	
	// Busca pelo CPF
	FILE *file;
	file = fopen(CPF, "r"); // Leitura da Vari�vel
	
	if(file == NULL)
	{
		printf("N�o foi possivel localizar o usu�rio, n�o localizado!.\n"); // Resposta para quando n�o encontrado o usu�rio
	}
	
	// Busca pela vari�vel conteudo
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEsses s�o os dados do usu�rio:"); // Dados entregues pelos usu�rio
		printf("%s", conteudo);
		
		printf("\n\n");
	}
	
	system("pause"); // Pausa para leitura e esperando o pr�ximo comando
	
}

int retirar()
{
	// Cria��o de vari�veis
	char CPF[40];
	
	printf("Qual nome do usu�rio que gostaria de retirar ?:\n"); // Coletando informa��es do cliente
	scanf("%s",CPF); // Buscando informa��es pela vari�vel CPF
	
	remove(CPF); // Fun��o responsavel por deletar os nomes
	
	// Busca pelo CPF
	FILE *file;
	file = fopen(CPF, "r");
	
	if (file == NULL)
	{
		printf("O usu�rio n�o foi encontrado ! \n"); // Resposta para os dados entregues pelo usu�rio
		printf("\n");
		system("pause"); // Pausa para leitura e esperando o pr�ximo comando		
	}
	
}



int main() // come�o do menu
{
	int opcao=0;//Definindo vari�veis
	int laco=1;// Definindo repeti��o
	
	for(laco=1;laco=1;)// Informa��o de repeti��o
	{
	
		system("cls"); // Respons�vel por limpar a tela
	
		setlocale(LC_ALL, "Portuguese");// Inicio do Menu
		printf("### Cart�rio de Nomes da EBAC ### \n\n"); // Titulo
		printf("Escolha as op��es do menu: \n\n"); // Orienta��o para o usu�rio
		printf("\t1 - Cadastrar nomes\n"); //op��o 1
		printf("\t2 - Consultar nomes\n"); //op��o 2
		printf("\t3 - Retirar nomes\n\n"); //op��o 3
		printf("Op��o:");
		
		scanf("%d" , &opcao);// Armazenamento e escolha do usu�rio
		
		system("cls"); // Respons�vel por limpar a tela
		
		switch(opcao)// Inicio da sele��o
		{
			case 1: //op��o 1
			cadastro();
			break;
			
			case 2: //op��o 2
			consulta();
			break;
			
			case 3: //op��o 3
			retirar();
			break;
			
			case 4: //op��o 4
			printf("Obrigado, at� logo!");
			return 0;
			break;
			
			default: // Quando n�o h� op��o valida
			printf("Esta op��o n�o est� disponivel. Selecione algumas das 3 acima !\n"); // Resposta para quando a op��o n�o � valida
			system("pause"); // Pausa para leitura e esperando o pr�ximo comando
			// Fim da sele��o
		}
	}
} 
