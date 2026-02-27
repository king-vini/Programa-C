#include <stdio.h>

/*
 * Desafio Super Trunfo - Países
 * Nível: Mestre (Tema: Atributos Múltiplos)
 * Objetivo: Comparação de dois atributos, soma de valores e menus dinâmicos.
 */

int main() {
    // --- Variáveis da Carta 1 ---
    char estado1, codigo1[4], cidade1[50];
    unsigned long int populacao1;
    float area1, pib1, densidade1, pibPerCapita1;
    int pontosTuristicos1;

    // --- Variáveis da Carta 2 ---
    char estado2, codigo2[4], cidade2[50];
    unsigned long int populacao2;
    float area2, pib2, densidade2, pibPerCapita2;
    int pontosTuristicos2;

    // Variáveis de controle do jogo
    int opcao1, opcao2;
    float valor1_carta1, valor1_carta2;
    float valor2_carta1, valor2_carta2;
    float soma1, soma2;

    // === CADASTRO ===
    printf("--- Cadastro da Carta 1 ---\n");
    printf("Estado (A-H): "); scanf(" %c", &estado1);
    printf("Código: "); scanf("%s", codigo1);
    printf("Cidade: "); scanf(" %s", cidade1);
    printf("População: "); scanf("%lu", &populacao1);
    printf("Área (km²): "); scanf("%f", &area1);
    printf("PIB (bilhões): "); scanf("%f", &pib1);
    printf("Pontos Turísticos: "); scanf("%d", &pontosTuristicos1);

    densidade1 = (float)populacao1 / area1;
    pibPerCapita1 = (pib1 * 1000000000) / (float)populacao1;

    printf("\n--- Cadastro da Carta 2 ---\n");
    printf("Estado (A-H): "); scanf(" %c", &estado2);
    printf("Código: "); scanf("%s", codigo2);
    printf("Cidade: "); scanf(" %s", cidade2);
    printf("População: "); scanf("%lu", &populacao2);
    printf("Área (km²): "); scanf("%f", &area2);
    printf("PIB (bilhões): "); scanf("%f", &pib2);
    printf("Pontos Turísticos: "); scanf("%d", &pontosTuristicos2);

    densidade2 = (float)populacao2 / area2;
    pibPerCapita2 = (pib2 * 1000000000) / (float)populacao2;

    // === PRIMEIRO MENU DINÂMICO ===
    printf("\nEscolha o PRIMEIRO atributo:\n");
    printf("1. População\n2. Área\n3. PIB\n4. Pontos Turísticos\n5. Densidade Demográfica\n");
    printf("Opção: ");
    scanf("%d", &opcao1);

    // === SEGUNDO MENU DINÂMICO ===
    printf("\nEscolha o SEGUNDO atributo (diferente do primeiro):\n");
    if (opcao1 != 1) printf("1. População\n");
    if (opcao1 != 2) printf("2. Área\n");
    if (opcao1 != 3) printf("3. PIB\n");
    if (opcao1 != 4) printf("4. Pontos Turísticos\n");
    if (opcao1 != 5) printf("5. Densidade Demográfica\n");
    printf("Opção: ");
    scanf("%d", &opcao2);

    if (opcao1 == opcao2) {
        printf("\nERRO: Você escolheu o mesmo atributo duas vezes. Reinicie o jogo.\n");
        return 0;
    }

    // Lógica para definir os valores do Atributo 1
    switch (opcao1) {
        case 1: valor1_carta1 = (float)populacao1; valor1_carta2 = (float)populacao2; break;
        case 2: valor1_carta1 = area1; valor1_carta2 = area2; break;
        case 3: valor1_carta1 = pib1; valor1_carta2 = pib2; break;
        case 4: valor1_carta1 = (float)pontosTuristicos1; valor1_carta2 = (float)pontosTuristicos2; break;
        case 5: valor1_carta1 = densidade1; valor1_carta2 = densidade2; break;
        default: printf("Opção 1 inválida.\n"); return 0;
    }

    // Lógica para definir os valores do Atributo 2
    switch (opcao2) {
        case 1: valor2_carta1 = (float)populacao1; valor2_carta2 = (float)populacao2; break;
        case 2: valor2_carta1 = area1; valor2_carta2 = area2; break;
        case 3: valor2_carta1 = pib1; valor2_carta2 = pib2; break;
        case 4: valor2_carta1 = (float)pontosTuristicos1; valor2_carta2 = (float)pontosTuristicos2; break;
        case 5: valor2_carta1 = densidade1; valor2_carta2 = densidade2; break;
        default: printf("Opção 2 inválida.\n"); return 0;
    }

    
    soma1 = valor1_carta1 + valor2_carta1;
    soma2 = valor1_carta2 + valor2_carta2;

    // === EXIBIÇÃO DO RESULTADO ===
    printf("\n========================================\n");
    printf("          BATALHA FINAL: %s VS %s\n", cidade1, cidade2);
    printf("========================================\n");
    
    // Comparação Atributo 1 (Usando Operador Ternário para decidir vencedor individual)
    printf("Atributo 1: %s\n", (opcao1 == 5) ? 
        (valor1_carta1 < valor1_carta2 ? "Carta 1 venceu" : "Carta 2 venceu") : 
        (valor1_carta1 > valor1_carta2 ? "Carta 1 venceu" : "Carta 2 venceu"));

    // Comparação Atributo 2
    printf("Atributo 2: %s\n", (opcao2 == 5) ? 
        (valor2_carta1 < valor2_carta2 ? "Carta 1 venceu" : "Carta 2 venceu") : 
        (valor2_carta1 > valor2_carta2 ? "Carta 1 venceu" : "Carta 2 venceu"));

    printf("----------------------------------------\n");
    printf("Soma Atributos Carta 1 (%s): %.2f\n", cidade1, soma1);
    printf("Soma Atributos Carta 2 (%s): %.2f\n", cidade2, soma2);
    printf("----------------------------------------\n");

    // Resultado Final baseado na soma
    if (soma1 > soma2) {
        printf("RESULTADO FINAL: %s (CARTA 1) VENCEU!\n", cidade1);
    } else if (soma2 > soma1) {
        printf("RESULTADO FINAL: %s (CARTA 2) VENCEU!\n", cidade2);
    } else {
        printf("RESULTADO FINAL: EMPATE!\n");
    }
    printf("========================================\n");

    return 0;
}