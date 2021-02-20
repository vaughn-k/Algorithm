import sys
sys.setrecursionlimit(10000000) 

def bridge(bri,answer,i,j):
    if(i == j):
        return 1
    if(i == 1):
        return j
    if(answer[i][j] != -1):
        return answer[i][j]
    tmp1 = bridge(bri,answer,i,j-1)
    tmp2 = bridge(bri,answer,i-1,j-1)
    total = tmp1 + tmp2
    answer[i][j] = total
    return total


t = int(input(""))
bri = [[0] * 2 for i in range(0,t)]
answer = [[-1] * 31 for i in range(0,31)]
for i in range(0,t):
    a,b = input("").split(" ")
    bri[i][0] = int(a)
    bri[i][1] = int(b)

for i in range(0,t):
    print(bridge(bri,answer,bri[i][0],bri[i][1]))