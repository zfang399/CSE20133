/**
 * by Zhaoyuan Fang
 * CSE20133 HW5
 * mult.cpp
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;

int main(int argc,char * argv[]){
  int i=0;
  if(argc!=3){
    cerr<<"mult <row> <columns>"<<endl;
    return 1;
  }
  long int m=0,n=0;
  m=strtol(argv[1],NULL,16);
  n=strtol(argv[2],NULL,16);
  if(m<=0 || n<=0){
    cerr<<"mult <rows> <columns>"<<endl;
    return 1;
  }
  long long tot=m*n;
  int ltot=1;
  while(tot>0){
    ltot++;
    tot/=10;
  }
  for(int i=0;i<=m;i++){
    for(int j=0;j<=n;j++){
      if(i==0 && j==0){
        cout<<setw(ltot)<<"*";
      }else if(i==0){
        cout<<uppercase<<hex<<setw(ltot)<<j;
      }else if(j==0){
        cout<<uppercase<<hex<<setw(ltot)<<i;
      }else{
	cout<<uppercase<<hex<<setw(ltot)<<i*j;
      }
    }
    cout<<endl;
  }
  return 0;
}

