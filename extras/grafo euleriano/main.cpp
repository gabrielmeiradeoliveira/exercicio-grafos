#include <stdio.h>
#include <stdlib.h>

#define V 7 // Número de vértices do grafo

// Função para imprimir o caminho euleriano
void printCaminhoEuleriano(int grafo[][V], int u) {
    printf("O caminho euleriano: ");
    while (1) {
        printf("%d ", u);
        int v;
        for (v = 0; v < V; v++) {
            if (grafo[u][v]) {
                grafo[u][v] = 0; // Remove a aresta do grafo
                u = v;
                break;
            }
        }
        if (v == V) // Se não há mais arestas, sai do loop
            break;
    }
    printf("\n");
}

int main() {
    int grafo[V][V] = {
        {0, 1, 0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0, 0, 1},
        {0, 0, 0, 1, 0, 1, 0},
        {0, 0, 0, 0, 1, 0, 1},
        {0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0}
    };

    // O vértice 0 é escolhido como ponto de partida para o caminho euleriano
    printCaminhoEuleriano(grafo, 0);

    return 0;
}
