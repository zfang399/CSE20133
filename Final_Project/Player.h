/*
 * Player.h
 * Header file for the player class
 */

#include <iostream>
#include <string>
#include "Board.h"
using namespace std;

class Player
{
  private:
    string name;
    char piece_type;
    int last_x;
    int last_y;
    Board * pointer_board;
  public:
  	enum{ROWS = 31, COLS = 31};

  	//Constructor
  	Player();

    //Ask the user to input parameters
    void get_info(int index);

    //Link the player to the board that is being played on
    void link_to_Board(Board* pboard);

    //Check if this position is occupied by another chesspiece
    bool occupied(int x, int y);

    //Check if this position is on the board
    bool inboard(int x, int y);

    //Ask the user to put a piece onto board
    void place_piece();

    //Check if the player wins
    bool win_game();

    //Get the name of the player
    string get_name();

    //Get the chess type of the player
    char get_piece();

    //Set the chess piece again
    void reset_piece(char new_piece);

    //Deconstructor
    //~Player();

};