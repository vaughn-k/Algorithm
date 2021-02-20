import sys
sys.setrecursionlimit(10000000) 

def dpp(check,maze,dp,i,j,n,m,bi,bj,first):
    if(i < 0 or j < 0 or i > (n-1) or j > (m-1)):
        return 0
    if(maze[i][j] == 'H'):
        return 0
    if(check[i][j] == 0):
        check[i][j] = 1
    else:
        return "inf"
    maximum = 0
    if(dp[i][j] != -1):
        check[i][j] = 0
        return dp[i][j]
    tmp1 = dpp(check,maze,dp,i+maze[i][j],j,n,m,i,j,first)
    tmp2 = dpp(check,maze,dp,i,j+maze[i][j],n,m,i,j,first)
    tmp3 = dpp(check,maze,dp,i-maze[i][j],j,n,m,i,j,first)
    tmp4 = dpp(check,maze,dp,i,j-maze[i][j],n,m,i,j,first)
    if(tmp1 == "inf" or tmp2 == "inf" or tmp3 == "inf" or tmp4 == "inf"):
        check[i][j] = 0
        dp[i][j] = 'inf'
        return "inf"
    maximum = max(tmp1,tmp2,tmp3,tmp4)+1
    dp[i][j] = maximum
    check[i][j] = 0
    return maximum

n,m = input().split(" ")
n = int(n)
m = int(m)
maze = [[0]* (m+1) for i in range(n+1)]
check = [[0]* (m+1) for i in range(n+1)]

for i in range(n):
    a = input()
    for j in range(len(a)):
        if(a[j] != "H"):
            maze[i][j] = int(a[j])
        else:
            maze[i][j] = a[j]

dp = [[-1]* (m+1) for i in range(n+1)]
first = False
final = dpp(check,maze,dp,0,0,n,m,0,0,first)
if(final == "inf"):
    print(-1)
else:
    print(final)



# 10 10
# 1637482738
# 4132372338
# 3162782738
# 1162374873
# 6163728238
# 5163748238
# 3136374827
# 5163748273
# 2163748273
# 1637482738

