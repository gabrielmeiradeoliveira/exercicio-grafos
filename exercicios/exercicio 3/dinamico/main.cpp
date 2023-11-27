#include <stdio.h>

#define ORDEM 7

int main() {
    int grafo[ORDEM][ORDEM];
    int i, j;

    printf("Digite os pesos das arestas do grafo:\n");
    for (i = 0; i < ORDEM; i++) {
        for (j = 0; j < ORDEM; j++) {
            printf("Peso da aresta entre o vértice %d e o vértice %d: ", i+1, j+1);
            scanf("%d", &grafo[i][j]);
        }
    }

    printf("\nMatriz de adjacência ponderada do grafo:\n");
    for (i = 0; i < ORDEM; i++) {
        for (j = 0; j < ORDEM; j++) {
            printf("%d ", grafo[i][j]);
        }
        printf("\n");
    }

    return 0;
}
