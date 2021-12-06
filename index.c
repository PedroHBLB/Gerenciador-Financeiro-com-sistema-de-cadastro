
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define MAX_CLIENTES 50

/*Criação de uma variavel que armazena os arquivos do usuário em .txt*/
FILE *arquivoUsuario;

typedef struct{
  char nome[50];
  char sobrenome[50];
  char rg[11];
  char cpf[11];
  int ativo;
}Cliente;

/*Chamando todas as funções do código*/
Cliente clientes[MAX_CLIENTES];
void menuPrincipal();
void cadastrar();
void login();
void salario();
void saldo();
void gastos();
void excluirGastos();
void voltar();
void menuLogin();
void excluir();
void inserirCliente();
void sair();

int main() {
  menuPrincipal();
  return 0;
}

void sucesso(){
  system("clear");
  printf("Sucesso! Operação realizada corretamente!");
}

/*Função do menu principal do código*/
void menuPrincipal(){
  int op;
  do{
    system("clear");
    printf("\n");
    printf("\t\t Gerenciador Financeiro\n");
    printf("\t\t======================================\n");
    printf("\t\t|   1 - Cadastrar                    |\n");
    printf("\t\t|   2 - Login                        |\n");
    printf("\t\t|   3 - Excluir Cliente              |\n");
    printf("\t\t|   4 - Sair                         |\n");
    scanf("%d", &op);
    getchar();
    switch(op){
      case 1:
        fflush(stdin);
        cadastrar();
      break;

      case 2:
      system("clear");
        login();
      break;

      case 3:
        excluir();
      break;
      
      case 4:
        sair();
      break;

      default:
        printf("\t\t\tNenhumas das opções selecionadas\n");

    }
    getchar();
  }while(op != 4);

}
/*Função de cadastro de usuário*/
void cadastrar(){
  char nome[50];
  char sobrenome[50];
  char rg[50];
  char cpf[50];
  int op;
  
  do{
    system("clear");
    printf("\nNome: ");
    fgets(nome,sizeof(nome),stdin);
    printf("\nSobrenome: ");
    scanf("%s",sobrenome);
    printf("\nRG: ");
    scanf("%s",rg);
    printf("\nCPF: ");
    scanf("%s",cpf);
    sucesso();
    for (int i = 0; i < MAX_CLIENTES; ++i){
      if(clientes[i].ativo == 0){
        strcpy(clientes[i].nome, nome);
        strcpy(clientes[i].sobrenome, sobrenome);
        strcpy(clientes[i].rg, rg);
        strcpy(clientes[i].cpf, cpf);
        clientes[i].ativo = 1;
        break;
      }
    }
    printf("\n1 - Recadastrar\n0 - Sair\n");
    scanf("%d", &op);
    getchar();
  }while(op != 0);

  /*Arquiva o nome, sobrenome, rg e cpf do usuário*/
  arquivoUsuario = fopen("arquivosUsuario.txt","w");
  fprintf(arquivoUsuario,"%s",nome);
  fclose(arquivoUsuario);
  arquivoUsuario = fopen("arquivosUsuario.txt","a");
  fprintf(arquivoUsuario,"%s\n",sobrenome);
  fclose(arquivoUsuario);
  arquivoUsuario = fopen("arquivosUsuario.txt","a");
  fprintf(arquivoUsuario,"%s\n",rg);
  fclose(arquivoUsuario);
  arquivoUsuario = fopen("arquivosUsuario.txt","a");
  fprintf(arquivoUsuario,"%s\n",cpf);
  fclose(arquivoUsuario);
}
/*Função de Login do usuário*/
void login(){
  /*Variável arquivoUsuario ira ler "r" o que está dentro do arquivo .txt*/
  arquivoUsuario = fopen("arquivosUsuario.txt","r");
  
  char nomeUsuario[20], sobrenomeUsuario[50], rgUsuario[9], cpfUsuario[9];
  char nome[20], sobrenome[50], rg[11], cpf[11];

  printf("\nNOME: ");
  scanf("%s", nome);
  printf("\nSOBRENOME: ");
  scanf("%s", sobrenome);
  printf("\nRG: ");
  scanf("%s", rg);
  printf("\nCPF: ");
  scanf("%s", cpf);
  
    fscanf(arquivoUsuario,"%s", nomeUsuario);
    fscanf(arquivoUsuario,"%s", sobrenomeUsuario);
    fscanf(arquivoUsuario,"%s", rgUsuario);
    fscanf(arquivoUsuario,"%s", cpfUsuario);              
  
  fclose(arquivoUsuario);  

/*Strcmp ira comparar o que foi digitado com o que está no arquivoUsuario e ver se bate com o que está lá por meio do número de caracteres*/
 if((strcmp(nome, nomeUsuario)==0)&&(strcmp(sobrenome, sobrenomeUsuario)==0)&&(strcmp(rg, rgUsuario)==0)&&(strcmp(cpf, cpfUsuario)==0)){
      printf("Usuário correto!");
      return menuLogin();
    }else{
      printf("Usuário Incorreto");
      return menuPrincipal();
    }

}
/*Menu de login do usuário*/
  void menuLogin(){
    system("clear");
    int op;
    do{
      system("clear");
      printf("\n");
      printf("\t\t Gerenciador Financeiro\n");
      printf("\t\t======================================\n");
      printf("\t\t|   1 - Salário                    |\n");
      printf("\t\t|   2 - Saldo                      |\n");
      printf("\t\t|   3 - Gastos                     |\n");
      printf("\t\t|   4 - Excluir Gastos             |\n");
      printf("\t\t|   5 - Voltar                     |\n");
      scanf("%d", &op);
      getchar();
      switch(op){
        case 1:
          fflush(stdin);
          salario();
        break;

        case 2:
          saldo();
        break;

        case 3:
          gastos();
        break;
        
        case 4:
          excluirGastos();
        break;

        case 5:
          voltar();
          return menuPrincipal();
        break;

        default:
          printf("\t\t\tNenhumas das opções selecionadas\n");

      }
      getchar();
    }while(op != 5);
  
  }

/*Criação de uma variavel que armazena os arquivos de gastos em .txt*/
FILE *arquivoGastos;

/*Função onde ele pede o salário do usuário*/
void salario(){
  system("clear");
  char salario[50];
  printf("Digite o seu salário: ");
  scanf("%s", salario);
  arquivoGastos = fopen("arquivoGastos.txt","w");
  fprintf(arquivoGastos,"\nSalário: %s\n",salario);
  fclose(arquivoGastos);
}
/*Função onde ele pede o saldo do usuário*/
void saldo(){
  system("clear");
  char saldo[50];
  printf("Digite o seu saldo: ");
  scanf("%s", saldo);
  arquivoGastos = fopen("arquivoGastos.txt","a");
  fprintf(arquivoGastos,"\nSaldo: %s\n",saldo);
  fclose(arquivoGastos);
}

char moradia[50], estudos[50], transporte[50], alimentacao[50], trabalho[50], aluguel[50],agua[50],luz[50],internet[50],gas[50],matricula[50],mensalidade[50],material[50],dataAluguel[50],dataAgua[50],dataLuz[50],dataInternet[50], dataGas[50], dataMensalidade[50], dataMatricula[50],dataMaterial[50],dataArq[50];

// Criamos as variaveis dos gastos, e suas datas
void gastos(){
  system("clear");

// Solicitando os valores e pritando eles
  printf("======================");
  printf("Digite o seus gastos");
  printf("======================");
  printf("\nMoradia");

  printf("\n\nAluguel: ");
  scanf("%s",aluguel);
  arquivoGastos = fopen("arquivoGastos.txt","a");
  fprintf(arquivoGastos,"\nAluguel: %s",aluguel);
  fclose(arquivoGastos);
  
  printf("Data do pagamento do Aluguel: ");
  scanf("%s", dataAluguel);
  arquivoGastos = fopen("arquivoGastos.txt","a");
  fprintf(arquivoGastos,"\nData do Aluguel: %s",dataAluguel);
  fclose(arquivoGastos);
  
  printf("\nÁgua: ");
  scanf("%s",agua);
  arquivoGastos = fopen("arquivoGastos.txt","a");
  fprintf(arquivoGastos,"\n\nÁgua: %s",agua);
  fclose(arquivoGastos);

  printf("Data do pagamento de Agua: ");
  scanf("%s",dataAgua);
  arquivoGastos = fopen("arquivoGastos.txt","a");
  fprintf(arquivoGastos,"\nData da Água: %s",dataAgua);
  fclose(arquivoGastos);

  printf("\nLuz: ");
  scanf("%s",luz);
  arquivoGastos = fopen("arquivoGastos.txt","a");
  fprintf(arquivoGastos,"\n\nLuz: %s",luz);
  fclose(arquivoGastos);
  
  printf("Data do pagamento da Luz: ");
  scanf("%s",dataLuz);
  arquivoGastos = fopen("arquivoGastos.txt","a");
  fprintf(arquivoGastos,"\nData da Luz: %s",dataLuz);
  fclose(arquivoGastos);

  printf("\nInternet: ");
  scanf("%s",internet);
  arquivoGastos = fopen("arquivoGastos.txt","a");
  fprintf(arquivoGastos,"\n\nInternet: %s",internet);
  fclose(arquivoGastos);

  printf("Data do pagamento da internet: ");
  scanf("%s",dataInternet);
  arquivoGastos = fopen("arquivoGastos.txt","a");
  fprintf(arquivoGastos,"\nData da Internet: %s",dataInternet);
  fclose(arquivoGastos);
    
  printf("\nGás: ");
  scanf("%s",gas);
  arquivoGastos = fopen("arquivoGastos.txt","a");
  fprintf(arquivoGastos,"\n\nGás: %s",gas);
  fclose(arquivoGastos);
  
  printf("Data do pagamento do Gás: ");
  scanf("%s",dataGas);
  arquivoGastos = fopen("arquivoGastos.txt","a");
  fprintf(arquivoGastos,"\nData do Gás: %s",dataGas);
  fclose(arquivoGastos);

  printf("\n====================================\n");

  printf("\nEstudos");

  printf("\n\nMatricula: ");
  scanf("%s",matricula);
  arquivoGastos = fopen("arquivoGastos.txt","a");
  fprintf(arquivoGastos,"\nMatricula: %s",matricula);
  fclose(arquivoGastos);


  printf("Data do pagamento da Matricula: ");
  scanf("%s",dataMatricula);
  arquivoGastos = fopen("arquivoGastos.txt","a");
  fprintf(arquivoGastos,"\nData da Matricula: %s",dataMatricula);
  fclose(arquivoGastos);

  
  printf("\n\nMensalidade: ");
  scanf("%s",mensalidade);
  arquivoGastos = fopen("arquivoGastos.txt","a");
  fprintf(arquivoGastos,"\nMensalidade: %s",mensalidade);
  fclose(arquivoGastos);

  printf("Data do pagamento da Mensalidade: ");
  scanf("%s",dataMensalidade);
  arquivoGastos = fopen("arquivoGastos.txt","a");
  fprintf(arquivoGastos,"\nData da Mensalidade: %s",dataMensalidade);
  fclose(arquivoGastos);

  printf("\n\nMaterial: ");
  scanf("%s",material);
  arquivoGastos = fopen("arquivoGastos.txt","a");
  fprintf(arquivoGastos,"\nMaterial: %s",material);
  fclose(arquivoGastos);
  

  printf("Data do pagamento d Material: ");
  scanf("%s",dataMaterial);
  arquivoGastos = fopen("arquivoGastos.txt","a");
  fprintf(arquivoGastos,"\nData do Material: %s",dataMaterial);
  fclose(arquivoGastos);

  printf("\n====================================\n");

  printf("Transporte: ");
  scanf("%s", transporte);
  arquivoGastos = fopen("arquivoGastos.txt","a");
  fprintf(arquivoGastos,"\n\nTransporte: %s",transporte);
  fclose(arquivoGastos);

  printf("Alimentação: ");
  scanf("%s", alimentacao);
  arquivoGastos = fopen("arquivoGastos.txt","a");
  fprintf(arquivoGastos,"\n\nAlimentação: %s",alimentacao);
  fclose(arquivoGastos);
  
  printf("Trabalho: ");
  scanf("%s", trabalho);
  arquivoGastos = fopen("arquivoGastos.txt","a");
  fprintf(arquivoGastos,"\n\nTrabalho: %s",trabalho);
  fclose(arquivoGastos);

  printf("Data da arquivação: ");
  scanf("%s", dataArq);
  arquivoGastos = fopen("arquivoGastos.txt","a");
  fprintf(arquivoGastos, "\n\nData da Arquivação: %s", dataArq);
  fclose(arquivoGastos);
}
void voltar(){
  system("clear");
  printf("Voltar!");
}

// Excluir o cadastro do usuario
void excluir(){
  system("clear");
  int resposta;
  resposta = 1;
  printf("Você deseja excluir seu cadastro?  [1] = Excluir [0] = Não excluir\n");
  scanf("%d", &resposta);
  if(resposta == 1){
    printf("Ok, excluindo...");
    remove("arquivosUsuario.txt");
  }else{
    printf("Não será excluido");
    system("clear");
  } 
}

// Excluir os gastos do usuario
void excluirGastos(){
  system("clear");
  int resposta;
  resposta = 1;
  printf("Você deseja excluir seus gastos? [1] = Excluir [0] = Não excluir\n");
  scanf("%d", &resposta);
  if(resposta == 1){
    printf("Ok, excluindo...");
    remove("arquivoGastos.txt");
  }else{
    printf("Não será excluido");
    system("clear");
  }
}

void sair(){
  return menuPrincipal();
}