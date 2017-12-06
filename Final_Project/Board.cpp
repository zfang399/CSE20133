/*
 * Board.cpp
 * Implementation of the functions of board class
 */
#include <iostream>
#include <cstdlib>
#include <vector>

#include "Board.h"

using namespace std;

//Constructor of Board
Board::Board(){
  // Vertical boarders represented by '|'
  // Horizontal boarders represented by '-'

  // Draw the inner grid of the Board
  for(int i = 1; i <= ROWS - 2; i+=2){
    for(int j = 1; j <= COLS - 2; j+=2){
      chess_board[i][j] = ' ';
      chess_board[i][j+1] = '|';
      chess_board[i+1][j] = '-';
      chess_board[i+1][j+1] = '-';
    }
  }

  // Draw the left and right boarders of the Board
  for(int i = 0; i < ROWS; i++){
    chess_board[i][0] = '|';
    chess_board[i][COLS-1] = '|';
  }

  // Draw the upper and lower boarders of the Board
  for(int j = 0; j < COLS; j++){
    chess_board[0][j] = '-';
    chess_board[ROWS-1][j] = '-';
  }

  // The last line and the last column are for coordinate axes
  // Leave the first one blank to match up with the grids
  chess_board[ROWS][0] = ' ';
  chess_board[0][COLS] = ' ';

  // Fill the column index from 1 to 9
  for(int i= 1; i < 20; i += 2){
    chess_board[ROWS][i] = i / 2 +48;
    chess_board[ROWS][i+1] = ' ';
  }

  // Fill the row index from 1 to 9
  for(int j = 1; j < 20; j += 2){
    chess_board[j][COLS] = j / 2 + 48;
    chess_board[j+1][COLS] = ' ';
  }

  // Fill the column index from A to E
  for(int i = 21; i < ROWS; i += 2){
    chess_board[ROWS][i] = i / 2 + 55;
    chess_board[ROWS][i+1] = ' ';
  }

  // Fill the row index from A to E
  for(int j = 21; j < COLS; j += 2){
    chess_board[j][COLS] = j / 2 + 55;
    chess_board[j+1][COLS] = ' ';
  }
}

//Print the whole Board
void Board::show_board(){
  for(int i = 0; i <= ROWS; i++){
    for(int j = 0; j <= COLS; j++){
      cout<<chess_board[i][j];
    }
    cout<<endl;
  }
}