#include <iostream>
using namespace std;

void InsertionSort(int a[], int n);
/*
int main(){
	int a[5] = { 3,2,5,1,4 };
	InsertionSort(a,5);
}
*/
//�ε��� �����غ���, �����ڵ�� �ε���1���� ����
//���� �κ�ȭ��(����:nlogn > n^2)�϶��� ���������� ����(n=5~25)
void InsertionSort(int a[], int n) {
	for(int i = 1; i<=n ; i=i+1){
		int tmp = a[i];
		int j = i;
		
		while(a[j-1] > tmp && j>0){
			a[j]=a[j-1];
			j=j-1;
		}
		a[j] = tmp;
	}
	for(int k = 0; k<5; k++)	cout <<a[k];
	cout<<endl;
}