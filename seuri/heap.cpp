#include <iostream>
using namespace std;

//heap : 부모노드가 자식노드보다 큰 완전이진트리
//heap정렬 : heap을 구성하고, 오름차순/내림차순으로 정렬
int* heapSort(int* arr);
int* heapify(int* arr, int i, int n);
void testHeapSort();
/*
int main(){
	testHeapSort();
}
*/
void testHeapSort(){
	int a[10] = {10,5,8,7,6,9,4,3,2,1};
	//int* arr = a;	//arr = heapSort(arr);
	heapSort(a);
	for(int i=0; i<10; i++) cout << a[i] << " ";
}

int* heapSort(int* arr){
	int n = 10;
	cout << n <<endl;
	//a.length = 가장 오른쪽 원소-왼쪽원소+1로 유추
	for(int i = n/2 ; i>=1 ; i--){
		heapify(arr,i,n);
	}
	for(int i=0; i<10; i++) cout << arr[i] << " ";
	cout <<"heapcreate"<<endl;
	for(int i = n-1 ; i>=1 ; i--){
		int tmp = arr[1];
		arr[1] = arr[i+1];
		heapify(arr,1,i);
	}

	return arr;
}

int* heapify(int* arr, int h, int m){
	int v = arr[h];
	cout<<"sort:";
	for(int i=0; i<10; i++) cout << arr[i] << " ";
	cout<<endl;
	for(int j=2*h; j<=m ; j=2*j) {
		if(j<m && arr[j]<arr[j+1]){
			if(arr[j+1]!=NULL)	j++;
		}
		if(v>=arr[j]){
			break;
		}
		arr[j/2] = v;
	}
	return arr;
}