#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_VERTICES 100

int linhas;

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
      g->adj[i][j] = 0;
    }
  }
  return g;
}

void le_matriz_adjacencia(Grafo *g) {
  g->n = linhas;

  for (int i = 0; i < linhas; i++) {
    for (int j = 0; j < linhas; j++) {
      printf("Digite o peso da aresta entre V%d e V%d: ", i, j);
      char str[10];
      fgets(str, 10, stdin);
      
      int peso = 0;
      if (str[strlen(str)-1] == '\n') {
        str[strlen(str)-1] = '\0';
      }

      if (strcmp(str, "*0") == 0 || strcmp(str, "0") == 0) {
        peso = -1; // Ausência de conexão
      } else {
        peso = atoi(str); // Converte para inteiro
      }

      g->adj[i][j] = peso;
    }
  }
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
  printf("Digite o número de linhas da matriz: ");
  scanf("%d", &linhas);
  while ((getchar()) != '\n'); // limpar o buffer de entrada

  Grafo *g = cria_grafo(linhas);
  le_matriz_adjacencia(g);
  imprime_matriz_adjacencia(g);

  return 0;
}
