/**
 * Homework 8C: Towers of Hanoi Solver
 * by Zhaoyuan Fang
 */
#include <iostream>
#include <cstdlib>
using namespace std;

// Function Prototype
void solve(unsigned int disks, char source, char destination, char spare);

// Main
int main(int argc, char ** argv) {
  if (argc != 2) {
    cerr << "Usage: " << argv[0] << " <# of disks>" << endl;
    return 1;
  }
  solve(atoi(*(argv + 1)), 'A', 'C', 'B');
  return 0;
}

// Function Definitions
void solve(unsigned int disks, char source, char destination, char spare){
  if(!disks) return;
  solve(disks-1,source,spare,destination);
  cout<<"Move a disk from "<<source<<" to "<<destination<<"."<<endl;
  solve(disks-1,spare,destination,source);
}