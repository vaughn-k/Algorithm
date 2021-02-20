import sys
sys.setrecursionlimit(10000000) 

# 변수가 3개 필요한 메모이제이션시에 두개의 변수를 자릿수로 통제할때 다른자릿수로 다른 변수가 넘거가서 충돌이
# 일어나지 않는지 확인해야한다 반드시

def magic(answer,st,up,down,now,state,match):
    if(match == len(st)-1):
        return 1
    if(now == len(up)-1):
        return 0
    if(answer[now][match*10+state] != -1):
        return answer[now][match*10+state]
    if(state == 0):
        tmp1 = 0
        if(down[now] == st[match]):
            tmp1 = magic(answer,st,up,down,now+1,1,match+1)
        tmp2 = magic(answer,st,up,down,now+1,0,match)
    else:
        tmp1 = 0
        if(up[now] == st[match]):
            tmp1 = magic(answer,st,up,down,now+1,0,match+1)
        tmp2 = magic(answer,st,up,down,now+1,1,match)
    total = tmp1 + tmp2
    answer[now][match*10+state] = total
    return total


st = sys.stdin.readline()
up = sys.stdin.readline()
down = sys.stdin.readline()
answer = [[-1] * 300 for i in range(300)]

a1 = magic(answer,st,up,down,0,0,0)
a2 = magic(answer,st,up,down,0,1,0)
print(a1+a2)
