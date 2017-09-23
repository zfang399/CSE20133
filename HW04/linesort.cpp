/**
 * By Zhaoyuan Fang
 * Sort the chars of each line
 * CSE20133 Extra Credit 1
 */

#include <iostream>
#include <cstring>
using namespace std;

#define LINE_SIZE (1000)
int main(){
  char ch[LINE_SIZE];
  while(cin.getline(ch,LINE_SIZE)){
    int l=strlen(ch);
    //selection sort
    for(int i=0;i<l-1;i++){
      for(int j=i+1;j<l;j++){
        if(ch[i]>ch[j]){
          swap(ch[i],ch[j]);   //if a pair of wrong sequence detected, swap
        }
      }
      cout<<ch[i];
    }
    cout<<endl;
    memset(ch,0,sizeof(ch));   //clear the array for the next line
  }
  if(!cin.eof()){              //report error
    cerr<<"Your line is too long!";
    return 1;
  }
  return 0;
}
