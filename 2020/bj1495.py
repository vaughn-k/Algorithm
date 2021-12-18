
def guital(vol,answer,n,m,now,now_vol,maxv):
    if(now == n-1):
        plus = -1
        minus = -1
        ans = -1
        if(now_vol+vol[now] <= m):
            plus = now_vol + vol[now]
        if(now_vol-vol[now] >= 0 and now_vol-vol[now] <= m):
            minus = now_vol - vol[now]
        if(plus >= 0 or minus >= 0):
            if(plus < 0):
                ans = minus
            elif(minus < 0):
                ans = plus
            else:
                ans = max(plus,minus)
        if(maxv[0] < ans):
            maxv[0] = ans
    else:
        plus = -1
        minus = -1
        if(now_vol+vol[now] <= m):
            if(answer[now+1][now_vol + vol[now]] == 0):
                plus = guital(vol,answer,n,m,now+1,now_vol+vol[now],maxv)
        if(now_vol-vol[now] >= 0):
            if(answer[now+1][now_vol - vol[now]] == 0):
                minus = guital(vol,answer,n,m,now+1,now_vol-vol[now],maxv)
        answer[now][now_vol] = 1



a,b,c = input().split(" ")
n = int(a)
s = int(b)
m = int(c)
vol = []
maxv = []
maxv.append(-1)

vol = list(map(int, input().split()))

answer = [[0]*(m+1) for i in range(n+1)]


guital(vol,answer,n,m,0,s,maxv)
print(maxv[0])

