# 22m

import sys
sys.setrecursionlimit(10000000) 

def find_possible(answer,now):
    if(now == 1 or now == 0):
        return 1
    if(now == 2):
        return 2
    if(answer[now] != -1):
        return answer[now]
    tmp1 = find_possible(answer,now-1)
    tmp2 = find_possible(answer,now-2)
    total = tmp1 + tmp2
    answer[now] = total
    return total

def find_all(answer,n,m,fix):
    if(m == 0):
        total = find_possible(answer,n)
    else:
        total = 1
        for i in range(0,m):
            if(i == 0):
                total = total * find_possible(answer,fix[0]-1)
            else:
                total = total * find_possible(answer,fix[i]-fix[i-1]-1)

        if(fix[m-1] < n):
            total = total * find_possible(answer,n-fix[m-1])

    return total


n = int(input(""))
m = int(input(""))

answer = [-1] * (n+1)
fix = [0] * m
for i in range(0,m):
    x = int(input(""))
    fix[i] = x

print(find_all(answer,n,m,fix))
