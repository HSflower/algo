#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main() {
	int n=0 ;
	cin >> n;
	int sol=0 ;
	double solu2 = n/2, solu3 = n/3;
	if(n%2 == 1) sol = pow(3, solu2);
	if(n%2 == 0) sol = pow(3, solu2);
	if(n%3 == 1) sol = pow(6, solu3)*3*(n-1); //마지막 2*1블럭 넣는 방법
	if(n%3 == 0) sol = pow(6, solu3);
	//8 (81)171, 2 3
	cout << sol%10007;
}

http://wootool.tistory.com/87