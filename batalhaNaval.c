#include <stdio.h>

#define TAMANHO 10
#define NAVIO 3

int main() {
    int tabuleiro[TAMANHO][TAMANHO] = {0}; // Inicializa tudo com 0 (água)

    // Navios: cada um com 3 partes
    int navioHorizontal[NAVIO] = {NAVIO, NAVIO, NAVIO};
    int navioVertical[NAVIO] = {NAVIO, NAVIO, NAVIO};

    // Coordenadas iniciais dos navios (definidas diretamente no código)
    int linhaH = 2, colunaH = 4; // Navio horizontal começa em (2,4)
    int linhaV = 5, colunaV = 7; // Navio vertical começa em (5,7)

    // Validação: garantir que os navios estão dentro dos limites e não se sobrepõem
    if (colunaH + NAVIO <= TAMANHO && linhaV + NAVIO <= TAMANHO) {
        // Posiciona navio horizontal
        for (int i = 0; i < NAVIO; i++) {
            tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
        }

        // Posiciona navio vertical
        for (int i = 0; i < NAVIO; i++) {
            // Verifica se já há navio na posição
            if (tabuleiro[linhaV + i][colunaV] == 0) {
                tabuleiro[linhaV + i][colunaV] = navioVertical[i];
            } else {
                printf("Erro: sobreposição de navios na posição (%d,%d)\n", linhaV + i, colunaV);
                return 1;
            }
        }

        // Exibe o tabuleiro
        printf("\n=== Tabuleiro Batalha Naval ===\n");
        for (int i = 0; i < TAMANHO; i++) {
            for (int j = 0; j < TAMANHO; j++) {
                printf("%d ", tabuleiro[i][j]);
            }
            printf("\n");
        }

    } else {
        printf("Erro: coordenadas inválidas para posicionar os navios.\n");
    }

    return 0;
}
