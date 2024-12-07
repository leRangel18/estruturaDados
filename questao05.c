#include <stdio.h>

int main() {
    int x, y, *p;
    y = 0;
    p = &y; // Ponteiro p aponta para y
    x = *p; // x recebe o valor de y (0)
    x = 4;  // x agora recebe 4
    (*p)++; // Valor de y incrementado para 1
    --x;    // x decrementado para 3
    (*p) += x; // y = y + x (1 + 3 = 4)

    printf("x = %d, y = %d, *p = %d\n", x, y, *p);
    return 0;
}


