#include <stdio.h>

void imprime_matriz(int adj[][5]) {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      printf("%d ", adj[i][j]);
    }
    printf("\n");
  }
}

int main() {
  // Declaração da matriz
  int adj[5][5] = {0};

  // Leitura dos dados da matriz
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      printf("adj[%d][%d] = ", i, j);
      scanf("%d", &adj[i][j]);

      // Validar o valor inserido
      if (adj[i][j] < 0 || adj[i][j] > 9) {
        printf("Valor inválido. Digite um número entre 0 e 9.\n");
        j--;
      }
    }
  }

  // Imprimir a matriz
  imprime_matriz(adj);

  // Solicitar o nó a ser verificado
  int no;
  printf("Digite o nó que deseja verificar: ");
  scanf("%d", &no);

  // Percorrer a matriz e verificar se o nó informado está conectado a algum outro nó
  for (int i = 0; i < 5; i++) {
    if (adj[no - 1][i] == 1) {
      printf("O nó %d está conectado ao nó %d\n", no, i + 1);
    }
  }

  return 0;
}
