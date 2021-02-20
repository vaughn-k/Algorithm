# 짜증나네;; 내가 이해한게 맞는지 아닌지 몰겄ㄸ음;;

import sys

def dp(answer,true,party,n,m,now):
    if(now == m):
        return 0
    tmp1,tmp2 = 0,0
    if(same(true,party[now])): # 없다면 구라가능
        tmp1 = 1 + dp(answer,true,party,n,m,now+1)
    else: 
        tmp = true[:] # 얕은 복사
        true.extend(party[now])
        true = list(set(true))
        true.sort()
        tmp1 = dp(answer,true,party,n,m,now+1)
        # true = tmp[:]
        
    return tmp1

def same(l,s): # 항상 소트된 상태로 들어온다고 가정
    for i in range(len(l)): 
        for j in range(len(s)):
            if(l[i] == s[j]):
                return False
    return True

n,m = input().split(" ")
n = int(n)
m = int(m)
true = list(map(int, sys.stdin.readline().split()))
true = true[1:]
party = [0]*m
for i in range(m):
    a  = list(map(int, sys.stdin.readline().split()))
    party[i] = a[1:]


answer = []    
ans = dp(answer,true,party,n,m,0)
print(ans)
