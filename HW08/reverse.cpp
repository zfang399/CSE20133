/**
 * Homework 8B - Reverse a string
 * by Zhaoyuan Fang
 */
#include <iostream>
#include <cstring>

using namespace std;
#define SIZE (1000)

// Function prototype
void print_backwards(char * line);

// Main
int main() {
  char buffer[SIZE];
  while (cin.getline(buffer, SIZE)) {
    print_backwards(buffer);
    cout << endl;
  }
  if (!cin.eof()) {
    cerr << "Error: line too long." << endl;
    return 1;
  }
  return 0;
}

// Function definitions
void print_backwards(char * line){
  if(!*line) return;
  print_backwards(line+1);
  cout<<*line;
}