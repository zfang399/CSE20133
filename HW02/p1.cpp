#include <iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	if(n==0) return 0;
	else if(n<0){
		cout<<n<<endl;
		for(int i=n/2;i<0;i++){
			if(n%i==0){
				cout<<i<<endl;
			}
		}
		n=-n;
	}
	for(int i=1;i<=n/2;i++){
		if(n%i==0){
			cout<<i<<endl;
		}
	}
	cout<<n<<endl;
	return 0;
}