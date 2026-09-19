// cadastro teste
#include <stdio.h>
#include <string.h>

int main() {

    char nome[10][50];
    char email[10][100];
    int telefone[10][11];
    char senha[10][50];
    int ids[10];
    int quantidade = 0;

    char emailLogin[100];
    char senhaLogin[50];

    printf("digite seu nome\n");
    scanf("%[^\n]", nome[quantidade]);

    ids[quantidade] = quantidade + 1;

    printf("Seu ID e: %d\n", ids[quantidade]);

    printf("digite seu email\n");
    scanf("%s", email[quantidade]);

    printf("digite seu telefone\n");
    scanf("%d", &telefone[quantidade]);

    printf("criar uma senha\n");
    scanf("%s", senha[quantidade]);

    quantidade++;

    printf("\n===== DADOS CADASTRADO =====\n");

    printf("nome: %s\n", nome[0]);
    printf("email: %s\n", email[0]);
    printf("telefone: %d\n", telefone[0]);

    // login

    printf("\n===== LOGIN =====\n");

    printf("digite seu email:\n");
    scanf("%s", emailLogin);

    printf("digite sua senha:\n");
    scanf("%s", senhaLogin);

    // verificar login

    if (strcmp(emailLogin, email[0]) == 0 &&
        strcmp(senhaLogin, senha[0]) == 0) {

        printf("\nLogin realizado com sucesso!\n");
    }
    else {
        printf("\nEmail ou senha incorretos!\n");
    }

    return 0;
}