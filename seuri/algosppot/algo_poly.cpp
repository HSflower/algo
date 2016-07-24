
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

const int MOD = 10*1000*1000;

int cache[101][101];
int N = 12;
int count = 0; // �޸������̼� ���� ��, ������ Ȯ���ϱ� ���� cnt
 
// - poly(int n, int first)�Լ��� ��� -
//   -> n���� ���簢������ �̷������, �� �� �����ٿ� first����
//       ���簢���� �����ϴ� �������̳��� ���� ��ȯ��
int poly(int n, int first){
 if(n == first) return 1;
 
 int& ret = cache[n][first];
 if (ret != -1) return ret;
 ret = 0;
 
 for(int second = 1 ; second <= n-first ; ++second){
  int add = second + first -1;
  int sum = poly(n-first, second);
  count++;
  
  // DSP �޸������̼� ���� ����
  int temp = n - first;
  cache[temp][second] = sum;
  
  add = add * sum;
  add %= MOD;
    
  ret += add;
  ret %= MOD;
 }
  
 return ret;
}
int main()
{
 for(int i = 0 ; i < 101 ; i++)
  for(int j = 0 ; j < 101 ; j++)
   cache[i][j] = -1;
 
 int ret = 0;
 for(int i = 1 ; i <= N ; i++)
 {
  ret += poly(N, i);
  ret %= MOD;
 }

 for(int i = 0 ; i<101 ; i++) {
	 for(int j=0 ; j<101; j++) {
		 cout << cache[i][j];
	 }
	 cout << endl;
 }
 
 printf("%d, cnt : %d", ret, count);
 
 system("pause");
 return 0;
}
