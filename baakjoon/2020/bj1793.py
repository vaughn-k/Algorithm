from sys import stdin
import sys
sys.setrecursionlimit(10000000) 

def tile(answer,n,now):
    if(now == 0 or now == 1):
        return 1
    elif(now == 2):
        return 3
    if(answer[now] != 0):
        return answer[now]
    tmp1 = 2*tile(answer,n,now-2)
    tmp2 = tile(answer,n,now-1)
    total = tmp1 + tmp2
    answer[now] = total
    return total

answer = [0] * (251)

for n in map(int, stdin.read().split()):
    print(tile(answer,n,n))


# while True:
#     n = int(input())
#     # 답을 계산하고 출력

# ######

