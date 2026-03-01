#include <stdio.h>

/**
 * Desafio: Batalha Naval - Nível Mestre
 * Objetivo: Adicionar habilidades especiais (Cone, Cruz, Octaedro) com áreas de efeito.
 */

int main() {
    // 1. Tabuleiro Principal (10x10)
    int tabuleiro[10][10] = {0};
    int tamNavio = 3;

    // --- POSICIONAMENTO DOS NAVIOS ---
    // Horizontal
    for (int j = 0; j < tamNavio; j++) tabuleiro[1][1 + j] = 3;
    // Vertical
    for (int i = 0; i < tamNavio; i++) tabuleiro[4 + i][1] = 3;
    // Diagonal 1
    for (int i = 0; i < tamNavio; i++) tabuleiro[1 + i][6 + i] = 3;
    // Diagonal 2
    for (int i = 0; i < tamNavio; i++) tabuleiro[7 + i][8 - i] = 3;

    // 2. DEFINIÇÃO DAS MATRIZES DE HABILIDADE (5x5)
    int cone[5][5] = {0}, cruz[5][5] = {0}, octaedro[5][5] = {0};

    // Construção Dinâmica das Habilidades usando Condicionais
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            // Cone (Triângulo apontando para baixo)
            if (i == 0 && j == 2) cone[i][j] = 1;
            else if (i == 1 && j >= 1 && j <= 3) cone[i][j] = 1;
            else if (i == 2) cone[i][j] = 1;

            // Cruz
            if (i == 2 || j == 2) cruz[i][j] = 1;

            // Octaedro 
            if ((i == 1 && j == 2) || (i == 2 && j >= 1 && j <= 3) || (i == 3 && j == 2)) octaedro[i][j] = 1;
        }
    }

    // 3. INTEGRAÇÃO AO TABULEIRO 
    // Definimos pontos de origem 
    int origens[3][2] = {{2, 2}, {5, 5}, {8, 7}}; // [0]=Cone, [1]=Cruz, [2]=Octaedro

    // Loop para aplicar as 3 habilidades
    for (int h = 0; h < 3; h++) {
        int linO = origens[h][0];
        int colO = origens[h][1];

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                // Cálculo da posição no tabuleiro (centralizando a matriz 5x5)
                int tabL = linO + i - 2;
                int tabC = colO + j - 2;

                // Validação de limites do tabuleiro
                if (tabL >= 0 && tabL < 10 && tabC >= 0 && tabC < 10) {
                    int valorHabilidade = 0;
                    if (h == 0) valorHabilidade = cone[i][j];
                    else if (h == 1) valorHabilidade = cruz[i][j];
                    else valorHabilidade = octaedro[i][j];

                    // Se a habilidade atingir a área (1) e não houver navio (3)
                    if (valorHabilidade == 1 && tabuleiro[tabL][tabC] == 0) {
                        tabuleiro[tabL][tabC] = 5; // 5 representa área de efeito
                    }
                }
            }
        }
    }

    // 4. EXIBIÇÃO FINAL
    printf("--- BATALHA NAVAL: MESTRE ---\n");
    printf("Legenda: 0=Agua | 3=Navio | 5=Habilidade\n\n   ");
    for(int c = 0; c < 10; c++) printf("%d ", c);
    printf("\n");

    for (int i = 0; i < 10; i++) {
        printf("%d |", i);
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}