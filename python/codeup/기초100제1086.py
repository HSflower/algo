#1086 : [기초-종합] 그림 파일 저장용량 계산하기(설명)
#https://codeup.kr/problem.php?id=1086
input_data = input("").split()
w = int(input_data[0])
h = int(input_data[1])
b = int(input_data[2])

total_amount = 0
if h<=1024 and b%4 == 0 and w<=1024:
  total_amount = h*b*w

result = float(total_amount)/8

print('%.2f MB' % (result/1024/1024))
