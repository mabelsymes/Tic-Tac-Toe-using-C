#include <stdio.h>
#include "computer.h"
#include "basic_funcs_data.h"
#include "non_game_funcs.h"
#include "game_states.h"

// DISPLAY FUNCTIONS ----------------------------------------------------------------------------------------------

// Function to display the board. 
void displayBoard(char board[3][3]){
    printf("      0   1   2\n");
    printf("    -------------\n");
    printf("  0 | %c | %c | %c |\n", board[0][0], board[0][1], board[0][2]);
    printf("    -------------\n");
    printf("  1 | %c | %c | %c |\n", board[1][0], board[1][1], board[1][2]);
    printf("    -------------\n");
    printf("  2 | %c | %c | %c |\n", board[2][0], board[2][1], board[2][2]);
    printf("    -------------\n\n");
}

// Function to check if a position is valid. Returns 1 if the position is valid, 0 otherwise.
int isPositionValid(char board[3][3], int row, int col){
    if (board[row][col] != EMPTY){
        printf("This position is already taken. Please choose another one\n");
        return 0;
    }
    return 1;
}

// Function to display the end game information. 
void displayEndGameInformation(char board[3][3], int playerNumber){

    displayBoard(board);

    printf("Game over!\n");
    if (isThereWinner(board)){
        printf("We have a winner! Well done to player %d\n", !playerNumber + 1);
    }
    else if (isThereDraw(board)){
        printf("It's a draw! Well played both players\n");
    }
}

// EXECUTING TURNS ------------------------------------------------------------------------------------------------

// Function to execute a player turn.
void executePlayerTurn(char board[3][3], int *pCurrentPlayerNumber){
    int row, col, result;
    printf("It is player %d's turn\n\n", *pCurrentPlayerNumber + 1);

    do {
        do{printf("Enter the row you want to place your mark at: ");
        result = scanf("%d", &row);} while (result != 1 || row < 0 || row > 2);

        do{printf("Enter the column you want to place your mark at: ");
        result = scanf("%d", &col);} while (result != 1 || col < 0 || col > 2);
    } while (!isPositionValid(board, row, col));

    char mark = getMark(*pCurrentPlayerNumber);
    placeMark(board, row, col, mark);

    *pCurrentPlayerNumber = !(*pCurrentPlayerNumber);
}

// Function to execute a computer player turn.
void executeComputerPlayerTurn(char board[3][3], int *pCurrentPlayerNumber){
    printf("It is player %d's turn\n\n", *pCurrentPlayerNumber + 1);

    Position computerMove = getBestMove(board, *pCurrentPlayerNumber);
    char markToPlace = getMark(*pCurrentPlayerNumber);
    placeMark(board, computerMove.row, computerMove.col, markToPlace);

    *pCurrentPlayerNumber = !(*pCurrentPlayerNumber);
}

// GAME MODES ------------------------------------------------------------------------------------------------

// Function to play a player vs player game.
void doPlayerVsPlayerGame(){
    char board[3][3];
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            board[i][j] = EMPTY;
        }
    }
    int playerNumber = 0;
    do {
        displayBoard(board);
        executePlayerTurn(board, &playerNumber);
    } while (!isGameFinished(board, playerNumber));
    displayEndGameInformation(board, playerNumber);  
}

// Function to play a player vs computer game.
void doPlayerVsComputerGame(){
    char board[3][3];
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            board[i][j] = EMPTY;
        }
    }
    int playerNumber = 0;

    char choice;
    do {
        printf("Do you want to be player 1 or player 2? Enter '1' for player 1 and '2' for player 2.\n");
        scanf("%c", &choice);
        clearInputBuffer();
    } while (choice != '1' && choice != '2');

    int humanPlayerNumber = choice == '1' ? 0 : 1;
    do {
        displayBoard(board);
        if (playerNumber == humanPlayerNumber){
            executePlayerTurn(board, &playerNumber);
        }
        else{
            executeComputerPlayerTurn(board, &playerNumber);
        }
        } while (!isGameFinished(board, playerNumber));
    displayEndGameInformation(board, playerNumber);

}