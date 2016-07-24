#include <iostream>
#include <string>
using namespace std;
#define X 100;
#define Y 100;
//동적배열
/*

bool jump(int (*arr)[100], int i, int j, int n){
			int dist=arr[i][j];
			if( (i+dist < n) && (j+dist < n) ) {
				//둘중하나
				if(arr[i][j+dist] != 0) {
					jump(arr, i , j+dist, n);
				} else return true;
				if(arr[i+dist][j] != 0) {
					jump(arr, i+dist, j, n);
				} else return true;
			}
			return jump(arr, i+dist,j, n) || jump(arr, i,j+dist, n)
			else return false;
}

int main() {

	//테스트케이스 수 c 입력(50이하)
	int n;
	cout << "외발뛰기 게임판 한 변의 크기 : ";
	cin >> n;
	cout << "외발뛰기 게임판에 입력할 정수들을 "<<n<<"개씩 입력";
	
	int arr[100][100];
	//1000*1000 int
	for(int i = 0 ; i<n ; i++) {
		for(int j=0; j<n ; j++){
			cin >> arr[i][j];
		}
	}
	//1-9, 잘못입력하는 경우 에러 처리
	//끝점은 0

	//탐색, 루트있으면yes/no
	int result = jump(arr,0,0,n);
	cout << result ;
	cin >> n;
}
*/