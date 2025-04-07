#include <stdio.h>

int main() {
    // --- Movimento da TORRE: 5 casas para a direita (usando FOR) ---
    printf("Movimento da Torre (5 casas para a Direita):\n");
    for (int i = 1; i <= 5; i++) {
        printf("Direita (%d)\n", i);
    }

    printf("\n");

    // --- Movimento do BISPO: 5 casas na diagonal cima + direita (usando WHILE) ---
    printf("Movimento do Bispo (5 casas na Diagonal Cima Direita):\n");
    int j = 1;
    while (j <= 5) {
        printf("Cima Direita (%d)\n", j);
        j++;
    }

    printf("\n");

    // --- Movimento da RAINHA: 8 casas para a esquerda (usando DO-WHILE) ---
    printf("Movimento da Rainha (8 casas para a Esquerda):\n");
    int k = 1;
    do {
        printf("Esquerda (%d)\n", k);
        k++;
    } while (k <= 8);

    return 0;
}
