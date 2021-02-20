a = "YNN"
total = 0
for i in range(0,len(a)):
    if(a[i] == "Y"):
        total = total + (1 << (len(a)-i-1))

a = total
print(a)
print(bin(a))

a = 1 << 5
n = 3

for i in range(0,5):
    if(a & 1 << (n-1-i)):
        print(i,"ok")
    else:
        print(i,"no")