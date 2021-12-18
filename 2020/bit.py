# 비트연산
n = 5
a = 1 << n-1
b = (1 << n) -1


print(bin(a))
a = a + (1 << (n-4-1))
print(bin(a))

a = a + (1 << (n-3-1))
print(bin(a))
a = a + (1 << (n-2-1))
print(bin(a))
a = a + (1 << (n-1-1))
print(bin(a))

print(bin(b))
# a = 0b1011001110


# # 1 4 5
# n = 10
# print(a)
# print(bin(a))
# print("------------")
for i in range(n):
    print(i)
    # if(a & (1 << i) == 0):
    #     print(n-i-1)