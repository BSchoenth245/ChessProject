#include "Functions.h"

#include <iostream>

using namespace std;

movement::movement()
{
}

void movement::GeneralMove(BoardSpace **board, int row, int col, int row2, int col2,
                           bool &valid)
{

    switch (board[row][col].getState()) {
    case 'p':
      PawnMove(board, row, col, row2, col2, valid);
    case 'r':
    case 'b':
    case 'n':
    case 'q':
    case 'k':
    default:
        return;
    }

    // Movement for Rook
    // Movement for Knight
    // Movement for Bishop
    // Movement for Queen
    // Movement for King
}