#include <stdio.h>

typedef struct {
    char estado[30];
    char codigo[10];
    char nome[50];
    unsigned long int populacao;
    float area;
    double pib;
    int pontos_turisticos;
    float densidade;
    float pib_per_capita;
    float super_poder;
} Carta;

void calcularAtributos(Carta *c) {
    // densidade populacional
    c->densidade = (float)c->populacao / c->area;

    // PIB per capita
    c->pib_per_capita = (float)(c->pib / c->populacao);

    // super poder: soma de tudo
    // OBS: usamos 1/densidade pois menor densidade => maior poder
    c->super_poder = 
        (float)c->populacao +
        c->area +
        (float)c->pib +
        (float)c->pontos_turisticos +
        c->pib_per_capita +
        (1.0f / c->densidade);
}

int main() {
    Carta c1, c2;

    printf("Digite os dados da Carta 1:\n");
    printf("Estado: "); fgets(c1.estado, sizeof(c1.estado), stdin);
    printf("Codigo: "); fgets(c1.codigo, sizeof(c1.codigo), stdin);
    printf("Nome: "); fgets(c1.nome, sizeof(c1.nome), stdin);
    printf("Populacao: "); scanf("%lu", &c1.populacao);
    printf("Area: "); scanf("%f", &c1.area);
    printf("PIB: "); scanf("%lf", &c1.pib);
    printf("Pontos turisticos: "); scanf("%d", &c1.pontos_turisticos);
    getchar(); // limpar buffer

    printf("\nDigite os dados da Carta 2:\n");
    printf("Estado: "); fgets(c2.estado, sizeof(c2.estado), stdin);
    printf("Codigo: "); fgets(c2.codigo, sizeof(c2.codigo), stdin);
    printf("Nome: "); fgets(c2.nome, sizeof(c2.nome), stdin);
    printf("Populacao: "); scanf("%lu", &c2.populacao);
    printf("Area: "); scanf("%f", &c2.area);
    printf("PIB: "); scanf("%lf", &c2.pib);
    printf("Pontos turisticos: "); scanf("%d", &c2.pontos_turisticos);

    // calcular atributos derivados
    calcularAtributos(&c1);
    calcularAtributos(&c2);

    // comparações
    int vitoria_populacao = (c1.populacao > c2.populacao);
    int vitoria_area = (c1.area > c2.area);
    int vitoria_pib = (c1.pib > c2.pib);
    int vitoria_pontos = (c1.pontos_turisticos > c2.pontos_turisticos);
    int vitoria_densidade = (c1.densidade < c2.densidade); // menor vence
    int vitoria_pib_per_capita = (c1.pib_per_capita > c2.pib_per_capita);
    int vitoria_super_poder = (c1.super_poder > c2.super_poder);

    printf("\nComparacao de Cartas:\n\n");
    printf("Populacao: Carta %d venceu (%d)\n", vitoria_populacao ? 1 : 2, vitoria_populacao);
    printf("Area: Carta %d venceu (%d)\n", vitoria_area ? 1 : 2, vitoria_area);
    printf("PIB: Carta %d venceu (%d)\n", vitoria_pib ? 1 : 2, vitoria_pib);
    printf("Pontos Turisticos: Carta %d venceu (%d)\n", vitoria_pontos ? 1 : 2, vitoria_pontos);
    printf("Densidade Populacional: Carta %d venceu (%d)\n", vitoria_densidade ? 1 : 2, vitoria_densidade);
    printf("PIB per Capita: Carta %d venceu (%d)\n", vitoria_pib_per_capita ? 1 : 2, vitoria_pib_per_capita);
    printf("Super Poder: Carta %d venceu (%d)\n", vitoria_super_poder ? 1 : 2, vitoria_super_poder);

    return 0;
}
