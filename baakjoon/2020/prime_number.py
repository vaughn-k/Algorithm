n = int(input(""))

arr = list(range(2,n+1))
answer = []
while(len(arr) != 0):
    print(arr)
    tmp = arr[0]
    answer.append(tmp)
    arr.remove(tmp)
    for i in arr:
        if(i%tmp == 0):
            arr.remove(i)

print(answer)