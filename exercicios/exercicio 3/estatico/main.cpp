#include <stdio.h>

#define ORDEM 5

int main() {
    int grafo[ORDEM][ORDEM] = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 1, 0},
        {0, 1, 1, 0, 0},
        {0, 0, 0, 1, 1}
    };

    int i, j;

    printf("\nMatriz de adjacência ponderada do grafo:\n");
    for (i = 0; i < ORDEM; i++) {
        for (j = 0; j < ORDEM; j++) {
            printf("%d ", grafo[i][j]);
        }
        printf("\n");
    }

    return 0;
}
