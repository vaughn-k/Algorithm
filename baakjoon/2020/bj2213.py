import sys
sys.setrecursionlimit(10000000)

n = int(input(""))
v = list(map(int, sys.stdin.readline().split()))
v = [0] + v
e = [[0] * (n+1) for i in range(n+1)]
dp = [[0] * 2 for i in range(n+1)]
link = list(range(n+1))


for i in range(n-1):
    tmp = list(map(int, sys.stdin.readline().split()))
    a = tmp[0]
    b = tmp[1]
    e[a][0] = e[a][0]+1
    e[a][e[a][0]] = b
    e[b][0] = e[b][0]+1
    e[b][e[b][0]] = a

dp[1][0] = 0
dp[1][1] = v[1]
for i in range(2,n+1):
    #1 해당 v 미선택
    tmp1 = 0
    #2 해당 v 선택
    tmp2 = v[i]
    for j in range(1,e[i][0]+1):
        print(i)
        k = e[i][j]
        if(e[i][j] < i):
            tmp1 = tmp1 + max(dp[link[k]][0],dp[link[k]][1])
            tmp2 = tmp2 + dp[link[k]][0]
            link[e[i][j]] = i
    dp[i][0] = tmp1
    dp[i][1] = tmp2 

# for i in range(len(e)):
#     print(e[i])
print(link)

print(dp)