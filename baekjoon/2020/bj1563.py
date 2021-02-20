# 12m

# 메모이제이션을 할때 보통 now와 다른변수를 같이 이용해서 2차원배열로 메모이제이션을 하는데 이문제에서는 
# 현재 now와 지각횟수 l, 결석횟수 a 3가지 변수를 동시에 고려해야 하므로 3차원 배열이 필요했는데 지각과 결석횟수는
# 각각 최대 2번과 3번을 넘어갈수 없으므로 한가지변수에 10을 곱해 십의자리와 일이의자리로 구분하여 2차원배열 안에서 구현하였다.

import sys
sys.setrecursionlimit(10000000) 


def ola(answer,n,now,l,a):
    if(l >= 2 or a >= 3):
        return 0
    if(now == n):
        return 1
    if(answer[now][l*10+a] != -1):
        return answer[now][l*10+a]
    total = (ola(answer,n,now+1,l,0) + ola(answer,n,now+1,l+1,0) + ola(answer,n,now+1,l,a+1))%1000000
    answer[now][l*10+a] = total
    return total


n = int(sys.stdin.readline())
answer = [[-1] * 50 for i in range(n+1)]

print(ola(answer,n,0,0,0))