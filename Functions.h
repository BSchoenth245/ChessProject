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
  Board(BoardSpace**);

  void printBoard(BoardSpace**);
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