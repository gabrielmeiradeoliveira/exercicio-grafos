#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

struct No {
    int id;
    struct No *adj[MAX_VERTICES];
    int num_arestas_entrada;
    int num_arestas_saida;
};

struct No *vertices[MAX_VERTICES];

void adicionar_vertice(int id) {
    struct No *novo_vertice = (struct No *)malloc(sizeof(struct No));
    if (novo_vertice == NULL) {
        printf("Erro ao alocar memória para o novo vértice.\n");
        return;
    }
    novo_vertice->id = id;
    novo_vertice->num_arestas_entrada = 0;
    novo_vertice->num_arestas_saida = 0;
    for (int i = 0; i < MAX_VERTICES; i++) {
        novo_vertice->adj[i] = NULL;
    }
    vertices[id] = novo_vertice;
    printf("Vértice %d adicionado.\n", id);
}

void adicionar_aresta(int origem, int destino) {
    struct No *vertice_origem = vertices[origem];
    struct No *vertice_destino = vertices[destino];
    vertice_origem->adj[vertice_origem->num_arestas_saida++] = vertice_destino;
    vertice_destino->adj[vertice_destino->num_arestas_entrada++] = vertice_origem;
    printf("Aresta adicionada de %d para %d.\n", origem, destino);
}

void imprimir_grafo() {
    for (int i = 0; i < MAX_VERTICES; i++) {
        struct No *vertice = vertices[i];
        if (vertice != NULL) {
            printf("Vértice %d (Entrada: %d, Saída: %d):\n", vertice->id, vertice->num_arestas_entrada, vertice->num_arestas_saida);
            for (int j = 0; j < vertice->num_arestas_saida; j++) {
                printf("  adjacente de saída: %d\n", vertice->adj[j]->id);
            }
            for (int j = 0; j < vertice->num_arestas_entrada; j++) {
                printf("  adjacente de entrada: %d\n", vertice->adj[j]->id);
            }
        }
    }
}

int main() {
  for (int i = 0; i < MAX_VERTICES; i++) {
    vertices[i] = NULL;
  }

  int opcao;
  do {
    printf("1 - Adicionar vértice\n");
    printf("2 - Adicionar aresta\n");
    printf("3 - Imprimir grafo\n");
    printf("0 - Sair\n");
    scanf("%d", &opcao);
    switch (opcao) {
      case 1:
        printf("Informe o identificador do vértice a ser adicionado: ");
        int id;
        scanf("%d", &id);
        adicionar_vertice(id);
        break;
      case 2:
        printf("Informe o identificador do vértice de origem: ");
        int origem;
        scanf("%d", &origem);
        printf("Informe o identificador do vértice de destino: ");
        int destino;
        scanf("%d", &destino);
        adicionar_aresta(origem, destino);
        break;
      case 3:
        imprimir_grafo();
        break;
      case 0:
        break;
      default:
        printf("Opção inválida.\n");
        break;
    }
  } while (opcao != 0);

  for (int i = 0; i < MAX_VERTICES; i++) {
    if (vertices[i] != NULL) {
      free(vertices[i]);
    }
  }
  
  return 0;
}
