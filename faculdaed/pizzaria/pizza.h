#ifndef PIZZA_H
#define PIZZA_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ingredientes.h"

#define limite_maximo_pizzas 20

typedef struct {
    int id;
    char nome[50];
    char tamanho;
    float preco;
    Ingrediente ingredientes[10];
    int qtd_ingredientes;
} Pizza;

void adicionarPizza(Pizza pizzas[], int *qtd);
void visualizarPizzas(const Pizza pizzas[], int qtd);
void editarPizza(Pizza pizzas[], int qtd);
void removerPizza(Pizza pizzas[], int *qtd);
void venderPizza(Pizza pizzas[], int qtdPizzas, Ingrediente ingredientes[], int qtdIngredientes);
void exportarPizzas(const Pizza pizzas[], int qtd, const char *nomeArquivo);
void importarPizzas(Pizza pizzas[], int *qtd, const char *nomeArquivo);

#endif
