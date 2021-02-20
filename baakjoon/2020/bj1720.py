# 몇개의 타일 채우기를 풀어봤지만 점화식이 가장 까다로웠던 dp였던것같다.
# 13m

n = int(input(""))

dp = [0] * 32
dp[1] = 1
dp[2] = 3

if(n == 1):
    ans = 1
elif(n == 2):
    ans = 3
else:
    for i in range(3,n+1):
        dp[i] = dp[i-2]*2 + dp[i-1]
    if(n%2 == 1): # 홀수
        ans = (dp[n] + dp[int((n-1)/2)])/2
    else: # 짝수    
        ans = (dp[n] + dp[int(n/2)] + dp[int(n/2)-1]*2)/2

print(int(ans))