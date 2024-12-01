#include <stdio.h>
#include "pizza.h"
#include "ingredientes.h"
const char* ascii_art =
    "                                   ._\n"
    "                                   ,(  `-.\n"
    "                                 ,': `.   `.\n"
    "                               ,` *   `-.   \\\n"
    "                             ,'  ` :+  = `.  `.\n"
    "                           ,~  (o):  .,   `.  `.\n"
    "                         ,'  ; :   ,(__) x;`.  ;\n"
    "                       ,'  :'  itz  ;  ; ; _,-'\n"
    "                     .'O ; = _' C ; ;'_,_ ;\n"
    "                   ,;  _;   ` : ;'_,-'   i'\n"
    "                 ,` `;(_)  0 ; ','       :\n"
    "               .';6     ; ' ,-'~\n"
    "             ,' Q  ,& ;',-.'\n"
    "           ,( :` ; _,-'~  ;\n"
    "         ,~.`c _','\n"
    "       .';^_,-' ~\n"
    "     ,'_;-''\n"
    "    ,,~\n"
    "    i'\n"
    "    :\n";

void exibirMenu() {
    printf("\n");
    printf("%s", ascii_art);
    printf("\n");
    printf("========== Bem-vindo a Pizzaria generica 1997 ==========\n");
    printf("1. Adicionar Pizza\n");
    printf("2. Visualizar Pizzas\n");
    printf("3. Editar Pizza\n");
    printf("4. Remover Pizza\n");
    printf("5. Registrar Venda de Pizza\n");
    printf("6. Exportar Pizzas\n");
    printf("7. Importar Pizzas\n");
    printf("8. Adicionar Ingrediente\n");
    printf("9. Visualizar Ingredientes\n");
    printf("10. Editar Ingrediente\n");
    printf("11. Remover Ingrediente\n");
    printf("12. Exportar Ingredientes\n");
    printf("13. Importar Ingredientes\n");
    printf("0. Sair\n");
    printf("======================================================\n");
    printf("Escolha uma alternativa: ");
}

int main() {
    Pizza pizzas[limite_maximo_pizzas];
    Ingrediente ingredientes[limite_maximo_ingredientes ];
    int qtdPizzas = 0;
    int qtdIngredientes = 0;
    int opcao;

    do {
        exibirMenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarPizza(pizzas, &qtdPizzas);
                break;
            case 2:
                visualizarPizzas(pizzas, qtdPizzas);
                break;
            case 3:
                editarPizza(pizzas, qtdPizzas);
                break;
            case 4:
                removerPizza(pizzas, &qtdPizzas);
                break;
            case 5:
                venderPizza(pizzas, qtdPizzas, ingredientes, qtdIngredientes);
                break;
            case 6:
                exportarPizzas(pizzas, qtdPizzas, "pizzas.txt");
                break;
            case 7:
                importarPizzas(pizzas, &qtdPizzas, "pizzas.txt");
                break;
            case 8:
                adicionarIngrediente(ingredientes, &qtdIngredientes);
                break;
            case 9:
                visualizarIngredientes(ingredientes, qtdIngredientes);
                break;
            case 10:
                editarIngrediente(ingredientes, qtdIngredientes);
                break;
            case 11:
                removerIngrediente(ingredientes, &qtdIngredientes);
                break;
            case 12:
                exportarIngredientes(ingredientes, qtdIngredientes, "ingredientes.txt");
                break;
            case 13:
                importarIngredientes(ingredientes, &qtdIngredientes, "ingredientes.txt");
                break;
            case 0:
                printf("Saindo do sistema. Buona giornata!!\n");
                break;
            default:
                printf("Animal.\n");
        }
    } while (opcao != 0);

    return 0;
}
