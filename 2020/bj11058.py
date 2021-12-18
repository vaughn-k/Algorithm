import sys
sys.setrecursionlimit(10000000) 
import time


def make_a(n,now,a,buffer):
    if(now == n):
        return a
    if(now >= n+1):
        return -1
    if(now <= 6):
        tmp1 = make_a(n,now+1,a+1,buffer)
    else:
        tmp1 = -1
    tmp2 = make_a(n,now+3,2*a,a)
    tmp3 = make_a(n,now+1,a+buffer,buffer)
    maximum = max(tmp1,tmp2,tmp3)
    return maximum


# n = int(input(""))
for i in range(40):
    now = time.time()
    print(i+1,make_a(i+1,0,0,0))
    after = time.time()
    print(after-now)

# 처음
# 약 7.5 7.6 7.5 7.6

# a 6이상에서는 안보는조건 추가
# 약 0.1


