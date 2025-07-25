#include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() // fun��o responsavel por cadastrar usuarios do sistema
{
	//inicio da cria��o de variaveis/string
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final das variaveis
    
    printf("Digite o CPF a ser cadastrado: "); //coletando info do usu�rio
    scanf("%s", cpf); //%s refere-se � string (salvar)
    
    strcpy(arquivo, cpf); //respons�vel por copiar os valores das strings
    
    FILE *file; // cria o arquivo
    file = fopen(arquivo,"w"); // cria o arquivo; "w" de write (escrever) 
    fprintf(file,cpf); // salvo o valor da vari�vel (cpf)
    fclose(file); // fecho o arquivo 
    
    file = fopen(arquivo, "a"); //file de arquivo (cpf), fopen (abrindo o arquivo) e "a" de atualizar o arquivo
    fprintf(file,","); // virgula para n�o ficar tudo junto
    fclose(file); // fecha o arquivo
    
    printf("Digite o nome a ser cadastrado: "); // coletando info do usu�rio				
    scanf("%s", nome); //%s refere-se � string (salvar)
    
    file = fopen(arquivo,"a"); // arquivo = abrindo o arquivo, atualizando
    fprintf(file,nome); //fprintf = estamos falando com o arquivo; printf ("") = estamos falando com o usu�rio 
    fclose(file); // fechando o arquivo
    
    file = fopen(arquivo,"a"); //atualizando arquivo	
    fprintf(file,","); // v�rgula para n�o ficar td junto
    fclose(file); // fechando o arquivo
    
    printf("Digite o sobrenome a ser cadastrado: "); //coletando info do usu�rio
    scanf("%s", sobrenome); // %s refere-se � string (salvando info)
    
    file = fopen(arquivo,"a"); //atualizando aerquivo
    fprintf(file,sobrenome); // salvo o valor da variavel (sobrenome)
    fclose(file); //fecha arquivo
    
    file = fopen(arquivo,"a"); //atualizando arquivo
    fprintf(file,","); //virgula pra n�o ficar tudo junto
    fclose(file); //fechando arquivo
    
    printf("Digite o cargo a ser cadastrado: "); //coletando info do usu�rio
    scanf("%s", cargo); // %s refere-se a string (salvando a info cargo)
    
    file = fopen(arquivo, "a"); //atuaizando arquivo
    fprintf(file,cargo); // salva o valor da string (cargo)
    fclose(file); //fecha arquivo
    
    system("pause"); // Deixa o usu�rio ler as mens�gens destinadas para o mesmo
}  // fim da fun��o registro

int consulta() // fun��o respons�vel por consultar usu�rios do sistema
{
	setlocale(LC_ALL, "Portuguese"); // Permite a coloca��o de acentos no programa
	//in�cio da cria��o de vari�veis/strings
	char cpf[40];
	char conteudo[200];
	// fim das variaveis
	
	printf("Digite o CPF que deseja consultar: "); // coletando info do usu�rio a ser consultado
	scanf("%s", cpf); // %s refere-se a string (cpf)
	
	FILE *file; // cria arquivo
	file = fopen(cpf, "r"); //arquivo abrindo; "r" de read (ler)
	
	if(file == NULL) // Se o arquivo (file) n�o existe = Nulo (NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo! N�o localizado...\n"); //mensagem caso usu�rio consultado n�o estiver no sistema
	 } 
	
	while(fgets(conteudo, 200, file) != NULL) // enquato fgets (vai buscar) o conteudo, e o maximo de conteudo (200) at� trazer todas infos; quando parar? quando for nulo(NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: "); // mensagem caso o usu�rio consultado estiver no sistema
		printf("%s", conteudo); // %s refere-se a string conteudo (cpf, nome, sobrenome, cargo) / printf = apresentando o conteudo para o usurario
		printf("\n\n\n"); // par�grafos para melhor visualiza��o do conteudo
	}
	
	system("pause"); // deixa o usuario ler as mensagens destinadas para o mesmo
	
	
}  // fim da fun�ao consulta

int deletar() // fun�ao responsavel por deletar usuarios do sistema
{
    char cpf[40];    // cria��o da string/variavel
    
    printf("Digite o CPF do usu�rio que deseja deletar: "); // coletando info do usuario
    scanf("%s", cpf); // %s refere-se a string (cpf) 
    
    FILE *file; // cria arquivo
	file = fopen(cpf, "r"); // abrindo o arquivo e lendo o cpf
	
	if(file == NULL) // se o arquivo for nulo
	{
		printf("N�o foi poss�vel deletar o usu�rio! Usu�rio fora do sistema...\n"); // mensagem caso o arquivo for nulo
	 } 
	else // Caso o arquivo nao for nulo
     	{
        fclose(file);  // Fecha o arquivo antes de deletar
        if (remove(cpf) == 0) // � uma fun��o que deleta o arquivo cujo nome foi passado. "Se a fun��o remove deletou com sucesso (retornou 0), ent�o fa�a isto." (se(if) a fun��o "remove" funcionar(==0) fa�a isso)
		 {
            printf("Usu�rio deletado do sistema com sucesso!\n"); // mensagem de sucesso
         } 
		else // caso o arquivo nao for nulo porem nao conseguiu deletar
		 {
            printf("Erro ao deletar o usu�rio!\n"); // mensagem de erro
         }
   }

    system("pause"); // permite ao usuario a visualizacao das mesagens
    return 0; // Fim do programa com sucesso. 
}   // fim da funcao deletar 
	
	
int main () // funcao principal
{


	int opcao=0; //Definindo vari�veis. int opcao (variavel) inteira inicializando com valor 0. geralmente usada para armazenar escolha do usuario
	int laco=1; // variavel inteira (laco) inicializa com 1. esta sendo usada como uma condicao de laco
	for(laco=1;laco=1;) //for cria um laco de repeticao. nesse caso (laco=1;laco;), est� fazenod um laco infinito
	 {
	  system("cls"); //responsavel por limpar a tela 

	  setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	  printf("### Cart�rio da EBAC ###\n\n"); //In�cio do menu
 	  printf("Escolha a op��o desejada do menu: \n\n");
	  printf("\t1 - Registrar usu�rio\n");
 	  printf("\t2 - Consultar usu�rio\n");
	  printf("\t3 - Deletar usu�rio\n\n\n");
	  printf("\t4 - Sair do sistema\n\n");
	  printf("Op��o:"); //Fim do menu
      
	  scanf("%d", &opcao); //armazenando da escolha do usuario

      system("cls"); // responsavel por limpar a tela 
      
      
      switch(opcao) // switch avalia uma expressao ou variavel (inicio da selecao do menu)
      {
      	case 1: // case compara o valor com cada possibilidade. 
      		registro(); // chamada da funcao registro
      		break; // encerra o switch apos encontrar o case verdadeiro. Se nao encontrar continua executando os proximos case
      		
      	case 2:
      		consulta(); // chamada da funcao consulta
      		break;
      		
      	case 3:
		    deletar(); // chamada da funcao deletar
		    break;
			
		case 4:
		printf("Obrigado por utilizar nosso sistema");	
		return 0;
		break;
		
		 default: // executado se nenuhum case for correspondente
			printf("Essa op��o n�o existe!\n"); // mensagem caso o usuario clique em uma opcao que nao existe
			system("pause"); // permite que o usuario leia a mensagem na tela
			break;
				
	  }

      
	
}
   } // fim da funcao principal


