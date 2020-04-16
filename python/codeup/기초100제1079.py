#1079 : [기초-종합] 원하는 문자가 입력될 때까지 반복 출력하기
import io,sys
n = ''

n = input("").split()
for i in n:
    print(i, end='\n')
    if i is 'q':
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

