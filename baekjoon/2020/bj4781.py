import sys
sys.setrecursionlimit(10000000) 

# 0-1 knapsack인데 가격이 정수가 아닌실수라 100을 곱해 정수로 만들어주고 물건들이 무한개 있기때문에 같은 물건도
# 여러개 선택할수 있다. 

# dp로 풀었는데 python3 로 제출하면 시간초과인데 pypy3로 제출하면 통과한다; 

# def candy(answer,price,cal,now,n,m,now_m):
#     if(now == n):
#         return 0
#     int_m = int(now_m*100)
#     if(answer[int_m] != -1):
#         return answer[int_m]
#     if(now_m + price[now] <= m):
#         tmp1 = cal[now] + candy(answer,price,cal,now,n,m,now_m+price[now])
#     else:
#         tmp1 = -1
#     tmp2 = candy(answer,price,cal,now+1,n,m,now_m)
#     maximum = max(tmp1, tmp2)
#     answer[int_m] = maximum
#     return maximum

def candy(answer,price,cal,now,n,m,now_m):
    for i in range(0,m+1): # i = 잔액이 i원일때 가능한 최대 칼로리
        now_maximum = 0
        for j in range(0,n):
            if(i-price[j] >= 0):
                tmp = answer[i-price[j]] + cal[j]
                if(tmp > now_maximum):
                    now_maximum = tmp
        answer[i] = now_maximum
    print(max(answer))
    
n,m = 1,1
while(not(n == 0 and m == 0.0)):
    n,m = map(float,sys.stdin.readline().split())  
    n = int(n)
    m = int(m)
    price = [-1] * n
    cal = [-1] * n
    answer = [0] * 10002

    if(not(n == 0 and m == 0)):
        for i in range(n):
            sub_cal,sub_price = map(float,sys.stdin.readline().split())  
            cal[i] = int(sub_cal)
            price[i] = int(sub_price*100.0)
        candy(answer,price,cal,0,n,m*100,0)


