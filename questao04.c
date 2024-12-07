#include <stdio.h>
#include <locale.h> 

int main() {
    float pluviometria[7][6], mediaCidade[7], mediaMes[6] = {0};
    int i,j;
    
    setlocale(LC_ALL, "Portuguese");
    
    // Título
    printf("--------------------- MÉDIA DE PLUVIOSIDADE ---------------------\n");

    // Leitura dos índices pluviométricos
    for (i = 0; i < 7; i++) {
        printf("\nDigite os índices de pluviosidade para a cidade %d (Jan-Jun):\n", i + 1);
        for (j = 0; j < 6; j++) {
            scanf("%f", &pluviometria[i][j]);
            mediaMes[j] += pluviometria[i][j]; // Soma para a média mensal
        }
    }

    // Cálculo das médias
    for (i = 0; i < 7; i++) {
        float soma = 0;
        for (j = 0; j < 6; j++) {
            soma += pluviometria[i][j];
        }
        mediaCidade[i] = soma / 6;
    }

    for (j = 0; j < 6; j++) {
        mediaMes[j] /= 7;
    }

    // Exibição das médias
    printf("\nMédia de pluviosidade mensal de cada cidade:\n");
    for (i = 0; i < 7; i++) {
        printf("Cidade %d: %.2f\n", i + 1, mediaCidade[i]);
    }

    printf("\nMédia de pluviosidade em cada mês na região:\n");
    for (j = 0; j < 6; j++) {
        printf("Mês %d: %.2f\n", j + 1, mediaMes[j]);
    }

    return 0;
}

