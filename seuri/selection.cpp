#include <iostream>
using namespace std;
/*
SelectionSort(a[], n)
   for (i ← 1; i < n; i ← i + 1) do {
       배열 a[i], … , a[n] 중에서 가장 작은 원소 a[k]를 선택;
       a[k]를 a[i]와 교환;
   }
end SelectionSort()
*/
/*
#define Num 10
int selectionSort(int arr[], int n);

int main(){
	int arr[Num] = {0};
	for(int i=1;i<Num;i++) {
		arr[i] = 12-i;
	}
	for(int i=0; i<Num; i++) {
		cout << arr[i] << "  ";
	}
	cout<< endl;

	selectionSort(arr, Num);
}

int selectionSort(int arr[], int n){
	for(int i=1; i<n; i++) {
		//가장 작은 원소 선택
		int min = arr[i];
		int mink = i;
		for(int k=i + 1; k<n; k++) {
			if(min>arr[k]) {
				mink = k;
				min=arr[k]; // *빼먹었었어*
			}
			cout << arr[i] << "  ";
		}
		cout << "mink" << mink ;
		cout << " i" << min << "  ";

		// a[k] <--> a[i]
		int tmp = arr[i];
		arr[i] = arr[mink];
		arr[mink] = tmp;
	}

	cout << endl;
	for(int i=0; i<n; i++) {
		cout << arr[i] << "  ";
	}

	return 0;
}
*/