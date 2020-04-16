#1089 : [기초-종합] 수 나열하기1
#시작 값(a), 등차(d), 몇 번째인지를 나타내는 정수(n)가 입력될 때, n번째 수를 출력하는 프로그램을 만들어보자.
input_data = input().split(' ')
a = int(input_data[0])
d = int(input_data[1])
n = int(input_data[2])

for i in range(1,n):
  a+=d  
print(a)


#모범답안
a,d,n=input().split()

A=int(a)
D=int(d)
N=int(n)

for i in range(N-1) :
    A = A + D

print(A)

