#include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��o de texto por regi�o
#include <string.h> // biblioteca respons�vel por cuidar das string

int registro() // Fun��o respons�vel por cadastrar os usu�rios no sistema
{   // Definindo vari�veis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char idade[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: "); // Coletando informa��o do usu�rio
	scanf("%s", cpf); // %s refere-se a string
	
	strcpy(arquivo, cpf); // Respons�vel por copiar os valores das string
	
	FILE *file; // Criando arquivo file
	file = fopen(arquivo,"w"); // Criou o arquivo e o "W" significa escrever
	fprintf(file, "\nCPF: ");
	fprintf(file,cpf); // Salvando o valor da vari�vel
	fclose(file); // Fechando o arquivo
	
	file = fopen(arquivo, "a"); // Abrindo o arquivo e o "a" significa atualizar
	fprintf(file, "\nNome: "); 
	fclose(file); // Fechando o arquivo
	
	printf("Digite o nome a ser cadastrado: "); // Coletando informa��o do usu�rio
	scanf("%s", nome); // %s refere-se a string
	
	file = fopen(arquivo, "a"); // Abrindo o arquivo e o "a" significa atualizar
	fprintf(file, nome); // Salvando o valor da vari�vel
	fclose(file); // Fechando o arquivo
	
	file = fopen(arquivo, "a"); // Abrindo o arquivo e o "a" significa atualizar
	fprintf(file, "\nSobrenome: ");
	fclose(file); // Fechando o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); // Coletando informa��o do usu�rio
	scanf("%s", sobrenome); // %s refere-se a string
	
	file = fopen(arquivo, "a"); // Abrindo o arquivo e o "a" significa atualizar
	fprintf(file, sobrenome); // Salvando o valor da vari�vel
	fclose(file); // Fechando o arquivo
	
	file = fopen(arquivo, "a"); // Abrindo o arquivo e o "a" significa atualizar
	fprintf(file, "\nIdade: "); 
	fclose(file); // Fechando o arquivo
	
	printf("Digite a idade: "); // Coletando informa��o do usu�rio
	scanf("%s", idade); // %s refere-se a string
	
	file = fopen(arquivo, "a"); // Abrindo o arquivo e o "a" significa atualizar
	fprintf(file, idade); // Salvando o valor da vari�vel
	fclose(file); // Fechando o arquivo
	
	file = fopen(arquivo, "a"); // Abrindo o arquivo e o "a" significa atualizar
	fprintf(file, "\nCargo: ");
	fclose(file); // Fechando o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); // Coletando informa��o do usu�rio
	scanf("%s", cargo); // %s refere-se a string
	printf("\n");
	
	file = fopen(arquivo, "a"); // Abrindo o arquivo e o "a" significa atualizar
	fprintf(file, cargo); // Salvando o valor da vari�vel
	fclose(file); // Fechando o arquivo
	
	system("pause");
}


int consulta() {
	
	setlocale(LC_ALL, "Portuguese");
	
	
	char cpf[40];
	char conteudo[300];
	
	printf("Digite o CPF a ser consultado: "); // Coletando informa��o do usu�rio
	scanf("%s", cpf); // %s refere-se a string
	
	FILE *file;
	file = fopen(cpf, "r"); 
	
	if(file == NULL) {
		
		printf("\n");
		printf("Usu�rio n�o encontrado, CPF n�o localizado!\n");
	} 
	else {
		
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("\n");
	}
	
	// Enquanto a fun��o fgets conseguir ler uma linha do arquivo apontado por file e n�o atingir o final do arquivo ou retornar. 
	//NULL(quando ocorre erro ou atinge o final do arquivo, continue executando o c�digo dentro deste loop.
	while(fgets(conteudo, 300, file) != NULL)  {
		
		printf("%s", conteudo); // %s refere-se a string
	}
	
	printf("\n\n");
	fclose(file);
	system("pause");
	
}

int deletar() {
	
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: "); // Coletando informa��o do usu�rio
	scanf("%s", cpf); // %s refere-se a string
	
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);
	
	if(file == NULL) {
		
		printf("\nO usu�rio n�o se encontra no sistema!\n\n");
		system("pause");
	}
	
	else
		
	if (remove(cpf) == 0) {
		
		printf("\nCPF do usu�rio deletado com sucesso!\n\n");
		system("pause");
	}
	
}


int main() 
	{
	int opcao=0; // definindo a vari�veis
	int laco=1;
	char senhaDigitada[] = "a";
	int comparacao;
	
	
	printf("#### Cart�rio ####\n\n");
	printf("Login de Administrador!\n\nDigite a sua senha: "); // Coletando informa��o do usu�rio
	scanf("%s", senhaDigitada); // %s refere-se a string
	
	comparacao = strcmp(senhaDigitada, "admin"); // strcmp siginifica compara��o de string
	
	if (comparacao == 0) {
		
		system("cls");
		for(laco=1; laco=1;) {
		
			setlocale(LC_ALL, "Portuguese"); // definindo a linguagem
	
			printf("\n#### Cart�rio ####\n\n");
			printf("Escolha a op��o desejada do menu:\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n");
			printf("\t4 - Sair do sistema\n\n");
			printf("Op��o: ");
	
			scanf("%d", &opcao); // scanf � pra receber a entrada do usu�rio/resposta e %d indica o formato que vai ser inserido, no caso � n�mero inteiro. Armazenando a escolha do usu�rio.
	
			system("cls"); //limpar
		
			switch (opcao)
			{
				case 1:
				registro();
				break;
				
				case 2:
				consulta();
				break;
				
				case 3:
				deletar();
				break;
				
				case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
				break;
				
				default:
				printf("Essa op��o n�o est� disponivel!\n");
				system("pause");
				break;
			}
		}
	}
	
	else
		printf("\nSenha incorreta!");
	}
