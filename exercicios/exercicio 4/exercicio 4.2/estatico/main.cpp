#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_VERTICES 100

int linhas = 3;

int matriz_adjacencia[3][3] = {
  {1, 15, 40},
  {23, 11, 5},
  {11, 7, 4}
};

typedef struct {
  int n;
  int **adj;
} Grafo;

Grafo* cria_grafo(int n) {
  Grafo *g = (Grafo*)malloc(sizeof(Grafo));
  g->n = n;
  g->adj = (int**)malloc(n * sizeof(int*));
  for (int i = 0; i < n; i++) {
    g->adj[i] = (int*)malloc(n * sizeof(int));
    for (int j = 0; j < n; j++) {
      g->adj[i][j] = matriz_adjacencia[i][j];
    }
  }
  return g;
}

void imprime_matriz_adjacencia(Grafo *g) {
  for (int i = 0; i < g->n; i++) {
    for (int j = 0; j < g->n; j++) {
      printf("%d ", g->adj[i][j]);
    }
    printf("\n");
  }
}

int main() {
  Grafo *g = cria_grafo(linhas);
  imprime_matriz_adjacencia(g);

  return 0;
}
