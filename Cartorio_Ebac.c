#include <stdio.h> //Biblioteca de Comunica��o com o Usu�rio
#include <stdlib.h> //Biblioteca Para Alocar Espa�o na Mem�ria
#include <locale.h> //Biblioteca Para  aloca��es de Texto por Regi�o
#include <string.h> //biblioteca res�nsavel por cuidar das string

int cadastrar()
{
	//char vai receber de um a um cada string fazendo um conjunto de 40 delas
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a Ser Cadastrado: \n");
	scanf("%s", cpf);
	
	//strcpy copia variaveis (Tal variavel, recebe)
	strcpy(arquivo, cpf);

	FILE *file; 	//Busca Metodos de Criar arquivos na Biblioteca
	file = fopen(arquivo, "w"); 	//Cria o Arquivo E nomea-o Com O CPF digitado
	fprintf(file, cpf); 		//Salva o Valor da Variavel Dentro Do Arquivo
	fclose(file);  		//Fecha o Arquivo
	
	file = fopen(arquivo, "a"); 		//Abre o Arquivo com inten��o de atualizar-lo
	fprintf(file, ",");  		//Escreve uma virgula apos o CPF
	fclose(file); 		//Fecha o arquivo
	
	printf("Digite o Nome a Ser Cadastrado: \n");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a"); 		//Abre o Arquivo com inten��o de atualizar-lo
	fprintf(file, nome);  		//Escreve um Nome cadastrado no Arquivo
	fclose(file); 		//Fecha o arquivo
	
	file = fopen(arquivo, "a"); 		//Abre o Arquivo com inten��o de atualizar-lo
	fprintf(file, ",");  		//Escreve uma virgula apos o CPF
	fclose(file); 		//Fecha o arquivo
	
	printf("Digite o SobreNome a Ser Cadastrado: \n");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a"); 		//Abre o Arquivo com inten��o de atualizar-lo
	fprintf(file, sobrenome);  		//Escreve um SobreNome cadastrado no Arquivo
	fclose(file); 		//Fecha o arquivo
	
	file = fopen(arquivo, "a"); 		//Abre o Arquivo com inten��o de atualizar-lo
	fprintf(file, ",");  		//Escreve uma virgula apos o CPF
	fclose(file); 		//Fecha o arquivo
	
	printf("Digite o Cargo a ser Cadastrado: \n");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");  		//Abre o Arquivo com inten��o de atualizar-lo
	fprintf(file, cargo);  			//Escreve o Cargo cadastrado no Arquivo
	fclose(file);  		//Fecha o arquivo
	
	system("pause");
}

int consultar()
{
	 setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[205];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
  	
	FILE *file;	  		//Busca Metodos de Criar e buscar arquivos na Biblioteca
	file = fopen(cpf,"r");  		//Abre o Arquivo com inten��o de leitura
  	
	if(file == NULL)
	{
		printf("N�o Localizado!.\n");
	}

	while(fgets(conteudo, 205, file) != NULL)
	{
		printf("\n Perfil Do Usuario : ");
		printf("%s", conteudo);
		printf("\n\n");
	}
  	
	system ("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do Usu�rio a Ser deletado : \n");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Usu�rio N�o Encontrado !.\n\n");
	}
	else
	{
		remove(cpf);  		//Remove uma pasta com mesmo nome da variavel CPF
		printf("Usu�rio Deletado Com Sucesso ! \n");
	}	
	system("pause");	
}

int main()
{
	//Definindo As Variaveis 
	int opcao=0;
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls"); //Limpar Menu
		
		setlocale(LC_ALL, "Portuguese"); 	//Definindo a Linguagem
	
					//Menu Inicial
		printf("********** Cart�rio Da Ebac **********\n\n");	
		printf("Selecione Uma Das Op��es Abaixo:\n\n");
		printf("\t 1 - Cadastrar Usu�rio \n");
		printf("\t 2 - Consultar Usu�rio \n");
		printf("\t 3 - Deletar Usu�rio \n");
		printf("\t 4 - Sair Do Sistema \n\n");
	
		printf("Digite a Op��o Desejada: ");
		scanf("%d", &opcao); 	//Armazenar Escolha De Menu
	
		system("cls");	 //Limpar Menu
	
			//Escolha De Menu
		
		switch(opcao)
		{
			case 1:
				cadastrar();	
			break;
			
			case 2:
				consultar();
			break;
			
			case 3:
				deletar();
			break;
			
			case 4:
				printf("Obrigado Por Utilizar Nosso Sistema ! \n");
				return 0;
			break;
			
			default:
				printf("Op��o Invalida \n");
				system("pause");
			break;
		}
	}
	
		//printf("Esse SoftWare � de Livre Acesso Para Alunos Cursando a Ebac, By Paulo");
	
	
}
