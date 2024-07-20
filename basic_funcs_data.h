#ifndef BASIC_FUNCS_DATA_H
#define BASIC_FUNCS_DATA_H

#define EMPTY '-'

typedef struct {
    int row;
    int col;
} Position;

char getMark(int playerNumber);
void placeMark(char board[3][3], int row, int col, char mark);

#endif