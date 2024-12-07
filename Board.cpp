#include "Functions.h"
#include <iostream>
using namespace std;


Board::Board(BoardSpace **board) {
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
  };

  void printBoard(BoardSpace **board) {
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        cout << "|" << board[i][j].getState();
      }
      cout << "|" << endl;
    }
  }