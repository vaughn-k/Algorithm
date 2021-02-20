import sys
sys.setrecursionlimit(1000000000) 
import time

def blocktop(answer,block,left,right,n,now,total,now_max):
    if(now == n):
        if(left != right):
            return -1
        else:
            if(now_max[0] < left):
                now_max[0] = left
            return left
    if(abs(left-right) > total):
        return -1
    if(answer[now][abs(right-left)] != None):
        return answer[now][abs(right-left)] + min(left,right)
    # if(now_max[0] > (left+right+total)/2):
    #     return -1
    # 해당 블록을 왼쪽에 쌓음
    tmp1 = blocktop(answer,block,left+block[now],right,n,now+1,total-block[now],now_max)
    # 해당 블록을 오른쪽에 쌓음
    tmp2 = blocktop(answer,block,left,right+block[now],n,now+1,total-block[now],now_max)
    # 해당 블록은 쌓지 않음
    tmp3 = blocktop(answer,block,left,right,n,now+1,total-block[now],now_max)

    maximum = max(tmp1,tmp2,tmp3)
    if(maximum != -1):
        answer[now][abs(right-left)] = maximum - min(left,right)
    else:
        answer[now][abs(right-left)] = maximum
    return maximum

n = int(input(""))
block = list(map(int, input().split()))
answer = [[None]*500001 for i in range(n+1)]
# None : 아직 방문 안한 상태
# -1 : 불가능
# 나머지 : 쌓을수 있는 총개수

now = time.time()
now_max = []
now_max.append(-1)
ans = blocktop(answer,block,0,0,n,0,sum(block),now_max)
if(ans == -1 or ans == 0):
    print(-1)
else:
    print(ans)
after = time.time()

print(after - now)

# for i in range(0,20):
#     for j in range(0,20):
#         print("answer[",i,"][",j,"] = ",answer[i][j])
# for i in range()

# 50
# 3332 892 7842 627 879 7238 6782 9613 8447 6922 8226 2224 982 256 9224 2285 922 8457 9287 325 93 823 674 982 32 644 740 223 478 968 17462 3874 563 823 75682 744 658 274 658 734 685 734 748 658 562 575 564 516 425 218