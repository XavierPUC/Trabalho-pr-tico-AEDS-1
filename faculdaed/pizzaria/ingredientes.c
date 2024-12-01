#include <stdio.h>
#include "ingredientes.h"


void adicionarIngrediente(Ingrediente ingredientes[], int *qtd) {
    if (*qtd >= limite_maximo_ingredientes) {
        printf("Limite de ingredientes atingido.\n");
        return;
    }

    Ingrediente novoIngrediente;
    novoIngrediente.id = (*qtd == 0) ? 1 : ingredientes[*qtd - 1].id + 1;

    printf("Digite o nome do ingrediente: ");
    scanf(" %[^\n]", novoIngrediente.nome);

    printf("Digite o preco do ingrediente: ");
    scanf("%f", &novoIngrediente.preco);

    ingredientes[*qtd] = novoIngrediente;
    (*qtd)++;
    printf("Ingrediente adicionado.\n");
}

void visualizarIngredientes(const Ingrediente ingredientes[], int qtd) {
    if (qtd == 0) {
        printf("Nenhum ingrediente cadastrado.\n");
        return;
    }

    for (int i = 0; i < qtd; i++) {
        printf("\n--- Ingrediente ID: %d ---\n", ingredientes[i].id);
        printf("Nome: %s\n", ingredientes[i].nome);
        printf("Preco: %.2f\n", ingredientes[i].preco);
    }
}

void editarIngrediente(Ingrediente ingredientes[], int qtd) {
    if (qtd == 0) {
        printf("Nenhum ingrediente cadastrado.\n");
        return;
    }

    int id, index = -1;
    printf("Digite o ID do ingrediente a ser editado: ");
    scanf("%d", &id);

    for (int i = 0; i < qtd; i++) {
        if (ingredientes[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Ingrediente com ID %d nao encontrado.\n", id);
        return;
    }

    printf("Editando o ingrediente ID %d.\n", id);
    printf("Digite o novo nome do ingrediente: ");
    scanf(" %[^\n]", ingredientes[index].nome);

    printf("Digite o novo preco do ingrediente: ");
    scanf("%f", &ingredientes[index].preco);

    printf("Ingrediente editado.\n");
}

void removerIngrediente(Ingrediente ingredientes[], int *qtd) {
    if (*qtd == 0) {
        printf("Nenhum ingrediente cadastrado.\n");
        return;
    }

    int id, index = -1;
    printf("Digite o ID do ingrediente a ser removido: ");
    scanf("%d", &id);

    for (int i = 0; i < *qtd; i++) {
        if (ingredientes[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Ingrediente com ID %d nao encontrado.\n", id);
        return;
    }

    for (int i = index; i < *qtd - 1; i++) {
        ingredientes[i] = ingredientes[i + 1];
    }

    (*qtd)--;
    printf("Ingrediente removido com sucesso.\n");
}

void exportarIngredientes(const Ingrediente ingredientes[], int qtd, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    for (int i = 0; i < qtd; i++) {
        fprintf(arquivo, "%d;%s;%.2f\n",
                ingredientes[i].id,
                ingredientes[i].nome,
                ingredientes[i].preco);
    }

    fclose(arquivo);
    printf("Ingredientes exportados com sucesso para o arquivo '%s'.\n", nomeArquivo);
}


void importarIngredientes(Ingrediente ingredientes[], int *qtd, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    *qtd = 0;
    while (fscanf(arquivo, "%d;%49[^;];%f\n",
                  &ingredientes[*qtd].id,
                  ingredientes[*qtd].nome,
                  &ingredientes[*qtd].preco) == 3) {
        (*qtd)++;
        if (*qtd >= limite_maximo_ingredientes) {
            printf("Limite máximo de ingredientes atingido.\n");
            break;
        }
    }

    fclose(arquivo);
    printf("Ingredientes importados com sucesso. '%s'.\n", nomeArquivo);
}


