import sys
sys.setrecursionlimit(10000000) 

def w(store,a,b,c):
    if(a <= 0 or b <= 0 or c <= 0):
        return 1
    if(a > 20 or b > 20 or c > 20):
        return w(store,20,20,20)
    if(store[a][b][c] != None):
        return store[a][b][c]
    if(a < b and b < c):
        ans = w(store,a,b,c-1) +w(store,a,b-1,c-1) - w(store,a,b-1,c)
        store[a][b][c] = ans
        return ans
    else:
        ans = w(store,a-1,b,c) + w(store,a-1,b-1,c) + w(store,a-1,b,c-1) - w(store,a-1,b-1,c-1)
        store[a][b][c] = ans
        return ans

a,b,c = 1,2,3
while(not(a == -1 and b == -1 and c == -1)):
    a,b,c = input().split()
    a = int(a)
    b = int(b)
    c = int(c)
    if(not(a == -1 and b == -1 and c == -1)):
        store = [[[None for col in range(21)] for row in range(21)] for depth in range(21)]
        print("w(",end="")
        print(a,end="")
        print(", ",end="")
        print(b,end="")
        print(", ",end="")
        print(c,end="")
        print(") = ",end="")
        print(w(store,a,b,c))

# 1 1 1
# 2 2 2
# 10 4 6
# -1 -1 -1
