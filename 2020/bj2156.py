# 46m



import sys
sys.setrecursionlimit(100000) 


def grape(glass,answer,n,now,count):
    if(now == n-1): #마지막 잔
        if(count <= 1):
            return glass[now]
        else:
            return 0
    else:
        if(count <= 1):
            if(answer[now+1][count+1] != 0):
                tmp1 = glass[now] + answer[now+1][count+1]
            else:
                tmp1 = glass[now] + grape(glass,answer,n,now+1,count+1)
            
            if(answer[now+1][0] != 0):
                tmp2 = answer[now+1][0]
            else:
                tmp2 = grape(glass,answer,n,now+1,0)

        else: # count == 2
            if(answer[now+1][0] != 0):
                tmp1 = answer[now+1][0]
            else:
                tmp1 = grape(glass,answer,n,now+1,0)
            tmp2 = -1

        final = max(tmp1,tmp2)
        answer[now][count] = final
        return final


n = int(input(""))

glass = []
answer = [[0]*3 for i in range(n)]

for i in range(0,n):
    a = int(input(""))
    glass.append(a)

print(grape(glass,answer,n,0,0))



