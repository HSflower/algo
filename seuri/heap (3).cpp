#include <iostream>
#include <string>

#include <vector>
#include <algorithm>
using namespace std;

#define HEAP_SIZE 5

/*
//�ּ� �� �Լ� : ū�� �Ʒ��� a>b�϶�, true�� return�Ͽ� a�� �Ʒ��� �̵�
bool compare(int a, int b){
	return a>b;
}

//�ִ� �� ���� stl <vector>, <algorithm>
int main() {
	int arr[] = {6,4,2,9,3};
	int size = 5;
	//vector<int> v(&arr[0], &arr[5]);
	//make_heap(v.begin(), v.end());
	make_heap(&arr[0], &arr[5]);

	//<vector>�� push_back()�Լ� �̿�
	//push_heap()�Լ��� ������ �������
	//<vector> front()�Լ��� ���� ���� ���ҿ� ����
	//pop_heap() : �������� ���Ұ� ���������� �̵�
	//<vector> pop_back()�Լ��� ������ ���� ����
	//������ : sort_heap()������������
	
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

	//�ּ� ��
	int input=3;
	vector <int> v;
	v.push_back(input);
	push_heap(v.begin(), v.end(), compare);
	cout << v.front() << endl;
	pop_heap(v.begin(), v.end(), compare);
	v.pop_back();
	sort_heap(v.begin(), v.end(), compare);

	//�迭�� �̿��� �� ����
	
}

//�������� ��� �ε����� 1, ���� ����Ʈ�� ���·� �����ǹǷ�
//i�� Ǫ�õ� �������� �ε���, i=������������ġ+1
//�θ���ġ ����heap[i/2]���� Ǫ�õ� ���Ұ� ũ�� �θ���ġ�� ���Ҹ� �ڽ���ġ�� ����� heap[i]=heap[i/2]
//i�� �θ���ġ�� �ö󰣴� = i/=2
//�θ���Ұ� Ǫ�õ� ���Һ��� ũ�ų� i�� ������(1)�� �ɶ����� �θ� �ڽ���ġ�� �������, i��ġ�� Ǫ�õ� ���Ҹ� �ִ´�
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

//�˵� ���Ҹ� item�� ����, parent�� ����������tmp�� ���ο���ġ�� �ȴ�
//parent = 1 , ����
//parent�� �� �ڽ��� ū�� ����, tmp�� ��, �ڽ��� ũ�� ���� : heap[parent] = heap[child]
//parent�� �ڽ���ġ�� ������
//tmp�� �ڽĺ��� Ŭ������ �ݺ�, parent�� tmp�ְ�, item����
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

//heap���� pop�ؼ� ������ ��ġ�� �ֱ� �ݺ�
void sort(int heap[], int *size) {
	int i;
	for( i = *size ; i>0 ; i-- ) {
		heap[i] = pop(heap, size);
	}
}
*/