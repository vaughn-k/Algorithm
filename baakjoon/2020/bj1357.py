def rev(x):
    ans = ''
    for i in range(len(x)):
        index = len(x)-i-1
        ans = ans + x[index]
    return ans


x,y = input().split(" ")
a = int(rev(x))
b = int(rev(y))
tot = a+b
ans = int(rev(str(tot)))
print(ans)
n