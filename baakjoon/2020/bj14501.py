# 13m

import sys
sys.setrecursionlimit(10000000) 

def cal(answer,day,n,now):
    if(now == n):
        return 0
    if(now == n-1):
        if(day[now][0] == 1):
            return day[now][1]
        else:
            return 0
    if(now > n-1):
        return -1
    if(answer[now] != -1):
        return answer[now]
    tmp1 = cal(answer,day,n,now+day[now][0])
    tmp2 = cal(answer,day,n,now+1)
    if(tmp1 != -1):
        tmp1 = tmp1 + day[now][1]
    total = max(tmp1,tmp2)
    answer[now] = total
    return total
    



n = int(input(""))
day = [[0] * 2 for i in range(0,n)]
answer = [-1] * 16

for i in range(0,n):
    a,b = input().split(" ")
    day[i][0] = int(a)
    day[i][1] = int(b)

print(cal(answer,day,n,0))