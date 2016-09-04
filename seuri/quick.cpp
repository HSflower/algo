#include <iostream>
using namespace std;
/*
//input 62813945107
void QuickSort(int a[],int l,int r) ;
int partition(int a[], int l, int r);
int main() {
	int a[11] = { -1,6,2,8,1,3,9,4,5,10,7 };
	QuickSort(a,1,10);
}

void QuickSort(int a[], int l, int r){
	if(r>l) {
		int i = partition(a, l, r);
		QuickSort(a,l,i-1);
		QuickSort(a,i+1,r);
	}
	for(int k=0; k<11; k++)	cout << a[k];
	cout << endl;
}

int partition(int a[], int l, int r){
	int v = a[r];
	int i = l-1;
	int j = r;
	for(;;) {
		do{
			i++;
		}while(a[i]<v);
		//		for(i=i+1;a[i]<v;i++)
		do{
			j=j-1;
		}while(a[j]>v);
		if(i>=j) break;
		int temp = a[i];
		a[i]=a[j];
		a[j]=temp;
	}
	int temp = a[i];
	a[i] = a[r];
	a[r] = temp;

	return i;
}
*/
