import sys
sys.setrecursionlimit(1000000000) 

def ps(station,store,n,remain,answer): # remain : 앞으로 더 켜야할 발전소 수
    minimum = float('inf')
    if(remain == 0):
        return 0

    if(answer[store][remain] != -1):
        return answer[store][remain]
    for i in range(0,n):
        if(store & 1 << (n-1-i)): # 이미 갔던곳
            pass
        else: # 안간곳 
            tmp = find(station,store,n,i) + ps(station,store+(1 << (n-i-1)),n,remain-1,answer)
            if(minimum > tmp):
                minimum = tmp
    answer[store][remain] = minimum
    return minimum

def find(station,store,n,target):
    minimum = float('inf')
    for i in range(0,n):
        if(store & 1 << (n-1-i)): # 이미 갔던곳
            tmp = station[i][target]
            if(minimum > tmp):
                minimum = tmp
    return minimum


n = int(input(""))
station = [[0]*n for i in range(n)]
for i in range(0,n):
    station[i] = list(map(int, input().split()))
state = input("")
p = int(input(""))

total = 0
possible = 0
for i in range(0,len(state)):
    if(state[i] == "Y"):
        total = total + (1 << (len(state)-i-1))
        possible = possible + 1

store = total
answer = [[-1]*n for i in range(66000)]


if(possible == 0):
    print(-1)
elif(possible >= p):
    print(0)
else:
    print(ps(station,store,n,p-possible,answer))

# 5
# 0 9 6 6 6
# 6 0 6 6 1
# 6 20 0 6 6
# 6 30 6 0 6
# 6 50 6 6 0
# NNYYY
# 4

# 16
# 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12
# 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12
# 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12
# 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12
# 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12
# 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12
# 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12
# 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12
# 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12
# 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12
# 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12
# 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12
# 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12
# 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12
# 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12
# 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12
# YYYYYYYYYYYYYYYYY
# 16


# 6
# 0 23 43 14 12 11
# 34 0 43 42 14 34
# 14 29 0 23 28 14
# 19 22 14 0 19 11
# 50 23 13 23 0 45
# 45 24 13 14 11 0
# YNYNNN
# 4