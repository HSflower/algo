#1083 : [기초-종합] 3 6 9 게임의 왕이 되자!(설명)
#3 6 9 게임을 하던 영일이는 3 6 9 게임에서 잦은 실수로 계속해서 벌칙을 받게 되었다.
#3 6 9 게임의 왕이 되기 위한 마스터 프로그램을 작성해 보자.
import io,sys

input_data = input("")
#input_data = int(input)
for i in range(1, int(input_data)+1):
    if i%3 is 0:
        print('X', end=' ')
    else:
        print('%d' % (i) , end=' ')
        
       
#모범답안
a=input()

n=int(a)

for i in range(1, n+1) :
    if i%3==0 :
        print('X', end=' ')
    else :
        print(i, end=' ')
