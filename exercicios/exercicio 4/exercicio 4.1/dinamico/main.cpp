#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* TipoItem;

typedef struct {
    int arestanula;
    int maxvertices;
    int numvertices;
    TipoItem* vertices;
    int** matrizadjacencias;
} Grafo;

Grafo* criarGrafo(int max, int valorarestanula) {
    Grafo* grafo = (Grafo*)malloc(sizeof(Grafo));
    grafo->numvertices = 0;
    grafo->maxvertices = max;
    grafo->arestanula = valorarestanula;

    grafo->vertices = (TipoItem*)malloc(max * sizeof(TipoItem));

    grafo->matrizadjacencias = (int**)malloc(max * sizeof(int*));
    for (int i = 0; i < max; i++) {
        grafo->matrizadjacencias[i] = (int*)malloc(max * sizeof(int));
    }

    for (int i = 0; i < max; i++) {
        for (int j = 0; j < max; j++) {
            grafo->matrizadjacencias[i][j] = grafo->arestanula;
        }
    }

    return grafo;
}

void destruirGrafo(Grafo* grafo) {
    free(grafo->vertices);
    for (int i = 0; i < grafo->maxvertices; i++) {
        free(grafo->matrizadjacencias[i]);
    }
    free(grafo->matrizadjacencias);
    free(grafo);
}

int obterindice(Grafo* grafo, TipoItem item) {
    int indice = 0;
    while (strcmp(item, grafo->vertices[indice]) != 0) {
        indice++;
    }
    return indice;
}

int estacheio(Grafo* grafo) {
    return (grafo->numvertices == grafo->maxvertices);
}

void inserirvertice(Grafo* grafo, TipoItem item) {
    if (estacheio(grafo)) {
        printf("O numero maximo de vertices foi alcancado!\n");
    } else {
        grafo->vertices[grafo->numvertices] = strdup(item);
        grafo->numvertices++;
    }
}

void inseriraresta(Grafo* grafo, TipoItem Nosaida, TipoItem Noentrada, int peso) {
    int linha = obterindice(grafo, Nosaida);
    int coluna = obterindice(grafo, Noentrada);

    grafo->matrizadjacencias[linha][coluna] = peso;
    grafo->matrizadjacencias[coluna][linha] = peso; // Remover se for direcionado
}

int obterpeso(Grafo* grafo, TipoItem Nosaida, TipoItem Noentrada) {
    int linha = obterindice(grafo, Nosaida);
    int coluna = obterindice(grafo, Noentrada);
    return (grafo->matrizadjacencias[linha][coluna]);
}

int obtergrau(Grafo* grafo, TipoItem item) {
    int linha = obterindice(grafo, item);
    int grau = 0;
    for (int i = 0; i < grafo->maxvertices; i++) {
        if (grafo->matrizadjacencias[linha][i] != grafo->arestanula) {
            grau++;
        }
    }
    return grau;
}

void imprimirmatriz(Grafo* grafo) {
    printf("Matriz de adjacencias:\n");
    for (int i = 0; i < grafo->maxvertices; i++) {
        for (int j = 0; j < grafo->maxvertices; j++) {
            printf("%d ", grafo->matrizadjacencias[i][j]);
        }
        printf("\n");
    }
}

void imprimirvertices(Grafo* grafo) {
    printf("Lista de Vertices:\n");
    for (int i = 0; i < grafo->numvertices; i++) {
        printf("%d: %s\n", i, grafo->vertices[i]);
    }
}

int main() {
    int max, valorarestanula;
    printf("Digite a quantidade maxima de vertices:\n");
    scanf("%d", &max);
    printf("Digite o valor para representar a ausencia de aresta:\n");
    scanf("%d", &valorarestanula);
    Grafo* grafo1 = criarGrafo(max, valorarestanula);
    TipoItem item1, item2;
    int opcao, valor, peso;

    do {
        printf("Digite 0 para parar o algoritmo!\n");
        printf("Digite 1 para inserir um vertice!\n");
        printf("Digite 2 para inserir uma aresta!\n");
        printf("Digite 3 para imprimir o grau de um vertice!\n");
        printf("Digite 4 para imprimir o peso de uma aresta!\n");
        printf("Digite 5 para imprimir a matriz de adjacencias!\n");
        printf("Digite 6 para imprimir a lista de vertices!\n");
        scanf("%d", &opcao);

        if (opcao == 1) {
            printf("Digite o elemento do vertice que sera inserido:\n");
            scanf("%s", item1);
            inserirvertice(grafo1, item1);
        } else if (opcao == 2) {
            printf("Digite o vertice de saida:\n");
            scanf("%s", item1);
            printf("Digite o vertice de entrada:\n");
            scanf("%s", item2);
            printf("Digite o peso desta aresta:\n");
            scanf("%d", &peso);
            inseriraresta(grafo1, item1, item2, peso);
        } else if (opcao == 3) {
            printf("Digite o vertice que sera calculado o grau:\n");
            scanf("%s", item1);
            valor = obtergrau(grafo1, item1);
            printf("O grau desse vertice e: %d\n", valor);
        } else if (opcao == 4) {
            printf("Digite o vertice de saida:\n");
            scanf("%s", item1);
            printf("Digite o vertice de entrada:\n");
            scanf("%s", item2);
            valor = obterpeso(grafo1, item1, item2);
            printf("O peso dessa aresta e: %d\n", valor);
        } else if (opcao == 5) {
            imprimirmatriz(grafo1);
        } else if (opcao == 6) {
            imprimirvertices(grafo1);
        }
    } while (opcao != 0);

    destruirGrafo(grafo1);

    return 0;
}
