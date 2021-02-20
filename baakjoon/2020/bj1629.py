a,b,c = input().split(" ")

a = int(a)
b = int(b)
c = int(c)


total = a

while(b != 0):
    total = (total*a)%c
    b = b-1
    print(total)
print(total)

# 2111111111 2111234234 21111987654