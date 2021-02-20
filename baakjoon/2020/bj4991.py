import sys
import time
import os

def short_path(length,ans,before,a,n):
    now_min = float('inf')
    if(count_0(a,n) == n):
        return 0
    for i in range(n-1):
        if(a & 1<<i == 0):
            tmp = max(length[before][n-i-1],length[n-i-1][before]) + short_path(length,ans,n-i-1,a+(1<<i),n)
            if(tmp < now_min):
                now_min = tmp
    return now_min

def count_0(a,n):
    count = 0
    for i in range(n):
        if(a & 1<<i):
            count = count + 1
    return count

def draw(a,m,n):
    # print(a)
    for i in range(m):
        print(a[i],end="")

def atob(maze,answer,n,m,si,sj,ei,ej,i,j):
    if(i < 0 or j < 0 or i >= n or j >= m):
        return float('inf')
    # time.sleep(0.02)
    # os.system('clear')
    # draw(maze,n,m)
    state = 0
    if(i-1 < 0):
        state = state + 1  
    elif(maze[i-1][j] == 'x' or maze[i-1][j] == 'n'):
        state = state + 1  
    if(i+1 >= n):
        state = state + 2
    elif(maze[i+1][j] == 'x' or maze[i+1][j] == 'n'):
        state = state + 2
    if(j-1 < 0):
        state = state + 4
    elif(maze[i][j-1] == 'x' or maze[i][j-1] == 'n'):
        state = state + 4
    if(j+1 >= m):
        state = state + 8
    elif(maze[i][j+1] == 'x' or maze[i][j+1] == 'n'):
        state = state + 8

    if(maze[i][j] == 'x' or maze[i][j] == 'n'):
        return float('inf')
    if(i==ei and j==ej):
        return 0
    if(answer[i][j][state] != -1):
        return answer[i][j][state]

    maze[i] = maze[i][:j] + 'n' + maze[i][(j+1):]
    tmp1 = atob(maze,answer,n,m,si,sj,ei,ej,i+1,j)
    tmp2 = atob(maze,answer,n,m,si,sj,ei,ej,i-1,j)
    tmp3 = atob(maze,answer,n,m,si,sj,ei,ej,i,j+1)
    tmp4 = atob(maze,answer,n,m,si,sj,ei,ej,i,j-1)
    minimum = min(tmp1,tmp2,tmp3,tmp4)+1
    answer[i][j][state] = minimum
    maze[i] = maze[i][:j] + '.' + maze[i][(j+1):]
    return minimum

n,m = 1,2
while(not(n == 0 and m == 0)):
    m,n = input("").split(" ")
    m = int(m)
    n = int(n)
    if(not(n == 0 and m == 0)):
        # if()
        maze = [0]*n
        answer = [[[-1]*(16) for i in range(m)] for i in range(n)]
        end = []
        start = []
        for i in range(n):
            maze[i] = sys.stdin.readline()
        for i in range(n):
            for j in range(m):  
                if(maze[i][j] == 'o'):
                    start.append([i,j])
                    end = start + end
                if(maze[i][j] == '*'):
                    end.append([i,j])
        # print(si,sj,ei,ej)
        print(end)
        length = [[0]*len(end) for i in range(len(end))]
        for i in range(0,len(end)):
            for j in range(0,i):
                print(i,j)
                a = atob(maze,answer,n,m,end[i][0],end[i][1],end[j][0],end[j][1],end[i][0],end[i][1]) 
                length[i][j] = a
                print(end[i]," -> ",end[j]," = ",a)
                answer = [[[-1]*(16) for i in range(m)] for i in range(n)]
        print(length)       
        ans = [[-1] * len(end) for i in range(len(end))]
        a = 1<<(len(end)-1)
        print(short_path(length,ans,0,a,len(end)))


        
        # print(dp(answer1,answer0,maze,0,0,n,m,0))