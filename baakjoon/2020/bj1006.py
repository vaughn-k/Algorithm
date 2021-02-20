import sys
sys.setrecursionlimit(10000000)

def dp(answer,v,n,w,now,up,down,s_up,s_down):
    if(n == 3):
        if(s_up == 1 and s_down == 1):
            if(v[1][1] + v[0][1] <= w):
                return 1
            else:
                return 2
        if(s_up == 1):
            if(v[1][0]+v[1][1] <= w or v[0][1]+v[1][1] <= w or v[1][1]+v[1][2] <= w):
                return 3
            else:
                return 4        
        if(s_down == 1):
            if(v[0][0]+v[0][1] <= w or v[0][1]+v[1][1] <= w or v[0][1]+v[0][2] <= w):
                return 3
            else:
                return 4
        else:
            if(v[0][0]+v[1][0] <= w):
                

    if(now == n):
        return 0
    if(now == n-1):
        if(s_up == 0 and s_down == 0):
            if(up == 1):
                return 1
            if(down == 1):
                return 1
            else:
                if(v[0][now]+v[1][now] <= w):
                    return 1
                else:
                    return 2
        elif(s_up == 1 and s_down == 0):
            return 1
        else: # s_up == 0 and s_down == 1
            return 1
    if(now == n-2 and (s_up == 1 or s_down == 1)):
        if(s_up == 1):
            if(v[0][now]+v[1][now] <= w):
                return 2
            if(v[1][now]+v[1][now+1] <= w):
                return 2
            return 3
        else: # s_down == 1
            if(v[0][now]+v[1][now] <= w):
                return 2
            if(v[0][now]+v[0][now+1] <= w):
                return 2
            return 3

    if(answer[up+down*2+s_up*4+s_down*8][now] != -1):
        return answer[up+down*2+s_up*4+s_down*8][now]
    tmp1,tmp2,tmp3,tmp4 = float('inf'),float('inf'),float('inf'),float('inf')
    # up donw 0,0일때
    if(up==0 and down == 0):
        tmp1 = dp(answer,v,n,w,now+1,0,0,s_up,s_down)
        if(v[0][now]+v[1][now] <= w): # 위아래로 한소대가 맡을수 있는경우
            tmp1 = tmp1+1
        else: # 위아래 따로 맡을경우
            tmp1 = tmp1+2

        if(v[0][now]+v[0][now+1] <= w and v[1][now]+v[1][now+1] <= w): 
            tmp2 = 2 + dp(answer,v,n,w,now+2,0,0,s_up,s_down) # 위아래 동시에 옆으로 맡음
            tmp3 = 2 + dp(answer,v,n,w,now+1,1,0,s_up,s_down) # 위에만 두개 맡음
            tmp4 = 2 + dp(answer,v,n,w,now+1,0,1,s_up,s_down) # 아래만 두개맡음
        else:
            if(v[0][now]+v[0][now+1] <= w):
                tmp2 = 2 + dp(answer,v,n,w,now+1,1,0,s_up,s_down) 
            if(v[1][now]+v[1][now+1] <= w):
                tmp3 = 2 + dp(answer,v,n,w,now+1,0,1,s_up,s_down) 
    elif(up == 1 and down == 0):
        tmp1 = 1 + dp(answer,v,n,w,now+1,0,0,s_up,s_down) 
        if(v[1][now]+v[1][now+1] <= w):
            tmp2 = 1 + dp(answer,v,n,w,now+1,0,1,s_up,s_down)
    else:
        tmp1 = 1 + dp(answer,v,n,w,now+1,0,0,s_up,s_down)
        if(v[0][now]+v[0][now+1] <= w):
            tmp2 = 1 + dp(answer,v,n,w,now+1,1,0,s_up,s_down)


    
    maximum = min(tmp1,tmp2,tmp3,tmp4)
    answer[up+down*2+s_up*4+s_down*8][now] = maximum
    return maximum
        


t = int(input(""))
for i in range(t):
    n,w = input().split(" ")
    n = int(n)
    w = int(w)

    v = [[0]*n for i in range(2)]
    v[0] = list(map(int, sys.stdin.readline().split()))
    v[1] = list(map(int, sys.stdin.readline().split()))

    answer = [[-1] * n for i in range(16)]
    ans1 = dp(answer,v,n,w,0,0,0,0,0)
    ans2,ans3,ans4 = float('inf'),float('inf'),float('inf')
    if(v[0][0]+v[0][n-1] <= w):
        ans2 = 1 + dp(answer,v,n,w,0,1,0,1,0)
    if(v[1][0]+v[1][n-1] <= w):
        ans3 = 1 + dp(answer,v,n,w,0,0,1,0,1)
    if(v[1][0]+v[1][n-1] <= w and v[0][0]+v[0][n-1] <= w):
        ans4 = 2 + dp(answer,v,n,w,1,0,0,1,1)
    final = min(ans1,ans2,ans3,ans4)
    print(final)

# 2
# 8 100
# 70 60 55 43 57 60 44 50 
# 58 40 47 90 45 52 80 40
# 5 120
# 70 55 57 60 50 
# 47 90 45 52 80

# 1
# 6 9443
# 7422 2745 8376 2874 1159 7119
# 9400 5836 7028 6597 5881 7640

# 3
# 8 100
# 70 60 55 43 57 60 44 50
# 58 40 47 90 45 52 80 40
# 1 100
# 49
# 49
# 1 100
# 51
# 51

# 8
# 2 100
# 49 49
# 49 49
# 2 100
# 51 51
# 51 51
# 2 100
# 49 51
# 51 49
# 2 100
# 51 51
# 49 49
# 2 100
# 49 51
# 51 51
# 2 100
# 51 49
# 51 51
# 2 100
# 51 51
# 49 51
# 2 100
# 51 51
# 51 49

# 8
# 3 100
# 49 49 49
# 49 49 49
# 3 100
# 49 51 51
# 51 51 51
# 3 100
# 51 51 51
# 49 51 51
# 3 100
# 49 51 51
# 49 51 51
# 3 100
# 49 51 49
# 49 51 49
# 3 100
# 51 51 49
# 51 49 51
# 3 100
# 49 51 49
# 51 51 51
# 3 100
# 51 49 51
# 51 51 51

