#include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o e memoria
#include <locale.h> // biblioteca de aloca��es de texto por regi�o
#include <string.h> // biblioteca das strings presentes no arquivo

int registro()
{
	setlocale(LC_ALL,"Portuguese"); //definindo as linguagens
	//inico da cria��o de strings/variaveis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final das variaveis/strings
	printf("Digite o cpf a ser cadastrado: "); //coleta de dados do usuario
	scanf("%s",cpf); //%s sao as strings presentes 
	
	strcpy(arquivo,cpf); // responsavel por copiar valor da string
	
	FILE *file; // Cria o arquivo 
	file = fopen(arquivo, "w"); // cria o arquivo, "w" � escrever 
	fprintf(file,cpf); // salva valor da variavel
	fclose(file); // fecha arquivo
	
	file = fopen(arquivo, "a"); // "a" atualizar 
	fprintf(file, ",");
	fclose(file);
	
	printf("digite um nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("digite um sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");

}

int consultar()
{
	setlocale(LC_ALL,"Portuguese"); //definindo as linguagens
	//inico das strings/variaveis presentes na conuslta
	char cpf[40];
	char conteudo[200];
	//fim das strings/variaveis
	printf("digite o CPF que gostaria de consultar: "); // cosultar dados presentes no documetos que foram salvos
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); // "r" significa ler
	
	if(file == NULL) // condi��o a qual nao foi encontrada o dado
	{
		printf("Arquivo n�o localizado, impossivel sua abertura!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s",conteudo);
		printf("\n\n");
	}
	
	system("pause");	
}

int deletar()
{
	setlocale(LC_ALL,"Portuguese"); //definindo as linguagens
	//inico das strings/variaveis
	char cpf[40];
	//final das strings/variaveis
	printf("digite o CPF do usuario que voc� gostaria de apagar: "); // apagar dados presentes que nao s�o mais nescessarios
	scanf("%s",cpf);
	
	remove(cpf); // fun��o de remo��o 
	
	FILE *file; // fun�ao de puxar dados dentro do sistema de armazenamento ou local de armazenamento
	file = fopen(cpf,"r");
	
	if(file == NULL) // fun�ao caso nao seja possivel encontrar usuario presente, ou usuario que foi deletado
	{
		printf("Usuario nao encontrado!\n");
		system("pause");
	}
}

int main()
{
	int opcao=0; //definindo as variaveis
	int comando=1;
	
	for(comando=1;comando;)
	{
		
		system("cls"); // responsavel por limpar a tela
	
		setlocale(LC_ALL,"Portuguese"); //definindo as linguagens
	
		printf("\tCart�rio da EBAC\t \n\n"); // inicio do menu
		printf("escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("\t4 - sair do sistema\n\n");
		printf("op��o:"); //final do menu
	
		scanf("%d", &opcao); // aramazenado a escolha do usuario 
	
		system("cls");
		
		switch(opcao) // inicio das fun��es do menu
		{
			case 1:
			registro(); //chamada de fun��o de registro
			break;
			
			case 2:
			consultar(); // chamada de fun��o de consulta
			break;
			
			case 3:
			deletar(); // chamada de fun��o de deletar 
			break;
			
			case 4:
			printf("obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf("essa fun��o nao existe!\n");
			system("pause");
			break;
		
		}
	
	}
}
