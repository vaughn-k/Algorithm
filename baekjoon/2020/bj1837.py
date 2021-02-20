import time
# count = pow(10,50)

# print(count)
# a = 1
# before = time.time()
# for i in range(0,count):
#     a = a+1
# after = time.time()

# print(after-before)


before = time.time()
def sieve(n):
    if n < 2:
        return []
    s = [0, 0] + [1] * (n - 1)
    for i in range(2, int(n**.5)+1):
        if s[i]:
            print(i)
            s[i*2::i] = [0] * ((n - i)//i)
    return [i for i, v in enumerate(s) if v]

print(len(sieve(500)))
after = time.time()

print(after-before)