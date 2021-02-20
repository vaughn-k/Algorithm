# 20 - python - 아스키코드, 내장 sort


n = int(input(""))
arr = []

answer = []
for i in range(0,100):
    answer.append(0)


for i in range(0,n):
    x = input("")
    arr.append(x)

for i in range(0,n):
    for j in range(0,len(arr[i])):
        answer[ord(arr[i][j])] = answer[ord(arr[i][j])] + pow(10,len(arr[i]) -j -1)

ans = []
for i in range(0,100):
    if(answer[i] != 0):
        ans.append(answer[i])

ans.sort(reverse=True)
count = 9
final = 0
for i in range(0,len(ans)):
    final = final + ans[i]*count
    count = count - 1
print(final)
