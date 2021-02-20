# 8m

import sys
sys.setrecursionlimit(10000000) 

def tri(answer,n,now):
    if(now <= 3):
        return 1
    if(now <= 5):
        return 2
    if(answer[now] != -1):
        return answer[now]
    tmp1 = tri(answer,n,now-1)
    tmp2 = tri(answer,n,now-5)
    total = tmp1 + tmp2
    answer[now] = total
    return total


t = int(input(""))
arr = []
answer = [-1] * 101
for i in range(0,t):
    x = int(input(""))
    arr.append(x)

for i in range(0,t):
    print(tri(answer,arr[i],arr[i]))