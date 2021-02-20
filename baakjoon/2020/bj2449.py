

def delete_same(arr):
    ans = []
    ans.append(arr[0])
    tmp = 0
    for i in arr:
        if(ans[-1] != i):
            ans.append(i)
    return ans

def find_length(arr,store,sub):
    max_i = -1
    maximum = -1
    for i in range(len(arr)):
        if(sub[arr[i]] == -1): # 이제 첫숫자 발견
            sub[arr[i]] = i
        else:
            tmp = i - sub[arr[i]]
            store[sub[arr[i]]] = tmp
            if(tmp > maximum):
                maximum = tmp
                max_i = sub[arr[i]]
            sub[arr[i]] = i 
    # print(max_i, maximum)
    # print(arr[:max_i] + arr[(max_i+maximum):])
    return arr[:max_i] + arr[(max_i+maximum):]   

store = [-1] * 201
sub = [-1] * 21

a,b = input().split(" ")
arr = list(map(int,input().split()))

arr = delete_same(arr)
count = 0
print(arr)

while (len(arr) != 1):
    arr = find_length(arr,store,sub)
    count = count + 1
    print(arr)

print(count)