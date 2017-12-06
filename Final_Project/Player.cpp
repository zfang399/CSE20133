/*
 * Player.cpp
 * Implementation of the functions of player class
 */
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>

#include "Player.h"

using namespace std;

// Default constructor
Player::Player(){
  this->name = "Guest Player";
  this->piece_type = ' ';
  this->last_x = 0;
  this->last_y = 0;
  this->pointer_board = NULL;
}

void Player::get_info(int index){
  // Get the name of the player
  cout<<"Player "<<index<<" Name: ";
  cin >> this->name;

  //Keep going until a proper name is given
  while(!cin){
  	cin.clear();
  	cin.ignore(2048, '\n');
  	cout<<"Player"<<index<<", please enter a proper name: ";
  	cin >> this->name;
  }

  // Get the chess piece of the player
  cout<<"Hello "<<this->name<<", please enter chess type: ";
  cin >> this->piece_type;

  // Keep going until a proper chess piece is given
  while(!cin){
  	cin.clear();
  	cin.ignore(2048, '\n');
  	cout<<"Player"<<index<<", please enter a proper chess type: ";
  	cin >> this->piece_type;
  }
}

// Link the board pointer to the board being used
void Player::link_to_Board(Board * pboard){
  this->pointer_board = pboard;
}

// Check if this position is occupied by another piece
bool Player::occupied(int x, int y){
  if(this->pointer_board->chess_board[x][y]!=' '){
  	return true;
  }
  return false;
}

// Check if this position is in the board
bool Player::inboard(int x, int y){
  if(x > 0 && x < ROWS - 1 && y > 0 && y < COLS - 1){
  	return true;
  }
  return false;
}

void Player::place_piece(){
  // use char because the input could be anything
  char x,y;
  cout<<this->name<<", please input your next move (Row and Col, separated by space)"<<endl;
  cin>> x >> y;
  bool valid_x = false, valid_y = false;

  while(!(valid_x && valid_y)){
    // check if x input is a legal row number
    if( (x - '0' >= 0) && (x - '9' <= 0) ){
      // between 0 and 9
      valid_x = true;
      this->last_x = x - '0';
    }else if(x - 'A' >= 0){
      // larger than or equal to 10
      valid_x = true;
      this->last_x = x - 'A' + 10;
    }else{
      // otherwise they are not valid
      valid_x = false;
    }

    // check if y input is a legal row number
    if( (y - '0' >= 0) && (y - '9' <= 0) ){
      // between 0 and 9
      valid_y = true;
      this->last_y = y - '0';
    }else if(y - 'A' >= 0){
      // larger than or equal to 10
      valid_y = true;
      this->last_y = y - 'A' + 10;
    }else{
      // otherwise they are not valid
      valid_y = false;
    }

    // re-enter if not valid
    if(!valid_x || !valid_y){
      cout << this->name << ", please give legal inputs(Row and Col, separated by space)" << endl;
      cin >> x >> y;
      continue;
    }

    // update the x and y values
    last_x = 2 * last_x + 1;
    last_y = 2 * last_y + 1;

    // re-enter if the value is not in the board
    if(!this->inboard(this->last_x, this->last_y)){
      valid_x = false;
      valid_y = false;
      cout << this->name << ", please give legal inputs(Row and Col, separated by space)" << endl;
      cin >> x >> y;
      continue;
    }

    // re-enter if the position is occupied
    if(this->occupied(this->last_x, this->last_y)){
      valid_x = false;
      valid_y = false;
      cout << this->name << ", that position is occupied! Please re-enter: "<<endl;
      cin >> x >> y;
      continue;
    }

    // All the conditions are met, valid.
    valid_x = true;
    valid_y = true;
  }

  // After getting proper inputs, set the chesspiece
  pointer_board->chess_board[last_x][last_y] = piece_type;
}

string Player::get_name(){
  return name;
}

char Player::get_piece(){
  return piece_type;
}

void Player::reset_piece(char new_piece){
  piece_type = new_piece;
}

bool Player::win_game(){
  // The player wins the game after the last move
  // So we only need to check the conditions for the newly placed chess piece

  // Horizontal connections
  int rnum = last_x;
  int connection = 1;
  for(int j = 1; j < 15; j++){
    // Connection would be 0 if this is not the player's own chess type
    if(pointer_board->chess_board[rnum][2 * j + 1] == piece_type){
      // If this is not the first in the row
      if(pointer_board->chess_board[rnum][2 * j + 1] == pointer_board->chess_board[rnum][2 * j - 1]){
        connection++;
      }else{
        // First in the row
        connection = 1;
      }
    }else{
      connection = 0;
    }

    // Check if the current connection is enough to win
    if(connection == 5){
      return true;
    }
  }

  // Vertical connections
  int cnum = last_y;
  connection = 1;
  for(int i = 1; i < 15; i++){
    // Connection would be 0 if this is not the player's own chess type
    if(pointer_board->chess_board[2 * i + 1][cnum] == piece_type){
      // If this is not the first in the column
      if(pointer_board->chess_board[2 * i + 1][cnum] == pointer_board->chess_board[2 * i - 1][cnum]){
        connection++;
      }else{
        // First in the column
        connection = 1;
      }
    }else{
      connection = 0;
    }

    // Check if the current connection is enough to win
    if(connection == 5){
      return true;
    }
  }

  // Upperright to Lowerleft connections
  connection = 1;
  // Proceed only if the diagonal has enough space
  if(rnum + cnum >= 4 && rnum + cnum <= 24){
    for(int i = 1; i < rnum + cnum; i++){
      if(pointer_board->chess_board[2 * i + 1][2 * (rnum + cnum - i) + 1] == piece_type){
        //If this is not the first in the diagonal connection
        if(pointer_board->chess_board[2 * i + 1][2 * (rnum + cnum - i) + 1] == pointer_board->chess_board[2 * i - 1][2 * (rnum + cnum - i) - 1]){
          connection++;
        }else{
          //First in the diagonal connection
          connection = 1;
        }
      }else{
        connection = 0;
      }

      // Check if the current connection is enough to win
      if(connection == 5){
        return true;
      }
    }
  }

  // Upperleft to Lowerright connections
  connection = 1;
  //Proceed only if the diagonal has enough space
  if(!( (cnum > 10 && rnum < 4) || (cnum < 4 && rnum > 10))){
    int common = min(cnum, rnum);
    int cstart = cnum - common + 1;
    int rstart = rnum - common + 1;
    for(cstart=cstart, rstart=rstart; cstart < 15 && rstart < 15; cstart++, rstart++){
      if(pointer_board->chess_board[2 * rstart + 1][2 * cstart + 1] == piece_type){
        //If this is not the first in the  diagonal connection
        if(pointer_board->chess_board[2 * rstart + 1][2 * cstart + 1] == pointer_board->chess_board[2 * rstart - 1][2 * cstart - 1]){
          connection++;
        }else{
          //First in the diagonal connection
          connection = 1;
        }
      }else{
        connection = 0;
      }

      // Check if the current connection is enough to win
      if(connection == 5){
        return true;
      }
    }
  }

  return false;
}