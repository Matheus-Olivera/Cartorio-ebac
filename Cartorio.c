#include <stdio.h> //bliblioteca de comunica��o com o usu�rio
#include <stdlib.h> //bliblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //bliblioteca de aloca��es de texto por regi�o
#include <string.h> //bliblioteca das strings
	
	int registro() //fun��o que cadastra os usu�rios
	{
		//�nicio das variaveis/stirng
		char cpf[40];
		char nome[40];
		char sobrenome[40];
		char cargo[40];
		char arquivo[40];
		//final das variaveis
		
		printf("Digite o seu CPF: ");//coletando dados do usu�rio
		scanf("%s",cpf);//%s refere-se a string
		
		strcpy(arquivo, cpf); // responsavel por copiar os valores das strings
		
		FILE *file; //chama o FILE
		file= fopen(arquivo, "w"); // cria o arquivo w = write
		fprintf(file,cpf); //salva o valor da variavel
		fclose(file);// fecha o arquivo
		
		file = fopen(arquivo, "a");
		fprintf(file,",");
		fclose(file);
		
		printf("Digite o nome a ser cadastrado: ");
		scanf("%s",nome);
		
		file = fopen(arquivo, "a");
		fprintf(file,nome);
		fclose(file);
		
		file = fopen(arquivo, "a");
		fprintf(file,",");
		fclose(file);
		
		printf("Digite o sobrenome a ser cadastrado: ");
		scanf("%s",sobrenome);
		
		file = fopen(arquivo, "a");
		fprintf(file,sobrenome);
		fclose(file);
		
		file = fopen(arquivo, "a");
		fprintf(file,",");
		fclose(file);
		
		printf("Digite o cargo a ser cadastrado: ");
		scanf("%s",cargo);
		
		file = fopen(arquivo, "a");
		fprintf(file,cargo);
		fclose(file);
		
		system("pause");
		
	}
	
	int consulta()
	
	{
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
		char cpf[40];
		char conteudo[200];
		
		printf("Digite o CPF a ser consultado: ");
		scanf("%s",cpf);
		
		FILE *file;
		file = fopen(cpf, "r");
		
		if(file == NULL)
		{
		printf("Usu�rio n�o localizado.\n ");  	
		}	
		
		while(fgets(conteudo, 200, file) != NULL)
		{
			printf("Esses s�o os dados do usu�rio: ");
			printf("%s", conteudo);
			printf("\n\n");
		}
		
		system("pause");
		
		
	}
	
	int deletar()
	
	{
		char cpf[40];
		
		printf("Qual o CPF a ser deletado?: ");
		scanf("%s", cpf);
		
		remove(cpf);
		
		FILE *file;
		file = fopen(cpf,"r");
		
		if(file == NULL)	
			
		{
			printf("esse usu�rio n�o existe no sistema!\n");
			
		}
			 	
		system("pause");
		
	}
	
	
	
	int main()

	{
		
	int opcao=0; //definindo as variaveis
	int repeticao=1;
	
	for (repeticao=1;repeticao=1;)
	
	{
		
	system("cls");//limpar a tela
		
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	printf("\t___ Cart�rio EBAC ___\n\n"); //inicio do menu
	printf("\tEscolha a op��o desejada no menu:\n\n");
	printf("\t1-Registrar nomes\n");
	printf("\t2-Consultar nomes\n");
	printf("\t3-Deletar nomes\n\n\n");
	printf("\tOp��o: ");//fim do menu
	
	scanf("%d", &opcao); //(escolha do usu�rio)
	
	system("cls"); //limpar a tela
	
	switch(opcao) //�nicio da sele��o do menu
	
		{	case 1:
			registro();//chmada de fun��es
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel!\n");
			system("pause");
			break;
			//fim da sel��o
		}
	 }

}

