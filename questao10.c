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
    
    printf("\nDigite um número inteiro positivo: ");
    scanf("%d", &n);

    printf("A somatória de 1 a %d é: %d\n", n, somaRecursiva(n));
    return 0;
}

