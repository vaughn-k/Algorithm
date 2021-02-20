def gcd(m,n):
    while n != 0:
       t = m%n
       (m,n) = (n,t)
    return abs(m)

a = 154
b = 128
gc = gcd(a, b)
print("gc = ",gc)
print(gc,"로 나눈 나머지 : " ,a/gc," ",b/gc)