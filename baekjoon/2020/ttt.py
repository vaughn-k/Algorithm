def count_0(a,n):
    count = 0
    for i in range(n):
        if(a & 1<<i == 0):
            count = count + 1
    return count


a = (1<<0) + (1<<1) + (1<<4)
print(bin(a))
n = 5
print(count_0(a,n))