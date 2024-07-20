// A Tic-tac-toe game in C that can allow player vs player games and player vs computer games. 
// If you choose to play the computer, you can decide whether to be player 1 or player 2.
// The computer uses the minimax algorithm to decide the best move to make.

// INCLUDES ------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include "running_game.h"
#include "non_game_funcs.h"

// MAIN PROGRAM -------------------------------------------------------------------------------------------------

// Main function.
int main(){
    
    char choice;
    do {
        printf("Do you want to play with a person or the computer? Enter 'p' for person and 'c' for computer.\n");
        scanf("%c", &choice);
        clearInputBuffer();
    } while (choice != 'p' && choice != 'c');

    if (choice == 'p'){
        doPlayerVsPlayerGame();
        return 0;
    }
    
    if (choice == 'c'){
        doPlayerVsComputerGame();
        return 0;
    }

    return 0;
}