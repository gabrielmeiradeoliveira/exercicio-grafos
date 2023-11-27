#include <stdio.h>

#define MAX_VERTICES 100

typedef struct {
    int vertices;
    int matriz_adj[MAX_VERTICES][MAX_VERTICES];
} Grafo;

void inicializarGrafo(Grafo *grafo, int vertices) {
    grafo->vertices = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            grafo->matriz_adj[i][j] = 0;
        }
    }
}

void adicionarAresta(Grafo *grafo, int origem, int destino) {
    grafo->matriz_adj[origem][destino] = 1;
}

void imprimirGrafo(Grafo *grafo) {
    printf("Matriz de adjacência:\n");
    for (int i = 0; i < grafo->vertices; i++) {
        for (int j = 0; j < grafo->vertices; j++) {
            printf("%d ", grafo->matriz_adj[i][j]);
        }
        printf("\n");
    }
}

void mostrarEntradaSaidaVertices(Grafo *grafo) {
    printf("Entrada e Saída de cada vértice:\n");
    for (int i = 0; i < grafo->vertices; i++) {
        int entrada = 0;
        int saida = 0;

        for (int j = 0; j < grafo->vertices; j++) {
            entrada += grafo->matriz_adj[j][i];
            saida += grafo->matriz_adj[i][j];
        }

        printf("Vértice %d - Entrada: %d, Saída: %d\n", i, entrada, saida);
    }
}

int main() {
    Grafo grafo;
    int vertices = 5;

    inicializarGrafo(&grafo, vertices);

    adicionarAresta(&grafo, 0, 1);
    adicionarAresta(&grafo, 0, 2);
    adicionarAresta(&grafo, 1, 3);
    adicionarAresta(&grafo, 2, 4);
    adicionarAresta(&grafo, 3, 4);
    adicionarAresta(&grafo, 4, 1);

    imprimirGrafo(&grafo);
    mostrarEntradaSaidaVertices(&grafo);

    return 0;
}
