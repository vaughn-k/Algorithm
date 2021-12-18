import sys
sys.setrecursionlimit(10000000) 

def max_box(box,answer,now,n):
    if(now == n-1):
        return 1
    now_max = 1
    if(answer[now] != -1):
        return answer[now]
    for i in range(now,n):
        if(box[now] < box[i]):
            tmp = 1 + max_box(box,answer,i,n)
            if(now_max < tmp):
                now_max = tmp
    answer[now] = now_max
    return now_max

n = int(input(""))
box = list(map(int, input().split()))
answer = [-1] * (n+1)

for i in range(0,n):
    max_box(box,answer,i,n)
print(max(answer))
