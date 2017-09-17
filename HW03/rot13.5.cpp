/**
 * by Zhaoyuan Fang
 * Rot13.5
 * CSE20133 Homework3
 */

#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
using namespace std;

int main() {
  string s;
  while(getline(cin,s)){            //use getline() to get the whole line
    string ans;                     //answer for the current case
    char c;
    for(int i=0;i<s.length();i++){
      if(isalpha(s[i])){            //if it is a letter
        if(isupper(s[i])){          //if it is uppercase
          c='A'+(s[i]+13-'A')%26;
          ans += c;
        }else{
          c='a'+(s[i]+13-'a')%26;   //if it is lowercase
          ans += c;
        }
      }else if(isalnum(s[i])){      //if it is a number
        c='0'+(s[i]+5-'0')%10;
        ans +=c;
      }else{                        //if not both, just append it to the ans
        ans += s[i];
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}