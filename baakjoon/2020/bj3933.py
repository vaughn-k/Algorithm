import math

# 개어렵네

# def fdp(dp,n):
#     if(n == 0):
#         return 0
#     if(dp[n] != -1):
#         return dp[n]
#     else:
#         total = 0
#         k = math.sqrt(n)
#         if(k == int(k)):
#             total = total+1
#             k = int(k)-1
#         k = int(k)
#         for i in range(1,k+1):
#             tmp = k+1-i
#             total = total + fdp(dp,n-tmp) 
#     dp[n] = total
#     return total

def posi(n):
    if(n == -1):
        return 0
    else:
        return n

def fdp(dp,n,k):
    print(n,k)
    if(n == 0):
        return 0
    if(dp[n][k] != -1):
        return dp[n][k]
    s = math.sqrt(n)
    if(k == 0):
        if(s == int(s)): # 제곱인수
            dp[n][k] = 1
            return 1
        else:
            dp[n][k] = 0
            return 0
    s = int(s)
    total = 0
    for i in range(1,s+1):
        tmp = (s+1-i)**2
        if(tmp > math.sqrt(n)+1):
            total = total + fdp(dp,n-tmp,k-1) 
    dp[n][k] = total
    return total

n = int(input(""))

# dp = [[-1] * (2**15+1) for i in range(4)
dp = [[-1] * (4) for i in range(10000)]
dp[1][0] = 1
dp[1][1] = 0
dp[1][2] = 0
dp[1][3] = 0

fdp(dp,n,0)
fdp(dp,n,1)
fdp(dp,n,2)
fdp(dp,n,3)
for i in range(n+1):
    total = posi(dp[i][0]) + posi(dp[i][1]) + posi(dp[i][2]) + posi(dp[i][3])
    print(i,dp[i]," total = ",total)