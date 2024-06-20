#include<stdio.h>

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

int checkWin(char board[SIZE][SIZE], char player) {
    // Check rows and columns
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return 1;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return 1;
    }
    return 0;
}

int main() {
    char board[SIZE][SIZE] = { {'1', '2', '3'},
                               {'4', '5', '6'},
                               {'7', '8', '9'} };
    char player = 'X';
    int choice;
    int row, col;
    int moves = 0;

    printf("Welcome to Tic Tac Toe!\n");
    printBoard(board);

    while (moves < SIZE * SIZE) {
        printf("Player %c, enter your move (1-9): ", player);
        scanf("%d", &choice);

        // Convert choice to board coordinates
        row = (choice - 1) / SIZE;
        col = (choice - 1) % SIZE;

        if (choice < 1 || choice > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
            printf("Invalid move. Try again.\n");
            continue;
        }

        // Make the move
        board[row][col] = player;
        moves++;

        printBoard(board);

        if (checkWin(board, player)) {
            printf("Player %c wins!\n", player);
            return 0;
        }

        // Switch player
        player = (player == 'X') ? 'O' : 'X';
    }

    printf("It's a draw!\n");
    return 0;
}