# 2h
# 재귀를 돌때 포인트는 종료시점을 어떻게 조정해주느냐인데 이 문제를 풀면서 알았다.
# 일단 가능하던 불가능하던 일단 들어가고 들어간다음에 처리해주는것이다.
# 이것이 더 직관적이고 효율적인것같다.
# 또한 answer 불러오는것도 들어가기전에 확인하는것이 아닌 들어가서 확인하는것이다.

import sys
sys.setrecursionlimit(10000000) 

def divide(arr,answer,n,now,state,remain): 
    # state : 0 : 직전에 선택하지 않았다. 1 : 직전에 선택했다.
    # remain : 앞으로 만들수있는 구간 개수
    if(now == n-1):
        if(remain == 0):
            if(state == 1 and arr[now] > 0):
                return arr[now]
            else:
                return 0
        elif(remain == 1 and state == 0):
            return arr[now]
        else:
            return None
    if(remain < 0):
        return None

    if(answer[now][remain][state] != 'no'):
        return answer[now][remain][state]
    tmp1 = (-1) * float('inf')
    tmp2 = (-1) * float('inf')
    if(state == 0):
        tmp1 = divide(arr,answer,n,now+1,0,remain)
        tmp2 = divide(arr,answer,n,now+1,1,remain-1)
    else:
        tmp1 = divide(arr,answer,n,now+1,0,remain)
        tmp2 = divide(arr,answer,n,now+1,1,remain)

    if(tmp1 == None or tmp2 == None):
        if(tmp1 == None):
            if(tmp2 == None):
                final = None
            else:
                final = tmp2 + arr[now]
        else:
            final = tmp1
    else:
        final = max(tmp1,tmp2+arr[now])
    answer[now][remain][state] = final
    return final

n, m = input().split(" ")
n = int(n)
m = int(m)

arr = []
answer = [[['no' for col in range(2)] for row in range(m+1)] for depth in range(n+1)]
for i in range(0,n):
    x = int(input(""))
    arr.append(x)

print(divide(arr,answer,n,0,0,m))
