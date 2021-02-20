arr = [0] * 5

for i in range(5):
    arr[i] = input()

for i in range(15):
    for j in range(5):
        if(len(arr[j]) > i):
            print(arr[j][i],end="")