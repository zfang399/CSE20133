/**
 * by Zhaoyuan Fang
 * Compute the Average
 * CSE20133 Homework 3
 */

#include <iostream>
using namespace std;
int main() {
  int count = 0;                //count how many numbers are in the input
  double tmp;                   //used to read in the current number
  double tot = 0;               //save the sum of all numbers
  while(cin>>tmp){
    count++;                    //increment number of numbers
    tot += tmp;                 //add the new number to the sum
  }
  if (count == 0){
    cout<<0<<endl;              //if no number, output 0
  }else{
    cout<<tot/count<<endl;	//output the result sum over count
  }
  return 0;
}