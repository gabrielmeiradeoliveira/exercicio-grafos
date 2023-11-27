#include <stdio.h>
#include <stdbool.h>

#define V 9 // Número de vértices do grafo

// Função para verificar se um vértice v pode ser adicionado ao caminho atual
bool ehSeguro(int v, int grafo[V][V], int path[], int pos) {
    if (grafo[path[pos - 1]][v] == 0) // Verifica se o vértice é adjacente ao último vértice adicionado
        return false;

    for (int i = 0; i < pos; i++) // Verifica se o vértice já foi incluído no caminho
        if (path[i] == v)
            return false;

    return true;
}

// Função recursiva para encontrar um ciclo hamiltoniano no grafo
bool cicloHamiltonianoUtil(int grafo[V][V], int path[], int pos) {
    if (pos == V) {
        if (grafo[path[pos - 1]][path[0]] == 1) // Verifica se há uma aresta entre o último e o primeiro vértice
            return true;
        else
            return false;
    }

    for (int v = 1; v < V; v++) {
        if (ehSeguro(v, grafo, path, pos)) {
            path[pos] = v;

            if (cicloHamiltonianoUtil(grafo, path, pos + 1) == true)
                return true;

            path[pos] = -1; // Remove o vértice se não leva a uma solução
        }
    }

    return false;
}

// Função para encontrar e imprimir um ciclo hamiltoniano
void encontraCicloHamiltoniano(int grafo[V][V]) {
    int path[V];
    for (int i = 0; i < V; i++)
        path[i] = -1; // Inicializa o caminho como vazio

    path[0] = 0; // Começa do vértice 0 como ponto de partida

    if (cicloHamiltonianoUtil(grafo, path, 1) == false) {
        printf("Não existe um ciclo hamiltoniano no grafo.\n");
        return;
    }

    printf("Um ciclo hamiltoniano no grafo: ");
    for (int i = 0; i < V; i++)
        printf("%d ", path[i]);
    printf("%d", path[0]); // Imprime o primeiro vértice novamente para formar o ciclo
    printf("\n");
}

int main() {
    int grafo[V][V] = {
        {0, 1, 0, 0, 0, 0, 0, 1, 1},
        {1, 0, 1, 0, 0, 0, 1, 1, 0},
        {0, 1, 0, 1, 0, 1, 1, 0, 0},
        {0, 0, 1, 0, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 1, 1, 0, 1},
        {0, 0, 1, 1, 1, 0, 1, 0, 0},
        {0, 1, 1, 0, 1, 1, 0, 1, 1},
        {1, 1, 0, 0, 0, 0, 1, 0, 1},
        {1, 0, 0, 0, 1, 0, 1, 1, 0}
    };

    encontraCicloHamiltoniano(grafo);

    return 0;
}
