#include <iostream>
#include <string>

#include <vector>
#include <algorithm>
using namespace std;

#define HEAP_SIZE 5

/*
//최소 힙 함수 : 큰게 아래로 a>b일때, true를 return하여 a가 아래로 이동
bool compare(int a, int b){
	return a>b;
}

//최대 힙 생성 stl <vector>, <algorithm>
int main() {
	int arr[] = {6,4,2,9,3};
	int size = 5;
	//vector<int> v(&arr[0], &arr[5]);
	//make_heap(v.begin(), v.end());
	make_heap(&arr[0], &arr[5]);

	//<vector>에 push_back()함수 이용
	//push_heap()함수로 힙으로 만들어줌
	//<vector> front()함수로 가장 위의 원소에 접근
	//pop_heap() : 가장위의 원소가 마지막으로 이동
	//<vector> pop_back()함수로 마지막 원소 제거
	//힙정렬 : sort_heap()오름차순정렬
	
	int input = 3;
	vector <int> v;
	//push
	v.push_back(input);
	push_heap(v.begin(), v.end());
	//top
	cout << v.front() <<endl;
	//pop
	pop_heap(v.begin(), v.end());
	v.pop_back();
	//sort
	sort_heap(v.begin(), v.end());

	//최소 힙
	int input=3;
	vector <int> v;
	v.push_back(input);
	push_heap(v.begin(), v.end(), compare);
	cout << v.front() << endl;
	pop_heap(v.begin(), v.end(), compare);
	v.pop_back();
	sort_heap(v.begin(), v.end(), compare);

	//배열을 이용한 힙 구현
	
}

//가장위의 노드 인덱스가 1, 힙은 이진트리 형태로 구현되므로
//i는 푸시된 데이터의 인덱스, i=마지막원소위치+1
//부모위치 원소heap[i/2]보다 푸시된 원소가 크면 부모위치의 원소를 자식위치로 끌어내림 heap[i]=heap[i/2]
//i는 부모위치로 올라간다 = i/=2
//부모원소가 푸시된 원소보다 크거나 i가 가장위(1)이 될때까지 부모를 자식위치로 끌어내리고, i위치에 푸시된 원소를 넣는다
void push(int heap[], int *size, int data) {
	int i;
	if(*size+1 == HEAP_SIZE)
		return;
	(*size)++;
	i = *size;
	while(i!=1 && compare(heap[i/2], data)) {
		heap[i] = heap[i/2];
		i /= 2;
	}
	heap[i] = data;
}

//팝될 원소를 item에 저장, parent는 마지막원소tmp의 새로운위치가 된다
//parent = 1 , 최초
//parent의 두 자식중 큰것 선택, tmp와 비교, 자식이 크면 위로 : heap[parent] = heap[child]
//parent는 자식위치로 내려감
//tmp가 자식보다 클때까지 반복, parent에 tmp넣고, item리턴
int pop(int heap[], int *size) {
	int item, tmp, parent, child;
	if(*size == 0)
		return -1;
	item = heap[1];
	tmp = heap[*size];
	(*size)--;
	child = 2;
	while(child <= *size) {
		if( child < *size && compare(heap[child], heap[child+1]) ) {
			child++;
		}
		if(!compare(tmp, heap[child])) {
			break;
		}
		heap[parent] = heap[child];
		parent = child;
		child *=2;
	}
	heap[parent] = tmp;
	return item;
}

//heap에서 pop해서 마지막 위치에 넣기 반복
void sort(int heap[], int *size) {
	int i;
	for( i = *size ; i>0 ; i-- ) {
		heap[i] = pop(heap, size);
	}
}
*/