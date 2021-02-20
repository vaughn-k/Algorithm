import sys
sys.setrecursionlimit(10000000) 

def company(answer, profit, n, m, now, total):
    if(now == m+1):
        return 0
    maximum = -1000
    tmp = company(answer,profit,n,m,now+1,total)
    if(tmp > maximum):
        maximum = tmp 
    for i in range(0,n):
        if(total+(i+1) <= n):
            tmp = profit[i][now] + company(answer,profit,n,m,now+1,total+i+1)
            if(tmp > maximum):
                maximum = tmp 
        else:  
            return maximum
    return maximum

st = list(map(int, sys.stdin.readline().split()))
n = st[0]
m = st[1]
profit = [[-1]*3 for i in range(n)]
answer = []



for i in range(0,n):
    profit[i] = list(map(int, sys.stdin.readline().split()))


print(company(answer,profit,n,m,1,0))

