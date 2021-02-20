# 10m

import sys
sys.setrecursionlimit(100000) 

def stairs(n,now_index,now,answer):
    if(now_index == n-1):
        return 1

    if(answer[now_index][now] != -1):
        return answer[now_index][now]

    if(now == 0):
        total = stairs(n,now_index+1,now+1,answer)
    elif(now == 9):
        total = stairs(n,now_index+1,now-1,answer)
    else:
        tmp1 = stairs(n,now_index+1,now-1,answer)
        tmp2 = stairs(n,now_index+1,now+1,answer)
        total = tmp1 + tmp2
    
    answer[now_index][now] = total
    return total




n = int(input(""))
answer = [[-1]*10 for i in range(101)]
total = 0
for i in range(1,10):
    tmp = stairs(n,0,i,answer)
    total = total + tmp

print(total%1000000000)