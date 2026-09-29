// cadastro teste
#include <stdio.h>
#include <string.h>

int main() {
//char
    char nome[10][50];
    char email[10][100];
    char telefone[10][20];
    char senha[10][50];
    char data[10][11];
    char horario[10][6];

//int
    int ids[10];
    int quantidade = 0;
    int opcao = 0;
    int agendamento[10] = {0};
    

    char emailLogin[100];
    char senhaLogin[50];

    while (opcao != 3) {
        printf("\n===== SISTEMA =====\n");
        printf("1 - Cadastrar\n");
        printf("2 - LOGIN\n");
        printf("3 - Sair\n");

        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida!\n");
            return 1;
        }

        if (opcao == 1) {
            if (quantidade >= 10) {
                printf("Limite de cadastros atingido!\n");
                continue;
            }

            printf("Digite seu nome:\n");
            scanf(" %49[^\n]", nome[quantidade]);

            ids[quantidade] = quantidade + 1;

            do{
            printf("Digite seu email:\n");
            scanf(" %99s", email[quantidade]);
            int posicaoarroba = -1;
            for(int i; i < strlen(email[quantidade]); i++){
                if (email[quantidade][i] == '@') {
                    posicaoarroba = i;
                }
            }
            if (strchr(email[quantidade], '@') == NULL) {
                printf("Faltou o @ no seu email.\n");
            }
        }while (strchr(email[quantidade], '@') == NULL);

            int telefonevalido = 1;

            do {
                telefonevalido = 1;
                printf("Digite seu telefone:\n");
                scanf(" %19s", telefone[quantidade]);
                int tamanhotelefone = strlen(telefone[quantidade]);
                    if (tamanhotelefone == 10 || tamanhotelefone == 11){
                        printf("tamanho correto\n");
                    } else {
                        telefonevalido = 0;
                        printf("O telefone deve ter 10 ou 11 digitos.\n");
                    }
            

            for (int i = 0; i < tamanhotelefone; i++){
                if (telefone[quantidade][i] < '0' ||
                    telefone[quantidade][i] > '9') {
                    telefonevalido = 0;
                    printf("Caractere invalido!\n");
                }

            }
        } while (telefonevalido == 0);
        
            printf("Crie uma senha:\n");
            scanf(" %49s", senha[quantidade]);

            quantidade++;

            printf("\n===== DADOS CADASTRADOS =====\n");
            printf("ID: %d\n", ids[quantidade - 1]);
            printf("Nome: %s\n", nome[quantidade - 1]);
            printf("Email: %s\n", email[quantidade - 1]);
            printf("Telefone: %s\n", telefone[quantidade - 1]);

        } else if (opcao == 2) {
            printf("\n===== LOGIN =====\n");

            printf("Digite seu email:\n");
            scanf(" %99s", emailLogin);

            printf("Digite sua senha:\n");
            scanf(" %49s", senhaLogin);

            int loginValido = 0;
            int usuariologado = -1;

            for (int i = 0; i < quantidade; i++) {
                if (strcmp(emailLogin, email[i]) == 0 &&
                    strcmp(senhaLogin, senha[i]) == 0) {

                    loginValido = 1;
                    usuariologado = i;

                    printf("\nLogin realizado com sucesso!\n");
                    int opcaoUsuario = 0;

                    while (opcaoUsuario != 4) {
                        printf("\n===== DADOS DO USUARIO =====\n");
                        printf("1 - Criar agendamento\n");
                        printf("2 - Ver agendamento\n");
                        printf("3 - Excluir agendamento\n");
                        printf("4 - Sair da conta\n");

                        if (scanf("%d", &opcaoUsuario) != 1) {
                            printf("Entrada invalida!\n");
                            return 1;
                        }

                        if (opcaoUsuario == 1) {
                            if (agendamento[usuariologado] == 0) {
                                printf("Digite a data (DD/MM/AAAA):\n");
                                scanf( "%10s", data[usuariologado]);
                                printf("Digite um horario\n");
                                scanf("%5s", horario[usuariologado]);
                                agendamento[usuariologado] = 1;
                                printf("Agendamento criado!\n");
                            } else {
                                printf("Voce ja possui um agendamento!\n");
                            }
                        } else if (opcaoUsuario == 2) {
                            if (agendamento[usuariologado] == 1) {
                                printf("seu agendamento e: %s\nas: %s\n", data[usuariologado], horario[usuariologado]);
                            } else {
                                printf("voce nao possui um agendamento\n");
                            }
                        } else if (opcaoUsuario == 3) {
                            if (agendamento[usuariologado] == 1) {
                                agendamento[usuariologado] = 0;
                                printf("agendamento excluido com sucesso\n");
                            }
                        }
                    }

                    break; // encerra a busca
                }
            }

            if (loginValido == 0) {
                printf("\nEmail ou senha incorretos!\n");
            }

        } else if (opcao == 3) {
            printf("\nSaindo do sistema...\n");
        } else {
            printf("\nOpcao invalida!\n");
        }
    }

    return 0;
}