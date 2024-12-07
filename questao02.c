#include <stdio.h>
#include <locale.h> 

char tabuleiro[3][3];
int i, j;

// Inicializa o formato do tabuleiro
void inicializaTabuleiro() {
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            tabuleiro[i][j] = ' ';
        }
    }
}

// Exibe o tabuleiro
void exibeTabuleiro() {
    printf("  0   1   2\n");
    for (i = 0; i < 3; i++) {
        printf("%d", i);
        for (j = 0; j < 3; j++) {
            printf(" %c ", tabuleiro[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf(" ---|---|---\n");
    }
}

// Verifica se há um vencedor
char verificaVencedor() {
    for (i = 0; i < 3; i++) {
        // Verificar linhas e colunas
        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][0] != ' ')
            return tabuleiro[i][0];
        if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i] && tabuleiro[0][i] != ' ')
            return tabuleiro[0][i];
    }

    // Verificar diagonais
    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[0][0] != ' ')
        return tabuleiro[0][0];
    if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0] && tabuleiro[0][2] != ' ')
        return tabuleiro[0][2];

    return ' '; // Nenhum vencedor ainda
}

// Verifica se o tabuleiro está cheio
int tabuleiroCheio() {
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (tabuleiro[i][j] == ' ') return 0;
        }
    }
    return 1;
}

int main() {
    int linha, coluna;
    char jogador = 'X';
    inicializaTabuleiro();
    
    setlocale(LC_ALL, "Portuguese");

    printf("Jogo da Velha\n");
    while (1) {
        exibeTabuleiro();
        printf("\nJogador %c, escolha sua jogada (linha e coluna): ", jogador);

        if (scanf("%d %d", &linha, &coluna) != 2) { // Verifica se a entrada é válida
            printf("\nEntrada inválida! Tente novamente.\n");
            while (getchar() != '\n'); // Limpa o buffer de entrada
            continue;
        }

        if (linha < 0 || linha > 2 || coluna < 0 || coluna > 2 || tabuleiro[linha][coluna] != ' ') {
            printf("\nJogada inválida! Tente novamente.\n");
            continue;
        }

        tabuleiro[linha][coluna] = jogador;
        char vencedor = verificaVencedor();
        if (vencedor != ' ') {
            exibeTabuleiro();
            printf("\nJogador %c venceu!\n", vencedor);
            break;
        }

        if (tabuleiroCheio()) {
            exibeTabuleiro();
            printf("\nEmpate!\n");
            break;
        }

        jogador = (jogador == 'X') ? 'O' : 'X';
    }

    return 0;
}

