# 23m
# 일단 DP로 풀어야하는데 입력값이 작아서 굳이 메모이제이션을 사용하지 않아도 시간내에 돌아가기에 메모이제이션을 사용하지않았다
# 그리고 점화식 부분에서 한번에 채울 타일 가로크기에 따라 가능한 경우의 수를 보니
# 2칸일때만 3가지고 4,6,8...칸 일때는 모두 두가지씩이였다.
# 여기서 이 몇칸인지까지 구할수 있는 알고리즘이 있을지는 고민해봐야하는 부분이다.
# (지금이야 판단이 가능해서 3,2를 대입한것)

def three_tile(answer,n,now): # now : 채운 타일개수
    if(n%2 == 1):
        return 0
    elif(now == n):
        return 1
    else:
        total = 0
        i = 2
        while(n - now - i >= 0):
            if(i == 2):
                total = total + 3 * three_tile(answer,n,now+i)
            else:
                total = total + 2 * three_tile(answer,n,now+i)
            i = i + 2
    return total


n = int(input(""))
answer = []
print(three_tile(answer,n,0))

