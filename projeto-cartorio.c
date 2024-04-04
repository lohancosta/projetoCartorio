#include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��o de texto por regi�o
#include <string.h> // biblioteca respons�vel por cuidar das string

int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char idade[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); // Respons�vel por copiar os valores das string
	
	FILE *file; // ele vai acessar o FILE e criar um arquivo file
	file = fopen(arquivo,"w"); // arquivo file criado e abrindo e escrevendo
	fprintf(file, "\nCPF: ");
	fprintf(file,cpf); // salvo o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // vai abrir o aquivo para atualizar ("a")
	fprintf(file, "\nNome: "); // incluir mais informa��es (",")
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, "\nSobrenome: ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, "\nIdade: ");
	fclose(file);
	
	printf("Digite a idade: ");
	scanf("%s", idade);
	
	file = fopen(arquivo, "a");
	fprintf(file, idade);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, "\nCargo: ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	printf("\n");
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
}


int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	
	char cpf[40];
	char conteudo[300];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); 
	
	if(file == NULL)
	{
		printf("\n");
		printf("Usu�rio n�o encontrado, CPF n�o localizado!\n");
	} 
	else
	{
	printf("\nEssas s�o as informa��es do usu�rio: ");
	printf("\n");
	}
	
	while(fgets(conteudo, 300, file) != NULL) // Enquanto a fun��o fgets conseguir ler uma linha do arquivo apontado por file e n�o atingir o final do arquivo ou retornar 
	//NULL(quando ocorre erro ou atinge o final do arquivo, continue executando o c�digo dentro deste loop.
	
	{
		printf("%s", conteudo);
	}
	
	printf("\n\n");
	fclose(file);
	system("pause");
	
}

int deletar()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);	
	
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);
	
	if(file == NULL)
	{
		printf("\nO usu�rio n�o se encontra no sistema!\n\n");
		system("pause");
	}
	
	else
		
	if (remove(cpf) == 0)
	{
		printf("\nCPF do usu�rio deletado com sucesso!\n\n");
		system("pause");
	}
	
}


int main() 
	{
	int opcao=0; // definindo a vari�vel
	int laco=1;
	
	for(laco=1; laco=1;) 
	{
		
		system("cls");
	
	
		setlocale(LC_ALL, "Portuguese"); // definindo a linguagem
	
	
		printf("#### Cart�rio ####\n\n");
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
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
			
			default:
			printf("Essa op��o n�o est� disponivel!\n");
			system("pause");
			break;
		}
	}
	}
	

