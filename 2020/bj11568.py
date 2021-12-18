import sys

n = int(input(""))
arr = list(map(int, sys.stdin.readline().split()))
dp = [-1] * n
dp[n-1] = 1
for i in range(1,n):
    index = n-i-1
    maximum = 0
    for j in range(index+1,n):
        if(arr[index] < arr[j] and dp[j] > maximum):
            maximum = dp[j]+1
    if(maximum == 0):
        dp[index] = 1
    else:
        dp[index] = maximum

print(max(dp))