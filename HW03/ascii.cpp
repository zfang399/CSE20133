/**
 * by Zhaoyuan Fang
 * ASCII Characters Printout
 * CSE20133 Homework 3
*/

#include <iostream>
using namespace std;

int main() {
  char c;
  for(int i=0;i<10;i++){        //the format "00x"
    c=i;
    if(isprint(c) && c!=' '){   //printable and is not whitespace
      cout<<"00"<<i<<" "<<c<<endl;
    }
  }
  for(int i=10;i<100;i++){	//the format "0xx"
    c=i;
    if(isprint(c) && c!=' '){   //printable and is not whitespace
      cout<<"0"<<i<<" "<<c<<endl;
    }
  }

  for(int i=100;i<128;i++){     //the format "xxx"
    c=i;
    if(isprint(c) && c!=' '){   //printable and is not whitespace
      cout<<i<<" "<<c<<endl;
    }
  }

  return 0;
}