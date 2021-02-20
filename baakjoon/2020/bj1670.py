# 점화식이 조금 까다로웠던 문제
# 일반적으로 n을 구할때 n-1이나 n-2까지만 고려하면 구할수 있었는데
# 이문제같은경우 n을 구할때 그 이전에 구했던 n-k들을 모두 이용했다는 점에서 조금 까다로웠다.

n = int(input(""))

dp = [0] * 10001
dp[0] = 1
dp[2] = 1
dp[4] = 2
i = 6
while(i <= n):
    total = 0
    for j in range(i//4):
        j = j*2
        total = total + dp[j]*dp[i-j-2]*2

    if(i%4 == 2): # 제곱 x
        total = total + dp[(i-2)//2]*dp[(i-2)//2]
    dp[i] = total%987654321
    i = i+2

print(dp[n])
