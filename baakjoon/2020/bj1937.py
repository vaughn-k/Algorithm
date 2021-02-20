import sys
sys.setrecursionlimit(10000000) 

# 26m

def panda(forest,answer,i,j,n):
    if(answer[i][j] != 0):
        return answer[i][j]
    max_food = 0
    tmp1, tmp2, tmp3, tmp4 = 1,1,1,1
    if(j < n-1): # 오른쪽으로 갈수있다.
        if(forest[i][j] < forest[i][j+1]): 
            tmp1 = tmp1 + panda(forest, answer,i,j+1,n)
    if(j > 0): # 왼쪽으로 갈수있다.
        if(forest[i][j] < forest[i][j-1]): 
            tmp2 = tmp2 + panda(forest, answer,i,j-1,n)
    if(i > 0): # 위로 갈수있다.
        if(forest[i][j] < forest[i-1][j]):
            tmp3 = tmp3 + panda(forest, answer,i-1,j,n)
    if(i < n-1): # 아래로 갈수있다. 
        if(forest[i][j] < forest[i+1][j]):
            tmp4 = tmp4 + panda(forest, answer,i+1,j,n)
    max_food = max(tmp1, tmp2, tmp3, tmp4)
    answer[i][j] = max_food
    return max_food

def start_panda(forest,answer,i,j,n):
    now_max = 0
    for i in range (0,n):
        for j in range (0,n):
            tmp = panda(forest,answer,i,j,n)
            if(now_max < tmp):
                now_max = tmp
    return now_max

n = int(input(""))

forest = [[0]*n for i in range(n)]
for i in range(0,n):
    forest[i] = list(map(int, input().split()))

answer = [[0]*n for i in range(n)]

print(start_panda(forest,answer,0,0,n))