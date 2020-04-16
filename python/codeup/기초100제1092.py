#1092 : [기초-종합] 함께 문제 푸는 날(설명)
#https://codeup.kr/problem.php?id=1092
input_data = input().split(' ')
a = int(input_data[0])
b = int(input_data[1])
c = int(input_data[2])
result = 1

while(result%a!=0 or result%b!=0 or result%c!=0):
  result+=1

print(result)


#모범답안
a,b,c=input().split()

x=int(a)
y=int(b)
z=int(c)

d=1
while (d%x!=0 or d%y!=0 or d%z!=0) :
    d+=1

print(d)
