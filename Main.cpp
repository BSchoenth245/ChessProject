#include <iostream>
#include "Functions.h"

using namespace std;

int main() {
  int turnCounter = 0;
  bool validMove = false;
  // bool checkmate = false;

  BoardSpace **boardSpaces = new BoardSpace *[8];
  for (int i = 0; i < 8; i++) {
    boardSpaces[i] = new BoardSpace[8];
  }
  Board board(boardSpaces);

  if (turnCounter == 0) {
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        if ((i == 0 || i == 7) && (j == 0 || j == 7)) {
          boardSpaces[i][j].setState('r');
        } else if ((i == 0 || i == 7) && (j == 1 || j == 6)) {
          boardSpaces[i][j].setState('n');
        } else if ((i == 0 || i == 7) && (j == 2 || j == 5)) {
          boardSpaces[i][j].setState('b');
        } else if ((i == 0 || i == 7) && (j == 3)) {
          boardSpaces[i][j].setState('q');
        } else if ((i == 0 || i == 7) && (j == 4)) {
          boardSpaces[i][j].setState('k');
        } else if ((i == 1 || i == 6)) {
          boardSpaces[i][j].setState('p');
        }
        if (i == 0 || i == 1) {
          boardSpaces[i][j].setPieceColor('b');
        } else if (i == 6 || i == 7) {
          boardSpaces[i][j].setPieceColor('w');
        }
      }
    }
  }

  board.printBoard(boardSpaces);
  int userRow, userCol, newRow, newCol;

  // while(checkmate == false){
  for (int i = 0; i < 8; i++) {
    
    if (turnCounter % 2 == 0) {
      cout << "\nWhite's turn" << endl;
      cout << "\n\nWhich piece would you like to move?(row column)" << endl;
      cin >> userRow >> userCol;
      while (boardSpaces[userRow - 1][userCol - 1].getPieceColor() != 'w') {
        if (boardSpaces[userRow - 1][userCol - 1].getState() == ' '){
          cout << "There is no piece there, try again" << endl;
          cout << "\n\nWhich piece would you like to move?(row column)" << endl;
          cin >> userRow >> userCol;
        }
        else if(boardSpaces[userRow - 1][userCol - 1].getPieceColor() == 'b'){
        cout << "That is not a white piece. Select Again" << endl;
        cout << "\n\nWhich piece would you like to move?(row column)" << endl;
        cin >> userRow >> userCol;
        }
      }
    }

    else {
      cout << "\nBlack's turn" << endl;
      cout << "\n\nWhich piece would you like to move?(row column)" << endl;
      cin >> userRow >> userCol;
      while (boardSpaces[userRow - 1][userCol - 1].getPieceColor() != 'b') {
        if(boardSpaces[userRow - 1][userCol - 1].getState() == ' '){
          cout << "There is no piece there, try again" << endl;
          cout << "\n\nWhich piece would you like to move?(row column)" << endl;
          cin >> userRow >> userCol;
        }
        else if(boardSpaces[userRow - 1][userCol - 1].getPieceColor() == 'w'){
        cout << "That is not a black piece. Select Again" << endl;
        cout << "\n\nWhich piece would you like to move?(row column)" << endl;
        cin >> userRow >> userCol;
        }
      }
    }

    movement move;
    while (validMove == false) {
      cout << "\n\nWhere would you like to move it to?(row column)" << endl;
      cin >> newRow >> newCol;
      move.Move(boardSpaces, userRow - 1, userCol - 1, newRow - 1, newCol - 1, validMove);
    }

    board.printBoard(boardSpaces);
    validMove = false;

    turnCounter += 1;
  }
  for (int i = 0; i < 8; i++) {
    delete[] boardSpaces[i];
  }
  delete[] boardSpaces;

  return 0;
}
