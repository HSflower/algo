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
//제네릭:타입을 알수없을때=템플릿, 함수포인터:함수에서 코드 한줄만바꿀수잇다.
//c언어 라이브러리 q솔트(어떤형태든 정렬가능) - 비교함수를 받는 함수포인터
//closure : 이름이 없는 코드 덩어리 - eg.함수, 람다(c++,java,안드로이드리스너,js)
//	프로그래밍언어론
//함수도 객체 - 함수지향적프로그래밍 eg.R

void mergeSort(int a[], int l, int r){
	if(r>l) {
		int m = (r+l)/2;
		//퀵정렬은 partition-->sort :정복 분할
		// 시간복잡도 = nlog(n), 자연합병정렬:정렬된 배열은 건드리지 않음
		// 합병정렬은 정렬된것도 확인, 순차접근밖에 안되는 경우에 많이 쓰임 - 자기테이프같이?다음에 뭐가 오는지 알 수 없는경우
		mergeSort(a, l, m);
		mergeSort(a, m+1, r);
		merge(a, l, m, r);
		cout<< "sortingLMR "<<l<<" "<<m<<" "<<r<<", ";
		for(int num=0; num<10; num++) 	cout<<a[num]<<" ";
		cout<<endl;
	}
}

void merge(int a[], const int l, const int m, const int r) {
	int b[10]={0}; //배열에 변수 개수
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
	//이걸왜 else안에 넣었었지..
	//임시배열에서 원래 배열의 자리로 복사
	for(int p = l ; p<=r ; p++) {
		a[p] = b[p];
	}
}
