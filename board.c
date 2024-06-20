#include <stdio.h>

#define SIZE 3

void printBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) printf("---|---|---\n");
    }
}

int main() {
    char board[SIZE][SIZE] = { {'1', '2', '3'},
                               {'4', '5', '6'},
                               {'7', '8', '9'} };

    printf("Tic Tac Toe Board:\n");
    printBoard(board);

    return 0;
}