#include <stdio.h>

char board[3][3] = { {'1','2','3'},
                     {'4','5','6'},
                     {'7','8','9'} };

void displayBoard() {
    printf("\n\n TIC TAC TOE \n\n");
    for(int i=0; i<3; i++) {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if(i < 2) printf("---|---|---\n");
    }
}

int checkWin() {
    for(int i=0; i<3; i++) {
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2]) return 1;
        if(board[0][i]==board[1][i] && board[1][i]==board[2][i]) return 1;
    }
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2]) return 1;
    if(board[0][2]==board[1][1] && board[1][1]==board[2][0]) return 1;

    return 0;
}

int main() {
    int choice, row, col, turn = 1, filled = 0;
    char mark;
    while(1) {
        displayBoard();
        turn = (turn % 2) ? 1 : 2;
        printf("\nPlayer %d, enter your move (1-9): ", turn);
        scanf("%d", &choice);

        mark = (turn == 1) ? 'X' : 'O';
        row = (choice - 1) / 3;
        col = (choice - 1) % 3;

        if(choice < 1 || choice > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
            printf("Invalid move, try again.\n");
            continue;
        }

        board[row][col] = mark;
        filled++;

        if(checkWin()) {
            displayBoard();
            printf("\nPlayer %d wins!\n", turn);
            break;
        }

        if(filled == 9) {
            displayBoard();
            printf("\nIt's a draw!\n");
            break;
        }

        turn++;
    }
    return 0;
}
