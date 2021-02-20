import sys
sys.setrecursionlimit(10000000) 

def tile(answer,n,now):
    if(now == 0 or now == 1):
        return 1
    elif(now == 2):
        return 3
    if(answer[now] != 0):
        return answer[now]
    tmp1 = 2*tile(answer,n,now-2)
    tmp2 = tile(answer,n,now-1)
    total = tmp1 + tmp2
    answer[now] = total
    return total

answer = [0] * (1001)

n = int(input(""))
print(tile(answer,n,n)%10007)
    




