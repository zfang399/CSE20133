/**
 * by Zhaoyuan Fang
 * Text Filter
 * CSE20133 Homework4
 */

#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

#define BUFFER_WIDTH (10000)
int main()
{
  char ch[10000000];
  char buffer[BUFFER_WIDTH];
  int l=0;
  while(cin.getline(buffer,BUFFER_WIDTH)){
    strcpy(ch+l,buffer);
    l += strlen(buffer)+1;
  }
  bool newline=true;    //flag to check if the current line is a new one
  for(int i=0;i<l;i++){
    if(isalnum(ch[i]) || ch[i]==39 || ch[i]==45){  //the characters to save
      if(newline){
        newline=false;  //the current line is no longer a new line
      }
      if(isalpha(ch[i])){     //convert the uppercase letters
        if(islower(ch[i])){
          ch[i]=ch[i]-32;
        }
      }
      cout<<ch[i];	//print it
    }else{              //the case of undesired chars
      if(!newline){     //if not newline already, get a new line and mark it
        cout<<endl;
        newline=true;
      }
    }
  }
  return 0;
}