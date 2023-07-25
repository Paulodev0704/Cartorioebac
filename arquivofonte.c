#include <stdio.h> // de cominucacao com o usuario
#include <stdlib.h>//biblioteca de alocacao de espaco em memoria
#include <locale.h>//biblioteca de alocacoes de texto popr regiao
#include <string.h>//biblioteca responsavel pelas strinh

int registro()//funcao responsavel por cadastras os usuarios no sistema
{
    //inicio criacao de variaveis
    char arquivo[40];
    char cpf [40];
    char nome[40];
    char sobrenome[40];
    char cargo [40];

    printf("Digite o CPF a ser cadastrado: ");// coletando informacao do usuario
    scanf("%s",cpf);//%s refere-se a strig

    strcpy(arquivo,cpf); //Responsavel por copiar os valores da str

    FILE *file;//cria o arquivo
    file = fopen(arquivo, "w");// cria o arquinvo
    fprintf(file,cpf);//salvo o valor da variavel
    fclose(file);//fecha o arquivo

    file = fopen(arquivo,"a");//adicionando virgulas                     
    fprintf(file,",");
    fclose(file);

    printf("Digite o nome a ser cadastrado: ");
    scanf("%s",nome);

    file = fopen(arquivo, "a");
    fprintf(file,nome);
    fclose(file);

    file = fopen(arquivo,"a");
    fprintf(file,",");
    fclose(file);

    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s",sobrenome);

    file = fopen(arquivo, "a");
    fprintf(file,sobrenome);
    fclose(file);

    file = fopen(arquivo,"a");
    fprintf(file,",");
    fclose(file);

    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s",cargo);

    file = fopen(arquivo,"a");
    fprintf(file,cargo);
    fclose(file);

    system("pause");

}

int consulta()
{
    setlocale(LC_ALL, "Portuguese");//definindo a linguagem

    char cpf[40];
    char conteudo[200];

    printf("Digite o Cpf a ser consultado: ");
    scanf("%s",cpf);

    FILE *file;
    file = fopen(cpf,"r");

    if(file == NULL)
    {
        printf("Nao foi possivel abrir o arquivo, nao localizado!.\n");
    }

    while(fgets(conteudo, 200, file) != NULL)
    {
        printf("\nEssas sao as informacoes do usuario: ");
        printf("%s", conteudo);
        printf("\n\n");
    }

    system("pause");

}



int deletar () 
{
    char cpf[40];

    printf("Digite o CPF a ser deletado: ");
    scanf("%s",cpf);

    remove(cpf);        
            
    FILE *file;
    file = fopen(cpf,"r");

    if (file == NULL)
    {
        printf("O usuario nao se encontra no sistema. \n");
        system("pause");
    }

}

int main(int argc, char const *argv[])
{
    int opcao = 0; //definindo variaveis
    int laco = 1; 
    for(laco = 1;laco = 1;){

        system("cls");

        setlocale(LC_ALL, "Portuguese"); //definindo a linguagem

        printf("### Cartorio da EBAC ###\n\n"); //inicio do menu
        printf("Escolha a opcao desejada do menu: \n\n");
        printf("\t1 - Registrar Nomes\n");
        printf("\t2 - Consultar Nomes\n");
        printf("\t3 - Deletar Nomes\n\n");
        printf("\t4 - Sair do sistema\n\n");
        printf("Digite uma opcao: "); // fim do menu

        scanf("%d", &opcao);

        system("cls");


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
        printf("Essa opcao nao esta disponivel\n");
            system("pause");
            break;
        }
    }    
}


