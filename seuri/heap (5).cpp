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

//우선순위가 높은 자식노드의 인덱스 값 반환하는 함수
int IdxHighPriority(int arr[], int root, int num) {
	if(num<root*2) {return 0;}
	else if(num==root*2) {return root*2;}
	else {
		if(arr[root*2] < arr[root*2 +1]) { return root*2; }
		else {return root*2 +1;}
	}
}

//루트노드 위치시키는 함수
void locateRootData(int arr[], int root, int num) {
	int rootData = arr[root];
	int currentIdx = root;
	int childIdx;

	while(childIdx=IdxHighPriority(arr, currentIdx, num)) {
		if(rootData > arr[childIdx]) {
			arr[currentIdx] = arr[childIdx];
			//지속적 갱신 : swap(&arr[currentIdx], &arr[childIdx]);
			currentIdx = childIdx;
		} else { break; }
	}
	arr[currentIdx] = rootData;
}

//깨진 힙 복구하는 함수
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