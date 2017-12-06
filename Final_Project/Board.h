/*
 * Board.h
 * Header file for the board class
 */
#include <iostream>
#include <vector>

using namespace std;

class Board
{
  public:
    enum{ROWS = 31, COLS = 31};
    char chess_board[ROWS+1][COLS+1];
  public:
    // Constructor
    Board();

    // Print the board
    void show_board();
};