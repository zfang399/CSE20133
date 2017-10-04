/**
 * by Zhaoyuan Fang
 * CSE20133 HW5
 * number.cpp
 */

#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

int main(int argc, char * argv[])
{
  //get the numbers and check conditions
  double num=0,maxn=0;

  //not exactly two numbers, report error
  if(argc!=3){
    cerr<<"Usage: numbers <numbers> <range>"<<endl;
    return 1;
  }

  //get number of numbers and the max range
  num=strtod(argv[1],NULL);
  maxn=strtod(argv[2],NULL);

  //if either of them is not an integer, or num is not positive
  if(num-int(num)!=0 || maxn-int(maxn)!=0 || num<=0 || maxn==0){
    cerr<<"Usage: numbers <numbers> <range>"<<endl;
    return 1;
  }

  //generate random numbers
  srand(time(NULL));
  for(int i=0;i<num;i++){
    cout<<(float)rand()/RAND_MAX*maxn<<endl;
  }
  return 0;
}