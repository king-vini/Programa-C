#include <stdio.h>

/*
 * Desafio Super Trunfo - Países
 * Nível: Mestre
 * Objetivo: Comparação de cartas e cálculo do Super Poder.
 */

int main() {
    // Variáveis para a Carta 1
    char estado1;
    char codigo1[4];
    char cidade1[50];
    unsigned long int populacao1; 
    float area1;
    float pib1;
    int pontosTuristicos1;
    float densidade1;
    float pibPerCapita1;
    float superPoder1;

    // Variáveis para a Carta 2
    char estado2;
    char codigo2[4];
    char cidade2[50];
    unsigned long int populacao2; 
    float area2;
    float pib2;
    int pontosTuristicos2;
    float densidade2;
    float pibPerCapita2;
    float superPoder2;

    // --- Cadastro da Carta 1 ---
    printf("--- Cadastro da Carta 1 ---\n");
    
    printf("Estado (A-H): ");
    scanf(" %c", &estado1); 

    printf("Código da Carta (ex: A01): ");
    scanf("%s", codigo1);

    printf("Nome da Cidade: ");
    scanf(" %s", cidade1); 

    printf("População: ");
    scanf("%lu", &populacao1);

    printf("Área (km²): ");
    scanf("%f", &area1);

    printf("PIB (em bilhões): ");
    scanf("%f", &pib1);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos1);

    // Cálculos da Carta 1
    densidade1 = (float)populacao1 / area1;
    pibPerCapita1 = (pib1 * 1000000000) / (float)populacao1;
    // Super Poder: Soma de atributos (Densidade entra invertida pois menor é melhor)
    superPoder1 = (float)populacao1 + area1 + pib1 + (float)pontosTuristicos1 + pibPerCapita1 + (1.0f / densidade1);

    printf("\n"); 

    // --- Cadastro da Carta 2 ---
    printf("--- Cadastro da Carta 2 ---\n");

    printf("Estado (A-H): ");
    scanf(" %c", &estado2);

    printf("Código da Carta: ");
    scanf("%s", codigo2);

    printf("Nome da Cidade: ");
    scanf(" %s", cidade2);

    printf("População: ");
    scanf("%lu", &populacao2);

    printf("Área (km²): ");
    scanf("%f", &area2);

    printf("PIB (em bilhões): ");
    scanf("%f", &pib2);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos2);

    // Cálculos da Carta 2
    densidade2 = (float)populacao2 / area2;
    pibPerCapita2 = (pib2 * 1000000000) / (float)populacao2;
    superPoder2 = (float)populacao2 + area2 + pib2 + (float)pontosTuristicos2 + pibPerCapita2 + (1.0f / densidade2);

    
    printf("\n==============================\n");
    printf("      CARTAS CADASTRADAS      \n");
    printf("==============================\n");
    printf("Carta 1 - %s: Super Poder %.2f\n", cidade1, superPoder1);
    printf("Carta 2 - %s: Super Poder %.2f\n", cidade2, superPoder2);

    // --- Comparação das Cartas ---
    printf("\n--- Comparação de Cartas ---\n");

    // Nas comparações: 1 significa que Carta 1 venceu, 0 significa que Carta 2 venceu.
    printf("População: Carta 1 venceu (%d)\n", populacao1 > populacao2);
    printf("Área: Carta 1 venceu (%d)\n", area1 > area2);
    printf("PIB: Carta 1 venceu (%d)\n", pib1 > pib2);
    printf("Pontos Turísticos: Carta 1 venceu (%d)\n", pontosTuristicos1 > pontosTuristicos2);
    
    // Densidade: MENOR valor vence
    printf("Densidade Populacional: Carta 1 venceu (%d)\n", densidade1 < densidade2);
    
    printf("PIB per Capita: Carta 1 venceu (%d)\n", pibPerCapita1 > pibPerCapita2);
    printf("Super Poder: Carta 1 venceu (%d)\n", superPoder1 > superPoder2);

    return 0;
}