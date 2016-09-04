#include <iostream>
using namespace std;

void mergeSort(int a[], int l, int r);
void merge(int a[],const int l,const int m,const int r);
void testMerge(int a[]);
/*
int main(){
	int z[] = { 1,2,3,6,7,4,5,8,9,10 };
	int x[] = { 1,2,3,4,8,6,5,7,9,10 };
	int y[] = { 1,2,3,6,8,4,5,7,9,10 };
	int c[] = { 5,4,3,2,1,10,9,8,7,6 };
	int d[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	
	testMerge(z);
	testMerge(x);
	testMerge(y);
	testMerge(c);
	testMerge(d);
	//test case function
}
*/
void testMerge(int a[]){
	cout<<"input ";
	for(int num=0; num<10; num++) cout<<a[num]<<" ";
	cout<<endl;
	mergeSort(a, 0, 9);
}
//���׸�:Ÿ���� �˼�������=���ø�, �Լ�������:�Լ����� �ڵ� ���ٸ��ٲܼ��մ�.
//c��� ���̺귯�� q��Ʈ(����µ� ���İ���) - ���Լ��� �޴� �Լ�������
//closure : �̸��� ���� �ڵ� ��� - eg.�Լ�, ����(c++,java,�ȵ���̵帮����,js)
//	���α׷��־���
//�Լ��� ��ü - �Լ����������α׷��� eg.R

void mergeSort(int a[], int l, int r){
	if(r>l) {
		int m = (r+l)/2;
		//�������� partition-->sort :���� ����
		// �ð����⵵ = nlog(n), �ڿ��պ�����:���ĵ� �迭�� �ǵ帮�� ����
		// �պ������� ���ĵȰ͵� Ȯ��, �������ٹۿ� �ȵǴ� ��쿡 ���� ���� - �ڱ�����������?������ ���� ������ �� �� ���°��
		mergeSort(a, l, m);
		mergeSort(a, m+1, r);
		merge(a, l, m, r);
		cout<< "sortingLMR "<<l<<" "<<m<<" "<<r<<", ";
		for(int num=0; num<10; num++) 	cout<<a[num]<<" ";
		cout<<endl;
	}
}

void merge(int a[], const int l, const int m, const int r) {
	int b[10]={0}; //�迭�� ���� ����
	int i = l;	
	int j = m+1;	
	int k = l;
	while((i<=m) && (j<=r)) {
		if(a[i] < a[j]) {
			b[k] = a[i];
			k++;	
			i++;
		} else {
			b[k] = a[j];
			k++;	
			j++;
		}
	}

	if(i>m) {
		for(int p = j; p<=r; p++) {
			b[k] = a[p];
			k++;
		}
	} else {
		for(int p = i; p<=m ; p++) {
			b[k] = a[p];
			k++;
		}
	}
	//�̰ɿ� else�ȿ� �־�����..
	//�ӽù迭���� ���� �迭�� �ڸ��� ����
	for(int p = l ; p<=r ; p++) {
		a[p] = b[p];
	}
}
