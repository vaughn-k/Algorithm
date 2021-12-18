import sys
sys.setrecursionlimit(10000000) 

# 이문제는 오히려 python3에서 돌아가고 pypy에서 런타임에러가 뜬 문제였다.
# 처음에 이문제를 접근할때는 특정 지점을 골랐을때 사탕의 개수가 0이 되는부분을 동기화해서 그 2차원배열을 계속 넘겨주려고 했지만
# 일단 nxm 사이즈가 작지않아 메모리초과가 날수도 있고 알고리즘상 효율적이지도 않아서 0이되는 부분을 피해서 가능한 곳만 방문하는
# 방향으로 설계를 했다. 그러다보니 좌에서우로, 위에서 아래로 순차적으로 간다고 생각했을때 
# 해당칸을 고르면 일단 다음칸은 못고르니 1칸을 건너뛰어야하고 
# 해당줄을 고르면 다음줄을 건너뛰어야한다.

def dp(answer1,answer0,maze,i,j,n,m,eat):
    tmp1,tmp2 = 0,0
    if(i >= n):
        return 0
    if(eat == 1 and answer1[i][j] != -1):
        return answer1[i][j]
    if(eat == 0 and answer0[i][j] != -1):
        return answer0[i][j]
    if(j+2 == m): # 마지막에서 2번째 칸 방문시
        if(eat == 1):
            tmp1 = max(maze[i][j],maze[i][j+1]) + dp(answer1,answer0,maze,i+2,0,n,m,0) # 마지막 두개중 큰거 선택
            # tmp2 = dp(answer1,answer0,maze,i+1,0,n,m,0) - 사실 있을필요가 없는 부분
        else:
            tmp1 = max(maze[i][j],maze[i][j+1]) + dp(answer1,answer0,maze,i+2,0,n,m,0) # 마지막 두개중 큰거 선택
            tmp2 = dp(answer1,answer0,maze,i+1,0,n,m,0)

    elif(j+1 == m): # 마지막칸 방문시
        if(eat == 1):
            tmp1 = maze[i][j] + dp(answer1,answer0,maze,i+2,0,n,m,0) # 마지막 사탕 선택
        else:
            tmp1 = maze[i][j] + dp(answer1,answer0,maze,i+2,0,n,m,0) # 마지막 사탕 선택
            tmp2 = dp(answer1,answer0,maze,i+1,0,n,m,0) 

    else: # 0 ~ m-2 사이의 칸 방문시
        tmp1 = maze[i][j] + dp(answer1,answer0,maze,i,j+2,n,m,1) # 현재사탕 선택
        tmp2 = dp(answer1,answer0,maze,i,j+1,n,m,eat) # 현재사탕 미선택
    maximum = max(tmp1,tmp2)
    if(eat == 1):
        answer1[i][j] = maximum
    else:
        answer0[i][j] = maximum
    return maximum

n,m = 1,2
while(not(n == 0 and m == 0)):
    n,m = input("").split(" ")
    n = int(n)
    m = int(m)
    if(not(n == 0 and m == 0)):
        # if()
        maze = [[0]*m for i in range(n)]
        answer1 = [[-1]*(m) for i in range(n)]
        answer0 = [[-1]*(m) for i in range(n)]
        for i in range(n):
            maze[i] = list(map(int, sys.stdin.readline().split()))

        print(dp(answer1,answer0,maze,0,0,n,m,0))