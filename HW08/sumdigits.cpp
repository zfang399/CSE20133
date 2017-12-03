/**
 * Homework 8A: Sum the Digits
 * by Zhaoyuan Fang
 */
#include <iostream>
#include <cmath>
using namespace std;

// Function prototype
unsigned int sum_digits(int number);

// Main
int main() {
  int number;
  while (cin >> number) {
    cout << sum_digits(number) << endl;
  }
  if (!cin.eof()) {
    cerr << "Error processing numbers" << endl;
    return 1;
  }
  return 0;
}

// Function Definitions
unsigned int sum_digits(int number){
  return number ? abs(number % 10) + sum_digits(number / 10) : 0;
}