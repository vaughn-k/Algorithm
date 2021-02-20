
# 예외처리가 까다로운 문제였음
# 추가로 python에서는 기본 재귀깊이가 2000? 이여서 그 이상 재귀를 돌게되면 런타임에러가 나버린다
# 그래서 아래와같이 수동으로 limit를 조절해주니 런타임에러가 뜨지않는다.

import sys
sys.setrecursionlimit(5000) 

def dynamic_secret(answer,secret,now,check): # now : 번째 글자차례
    # print(now)
    total = 0
    if(now >= len(secret)):
        return 1
    if(secret[now] == "0"): # 10 20이면 무조건 두칸씩 넘어간다는 가정하에 현재 0을 가리키고 있으면 
                            #무조건 불가능이다
        check[0] = -1
        return -1

    else:
        if(len(secret) - now >= 3):
            two = int(secret[now+1])*10+int(secret[now+2])
            if(two == 10 or two == 20):
                if(answer[now+1] != 0):
                    total = total + answer[now+1]
                    answer[now] = total
                    return total
                else:
                    total = total + dynamic_secret(answer,secret,now+1,check)
                    answer[now] = total
                    return total
            elif(two%10 == 0):
                check[0] = -1
                return -1
        if(len(secret) - now >= 2):
            two = int(secret[now])*10+int(secret[now+1])
            if(two == 10 or two == 20):
                if(answer[now+2] != 0):
                    total = total + answer[now+2]
                else:
                    total = total + dynamic_secret(answer,secret,now+2,check)
            else:
                if(two <= 26):
                    if(answer[now+2] != 0):
                        total = total + answer[now+2]
                    else:
                        total = total + dynamic_secret(answer,secret,now+2,check)
                if(answer[now+1] != 0):
                    total = total + answer[now+1]
                else:
                    total = total + dynamic_secret(answer,secret,now+1,check)
            answer[now] = total
            return total
        else:
            return 1
    return total

answer = []
check = []
check.append(0)
secret = input("")

for i in range(0,5005):
    answer.append(0)

ans = dynamic_secret(answer,secret,0,check)
if(check[0] == 0):
    print(ans%1000000)
else:
    print(0)
