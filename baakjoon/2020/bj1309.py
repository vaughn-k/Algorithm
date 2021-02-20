n = int(input(""))
now = 2
a = 2
b = 3
next_a = 0
next_b = 0
if(n == 1):
    print(3)
elif(n == 2):
    print(7)
else:
    while(now != n):
        next_a = (a+b)%9901
        next_b = (a+a+b)%9901
        a,b = next_a,next_b
        now = now + 1
    print((next_a*2+next_b)%9901)
