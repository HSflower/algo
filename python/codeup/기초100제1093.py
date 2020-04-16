#1091 : [기초-종합] 수 나열하기3
#시작 값(a), 곱할 값(m), 더할 값(d), 몇 번째인지를 나타내는 정수(n)가 입력될 때, n번째 수를 출력하는 프로그램을 만들어보자.
input_data = input().split(' ')
a = int(input_data[0])
m = int(input_data[1])
d = int(input_data[2])
n = int(input_data[3])

for i in range(1,n):
  a*=m
  a+=d
print(a)



#모범답안
a,m,d,n=input().split()

A=int(a)
M=int(m)
D=int(d)
N=int(n)

for i in range(N-1) :
    A = A*M+D

print(A)

