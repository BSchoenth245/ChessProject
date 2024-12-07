#include "Functions.h"
#include <iostream>
using namespace std;

bool PawnMove(BoardSpace **board, int row, int col, int row2, int col2,
                bool &valid) {
    if (col == col2 && board[row2][col2].getState() != ' ') {
      cout << "That is not a valid move" << endl;
    }


    else if ((row == 1 || row == 6) &&
             (((row - row2 == 1) || (row - row2 == 2)) ||
              ((row - row2 == -1) || (row - row2 == -2))) &&
             (col == col2) && board[row2][col2].getState() == ' ') {
      board[row2][col2].setState('p');
      if (row - row2 > 0) {
        board[row2][col2].setPieceColor('w');
      } else if (row - row2 < 0) {
        board[row2][col2].setPieceColor('b');
      }
      board[row][col].setState(' ');
      valid = true;
    }

    else if (col == col2 && ((row - row2) < 2 && (row - row2) > -2) &&
             board[row2][col2].getState() == ' ') {
      if ((row - row2 == 1) || (row - row2 == -1)) {
        board[row2][col2].setState('p');
        if (row - row2 > 0) {
          board[row2][col2].setPieceColor('w');
        } else if (row - row2 < 0) {
          board[row2][col2].setPieceColor('b');
        }
        board[row][col].setState(' ');
        valid = true;
      }
    }

    // attacking logic for pawns
    else if ((col - col2 == 1 || col - col2 == -1) &&
             (board[row2][col2].getState() != ' ') &&
             (row - row2 == 1 || row - row2 == -1)) {
      if (board[row2][col2].getPieceColor() !=
          board[row][col].getPieceColor()) {
        board[row2][col2].setState('p');
        if (row - row2 > 0) {
          board[row2][col2].setPieceColor('w');
        } else if (row - row2 < 0) {
          board[row2][col2].setPieceColor('b');
        }
        board[row][col].setState(' ');
        valid = true;
      } else {
        cout << "That is not a valid move" << endl;
      }
    } else {
      cout << "That is not a valid move" << endl;
    }

    return valid;
  }
