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
	//테스트케이스 수 1-10 입력
	cout << "testcase :";
	cin>>c;

	//와일드카드 문자열 W입력
	cout << "wildcard string :";
	//cin>>wildarr[i];
	cin>>str;
	//파일명의 수, 
	cout << "number of files :";
	cin>>n;
	//파일명1-100길이입력, 공백없이 알파벳대소문자숫자+ *,?
	for(int i=0 ; i<n ; i++){
		cin>>filearr[i];
	}
	//스택 저장?

	int finds = str.find("*");
	int findq = str.find("?");

	//?
	for(int i=0; i<n ; i++) {
		//finds전까지 같고, 후부터 같은거 찾으면 전부 해당 - s가 여러개면 그 개수만큼비교
		//finds없는부분만 같으면 모두 가능
		//findq전까지 같고, 후부터 같은거 찾고, 글자수는 한글자만

	//해당되는 파일명 출력
	//아스키코드순서 : 숫자,대문자,소문자 순으로 출력

}