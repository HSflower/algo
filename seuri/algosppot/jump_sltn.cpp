#include <iostream>
#include <string>
using namespace std;

/*
	int n, board[100][100];
	int cache[100][100];
	int jump2(int y, int x){
		//�������ó��
		if(y>=n || x>=n) return 0;
		if(y==n-1 && x==n-1) return 1;
		//memoization
		int& ret = cache[y][x];
		if(ret != -1) return ret;
		int jumpSize = board[y][x];
		return ret = (jump2(y+jumpSize,x) || jump2(y,x+jumpSize));
	}

	int main() {
		//�׽�Ʈ���̽� �� c �Է�(50����)
	//int n;
	cout << "�ܹ߶ٱ� ������ �� ���� ũ�� : ";
	cin >> n;
	cout << "�ܹ߶ٱ� �����ǿ� �Է��� �������� "<<n<<"���� �Է�";
	
	//int board[100][100];
	//1000*1000 int
	for(int i = 0 ; i<n ; i++) {
		for(int j=0; j<n ; j++){
			cin >> board[i][j];
			cache[i][j] = -1;
		}
	}

	int result = jump2(0,0);
	cout << result;
	cin>>n;
	
	}

	//�׷����𵨸� 7��
*/