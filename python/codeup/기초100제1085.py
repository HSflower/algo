#1085 : [기초-종합] 소리 파일 저장용량 계산하기(설명)
#https://codeup.kr/problem.php?id=1085
import io,sys

input_data = input("").split()
h = int(input_data[0])
b = int(input_data[1])
c = int(input_data[2])
s = int(input_data[3])
# h는 48,000이하, b는 32이하(단, 8의배수), c는 5이하, s는 6,000이하의 자연수

total_amount = 0
if h<=48000 and b%8 == 0 and b<=32 and c<=5 and s<6000:
  total_amount = h*b*c*s

#필요한 저장 공간을 MB 단위로 바꾸어 출력한다.
#단, 소수점 둘째 자리에서 반올림해 첫째 자리까지 출력하고 MB를 공백을 두고 출력
result = float(total_amount)/8
result = result/1024/1024

print('%.1f MB' % (result))


#모범답안
a,b,c,d=input().split()

H=int(a)
B=int(b)
C=int(c)
S=int(d)

print('%.1f MB' % (H*B*C*S/8/1024/1024))
