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
  int n = 6; // Ajustei para 6, pois os índices são de 0 a 5
  vertice **adj = criar_lista_adjacencia(n);

  // Adicionando arestas
  adicionar_aresta(adj, 0, 1);
  adicionar_aresta(adj, 0, 2);
  adicionar_aresta(adj, 0, 3);
  adicionar_aresta(adj, 1, 0);
  adicionar_aresta(adj, 1, 2);
  adicionar_aresta(adj, 1, 3);
  adicionar_aresta(adj, 1, 4);
  adicionar_aresta(adj, 2, 0);
  adicionar_aresta(adj, 2, 1);
  adicionar_aresta(adj, 2, 3);
  adicionar_aresta(adj, 2, 4);
  adicionar_aresta(adj, 2, 5);
  adicionar_aresta(adj, 3, 0);
  adicionar_aresta(adj, 3, 1);
  adicionar_aresta(adj, 3, 2);
  adicionar_aresta(adj, 3, 5);
  adicionar_aresta(adj, 4, 0);
  adicionar_aresta(adj, 4, 1);
  adicionar_aresta(adj, 4, 2);
  adicionar_aresta(adj, 4, 5);
  adicionar_aresta(adj, 5, 2);
  adicionar_aresta(adj, 5, 3);
  adicionar_aresta(adj, 5, 4);

  // Imprimindo lista de adjacência
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
