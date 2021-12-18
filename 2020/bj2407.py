n,m = input().split(" ")
n = int(n)
m = int(m)


dp = [[0]*(101) for i in range(101)]

for i in range(1,n+1):
    for j in range(1,i+1):
        if(j == 1):
            dp[i][j] = i
        
        elif(i == j):
            dp[i][j] = 1
        
        else:
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j]
        

print(dp[n][m])
