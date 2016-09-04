
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

const int MOD = 10*1000*1000;

int cache[101][101];
int N = 12;
int count = 0; // 메모이제이션 적용 시, 성능을 확인하기 위한 cnt
 
// - poly(int n, int first)함수의 기능 -
//   -> n개의 정사각형으로 이루어졌고, 맨 위 가로줄에 first개의
//       정사각형을 포함하는 폴리오미노의 수를 반환함
int poly(int n, int first){
 if(n == first) return 1;
 
 int& ret = cache[n][first];
 if (ret != -1) return ret;
 ret = 0;
 
 for(int second = 1 ; second <= n-first ; ++second){
  int add = second + first -1;
  int sum = poly(n-first, second);
  count++;
  
  // DSP 메모이제이션 상태 저장
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
