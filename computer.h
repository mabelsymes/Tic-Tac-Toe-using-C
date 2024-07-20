#ifndef COMPUTER_H
#define COMPUTER_H

#include "basic_funcs_data.h"

int minimax(char board[3][3], int depth, int currentPlayerNumber, int originalPlayerNumber);
Position getBestMove(char board[3][3], int currentPlayerNumber);

#endif