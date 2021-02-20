n = int(input(""))

total = 0
k = 1
while(total <= n):
    total = total + k
    k = k+1
if(n == 1):
    print(1)
else:
    print(k-2)