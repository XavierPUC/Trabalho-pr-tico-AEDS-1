#include "pizza.h"

void adicionarPizza(Pizza pizzas[], int *qtd) {
    if (*qtd >= limite_maximo_pizzas) {
        printf("Limite de pizzas atingido.\n");
        return;
    }

    Pizza novaPizza;
    novaPizza.id = (*qtd == 0) ? 1 : pizzas[*qtd - 1].id + 1;

    printf("Digite o nome da pizza: ");
    scanf(" %[^\n]", novaPizza.nome);

    printf("Digite o tamanho da pizza (P, M, G): ");
    scanf(" %c", &novaPizza.tamanho);

    printf("Digite o preco da pizza: ");
    scanf("%f", &novaPizza.preco);

    printf("Quantos ingredientes a pizza tem? ");
    scanf("%d", &novaPizza.qtd_ingredientes);

    for (int i = 0; i < novaPizza.qtd_ingredientes; i++) {
        printf("Digite o ID do ingrediente %d: ", i + 1);
        scanf("%d", &novaPizza.ingredientes[i].id);

        printf("Digite o nome do ingrediente %d: ", i + 1);
        scanf(" %[^\n]", novaPizza.ingredientes[i].nome);
    }

    pizzas[*qtd] = novaPizza;
    (*qtd)++;
    printf("Pizza adicionada.\n");
}

void visualizarPizzas(const Pizza pizzas[], int qtd) {
    if (qtd == 0) {
        printf("Nenhuma pizza cadastrada.\n");
        return;
    }

    for (int i = 0; i < qtd; i++) {
        printf("\n--- Pizza ID: %d ---\n", pizzas[i].id);
        printf("Nome: %s\n", pizzas[i].nome);
        printf("Tamanho: %c\n", pizzas[i].tamanho);
        printf("Preco: %.2f\n", pizzas[i].preco);

        printf("Ingredientes:\n");
        for (int j = 0; j < pizzas[i].qtd_ingredientes; j++) {
            printf("  %d. %s\n", pizzas[i].ingredientes[j].id, pizzas[i].ingredientes[j].nome);
        }
    }
}

void editarPizza(Pizza pizzas[], int qtd) {
    if (qtd == 0) {
        printf("Nenhuma pizza cadastrada.\n");
        return;
    }

    int id, index = -1;
    printf("Digite o ID da pizza a ser editada: ");
    scanf("%d", &id);

    for (int i = 0; i < qtd; i++) {
        if (pizzas[i].id == id) {
            index = i;
            i = qtd;
        }
    }

    if (index == -1) {
        printf("Pizza com ID %d nao encontrada.\n", id);
        return;
    }

    printf("Editando a pizza ID %d.\n", id);
    printf("Digite o novo nome da pizza: ");
    scanf(" %[^\n]", pizzas[index].nome);

    printf("Digite o novo tamanho da pizza (P, M, G): ");
    scanf(" %c", &pizzas[index].tamanho);

    printf("Digite o novo preco da pizza: ");
    scanf("%f", &pizzas[index].preco);

    printf("Quantos ingredientes a pizza vai ter? ");
    scanf("%d", &pizzas[index].qtd_ingredientes);

    for (int i = 0; i < pizzas[index].qtd_ingredientes; i++) {
        printf("Digite o ID do ingrediente %d: ", i + 1);
        scanf("%d", &pizzas[index].ingredientes[i].id);

        printf("Digite o nome do ingrediente %d: ", i + 1);
        scanf(" %[^\n]", pizzas[index].ingredientes[i].nome);
    }

    printf("Pizza editada.\n");
}


void removerPizza(Pizza pizzas[], int *qtd) {
    if (*qtd == 0) {
        printf("Nenhuma pizza cadastrada.\n");
        return;
    }

    int id, index = -1;
    printf("Digite o ID da pizza a ser removida: ");
    scanf("%d", &id);

    for (int i = 0; i < *qtd; i++) {
        if (pizzas[i].id == id) {
            index = i;
            i = *qtd;
        }
    }

    if (index == -1) {
        printf("Pizza com ID %d nao encontrada.\n", id);
        return;
    }

    for (int i = index; i < *qtd - 1; i++) {
        pizzas[i] = pizzas[i + 1];
    }

    (*qtd)--;
    printf("Pizza removida.\n");
}

void venderPizza(Pizza pizzas[], int qtdPizzas, Ingrediente ingredientes[], int qtdIngredientes) {
    if (qtdPizzas == 0) {
        printf("Nenhuma pizza disponível no cardapio.\n");
        return;
    }

    printf("Selecione uma pizza do cardapio:\n");
    visualizarPizzas(pizzas, qtdPizzas);

    int pizzaId;
    printf("Digite o ID da pizza que deseja vender: ");
    scanf("%d", &pizzaId);

    Pizza *pizzaSelecionada = NULL;
    for (int i = 0; i < qtdPizzas; i++) {
        if (pizzas[i].id == pizzaId) {
            pizzaSelecionada = &pizzas[i];
            break;
        }
    }

    if (pizzaSelecionada == NULL) {
        printf("Pizza nao encontrada.\n");
        return;
    }

    printf("Pizza selecionada: %s (Tamanho: %c, Preco Base: %.2f)\n",
           pizzaSelecionada->nome, pizzaSelecionada->tamanho, pizzaSelecionada->preco);

    float precoFinal = pizzaSelecionada->preco;

    printf("Deseja adicionar ingredientes extras? (1 - Sim, 0 - Nao): ");
    int adicionar;
    scanf("%d", &adicionar);

    if (adicionar) {
        printf("Ingredientes disponíveis:\n");
        visualizarIngredientes(ingredientes, qtdIngredientes);

        int qtdExtras;
        printf("Quantos ingredientes extras deseja adicionar? ");
        scanf("%d", &qtdExtras);

        for (int i = 0; i < qtdExtras; i++) {
            int ingredienteId;
            printf("Digite o ID do ingrediente extra %d: ", i + 1);
            scanf("%d", &ingredienteId);

            Ingrediente *ingredienteExtra = NULL;
            for (int j = 0; j < qtdIngredientes; j++) {
                if (ingredientes[j].id == ingredienteId) {
                    ingredienteExtra = &ingredientes[j];
                    break;
                }
            }

            if (ingredienteExtra != NULL) {
                printf("Ingrediente adicionado: %s (Preco: %.2f)\n", ingredienteExtra->nome, ingredienteExtra->preco);
                precoFinal += ingredienteExtra->preco;
            } else {
                printf("Ingrediente com ID %d nao encontrado.\n", ingredienteId);
            }
        }
    }

    printf("Preco final da pizza: %.2f\n", precoFinal);
    printf("Venda registrada.\n");
}

void exportarPizzas(const Pizza pizzas[], int qtd, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    for (int i = 0; i < qtd; i++) {
        fprintf(arquivo, "%d;%s;%c;%.2f;%d;",
                pizzas[i].id,
                pizzas[i].nome,
                pizzas[i].tamanho,
                pizzas[i].preco,
                pizzas[i].qtd_ingredientes);

        for (int j = 0; j < pizzas[i].qtd_ingredientes; j++) {
            fprintf(arquivo, "%d,%s,%.2f",
                    pizzas[i].ingredientes[j].id,
                    pizzas[i].ingredientes[j].nome,
                    pizzas[i].ingredientes[j].preco);

            if (j < pizzas[i].qtd_ingredientes - 1) {
                fprintf(arquivo, "|");
            }
        }
        fprintf(arquivo, "\n");
    }

    fclose(arquivo);
    printf("Pizzas exportadas com sucesso '%s'.\n", nomeArquivo);
}


void importarPizzas(Pizza pizzas[], int *qtd, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    *qtd = 0; //
    while (*qtd < limite_maximo_pizzas && !feof(arquivo)) {
        Pizza novaPizza;
        char linha[512];
        if (fgets(linha, sizeof(linha), arquivo) == NULL) break;

        char *token = strtok(linha, ";");
        novaPizza.id = atoi(token);

        token = strtok(NULL, ";");
        strcpy(novaPizza.nome, token);

        token = strtok(NULL, ";");
        novaPizza.tamanho = token[0];

        token = strtok(NULL, ";");
        novaPizza.preco = atof(token);

        token = strtok(NULL, ";");
        novaPizza.qtd_ingredientes = atoi(token);

        for (int i = 0; i < novaPizza.qtd_ingredientes; i++) {
            if (i == 0) token = strtok(NULL, "|");
            else token = strtok(NULL, "|");

            Ingrediente novoIngrediente;
            sscanf(token, "%d,%49[^,],%f",
                   &novoIngrediente.id,
                   novoIngrediente.nome,
                   &novoIngrediente.preco);

            novaPizza.ingredientes[i] = novoIngrediente;
        }

        pizzas[*qtd] = novaPizza;
        (*qtd)++;
    }

    fclose(arquivo);
    printf("Pizzas importadas com sucesso '%s'.\n", nomeArquivo);
}

