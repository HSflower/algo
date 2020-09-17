#큰 수의 법칙
#주어진 배열 안에 들어 있는 n개의 수를 m번 더하여 가장 큰 수를 만드는 방법(연속해서 최대 k번 더할 수 있다)

# 단순한 방법 풀이
n, m, k = map(int, input().split())
tmp = map(int,input().split())
arr = list(tmp)
arr.sort()
arr.reverse()

result = 0
count = k
for i in range(0,m):
  # print(result)
  if count > 0:
    result = result+arr[0]
    count=count-1
  else:
    count=k
    result = result+arr[1]

print(result)

# 수열 찾아서 반복문 없어도 되는 풀이
