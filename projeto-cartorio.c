#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocação de texto por região
#include <string.h> // biblioteca responsável por cuidar das string

int registro() // Função responsável por cadastrar os usuários no sistema
{   // Início da criação das variáveis/strings locais
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char idade[40];
	char cargo[40];
	// Final da criação das variáveis/strings locais
	
	printf("Digite o CPF a ser cadastrado: "); // Coletando informação do usuário
	scanf("%s", cpf); // %s refere-se a string
	
	strcpy(arquivo, cpf); // Responsável por copiar os valores das string
	
	FILE *file; // Criando arquivo file
	file = fopen(arquivo,"w"); // Criou o arquivo e o "W" significa escrever
	fprintf(file, "\nCPF: ");
	fprintf(file,cpf); // Salvando o valor da variável
	fclose(file); // Fechando o arquivo
	
	file = fopen(arquivo, "a"); // Abrindo o arquivo e o "a" significa atualizar
	fprintf(file, "\nNome: "); 
	fclose(file); // Fechando o arquivo
	
	printf("Digite o nome a ser cadastrado: "); // Coletando informação do usuário
	scanf("%s", nome); // %s refere-se a string
	
	file = fopen(arquivo, "a"); // Abrindo o arquivo e o "a" significa atualizar
	fprintf(file, nome); // Salvando o valor da variável
	fclose(file); // Fechando o arquivo
	
	file = fopen(arquivo, "a"); // Abrindo o arquivo e o "a" significa atualizar
	fprintf(file, "\nSobrenome: ");
	fclose(file); // Fechando o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); // Coletando informação do usuário
	scanf("%s", sobrenome); // %s refere-se a string
	
	file = fopen(arquivo, "a"); // Abrindo o arquivo e o "a" significa atualizar
	fprintf(file, sobrenome); // Salvando o valor da variável
	fclose(file); // Fechando o arquivo
	
	file = fopen(arquivo, "a"); // Abrindo o arquivo e o "a" significa atualizar
	fprintf(file, "\nIdade: "); 
	fclose(file); // Fechando o arquivo
	
	printf("Digite a idade: "); // Coletando informação do usuário
	scanf("%s", idade); // %s refere-se a string
	
	file = fopen(arquivo, "a"); // Abrindo o arquivo e o "a" significa atualizar
	fprintf(file, idade); // Salvando o valor da variável
	fclose(file); // Fechando o arquivo
	
	file = fopen(arquivo, "a"); // Abrindo o arquivo e o "a" significa atualizar
	fprintf(file, "\nCargo: ");
	fclose(file); // Fechando o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); // Coletando informação do usuário
	scanf("%s", cargo); // %s refere-se a string
	printf("\n");
	
	file = fopen(arquivo, "a"); // Abrindo o arquivo e o "a" significa atualizar
	fprintf(file, cargo); // Salvando o valor da variável
	fclose(file); // Fechando o arquivo
	
	system("pause"); // Pausando a execução do programa e pede pro usuário pressionar qualquer tecla para continuar
	system("cls"); // Limpando a tela e cls significa clear screen
}


int consulta() {
	
	setlocale(LC_ALL, "Portuguese");
	
	// Início da criação das variáveis/strings locais
	char cpf[40];
	char conteudo[200];
	// Fim da criação das variáveis/strings locais
	
	printf("Digite o CPF a ser consultado: "); // Coletando informação do usuário
	scanf("%s", cpf); // %s refere-se a string
	
	FILE *file; // Criando arquivo file
	file = fopen(cpf, "r"); // Criou o arquivo e o "r" significa ler
	
	if(file == NULL) {
		
		printf("\n");
		printf("Usuário não encontrado, CPF não localizado!\n");
	} 
	else {
		
		printf("\nEssas são as informações do usuário: ");
		printf("\n");
	}
	
	
	// fgets lê a linha de texto do arquivo conteúdo. 200 número máximo de caracter e file é o ponteiro para o arquivo de onde a linha será lida.
	// NULL é quando atinge o final do arquivo.
	while(fgets(conteudo, 200, file) != NULL)  {
		
		printf("%s", conteudo); // %s refere-se a string
	}
	
	printf("\n\n");
	fclose(file); // Fechando o arquivo
	system("pause"); // Pausando a execução do programa e pede pro usuário pressionar qualquer tecla para continuar
	system("cls"); // Limpando a tela e cls significa clear screen
	
}

int deletar() {
	
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: "); // Coletando informação do usuário
	scanf("%s", cpf); // %s refere-se a string
	
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);
	
	if(file == NULL) {
		
		printf("\nO usuário não se encontra no sistema!\n\n");
		system("pause"); // Pausando a execução do programa e pede pro usuário pressionar qualquer tecla para continuar
	}
	
	else
		
	if (remove(cpf) == 0) {
		
		printf("\nCPF do usuário deletado com sucesso!\n\n");
		system("pause"); // Pausando a execução do programa e pede pro usuário pressionar qualquer tecla para continuar
	}	
	system("cls"); // Limpando a tela e cls significa clear screen
	
}


int main() {
	// Início da criação das variáveis/strings
	int opcao=0;
	int laco=1;
	char senhaDigitada[] = "a";
	int comparacao;
	// Final da criação das variáveis/strings
	
	
	printf("#### Cartório ####\n\n");
	printf("Login de Administrador!\n\nDigite a sua senha: "); // Coletando informação do usuário
	scanf("%s", senhaDigitada); // %s refere-se a string
	
	comparacao = strcmp(senhaDigitada, "admin"); // strcmp siginifica comparação de string
	
	if (comparacao == 0) {
		
		system("cls"); // Limpando a tela e cls significa clear screen
		
		for(laco=1; laco=1;) {
		
			setlocale(LC_ALL, "Portuguese"); // definindo a linguagem
	
			printf("\n#### Cartório ####\n\n");
			printf("Escolha a opção desejada do menu:\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n");
			printf("\t4 - Sair do sistema\n\n");
			printf("Opção: ");
	
			scanf("%d", &opcao); // Armazenando a escolha do usuário. %d refere-se a número inteiro. o &opcao é onde o nº escolhido pelo usuário vai ser armazenado. 
	
			system("cls"); // Limpando a tela e cls significa clear screen
		
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
				printf("Essa opção não está disponivel!\n");
				system("pause"); // Pausando a execução do programa e pede pro usuário pressionar qualquer tecla para continuar
				break;
			}
		}
	}
	
	else
		printf("\nSenha incorreta!");
	}
