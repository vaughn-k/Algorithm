import time

n,k = input().split(" ")
n = int(n)
k = int(k)


m = [0] * n
for i in range(n):
    m[i] = int(input(""))

check = True


for i in range(10000):
    print(i)
    before = time.time()
    for j in range(1000000):
        n = n+1
    after = time.time()
    print(after-before)
        

