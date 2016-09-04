#include <iostream>
using namespace std;

/*
int main() {

	int n=0;
	cin >> n;
	int arr[1000][5]={0};
	int dead=0;

	for( int i=0 ; i<n ; i++ ) {
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}

	for( int i=0 ; i<n; i++) {
		for( int j=i+1 ; j<n ; j++) {
			if( arr[i][0] >= arr[j][0] && arr[i][1] >= arr[j][1] && arr[i][2] >= arr[j][2] ) {
				arr[i][4]++; //먹는애
				arr[j][3]++; //먹히는 애
				//이미 먹히면 못먹음//중복 제거
			} else {
				arr[i][3]++;
				arr[j][4]++;
			}
		}
	}

	for( int i=0; i<n ; i++){
		for( int j=0 ; j<5; j++){
			cout << arr[i][j] << " ";
		}
		cout <<endl;
	}

	return 0;
}
*/