#include <stdio.h>

int main() {
    int matriz[3][3], maior, menor;
    int i, j;

    printf("Digite os valores da matriz 3x3:\n\n");
    
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
        	printf("Digite um valor para [%d][%d]: ", i+1, j+1);
            scanf("%d", &matriz[i][j]);
            if (i == 0 && j == 0) {
                maior = menor = matriz[i][j];
            } else {
                if (matriz[i][j] > maior) maior = matriz[i][j];
                if (matriz[i][j] < menor) menor = matriz[i][j];
            }
        }
    }
    
        printf("\nMatriz inserida:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n"); 
    }
        
    printf("\nMaior elemento: %d\n", maior);
    printf("Menor elemento: %d\n", menor);

    return 0;

}
