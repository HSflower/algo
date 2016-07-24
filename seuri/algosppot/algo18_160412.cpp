#include <iostream>
using namespace std;

int main(){
	int t=1, a=1, b=1;
	// t=n, a=n-2, b=n-1
	while(a<100){
		cout<<a<<" ";
		cout<<b<<" ";
		t = b+a; //3 2 1
		a = b; //1>2
		b = t; //2>3
		//t = a+b; //5 2 3
		cout<<t<<" ";
		cout<<endl;
	}
	cin >> t;
}

