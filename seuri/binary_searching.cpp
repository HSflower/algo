#include <iostream>
#include <string>
using namespace std;

int search(int start, int end, int arr[], int object){
	int mid = (start+end) / 2;

	//�Է����Ѿ��� ����� ã�� �� ���� ��츦 ó���ϴ� ��� - �ִ��� ���� ���ɼ��� �����ϰ� ó��
	if(start>=end) {
		cout<<"���� ã���� ����. ";
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
	cout << "�ε����� " << key;
	cin >> key;

	//��谪 �׽�Ʈ, ����ó�� �׽�Ʈ ���� ���� Ȯ��
}



