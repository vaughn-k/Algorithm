import sys
sys.setrecursionlimit(100000) 

# 25m

def down_map(store,answer,n,m,now_n,now_m):
    if(now_n == n-1 and now_m == m-1):
        return 1
    else:
        if(answer[now_n][now_m] != -1):
            return answer[now_n][now_m] 
        tmp1,tmp2,tmp3,tmp4 = 0,0,0,0
        if(now_n != 0 and store[now_n-1][now_m] < store[now_n][now_m]): # up
            tmp1 = down_map(store,answer,n,m,now_n-1,now_m)
        if(now_n != n-1 and store[now_n+1][now_m] < store[now_n][now_m]): # down
            tmp2 = down_map(store,answer,n,m,now_n+1,now_m)
        if(now_m != 0 and store[now_n][now_m-1] < store[now_n][now_m]): # left
            tmp3 = down_map(store,answer,n,m,now_n,now_m-1)
        if(now_m != m-1 and store[now_n][now_m+1] < store[now_n][now_m]): # right
            tmp4 = down_map(store,answer,n,m,now_n,now_m+1)

        total = tmp1 + tmp2 + tmp3 + tmp4
        answer[now_n][now_m] = total
        return total


a,b = input().split(" ")
n = int(a)
m = int(b)
store = [[0]*m for i in range(n)]
answer = [[-1]*m for i in range(n)]

for i in range(0,n):
    store[i] = list(map(int, input().split()))

print(down_map(store,answer,n,m,0,0))