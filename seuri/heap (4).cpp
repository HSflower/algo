#include <iostream>
#include <string>
using namespace std;
//두개의 스트링 입력, 편집횟수 출력

int main() {
	//동적배열.. dynamic programming을 하자..
	//char str1[10] = {};
	//char str2[10] = {};
	string str1;
	string str2;

	while(1) {
	cin >> str1;
	cin >> str2;

	int cnt = 0;
	if( str1.length() < str2.length() ) {
		string tmp;
		tmp = str1;
		str1 = str2;
		str2 = tmp;
	}
	int row = str2.length();
	int column = str1.length();
	//함수로 문자열 길이와 내용을 받거나 string으로 입력받아서 넘기면

	int *arr = new int[column][row];

	for
	for(int i=0 ; i<str2.length() ; i++) {
		//for( int j=i ; j<str2.length() ; j++ ) {
			if( str1[i]!=str2[i] ) cnt++;
		//}
	}
	cnt = cnt + (str1.length()-str2.length());
	cout << cnt << endl ;
	}
}