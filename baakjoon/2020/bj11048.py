# 18m

import sys
sys.setrecursionlimit(10000000) 

def candy(maze,answer,n,m,i,j):
    if(i==(n-1) and j==(m-1)):
        return maze[i][j]

    if(answer[i][j] != -1):
        return answer[i][j]

    if(i == n-1):
        total = maze[i][j] + candy(maze,answer,n,m,i,j+1)
    elif(j == m-1):
        total = maze[i][j] + candy(maze,answer,n,m,i+1,j)
    else:
        tmp1 = maze[i][j] + candy(maze,answer,n,m,i,j+1)
        tmp2 = maze[i][j] + candy(maze,answer,n,m,i+1,j)
        total = max(tmp1,tmp2)
    
    answer[i][j] = total
    return total
 
n,m = input().split(" ")
n = int(n)
m = int(m)
maze = [[0]*m for i in range(n)]
answer = [[-1]*m for i in range(n)]

for i in range(0,n):
    maze[i] = list(map(int, input().split()))

print(candy(maze,answer,n,m,0,0))