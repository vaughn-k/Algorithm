
dp = [0] * 1000001
dp[1] = 0
dp[2] = 1
n = int(input(""))
for i in range(3,n+1):
    dp[i] = (i-1)*(dp[i-1]+dp[i-2])%1000000000

print(dp[n])


# print(a[n])
# print(fac)
# print(dp[:10])

# nCm = fac(n) / fac(m)*fac(n-m)
# = a[n]/(a[m]*a[n-m])
