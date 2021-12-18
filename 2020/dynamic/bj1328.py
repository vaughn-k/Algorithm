# 1h 40m
# 점화식을 찾는데 오래걸렸고 answer값이 존재할때 안할때 모두 (n-2)를 곱해줬어야 했는데
# answer이 있을때는 곱해주지 않아 계속 오류가 났었다.

"""
2021/08/20
오랜만에 다시보니 이당시 어떻게 풀었는지 생각이 잘 안났다;;
다른 블로그보면서 다시 생각해보니
이러한 문제에서 점화식을 찾는 방법은 만약 (7,2,3) 의 경우의 수를 구할때


"""

def building(n,left,right):

    if(left+right-1 > n or left == 0 or right == 0):
        return 0
    if(n == 1):
        if(left == 1 and right == 1):
            return 1
        else:
            return 0
    else:
        if(answer[n][left][right] != -1):
            return answer[n][left][right]
    
        a = building(n-1,left,right)*(n-2)
        b = building(n-1,left-1,right)
        c = building(n-1,left,right-1)
        total = a+b+c
        answer[n][left][right] = total
        return total

a,b,c = input().split(" ")
n = int(a)
left = int(b)
right = int(c)
answer = [[[-1 for col in range(n+1)] for row in range(n+1)] for depth in range(n+1)]
if(n == 1):
    print(1)
else:
    print(building(n,left,right)%1000000007)