# python으로는 안되고 pypy로는 통과
# 50m 처음에는 경우의 수가 너무 많아서 brute-force가 아닌 다른 방법인줄 알고
# 했으나 그냥 bf에서 메모이제이션하면서 재귀돌리면 됨;

import sys

def dp(answer,list_n,list_m,left_m,ni,nj):
    if(left_m == 0):
        return 0
    if(answer[ni][nj] != -1):
        return answer[ni][nj]
    minimum = float("inf")
    for i in range(ni,n-left_m+1):
        tmp = abs(list_n[i]-list_m[nj]) + dp(answer,list_n,list_m,left_m-1,i+1,nj+1)
        if(tmp < minimum):
            minimum = tmp
    answer[ni][nj] = minimum
    return minimum

n,m = input().split(" ")
n = int(n)
m = int(m)

if(n >= m):
    list_n = list(map(int, sys.stdin.readline().split()))
    list_m = list(map(int, sys.stdin.readline().split()))
else:
    list_m = list(map(int, sys.stdin.readline().split()))
    list_n = list(map(int, sys.stdin.readline().split()))
    n,m = m,n

# 항상 n의 길이가 더 길다

left_n = n
left_m = m
list_n.sort()
list_m.sort()
answer = [[-1] * m for i in range(n)]
ans = dp(answer,list_n,list_m,left_m,0,0)
print(ans)


