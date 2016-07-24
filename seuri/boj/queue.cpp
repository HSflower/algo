#include <iostream>
#include <queue>
#include <string>
#include <map>
#include <stdlib.h>
using namespace std;
#define PUSH 1
#define FRONT 2
#define BACK 3
#define SIZE 4
#define EMPTY 5
#define POP 6
/*
int main()
{
	int n;
	cin >> n;
	
	string str;
	int stn = 0;
	int idx = 0;
	
	static map<string, int> m;
	m["push"] = PUSH;
	m["front"] = FRONT;
	m["back"] = BACK;
	m["size"] = SIZE;
	m["empty"] = EMPTY;
	m["pop"] = POP;
	
	queue<int> Queue;

	for(int i=0 ; i<n ; i++){
		getline(cin,str) ;
		if( str == "") getline(cin,str);
		idx = str.find_first_of(" ");
		if( idx >= 0 ) {
			string chs = str.substr(idx+1,1);
			stn = atoi(chs.c_str());
			str = str.substr(0,idx);
		} 
	
		switch (m[str]) {
			case PUSH : 
				Queue.push(stn);
				break;
			case  FRONT : 
				if( !Queue.empty() ){
					cout << Queue.front() << endl;
				} else {
					cout << "-1" << endl ;
				}
				break;
			case  BACK : 
				if( !Queue.empty() ) {
					cout << Queue.back() << endl;
				} else {
					cout << "-1" << endl ;
				}
				break;
			case  SIZE : 
				cout << Queue.size() << endl;
				break;
			case  EMPTY : 
				if( !Queue.empty() ) {
					cout << Queue.empty() << endl;
				} else {
					cout << "1" << endl ;
				}
				break;
			case  POP : 
				if( !Queue.empty() ) {
					cout << Queue.front() << endl;
					Queue.pop();
				} else {
					cout << "-1" << endl;
				}
				break;
			default :
				break;
		}
	}
	
	
	return 0;
}
*/