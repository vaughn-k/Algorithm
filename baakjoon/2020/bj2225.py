# 18m
# n,m이 주어지고 앞뒤 규칙성을 잘 모르겠다 싶으면 표를 그려서 점화식을 추론해보자
# 보통 n=5가 되기전에 직감적으로 점화식이 보인다.

import sys
sys.setrecursionlimit(1000000000) 

def dynamic(answer,n,k):
    if(n == 1):
        return k
    if(k == 1):
        return 1
    if(answer[n][k] != -1):
        return answer[n][k]

    tmp1 = dynamic(answer,n-1,k)
    tmp2 = dynamic(answer,n,k-1)
    total = (tmp1+tmp2)%1000000000
    answer[n][k] = total
    return total


n, k = input().split(" ")
n = int(n)
k = int(k)
answer = [[-1] * (k+1) for i in range(n+1)]


print(dynamic(answer,n,k))
