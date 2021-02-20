# 37m

# 자칫하면 brute-force로 오해할수 있다.
# 앞뒤 관계가 독립인것 처럼 보이지만
# k번째까지 합을 구해봤을때 그 합은 0이상 20이하여야한다(문제조건)
# 따라서 현재까지 합을 total이라 한다면
# (k,total)일때 중복으로 재귀를 반복하는 경우가 있다.
# 따라서 k번째까지 합을 구했을때 모든 경우들을 한번에 묶어서 보는게아니라
# 그당시 total값을 함께 연관지어 생각해서 미지수가 두개인 상황으로 반복을 줄일수 있다.
# 따라서 2차원배열로 answer값을 저장해둬야한다.
# answer 구조에 대한 자세한 내용은 아래에 기술되어있다.

import sys
sys.setrecursionlimit(100000) 

def plus_minus(store,answer,n,now,total):
    if(now == n-2):
        if(total == store[n-1]):
            return 1
        else:
            return 0
    else:
        final = 0
        if(total + store[now+1] >= 0 and total + store[now+1] <= 20):
            tmp = answer[now+1][total+store[now+1]] if answer[now+1][total+store[now+1]] != -1 else plus_minus(store,answer,n,now+1,total+store[now+1])
            final = final + tmp
        if(total - store[now+1] >= 0 and total - store[now+1] <= 20):
            tmp = answer[now+1][total-store[now+1]] if answer[now+1][total-store[now+1]] != -1 else plus_minus(store,answer,n,now+1,total-store[now+1])
            final = final + tmp
                    
    answer[now][total] = final
    return final

n = int(input(""))

store = []
answer = [[-1]*21 for i in range(n)]
# answer[i][j] 설명 (i : 현재 몇번째인지, j : 현재까지 합이 몇인지)
# ex) answer[3][9] = 1 -> 현재 3번째까지 합했는데 9이다. 이때 뒤로 가능한 개수는 1개이다
# 
# -1 : 아직 안가봄
# 0이상 : 그만큼 가능하다(불가능)

store = list(map(int, input().split()))

print(plus_minus(store,answer,n,0,store[0]))