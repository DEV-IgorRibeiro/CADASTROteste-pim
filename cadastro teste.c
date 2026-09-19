// cadastro teste
#include <stdio.h>
#include <string.h>

int main() {

    char nome[10][50];
    char email[10][100];
    char telefone[10][20];
    char senha[10][50];
    int ids[10];
    int quantidade = 0;
    int opcao = 0;

    char emailLogin[100];
    char senhaLogin[50];


    while (opcao != 3) {

    printf("\n===== SISTEMA =====\n");
    printf("1 - Cadastrar\n");
    printf("2 - LOGIN\n");
    printf("3 - Sair\n");

    scanf("%d", &opcao);

   if (opcao == 1) {
        printf("digite seu nome\n");
            scanf(" %49[^\n]", nome[quantidade]);

        ids[quantidade] = quantidade + 1;

        //printf("Seu ID e: %d\n", ids[quantidade]);
    
        printf("digite seu email\n");
            scanf(" %99s", email[quantidade]);

        printf("digite seu telefone\n");
            scanf("%19s", telefone[quantidade]);

        printf("criar uma senha\n");
            scanf("%49s", senha[quantidade]);
   
    quantidade++;

    printf("\n===== DADOS CADASTRADO =====\n");

    printf("nome: %s\n", nome[quantidade - 1]);
    printf("email: %s\n", email[quantidade - 1]);
    printf("telefone: %s\n", telefone[quantidade - 1]);
   }
    // login

    else if (opcao == 2) {
        printf("\n===== LOGIN =====\n");

        printf("digite seu email:\n");
        scanf("%s", emailLogin);

        printf("digite sua senha:\n");
        scanf("%s", senhaLogin);
    
    // verificar login
        int loginValido = 0;

        for (int i = 0; i < quantidade; i++) {
    
            if(strcmp(emailLogin, email[i]) == 0 &&
            strcmp(senhaLogin, senha[i]) == 0) {
        
            loginValido = 1;

            printf("\nLogin realizado com sucesso!\n");
        
        
            }
        }
    
        if (loginValido == 0) {
            printf("\nEmail ou senha incorretos!\n");
        }
    }
    
    else if (opcao == 3) {
            printf("\nSaindo do sistema...\n");
        }else {
                 printf("\nOpção inválida!\n");
    }
  
    }
    
    return 0;
}