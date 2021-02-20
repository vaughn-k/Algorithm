import sys
sys.setrecursionlimit(10000000) 

def st(sticker,answer,now,state):
# state : 0-up 1-down - 2-no
    if(now == -1):
        return 0
    if(answer[state][now] != -1):
        return answer[state][now]
    if(state == 0): # 이전에 위를 선택
        tmp1 = sticker[1][now] + st(sticker,answer,now-1,1)
        tmp2 = st(sticker,answer,now-1,2)
    elif(state == 1): # 이전에 아래를 선택
        tmp1 = sticker[0][now] + st(sticker,answer,now-1,0)
        tmp2 = st(sticker,answer,now-1,2)
    if(state == 2): # 이전에 선택x
        tmp1 = sticker[0][now] + st(sticker,answer,now-1,0)
        tmp2 = sticker[1][now] + st(sticker,answer,now-1,1)
    maximum = max(tmp1, tmp2)
    answer[state][now] = maximum
    return maximum



t = int(input(""))
for i in range(0,t):
    n = int(input(""))
    sticker = [[0]*n for i in range(2)]
    answer = [[-1]*n for i in range(3)]

    for j in range(0,2):
        sticker[j] = list(map(int, input().split()))
    print(st(sticker,answer,n-1,2))

