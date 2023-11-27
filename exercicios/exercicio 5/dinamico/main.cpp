#include <stdio.h>
#include <stdlib.h>

typedef struct vertice {
  int valor;
  struct vertice *proximo;
} vertice;

vertice **criar_lista_adjacencia(int n) {
  vertice **adj = (vertice **)malloc(n * sizeof(vertice *));
  for (int i = 0; i < n; i++) {
    adj[i] = NULL;
  }
  return adj;
}

void adicionar_aresta(vertice **adj, int v1, int v2) {
  vertice *novo = (vertice *)malloc(sizeof(vertice));
  novo->valor = v2;
  novo->proximo = adj[v1];
  adj[v1] = novo;
}

void imprimir_lista_adjacencia(vertice **adj, int n) {
  for (int i = 0; i < n; i++) {
    printf("Vértice %d: ", i);
    vertice *v = adj[i];
    while (v != NULL) {
      printf("%d ", v->valor);
      v = v->proximo;
    }
    printf("\n");
  }
}

int main() {
  int n;
  printf("Digite o número de vértices: ");
  scanf("%d", &n);

  // Criando a lista de adjacência
  vertice **adj = criar_lista_adjacencia(n);

  // Lendo as arestas
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int v1, v2;
      printf("Existe uma aresta entre os vértices %d e %d? (1 para sim, 0 para não): ", i, j);
      scanf("%d", &v1);
      if (v1 == 1) {
        printf("Digite o valor da aresta: ");
        scanf("%d", &v2);
        adicionar_aresta(adj, i, v2);
      }
    }
  }

  // Imprimindo a lista de adjacência
  imprimir_lista_adjacencia(adj, n);

  // Liberando memória
  for (int i = 0; i < n; i++) {
    vertice *v = adj[i];
    while (v != NULL) {
      vertice *temp = v;
      v = v->proximo;
      free(temp);
    }
  }
  free(adj);

  return 0;
}
