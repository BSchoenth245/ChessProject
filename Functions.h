#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <memory>

#include <iostream>
using namespace std;

class BoardSpace {
private:
  char state;
  char color;
  char pieceColor;

public:
  void setState(char newState) { state = newState; }
  char getState() { return state; }

  void setColor(char newColor) { color = newColor; }
  char getColor() { return color; }

  void setPieceColor(char newColor) { pieceColor = newColor; }
  char getPieceColor() { return pieceColor; }
};

class Board {
public:
  Board(BoardSpace **board) {
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        board[i][j].setState(' ');
        if (i % 2 == 0 && j % 2 == 0) {
          board[i][j].setColor('W');
        } else if (i % 2 == 1 && j % 2 == 1) {
          board[i][j].setColor('B');
        }
      }
    }
  }

  void printBoard(BoardSpace **board) {
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        cout << "|" << board[i][j].getState();
      }
      cout << "|" << endl;
    }
  }
};

class movement {
public:
  movement() {}

  void GeneralMove(BoardSpace **board, int row, int col, int row2, int col2,
                   bool &valid) {

    switch (board[row][col].getState()) {
    case 'p':
      PawnMove(board, row, col, row2, col2, valid);
    case 'r':
    case 'b':
    case 'n':
    case 'q':
    case 'k':
    default:
    }
    if (board[row][col].getState() == 'p') {

      // checks if the space being moevd to is occupied
    }

    // Movement for Rook

    // Enters movement parameters
    if (board[row][col].getState() == 'r') {

      // checks if the space being moevd to is occupied
      for (int i = ; i <)
    }

    // Movement for Knight
    // Movement for Bishop
    // Movement for Queen
    // Movement for King
  }
  bool PawnMove(BoardSpace **board, int row, int col, int row2, int col2,
                bool &valid) {
    if (col == col2 && board[row2][col2].getState() != ' ') {
      cout << "That is not a valid move" << endl;
    }

    /*if the pawns have moved, and sets logic for a 2 space move
    if it is the pawns first move and is occupied
    */
    else if ((row == 1 || row == 6) &&
             (((row - row2 == 1) || (row - row2 == 2)) ||
              ((row - row2 == -1) || (row - row2 == -2))) &&
             (col == col2) && board[row2][col2].getState() != ' ') {
      board[row2][col2].setState('p');
      if (row - row2 > 0) {
        board[row2][col2].setPieceColor('w');
      } else if (row - row2 < 0) {
        board[row2][col2].setPieceColor('b');
      }
      board[row][col].setState(' ');
      valid = true;
    }
    // if the pawn is not the first move and is occupied
    else if (col == col2 && ((row - row2) < 2 && (row - row2) > -2) &&
             board[row2][col2].getState() != ' ') {
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
  }
};

#endif