#include "basic_funcs_data.h"

// GAME LOGIC FUNCTIONS ------------------------------------------------------------------------------------------------

// Function to check if there is a winner. Returns 1 if there is a winner, 0 otherwise.
int isThereWinner(char board[3][3]){
    int i;
    for (i=0; i<3; i++){
        // checking rows
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != EMPTY){
            return 1;
        }
        // checking columns
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != EMPTY){
            return 1;
        }
    }
    // checking diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != EMPTY){
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != EMPTY){
        return 1;
    }
    return 0;
}

// Function to check if there is a draw. Returns 1 if there is a draw, 0 otherwise.
int isThereDraw(char board[3][3]){
    if (isThereWinner(board)){
        return 0;
    }
    int i;
    for (i=0; i<3; i++){
        int j;
        for (j=0; j<3; j++){
            if (board[i][j] == EMPTY){
                return 0;
            }
        }
    }
    return 1;
}

// Function to check if the game is finished. Returns 1 if the game is finished, 0 otherwise.
int isGameFinished(char board[3][3], int playerNumber){
    if (isThereWinner(board) || isThereDraw(board)){
        return 1;
    }
    return 0;
}
