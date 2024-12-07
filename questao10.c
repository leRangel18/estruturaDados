#include <stdio.h>
#include <locale.h> 

int somaRecursiva(int n) {
    if (n == 1) return 1;
    return n + somaRecursiva(n - 1);
}

int main() {
    int n;
    setlocale(LC_ALL, "Portuguese");
    
    printf("--------------------- SOMA RECURSIVA ---------------------\n");
    
    printf("\nDigite um n�mero inteiro positivo: ");
    scanf("%d", &n);

    printf("A somat�ria de 1 a %d �: %d\n", n, somaRecursiva(n));
    return 0;
}

