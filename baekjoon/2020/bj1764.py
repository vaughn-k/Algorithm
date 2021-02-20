store = [0] * 26

print(ord('a')-97)


n,m = input().split(" ")
n = int(n)
m = int(m)

for i in range(n):
    tmp = input()
    store[ord(tmp[0])-97].append(tmp)

for i in range(m):
    tmp = input()

print(store)