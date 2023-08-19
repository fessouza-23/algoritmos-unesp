#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3
#define PLAYER_SYMBOL 'X'
#define COMPUTER_SYMBOL 'O'

void initializeBoard(char board[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard(char board[][SIZE]) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        if (i != SIZE - 1) {
            printf("\n---|---|---\n");
        }
    }
    printf("\n");
}

int isMoveValid(char board[][SIZE], int row, int col) {
    if (row < 0 || row >= SIZE || col < 0 || col >= SIZE) {
        return 0; // Posição inválida
    }
    if (board[row][col] != ' ') {
        return 0; // Posição já ocupada
    }
    return 1;
}

int checkWin(char board[][SIZE], char symbol) {
    // Verificação das linhas
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) {
            return 1; // Linha completa
        }
    }
    // Verificação das colunas
    for (int j = 0; j < SIZE; j++) {
        if (board[0][j] == symbol && board[1][j] == symbol && board[2][j] == symbol) {
            return 1; // Coluna completa
        }
    }
    // Verificação das diagonais
    if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) {
        return 1; // Diagonal principal completa
    }
    if (board[2][0] == symbol && board[1][1] == symbol && board[0][2] == symbol) {
        return 1; // Diagonal secundária completa
    }
    return 0; // Nenhum vencedor
}

int isBoardFull(char board[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                return 0; // Ainda há espaços vazios no tabuleiro
            }
        }
    }
    return 1; // Tabuleiro completo
}

void playerMove(char board[][SIZE]) {
    int row, col;
    printf("Sua vez de jogar (linha coluna): ");
    scanf("%d %d", &row, &col);

    if (!isMoveValid(board, row, col)) {
        printf("Movimento inválido! Tente novamente.\n");
        playerMove(board);
        return;
    }

    board[row][col] = PLAYER_SYMBOL;
}

void computerMove(char board[][SIZE]) {
    srand(time(NULL));

    int row, col;
    do {
        row = rand() % SIZE;
        col = rand() % SIZE;
    } while (!isMoveValid(board, row, col));

    board[row][col] = COMPUTER_SYMBOL;
}

int main() {
    char board[SIZE][SIZE];
    int gameOver = 0;

    initializeBoard(board);

    printf("Bem-vindo ao Jogo da Velha!\n\n");

    while (!gameOver) {
        printBoard(board);

        playerMove(board);
        if (checkWin(board, PLAYER_SYMBOL)) {
            printf("Parabens! Você ganhou!\n");
            gameOver = 1;
            break;
        }

        if (isBoardFull(board)) {
            printf("Empate! O jogo terminou empatado.\n");
            gameOver = 1;
            break;
        }

        computerMove(board);
        if (checkWin(board, COMPUTER_SYMBOL)) {
            printf("Você perdeu! O computador ganhou.\n");
            gameOver = 1;
            break;
        }

        if (isBoardFull(board)) {
            printf("Empate! O jogo terminou empatado.\n");
            gameOver = 1;
        }
    }

    printBoard(board);
    printf("Fim do jogo!\n");

    return 0;
}
