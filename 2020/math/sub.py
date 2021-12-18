j = 0

N = int(input())
if N >= 1023:
    print(-1)
    exit()

def dfs(c, d, l):
    global j, N
    print(c," ",d," ",l," ",j," ",N)

    r = '{:s}{:d}'.format(d, c)
    if l == 0:
        if j == N:
            print(r)
            exit()
        j += 1
        return
    for i in range(c):
        dfs(i, r, l-1)

level = 0
while 1:
    for i in range(10):
        dfs(i, '', level)
    level += 1