# 5m

a,b = input("").split(" ")
n = int(a)
m = int(b)
l = max(n,m)
s = min(n,m)

answer = l*(s-1) + l-1
print(answer)