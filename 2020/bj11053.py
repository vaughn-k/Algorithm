# 너무 짜증나네;; 한 10몇퍼에서 틀렸습니다가 뜸 20.01.17

import sys
sys.setrecursionlimit(10000000) 

def find_long(array,n,now,answer,now_max):
    if(now == n):
        return 0
    if(answer[now][now_max] != -1):
        return answer[now][now_max]
    tmp1, tmp2 = -1,-1
    check = False
    if(array[now] > now_max):
        check = True
        tmp1 = 1 + find_long(array,n,now+1,answer,array[now])
    tmp2 = find_long(array,n,now+1,answer,now_max)
    ans = max(tmp1,tmp2)
    answer[now][now_max] = ans
    return ans
    




n = int(input(""))
answer = [[-1]*1001 for i in range(1001)]
array = list(map(int, input().split()))

print(find_long(array,n,0,answer,-1))


# 15 
# 10 20 10 30 20 50 1 2 3 99 5 6 7 8 9

