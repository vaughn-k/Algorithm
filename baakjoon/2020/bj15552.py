import sys
t = int(sys.stdin.readline())
for i in range(0,t):
    a = list(map(int, sys.stdin.readline().split()))
    print(a[0]+a[1])