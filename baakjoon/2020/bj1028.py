import sys

def make_start(answer,dia,r,c):
    m = min(r,c)
    if(m%2 == 0): # 짝수
        maximum = m//2
    else:# 홀수
        maximum = (m+1)//2
    while(maximum >= 1):
        for i in range(0,r-(maximum*2-1)+1):
            for j in range(0,c-(maximum*2-1)+1):
                if(check(answer,dia,maximum,i,j) != 0):
                    return maximum
        maximum = maximum-1
    return 0

def check(answer,dia,n,i,j):
    i,j = i,j+(n-1)
    total = n*4 - 4
    tmp1,tmp2,tmp3,tmp4 = 0,0,0,0
    if(n == 1):
        if(dia[i][j] == '1'):
            return 1
        else:
            return 0
    for a in range(total):
        if(dia[i][j] == '0'):
            return 0
        if(a < total//4):
            i,j = i+1,j+1
            tmp1 = tmp1+1
            if(answer[i][j][0] < tmp1):
                answer[i][j][0] = tmp1
        elif(a < (total//4)*2):
            i,j = i+1,j-1
            tmp2 = tmp2+1
            if(answer[i][j][1] < tmp2):
                answer[i][j][1] = tmp2
        elif(a < (total//4)*3):
            i,j = i-1,j-1
            tmp3 = tmp3+1
            if(answer[i][j][2] < tmp3):
                answer[i][j][2] = tmp3
        else:
            i,j = i-1,j+1
            tmp4 = tmp4+1
            if(answer[i][j][3] < tmp4):
                answer[i][j][3] = tmp4
    return 1


r,c = input().split(" ")
r = int(r)
c = int(c)
dia = [0]*r
answer = [[[-1] * 4 for i in range(r)] for j in range(c)]
for i in range(r):
    dia[i] = sys.stdin.readline()

print(make_start(answer,dia,r,c))