# 33m

def tree(store,answer,n,m,now_n,now_m,state):
    tmp = 0
    tmp2 = 0
    if(now_n == n-1):
        return 0
    
    if(store[now_n+1] == state):
        tmp2 = tmp2+1
    if(answer[now_n+1][now_m] != -1):
        tmp2 = tmp2 + answer[now_n+1][now_m]
    else:
        tmp2 = tmp2 + tree(store,answer,n,m,now_n+1,now_m,state)
    if(now_m < m): # 나무 바꿀수 있을경우
        state = 1 if state == 2 else 2
        if(store[now_n+1] == state):
            tmp = tmp+1
        if(answer[now_n+1][now_m+1] != -1):
            tmp = tmp + answer[now_n+1][now_m+1]
        else:
            tmp = tmp + tree(store,answer,n,m,now_n+1,now_m+1,state) 
    ans = tmp if tmp > tmp2 else tmp2
    answer[now_n][now_m] = ans
    return ans

a,b = input().split(" ")
n = int(a)
m = int(b)

store = []
answer = [[-1]*(m+1) for i in range(n+1)]
# -1 : 안가봄
# 0이상 그개수

for i in range(0,n):
    a = int(input(""))
    store.append(a)

print(tree(store,answer,n,m,-1,0,1))
