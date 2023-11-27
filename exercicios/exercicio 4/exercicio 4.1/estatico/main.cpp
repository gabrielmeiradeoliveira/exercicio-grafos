#include <stdio.h>

int main() {
  // Declara as matrizes
  int matriz_distancias[3][3];
  int matriz_rotulos[3];

  // Inicializa a matriz de distâncias
  matriz_distancias[0][0] = 0;
  matriz_distancias[0][1] = 20;
  matriz_distancias[0][2] = 60;
  matriz_distancias[1][0] = 20;
  matriz_distancias[1][1] = 0;
  matriz_distancias[1][2] = 50;
  matriz_distancias[2][0] = 60;
  matriz_distancias[2][1] = 50;
  matriz_distancias[2][2] = 0;

  // Inicializa a matriz de rótulos
  matriz_rotulos[0] = 0; // São Paulo
  matriz_rotulos[1] = 1; // Curitiba
  matriz_rotulos[2] = 2; // Porto Alegre

  // Imprime as matrizes
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%d ", matriz_distancias[i][j]);
    }
    printf("\n");
  }

  for (int i = 0; i < 3; i++) {
    printf("%d ", matriz_rotulos[i]);
  }
  printf("\n");

  return 0;
}
