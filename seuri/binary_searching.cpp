#include <iostream>
#include <string>
using namespace std;

int search(int start, int end, int arr[], int object){
	int mid = (start+end) / 2;

	//입력제한없이 결과를 찾을 수 없는 경우를 처리하는 방법 - 최대한 오류 가능성을 간단하게 처리
	if(start>=end) {
		cout<<"값을 찾을수 없다. ";
		return -1;
	}
	if(arr[mid]<object) {
		search(mid+1,end,arr,object);
	} else if(arr[mid]>object) {
		search(start,mid-1,arr,object);
	} else {
		return mid;
	}

}

int main() {
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	int object = 0 ;
	cin >> object;

	int key = 5 ;
	int start = 0, end = 9;
	key = search(start,end, arr, object);
	cout << "인덱스는 " << key;
	cin >> key;

	//경계값 테스트, 예외처리 테스트 구문 으로 확인
}



