import sys
sys.setrecursionlimit(10000000) 

def seat(answer):
    a,b = input().split(" ")
    n = int(a)
    m = int(b)
    store = []

    for i in range(0,n):
        x = input()
        store.append(x)

    left = 0
    right = 0
    check = False
    for i in range(0,m):
        check = not check
        for j in range(0,n):
            if(store[j][i] == '.'):
                if(check):
                    left = left + 1
                else:
                    right = right + 1

    answer.append(max(left,right))
    return 0


c = int(input(""))
answer = []
for i in range(0,c):
    seat(answer)

for i in range(0,c):
    print(answer[i])
