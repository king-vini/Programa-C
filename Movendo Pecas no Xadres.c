#include <stdio.h>

// --- FUNCOES RECURSIVAS ---

// Funcao recursiva para a Torre
void moverTorre(int casas) {
    if (casas > 0) {
        printf("Direita\n");
        moverTorre(casas - 1); // Chamada recursiva diminuindo o contador
    }
}

// Funcao recursiva para a Rainha
void moverRainha(int casas) {
    if (casas > 0) {
        printf("Esquerda\n");
        moverRainha(casas - 1);
    }
}

// Funcao recursiva para o Bispo (Movimento Diagonal)
void moverBispoRecursivo(int casas) {
    if (casas > 0) {
        printf("Cima Direita\n");
        moverBispoRecursivo(casas - 1);
    }
}

int main() {
    // Definicao das constantes
    int casasTorre = 5;
    int casasBispo = 5;
    int casasRainha = 8;

    // --- MOVIMENTACAO DA TORRE (RECURSIVIDADE) ---
    printf("Movimento da Torre:\n");
    moverTorre(casasTorre);
    printf("\n");

    // --- MOVIMENTACAO DO BISPO (RECURSIVIDADE + LOOPS ANINHADOS) ---
    printf("Movimento do Bispo:\n");
    
    for (int i = 0; i < casasBispo; i++) {
        for (int j = 0; j < 1; j++) {
            printf("Cima "); // Movimento Vertical
        }
        printf("Direita\n"); // Movimento Horizontal
    }
    printf("\n");

    // --- MOVIMENTACAO da RAINHA (RECURSIVIDADE) ---
    printf("Movimento da Rainha:\n");
    moverRainha(casasRainha);
    printf("\n");

    // --- MOVIMENTACAO DO CAVALO ---
    // Movimento: 2 para Cima e 1 para a Direita
    printf("Movimento do Cavalo:\n");
    
    // Loop aninhado com multiplas variaveis e condicoes
    for (int i = 0, j = 0; i < 2; i++) {
        while (j < 1) {
            // Este loop interno controla o salto final para a direita
            // Mas so deve acontecer apos as duas casas para cima
            if (i < 2) {
                printf("Cima\n");
            }
            break; 
        }
        if (i == 1) { // Quando atingir a segunda casa para cima
            printf("Direita\n");
        }
    }
    printf("\n");

    return 0;
}