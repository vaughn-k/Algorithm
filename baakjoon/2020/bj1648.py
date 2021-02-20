# 이전에 5721번 사탕먹기 문제와 비슷했다.
# 그문제보다 조금 더 까다로웠던 문제였던것 같다.
# 중요한 포인트는
# 1. 모든칸을 방문하는 brute-force를 어떻게 구현할것인지와
# 2. 메모이제이션을 어떻게 할것인가 였다.
# 메모이제이션 같은 경우 2^n * n * m 만큼의 메모리를 사용할경우와
# 2^n * 2^n * n * m 만큼의 메모리를 사용할때로 나뉘는데 
# 후자가 더 빠르긴하지만 메모리가 너무 커져서 전자로 사용했는데 그정도로도 충분히 2초 이내에 성공한다.
# 보통 메모이제이션을 할때 빈틈없이 한번이라도 가봤으면 다 메모이제이션 처리하는데 
# 이 문제같은 경우는 next_state가 비워져있을때(현재줄 기준으로 오른쪽으로 튀어나간 블록이 없는경우)
# 만 고려하였다.


def dp(answer,n,m,i,j,now_state,next_state): # 진행우선방향 : 아래->오른쪽
    tmp1, tmp2 = 0,0
    if(j == m): # 맨 오른쪽 넘었을때
        if(now_state == 1 << n): 
            return 1 # 맨오른쪽을 넘었고 마지막줄을 빈칸없이 다 채웠을때
        else:
            return 0 # 맨오른쪽을 넘었고 마지막줄에 빈칸이 있을때
    if(i == n+1):
        return 0 # 맨 아래 한칸 초과
    if(i == n): # 맨 아래쪽 넘었을때
        now_state = next_state
        next_state = 1<<n
        return dp(answer,n,m,0,j+1,now_state,next_state) # 다음줄로 이동
    else:
        if(next_state == (1<<n) and answer[i][j][now_state] != -1):
            return answer[i][j][now_state]
        if(now_state & 1<<i): # 현재칸이 채워져있다면 다음칸으로 전진
            tmp1 = dp(answer,n,m,i+1,j,now_state,next_state) 
        else:
            tmp1 = dp(answer,n,m,i+1,j,now_state,next_state+(1<<i)) # 옆으로채우기
            if(not(now_state & 1<<(i+1))):
                tmp2 = dp(answer,n,m,i+2,j,now_state,next_state) # 아래로채우기
    total = (tmp1+tmp2)%9901
    if(next_state == (1<<n)):
        answer[i][j][now_state] = total
    return total

n,m = input().split(" ")
n = int(n)
m = int(m)

answer = [[[-1]*(1<<(n+1)) for i in range(m)] for j in range(n)]
now_state = 1 << n
next_state = 1 << n
print(dp(answer,n,m,0,0,now_state,next_state))