#include <stdio.h>

int main() {
  // Declaração da matriz
  int adj[5][5] = {
    {0, 1, 1, 0, 1},
    {1, 0, 1, 1, 0},
    {1, 1, 0, 1, 1},
    {0, 1, 1, 0, 0},
    {1, 0, 1, 0, 0},
  };

  // Impressão da matriz
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      printf("%d ", adj[i][j]);
    }
    printf("\n");
  }

  return 0;
}
