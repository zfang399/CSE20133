/*
 * Gomoku.cpp
 * Main function that integrates Board and Player.
 */

#include <iostream>
#include <cstdlib>
#include <vector>
#include <cctype>
#include "Player.h"

using namespace std;

int main(){
  cout<<"Welcome to the game of Gomoku!"<<endl;

  bool play_again = true;

  while(play_again){
    // Initialize the board
    Board k;

    // Initialize Player a
    Player a;
    a.get_info(1);
    a.link_to_Board(&k);

    // Initialize Player b
    Player b;
    b.get_info(2);
    b.link_to_Board(&k);
    while(a.get_piece() == b.get_piece()){
      cout<<b.get_name()<<", please enter another piece type! ";
      char new_piece;
      cin>>new_piece;
      b.reset_piece(new_piece);
    }

    // Play the game until someone wins, will break if b wins
    k.show_board();
    while(!b.win_game()){
      // Player a goes
      a.place_piece();

      // Print the updated board
      k.show_board();

      // Player a wins
      if(a.win_game()){
        cout<<"Congratulations "<<a.get_name()<<", you won!"<<endl;
        break;
      }

      // Player b goes
      b.place_piece();

      // Print the updated board
      k.show_board();

      // Player b wins
      if(b.win_game()){
        cout<<"Congratulations "<<a.get_name()<<", you won!"<<endl;
        break;
      }
    }

    // Ask the players if they want to play again
    cout<<"Do you want to play again? (Y/N) "<<endl;
    char yes_or_no;
    cin>>yes_or_no;
    if(toupper(yes_or_no) == 'Y'){
      play_again = true;
    }else{
      play_again = false;
    }
  }
  cout<<"Thank you. Bye!"<<endl;
  return 0;
}