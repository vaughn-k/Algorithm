a = int(input(""))
b = int(input(""))
c = int(input(""))
n = a*b*c
arr = [0] * 10
k = str(n)
for i in range(len(k)):
    arr[int(k[i])] = arr[int(k[i])] + 1

for i in range(0,10):
    print(arr[i])