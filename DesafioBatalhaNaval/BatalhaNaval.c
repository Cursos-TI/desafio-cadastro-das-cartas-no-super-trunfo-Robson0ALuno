#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3

int main() {
    // --- 1. Inicializar o tabuleiro 10x10 com água (0) ---
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // --- 2. Definir o navio horizontal ---
    int navio_horizontal[TAM_NAVIO] = {3, 3, 3};
    int linha_horizontal = 2; // Linha onde o navio será colocado
    int coluna_inicial_horizontal = 4; // Começa na coluna 4 (coloca nas colunas 4, 5, 6)

    // Validar se o navio cabe horizontalmente
    if (coluna_inicial_horizontal + TAM_NAVIO <= TAM_TABULEIRO) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[linha_horizontal][coluna_inicial_horizontal + i] = navio_horizontal[i];
        }
    }

    // --- 3. Definir o navio vertical ---
    int navio_vertical[TAM_NAVIO] = {3, 3, 3};
    int linha_inicial_vertical = 5; // Começa na linha 5
    int coluna_vertical = 1; // Fica na coluna 1 (coloca nas linhas 5, 6, 7)

    // Validar se o navio cabe verticalmente
    if (linha_inicial_vertical + TAM_NAVIO <= TAM_TABULEIRO) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            // Verifica se não há sobreposição
            if (tabuleiro[linha_inicial_vertical + i][coluna_vertical] == 0) {
                tabuleiro[linha_inicial_vertical + i][coluna_vertical] = navio_vertical[i];
            }
        }
    }

    // --- 4. Exibir o tabuleiro ---
    printf("=== TABULEIRO DE BATALHA NAVAL ===\n\n");

    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
