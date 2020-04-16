# [기초-종합] 짝수 합 구하기(설명)
#정수(1 ~ 100) 1개를 입력받아 1부터 그 수까지 짝수의 합을 구해보자.
import io,sys

sum=0
i=0
n = int(input(""))
for i in range(n+1):
  if (i%2==0):
      sum=sum+i
  
print(sum)


#모범소스
a=input()

n=int(a)

s=0
for i in range(1, n+1) :
    if(i%2==0) :
        s+=i

print(s)
