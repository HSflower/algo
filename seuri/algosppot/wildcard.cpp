#include <iostream>
#include <string>
using namespace std;

int c;
//int wildarr[];
string str;
int n;
//int filearr[];
string filestr[];

int main() {
	//�׽�Ʈ���̽� �� 1-10 �Է�
	cout << "testcase :";
	cin>>c;

	//���ϵ�ī�� ���ڿ� W�Է�
	cout << "wildcard string :";
	//cin>>wildarr[i];
	cin>>str;
	//���ϸ��� ��, 
	cout << "number of files :";
	cin>>n;
	//���ϸ�1-100�����Է�, ������� ���ĺ���ҹ��ڼ���+ *,?
	for(int i=0 ; i<n ; i++){
		cin>>filearr[i];
	}
	//���� ����?

	int finds = str.find("*");
	int findq = str.find("?");

	//?
	for(int i=0; i<n ; i++) {
		//finds������ ����, �ĺ��� ������ ã���� ���� �ش� - s�� �������� �� ������ŭ��
		//finds���ºκи� ������ ��� ����
		//findq������ ����, �ĺ��� ������ ã��, ���ڼ��� �ѱ��ڸ�

	//�ش�Ǵ� ���ϸ� ���
	//�ƽ�Ű�ڵ���� : ����,�빮��,�ҹ��� ������ ���

}