#include "computer.h"
#include "game_states.h"
#include "basic_funcs_data.h"

// Minimax algorithm function to find highest score.
int minimax(char board[3][3], int depth, int currentPlayerNumber, int originalPlayerNumber){
    if (isThereWinner(board)){
        if (currentPlayerNumber == originalPlayerNumber){
            return -1;
        }
        else{
            return 1;
        }
    }
    if (isThereDraw(board)){
        return 0;
    }

    int NewPlayerNumber = !currentPlayerNumber;
    char markToPlace = getMark(currentPlayerNumber);

    if (currentPlayerNumber == originalPlayerNumber){
        int best_score = -1000;
        for (int i=0; i<3; i++){
            for (int j=0; j<3; j++){
                if (board[i][j] == EMPTY){
                    board[i][j] = markToPlace;   
                    int score = minimax(board, depth + 1, NewPlayerNumber, originalPlayerNumber);
                    board[i][j] = EMPTY;
                    if (score > best_score){
                        best_score = score;
                    }
                }
            }
        }
        return best_score;
    }
    else{
        int best_score = 1000;
        for (int i=0; i<3; i++){
            for (int j=0; j<3; j++){
                if (board[i][j] == EMPTY){
                    board[i][j] = markToPlace;
                    int score = minimax(board, depth + 1, NewPlayerNumber, originalPlayerNumber);
                    board[i][j] = EMPTY;
                    if (score < best_score){
                        best_score = score;
                    }
                }
            }
        }
        return best_score;
    }
}

// Function to get the best move for the computer player.
Position getBestMove(char board[3][3], int currentPlayerNumber){
    int originalPlayerNumber = currentPlayerNumber;
    int best_score = -1000;
    Position best_move = {-1,-1};

    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            if (board[i][j] == EMPTY){
                board[i][j] = getMark(currentPlayerNumber);
                int score = minimax(board, 0, !currentPlayerNumber, originalPlayerNumber);
                board[i][j] = EMPTY;
                if (score > best_score){
                    best_score = score;
                    best_move.row = i;
                    best_move.col = j;
                }
            }
        }
    }
    return best_move;
}