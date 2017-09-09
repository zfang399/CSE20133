/**
 * by Zhaoyuan Fang
 * Multiplication Table Generator
 * CSE20133 Homework 2
 */

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main(){
	int m,n;
	cin>>hex>>m>>n;
	int ltot=to_string(m*n).length()+1;
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