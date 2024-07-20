#ifndef RUNNING_GAME_H
#define RUNNING_GAME_H

void displayBoard(char board[3][3]);
int isPositionValid(char board[3][3], int row, int col);
void displayEndGameInformation(char board[3][3], int playerNumber);
void executePlayerTurn(char board[3][3], int *pCurrentPlayerNumber);
void executeComputerPlayerTurn(char board[3][3], int *pCurrentPlayerNumber);
void doPlayerVsPlayerGame();
void doPlayerVsComputerGame();

#endif