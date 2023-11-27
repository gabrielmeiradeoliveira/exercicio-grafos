#include <stdio.h>

#define MAX_VERTICES 100

// Função para calcular o grau de um vértice em um grafo representado por uma matriz de adjacência
int calcularGrauVertice(int grafo[MAX_VERTICES][MAX_VERTICES], int vertice, int numVertices) {
    int grau = 0;
    
    // Percorre a linha correspondente ao vértice na matriz
    for (int i = 0; i < numVertices; ++i) {
        if (grafo[vertice][i] == 1) {
            grau++;
        }
    }
    
    return grau;
}

int main() {
    int numVertices, vertice;
    int grafo[MAX_VERTICES][MAX_VERTICES];

    printf("Digite o número de vértices do grafo (máximo de %d vértices): ", MAX_VERTICES);
    scanf("%d", &numVertices);

    printf("Digite a matriz de adjacência do grafo (insira 1 se houver aresta e 0 caso contrário):\n");
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            printf("Vértice %d está conectado ao vértice %d? (1 para sim, 0 para não): ", i, j);
            scanf("%d", &grafo[i][j]);
        }
    }

    printf("\nDigite o vértice para calcular o grau (de 0 a %d): ", numVertices - 1);
    scanf("%d", &vertice);

    if (vertice < 0 || vertice >= numVertices) {
        printf("Vértice inválido!\n");
    } else {
        int grau = calcularGrauVertice(grafo, vertice, numVertices);
        printf("O grau do vértice %d é: %d\n", vertice, grau);
    }

    return 0;
}
