#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int main(){
	string str;
	cin >> str;
	stack<int, vector<int>> stck;
	//stck.push(str[0]);
	for(int i=0 ; i<str.length() ; i++) {
		if(stck.empty()) continue;
		stck.push(str[i]);
		char tmp = stck.top();
		switch(str[i]) {
		case '(' :
		case ')' :	if(tmp == '('){
						stck.pop();
					} else {
						cout << "괄호 순서 틀림\n";
					}
					continue;
		case '[' :
		case ']' :  if(tmp == '[') {
						stck.pop();
					} else {
						cout << "괄호 순서 틀림\n";
					}
					continue;
		case '{' :
		case '}' :  if(tmp == '{') {
						stck.pop();
					} else {
						cout << "괄호 순서 틀림\n";
					}
					continue;
		}
	}
	cin>>str;
	/*
	bool wellMatched(const string& formula) {
	//여는 괄호 문자들과 닫는 괄호문자들
	const string opening("({["), closing(")}]");
	//이미 열린 괄호들을 순서대로 담는 스택
	stack<char> openStack;
	for(int i=0 ; i<formula.size(); ++i) {
		//여는 괄호인지 닫는 괄호인지 확인한다
		if(opening.find(formula[i]) != -1)
			//여는 괄호라면 무조건 스택에 집어넣는다.
			openStack.push(formula[i]);
		else {
			//이외의 경우, 스택 맨위의 문자와 맞춰보자.
			//스택이 비어있는 경우에는 실패
			if(openStack.empty()) return false;
			//서로 짝이 맞지않아도 실패
			if(opening.find(openStack.top()) != closing.find(formula[i]))
				return false;
			//짝을 맞춘 괄호는 스택에서 pop
			openStack.pop();
		}
	}
	//닫히지 않은 괄호가 없어야 성공
	return openStack.empty();
}