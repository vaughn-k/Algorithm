# 런타임 에러 날때
import sys
sys.setrecursionlimit(10000000) 
import time

    # p : 소형기관차가 태울수있는 손님수
    # now : 현재 기차의 index
    # remain : 남은 소형기관차 수
# def tr_main(answer, train, n, p, remain, now):
#     maximum = -1
#     for i in range(0,(n-3*p)+1):
#         for j in range(i+p,(n-2*p)+1):
#             for k in range(j+p,n-p+1):

#                 tmp = tr(answer,train,i,j,k,p)
#                 if(tmp > maximum):
#                     maximum = tmp
#     return maximum

# def tr(answer, train,i,j,k,p):

#     total = sum(train[i:i+p])+ sum(train[j:j+p])+ sum(train[k:k+p])
#     return total


# def tr_main(answer, train, n, p, remain, now):
#     print(remain, now)
#     maximum = -1
#     if(answer[now][remain] != -1):
#         print("used : now : ",now," remain : ",remain)
#         return answer[now][remain]
#     if(remain == 3):
#         for i in range(now,n-3*p+1):
#             tmp = sum(train[now:now+p])+tr_main(answer,train,n,p,2,i+p)
#             if(maximum < tmp):
#                 maximum = tmp 
#     elif(remain == 2):
#         for i in range(now,(n-2*p+1)):
#             tmp = sum(train[now:now+p])+tr_main(answer,train,n,p,1,i+p)
#             if(maximum < tmp):
#                 maximum = tmp 
#     elif(remain == 1):
#         for i in range(now,n-p+1):
#             tmp = sum(train[now:now+p])+tr_main(answer,train,n,p,0,i+p)
#             if(maximum < tmp):
#                 maximum = tmp 
#     else:
#         return 0
    
#     answer[now][remain] = maximum
#     return maximum

def tr_main(store, answer, train, n, p, remain, now):
    if(now == n and remain == 0):
        return 0
    if(now > n-1 or remain < 0):
        return float('inf')*(-1)
    if(answer[now][remain] != -1):
        return answer[now][remain]
    if(now+p < n):
        if(store[now][now+p] != -1):
            total = store[now][now+p]
        else:
            total = sum(train[now:now+p])
            store[now][now+p] = total
        tmp1 = total+ tr_main(store,answer,train,n,p,remain-1,now+p)
    else:
        tmp1 = -1
    tmp2 = tr_main(store,answer,train,n,p,remain,now+1)
    maximum = max(tmp1, tmp2)
    answer[now][remain] = maximum
    return maximum

n = int(sys.stdin.readline())
train = [0] * (n+1)
train = list(map(int, sys.stdin.readline().split()))
p = int(sys.stdin.readline())
answer = [[-1] * 4 for i in range(n+1)]
store = [[-1] * (n+1) for i in range(n+1)]

now = time.time()
print(tr_main(store,answer, train,n,p,3,0))
after = time.time()
print(after-now)


# 441
# 10 20 30 10 20 10 19 28 68 58 47 46 57 62 71 24 68 71 24 68 73 26 48 72 34 10 20 30 10 20 10 19 28 68 58 47 46 57 62 71 34 68 71 24 68 73 26 48 72 34 10 20 30 10 20 10 19 28 68 58 47 46 57 62 71 24 68 71 24 68 73 26 48 72 34 10 20 30 10 20 10 19 28 68 58 47 46 57 62 71 24 68 71 24 68 73 26 48 72 34 10 20 30 10 20 10 19 28 68 58 47 46 57 62 71 24 68 71 24 68 73 26 48 72 34 10 20 30 10 20 10 19 28 68 58 47 46 57 62 71 24 68 71 24 68 73 26 48 72 34 10 20 30 10 20 10 19 28 68 58 47 46 57 62 71 24 68 71 24 68 73 26 48 72 34 10 20 30 10 20 10 19 28 68 58 47 46 57 62 71 24 68 71 24 68 73 26 48 72 34 10 20 30 10 20 10 19 28 68 58 47 46 57 62 71 24 68 71 24 68 73 26 48 72 34 10 20 30 10 20 10 19 28 68 58 47 46 57 62 71 24 68 71 24 68 73 26 48 72 3410 20 30 10 20 10 19 28 68 58 47 46 57 62 71 24 68 71 24 68 73 26 48 72 34 10 20 30 10 20 10 19 28 68 58 47 46 57 62 71 34 68 71 24 68
# 5

