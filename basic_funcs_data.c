// BASIC FUNCTIONS -----------------------------------------------------------------------------------

// Function to get the mark of a player.
char getMark(int playerNumber){
    switch (playerNumber){
        case 0:
            return 'O';
        case 1:
            return 'X';
    }
    return '#';
}

// Function to place a mark on the board.
void placeMark(char board[3][3], int row, int col, char mark){
    board[row][col] = mark;
}