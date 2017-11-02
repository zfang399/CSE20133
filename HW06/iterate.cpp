#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

#define BUFFER_LEN (1000000)

int main(){
	char buffer[BUFFER_LEN];
	while(cin.getline(buffer,BUFFER_LEN)){
		char *ch=buffer;
		while(*ch!='\0'){
			*ch=tolower(*ch);
			++ch;
		}
		cout<<buffer<<endl;
	}
	if(!cin.eof()){
		cerr<<"Buffer can only hold 1,000,000 chars."<<endl;
		return 1;
	}
	return 0;
}