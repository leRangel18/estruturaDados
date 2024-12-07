#include <stdio.h>
#include <locale.h> 

int main() {
    float pluviometria[7][6], mediaCidade[7], mediaMes[6] = {0};
    int i,j;
    
    setlocale(LC_ALL, "Portuguese");
    
    // T�tulo
    printf("--------------------- M�DIA DE PLUVIOSIDADE ---------------------\n");

    // Leitura dos �ndices pluviom�tricos
    for (i = 0; i < 7; i++) {
        printf("\nDigite os �ndices de pluviosidade para a cidade %d (Jan-Jun):\n", i + 1);
        for (j = 0; j < 6; j++) {
            scanf("%f", &pluviometria[i][j]);
            mediaMes[j] += pluviometria[i][j]; // Soma para a m�dia mensal
        }
    }

    // C�lculo das m�dias
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

    // Exibi��o das m�dias
    printf("\nM�dia de pluviosidade mensal de cada cidade:\n");
    for (i = 0; i < 7; i++) {
        printf("Cidade %d: %.2f\n", i + 1, mediaCidade[i]);
    }

    printf("\nM�dia de pluviosidade em cada m�s na regi�o:\n");
    for (j = 0; j < 6; j++) {
        printf("M�s %d: %.2f\n", j + 1, mediaMes[j]);
    }

    return 0;
}

