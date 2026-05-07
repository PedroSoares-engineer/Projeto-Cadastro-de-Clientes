#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Cliente {
    char nome[100];
    char sexo;
    int idade;
    float salario;
    char email[100];
};

int main() {

    struct Cliente clientes[200];
    int opcao, numClientes = 0;

    do {
        printf("\n===== MENU =====\n");
        printf("1 - Adicionar Cliente\n");
        printf("2 - Visualizar Clientes\n");
        printf("3 - Editar Cliente\n");
        printf("4 - Excluir Cliente\n");
        printf("5 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {

        case 1: {
            if (numClientes >= 200) {
                printf("Limite de clientes atingido!\n");
                break;
            }

            printf("Nome: ");
            scanf(" %[^\n]", clientes[numClientes].nome);

            printf("Email: ");
            scanf("%s", clientes[numClientes].email);

            printf("Sexo (M/F): ");
            scanf(" %c", &clientes[numClientes].sexo);

            printf("Idade: ");
            scanf("%d", &clientes[numClientes].idade);

            printf("Salario: ");
            scanf("%f", &clientes[numClientes].salario);

            numClientes++;

            printf("Cliente cadastrado com sucesso!\n");
            break;
        }

        case 2: {
            if (numClientes == 0) {
                printf("Nenhum cliente cadastrado.\n");
                break;
            }

            printf("\n=== LISTA DE CLIENTES ===\n");

            for (int i = 0; i < numClientes; i++) {
                printf("\nCliente %d\n", i + 1);
                printf("Nome: %s\n", clientes[i].nome);
                printf("Email: %s\n", clientes[i].email);
                printf("Sexo: %c\n", clientes[i].sexo);
                printf("Idade: %d\n", clientes[i].idade);
                printf("Salario: %.2f\n", clientes[i].salario);
            }
            break;
        }

        case 3: {
            char nome[100];
            int encontrado = 0;

            printf("Digite o nome do cliente que deseja editar: ");
            scanf(" %[^\n]", nome);

            for (int i = 0; i < numClientes; i++) {
                if (strcmp(clientes[i].nome, nome) == 0) {

                    printf("Novo nome: ");
                    scanf(" %[^\n]", clientes[i].nome);

                    printf("Novo email: ");
                    scanf("%s", clientes[i].email);

                    printf("Novo sexo (M/F): ");
                    scanf(" %c", &clientes[i].sexo);

                    printf("Nova idade: ");
                    scanf("%d", &clientes[i].idade);

                    printf("Novo salario: ");
                    scanf("%f", &clientes[i].salario);

                    printf("Cliente atualizado com sucesso!\n");
                    encontrado = 1;
                    break;
                }
            }

            if (!encontrado) {
                printf("Cliente nao encontrado.\n");
            }
            break;
        }

        case 4: {
            char nome[100];
            int encontrado = 0;

            printf("Digite o nome do cliente que deseja excluir: ");
            scanf(" %[^\n]", nome);

            for (int i = 0; i < numClientes; i++) {
                if (strcmp(clientes[i].nome, nome) == 0) {

                    for (int j = i; j < numClientes - 1; j++) {
                        clientes[j] = clientes[j + 1];
                    }

                    numClientes--;

                    printf("Cliente excluido com sucesso!\n");
                    encontrado = 1;
                    break;
                }
            }

            if (!encontrado) {
                printf("Cliente nao encontrado.\n");
            }
            break;
        }

        case 5:
            printf("Encerrando o programa...\n");
            break;

        default:
            printf("Opcao invalida!\n");
        }

    } while (opcao != 5);

    return 0;
}