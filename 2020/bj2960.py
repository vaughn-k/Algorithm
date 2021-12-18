n,k = input().split(" ")
n = int(n)
k = int(k)

arr = list(range(2,n+1))
answer = []
while(len(arr) != 0):
    tmp = arr[0]
    answer.append(tmp)
    arr.remove(tmp)
    for i in arr:
        if(i%tmp == 0):
            arr.remove(i)
            answer.append(i)

print(answer[k-1])