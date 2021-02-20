# 13m

def jump(store,answer,n,i,j):
    if(i == n-1 and j == n-1):
        return 1
    now = store[i][j]
    if(now == 0):
        return 0
    total = 0
    if(n-i-1 >= now): # 오른쪽으로 진행
        tmp = answer[i+now][j] if answer[i+now][j] != -1 else jump(store,answer,n,i+now,j)
        total = total + tmp
    if(n-j-1 >= now): # 왼쪽으로 진행
        tmp = answer[i][j+now] if answer[i][j+now] != -1 else jump(store,answer,n,i,j+now)
        total = total + tmp
    
    answer[i][j] = total
    return total

n = int(input(""))
store = [[0]*n for i in range(n)]
answer = [[-1]*n for i in range(n)]
# -1 : 안가봄
# 0이상 갈수있는 개수

for i in range(0,n):
    store[i] = list(map(int, input().split()))

print(jump(store,answer,n,0,0))