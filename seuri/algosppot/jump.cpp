#include <iostream>
#include <string>
using namespace std;
#define X 100;
#define Y 100;
//�����迭
/*

bool jump(int (*arr)[100], int i, int j, int n){
			int dist=arr[i][j];
			if( (i+dist < n) && (j+dist < n) ) {
				//�����ϳ�
				if(arr[i][j+dist] != 0) {
					jump(arr, i , j+dist, n);
				} else return true;
				if(arr[i+dist][j] != 0) {
					jump(arr, i+dist, j, n);
				} else return true;
			}
			return jump(arr, i+dist,j, n) || jump(arr, i,j+dist, n)
			else return false;
}

int main() {

	//�׽�Ʈ���̽� �� c �Է�(50����)
	int n;
	cout << "�ܹ߶ٱ� ������ �� ���� ũ�� : ";
	cin >> n;
	cout << "�ܹ߶ٱ� �����ǿ� �Է��� �������� "<<n<<"���� �Է�";
	
	int arr[100][100];
	//1000*1000 int
	for(int i = 0 ; i<n ; i++) {
		for(int j=0; j<n ; j++){
			cin >> arr[i][j];
		}
	}
	//1-9, �߸��Է��ϴ� ��� ���� ó��
	//������ 0

	//Ž��, ��Ʈ������yes/no
	int result = jump(arr,0,0,n);
	cout << result ;
	cin >> n;
}
*/