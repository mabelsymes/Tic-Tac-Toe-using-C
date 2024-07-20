#ifndef GAME_STATES_H
#define GAME_STATES_H

int isThereWinner(char board[3][3]);
int isThereDraw(char board[3][3]);
int isGameFinished(char board[3][3], int playerNumber);

#endif