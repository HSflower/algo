#include <iostream>
#include <string>
using namespace std;
/*
void insertDataToArr(int arr[], int num) {
	for ( int i=1 ; i<num+1 ; i++ ) {
		arr[i] = rand() %20000;
	}
}

void swap(int *a, int *b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

//�켱������ ���� �ڽĳ���� �ε��� �� ��ȯ�ϴ� �Լ�
int IdxHighPriority(int arr[], int root, int num) {
	if(num<root*2) {return 0;}
	else if(num==root*2) {return root*2;}
	else {
		if(arr[root*2] < arr[root*2 +1]) { return root*2; }
		else {return root*2 +1;}
	}
}

//��Ʈ��� ��ġ��Ű�� �Լ�
void locateRootData(int arr[], int root, int num) {
	int rootData = arr[root];
	int currentIdx = root;
	int childIdx;

	while(childIdx=IdxHighPriority(arr, currentIdx, num)) {
		if(rootData > arr[childIdx]) {
			arr[currentIdx] = arr[childIdx];
			//������ ���� : swap(&arr[currentIdx], &arr[childIdx]);
			currentIdx = childIdx;
		} else { break; }
	}
	arr[currentIdx] = rootData;
}

//���� �� �����ϴ� �Լ�
void heapHealing(int arr[], int root, int num) {
	if(num>=root*2) {
		heapHealing(arr, root*2, num);
		heapHealing(arr, root*2+1, num);
		locateRootData(arr, root, num);
	}
}
int main() {

	return 0;
}
*/