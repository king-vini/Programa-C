#include <stdio.h>

int main() {
    // Definicao das constantes de movimento
    int casasTorre = 5;
    int casasBispo = 5;
    int casasRainha = 8;
    int casasCavaloBaixo = 2;
    int casasCavaloEsquerda = 1;

    // --- MOVIMENTACAO DA TORRE ---
    // Utilizando a estrutura FOR
    printf("Movimento da Torre:\n");
    for (int i = 0; i < casasTorre; i++) {
        printf("Direita\n");
    }
    printf("\n");

    // --- MOVIMENTACAO DO BISPO ---
    // Utilizando a estrutura WHILE
    printf("Movimento do Bispo:\n");
    int b = 0;
    while (b < casasBispo) {
        printf("Cima Direita\n");
        b++;
    }
    printf("\n");

    // --- MOVIMENTACAO DA RAINHA ---
    // Utilizando a estrutura DO-WHILE
    printf("Movimento da Rainha:\n");
    int r = 0;
    do {
        printf("Esquerda\n");
        r++;
    } while (r < casasRainha);
    printf("\n");

    // --- MOVIMENTACAO DO CAVALO ---
    // Implementacao de loops aninhados: um FOR e um WHILE
    printf("Movimento do Cavalo:\n");

    // Loop FOR externo para controlar as duas casas para baixo
    for (int i = 0; i < 1; i++) {
        int j = 0;
        // Loop WHILE interno para imprimir as casas para baixo
        while (j < casasCavaloBaixo) {
            printf("Baixo\n");
            j++;
        }
        // formando o movimento em "L"
        printf("Esquerda\n");
    }
    
    printf("\n");

    return 0;
}