#ifndef HEADER_H
#define HEADER_H

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
  movement();

  void GeneralMove(BoardSpace**, int, int, int, int,
                   bool&);
};


bool PawnMove(BoardSpace**, int, int, int, int,
                bool&);

#endif