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

  return 0;
}
