#ifndef INGREDIENTES_H
#define INGREDIENTES_H

#define limite_maximo_ingredientes 30


typedef struct {
    int id;
    char nome[50];
    float preco;
} Ingrediente;

void adicionarIngrediente(Ingrediente *ingredientes, int *numIngredientes);
void visualizarIngredientes(const Ingrediente *ingredientes, int numIngredientes);
void editarIngrediente(Ingrediente *ingredientes, int index);
void removerIngrediente(Ingrediente *ingredientes, int *numIngredientes);
void exportarIngredientes(const Ingrediente *ingredientes, int numIngredientes, const char *arquivo);
void importarIngredientes(Ingrediente *ingredientes, int *numIngredientes, const char *arquivo);

#endif
