#include <stdio.h>

#define ESTADOS 4
#define CIDADES 4

const char *estados[] = {"Minas Gerais", "Distrito Federal", "Sao Paulo", "Rio de Janeiro"};
const char *cidades[ESTADOS][CIDADES] = {
    {"Belo Horizonte", "Uberlandia", "Juiz de Fora", "Contagem"},
    {"Brasilia", "Taguatinga", "Ceilandia", "Gama"},
    {"Sao Paulo", "Campinas", "Santos", "Sao Jose dos Campos"},
    {"Rio de Janeiro", "Niteroi", "Petropolis", "Volta Redonda"}
};

typedef struct {
    char codigo[4];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
} Cidade;

void cadastrarCidades(Cidade cidades[ESTADOS][CIDADES]) {
    for (int i = 0; i < ESTADOS; i++) {
        for (int j = 0; j < CIDADES; j++) {
            snprintf(cidades[i][j].codigo, sizeof(cidades[i][j].codigo), "%c%02d", 'A' + i, j + 1);
            
            printf("\nCadastro da cidade %s (%s - %s):\n", cidades[i][j].codigo, cidades[i][j].codigo, estados[i]);
            printf("Populacao: ");
            scanf("%d", &cidades[i][j].populacao);
            printf("Area (km^2): ");
            scanf("%f", &cidades[i][j].area);
            printf("PIB (bilhoes): ");
            scanf("%f", &cidades[i][j].pib);
            printf("Numero de pontos turisticos: ");
            scanf("%d", &cidades[i][j].pontos_turisticos);
            
            cidades[i][j].densidade_populacional = cidades[i][j].populacao / cidades[i][j].area;
            cidades[i][j].pib_per_capita = cidades[i][j].pib / cidades[i][j].populacao;
        }
    }
}

void exibirCidades(Cidade cidades[ESTADOS][CIDADES]) {
    printf("\n===== Dados das Cidades Cadastradas =====\n");
    for (int i = 0; i < ESTADOS; i++) {
        for (int j = 0; j < CIDADES; j++) {
            printf("\nCidade: %s (%s - %s)\n", cidades[i][j].codigo, cidades[i][j].codigo, estados[i]);
            printf("Populacao: %d\n", cidades[i][j].populacao);
            printf("Area: %.2f km^2\n", cidades[i][j].area);
            printf("PIB: %.2f bilhoes\n", cidades[i][j].pib);
            printf("Pontos turisticos: %d\n", cidades[i][j].pontos_turisticos);
            printf("Densidade Populacional: %.2f hab/km^2\n", cidades[i][j].densidade_populacional);
            printf("PIB per Capita: %.2f\n", cidades[i][j].pib_per_capita);
        }
    }
}

int main() {
    Cidade cidades[ESTADOS][CIDADES];
    
    cadastrarCidades(cidades);
    exibirCidades(cidades);
    
    return 0;
}
