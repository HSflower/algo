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
						cout << "��ȣ ���� Ʋ��\n";
					}
					continue;
		case '[' :
		case ']' :  if(tmp == '[') {
						stck.pop();
					} else {
						cout << "��ȣ ���� Ʋ��\n";
					}
					continue;
		case '{' :
		case '}' :  if(tmp == '{') {
						stck.pop();
					} else {
						cout << "��ȣ ���� Ʋ��\n";
					}
					continue;
		}
	}
	cin>>str;
	/*
	bool wellMatched(const string& formula) {
	//���� ��ȣ ���ڵ�� �ݴ� ��ȣ���ڵ�
	const string opening("({["), closing(")}]");
	//�̹� ���� ��ȣ���� ������� ��� ����
	stack<char> openStack;
	for(int i=0 ; i<formula.size(); ++i) {
		//���� ��ȣ���� �ݴ� ��ȣ���� Ȯ���Ѵ�
		if(opening.find(formula[i]) != -1)
			//���� ��ȣ��� ������ ���ÿ� ����ִ´�.
			openStack.push(formula[i]);
		else {
			//�̿��� ���, ���� ������ ���ڿ� ���纸��.
			//������ ����ִ� ��쿡�� ����
			if(openStack.empty()) return false;
			//���� ¦�� �����ʾƵ� ����
			if(opening.find(openStack.top()) != closing.find(formula[i]))
				return false;
			//¦�� ���� ��ȣ�� ���ÿ��� pop
			openStack.pop();
		}
	}
	//������ ���� ��ȣ�� ����� ����
	return openStack.empty();
}