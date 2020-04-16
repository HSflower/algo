#1080 : [기초-종합] 언제까지 더해야 할까?
#1, 2, 3 ... 을 계속 더해 나갈 때, 그 합이 입력한 정수(0 ~ 1000)보다 같거나 작을 때까지 계속 더하는 프로그램을 작성해보자.
#즉, 1부터 n까지 정수를 계속 더한다고 할 때, 어디까지 더해야 입력한 수보다 같거나 커지는지 알아보고자 하는 문제이다.
import io,sys

n = int(input(""))
sum = 0
for i in range(n):
    sum = sum+i;
    if sum >= n:
        print(i)
        break;
        
#모범답안
a=input()

n=int(a)

i=0
s=0
while s<n :
    i+=1
    s+=i

print(i)
