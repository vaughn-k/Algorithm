# 런타임 에러 날때
import sys
sys.setrecursionlimit(10000000) 

# 숫자 하나 인풋
n = int(input(""))

# 띄어쓰기로 정해진 개수의 숫자 인풋(ex 3개)
a,b,c = input().split(" ")
a = int(a)
b= int(b)
c = int(c)

# k로 채워진 아래로 n개 오른쪽으로 m개의 2차원 리스트 생성
tmp = [[k]*m for i in range(n)]

# 3차원 리스트 생성
[[[0 for col in range(3)] for row in range(4)] for depth in range(2)]

# 띄어쓰기로 줄당 n개의 원소들을 m줄에 걸쳐 인풋할때
for i in range(0,m):
    forest[i] = list(map(int, input().split()))


