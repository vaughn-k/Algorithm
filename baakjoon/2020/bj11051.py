def atob_fac(a,b):
    total = 1
    for i in range(a,b+1):
        total = total * i
    return total


a,b = input("").split()
n = int(a)
k = int(b)

if(k > n-k):
    b = k
    a = n-k
else:
    b = n-k
    a = k
ans = atob_fac(b+1,n)//atob_fac(1,a)
print(ans%10007)

