import time

def tsp(store,min,end,last,n,save,total,remain):
    new = 0
    if(remain == 1):
        for i in range(0,n):
            if(save & (1 << i) == 0):
                new = n-i-1
                start = last
                target = new
                tmp = store[start][target]

                start = new
                target = 0
                tmp2 = store[start][target]
                
                if(tmp == 0 or tmp2 == 0): # 마지막 지점으로 갈때 or 원점으로 갈때 경로가 없다
                    return -1
                else:
                    total = total + tmp + tmp2
                    if(min[0] < 0 or min[0] > total):
                        min[0] = total
                    return 1
    # for i in range(0,n):
    #     if(save & (1 << i) == 0 and store[last][n-i-1] != 0): # 0인것이 존재한다
    #         tsp(store,min,end,n-i-1,n,save+(1<<(i)),total+store[last][n-i-1],remain-1)


    for i in range(0,n):
        if(save & (1 << i) == 0 and store[last][n-i-1] != 0): # 0인것이 존재한다
            if(min[0] < 0):
                tsp(store,min,end,n-i-1,n,save+(1<<(i)),total+store[last][n-i-1],remain-1)
            else:
                fb = find_bound(store,n-i-1,n,save+(1<<(i)),total+store[last][n-i-1],min)
                if(fb > 0 and min[0] > fb):
                    tsp(store,min,end,n-i-1,n,save+(1<<(i)),total+store[last][n-i-1],remain-1)
        
    return 0



def find_bound(store,last,n,save,total,min):
    first = time.time()
    bound = total
    now_min = 1000001
    # 앞으로 갈수있는 최소 bound(설령 실제로 그 길이 불가능할지라도)
    for i in range(0,n):
        if(save & (1 << i) == 0 and store[last][n-i-1] != 0): # 1 : 현재까지 간 곳중 마지막에서 갈수있는 최소 bound
            tmp = store[last][n-i-1]
            if(tmp < now_min):
                now_min = tmp
    if(now_min == 1000001):
        second = time.time()
        min[1] = min[1] + second - first
        return -1 # 아무리 따져도 불가능, 길이없다
    else:
        bound = bound + now_min

    now_min = 1000001
    for i in range(0,n):
        if(save & (1 << i) == 0):
            start = n-i-1
            sub = save + (1<<i)
            for j in range(0,n):
                if(j == n-1 and store[start][0]):
                    tmp = store[start][0]
                    if(tmp < now_min):
                        now_min = tmp
                if(sub & (1 << j) == 0 and store[start][n-j-1] != 0):
                    tmp = store[start][n-j-1]
                    if(tmp < now_min):
                        now_min = tmp
            if(now_min == 1000001):
                second = time.time()
                min[1] = min[1] + second - first
                return -1
            else:
                bound = bound + now_min
    second = time.time()
    min[1] = min[1] + second - first
    return bound



# stack = [] # 현재까지 경로 표시위한 스택
# stack_not = [] # 아직 안간 경로들

n = int(input(""))
store = [[0]*n for i in range(n)]
for i in range(0,n):
    store[i] = list(map(int, input().split()))
min = [] # 최소경로 저장값
min.append(-1)
min.append(0)

# stack.append(0)
# for i in range(1,n):
#     stack_not.append(i)

# print(stack)
# print(stack_not)

# print(find_bound(store,n,stack,stack_not))
save = 1 << n-1
end = (1 << n) - 1

now = time.time()
tsp(store,min,(1<<n)-1,0,n,save,0,n-1)
print(min[0])
# print(find_bound(store,0,n,save,0))
after = time.time()
print("time : ",after-now)
print("find time : ",min[1])

# 11
# 0 24 1 23 34 7 90 6 8 6 4
# 4 0 8 7 9 6 8 7 8 6 3
# 2 9 0 0 8 0 7 8 6 8 2
# 0 0 8 0 1 2 4 78 9 4 2
# 9 8 7 9 0 23 12 3 4 5 9
# 9 78 6 8 2 0 0 12 32 4 81247
# 7 9 8 6 8 69 0 90 76 2 1284
# 78 6 9 6 8 5 8 0 23 1 12412
# 6 9 8 9 6 8 12 23 12 0 1 12435
# 6 5 8 7 8 6 5 7 8 0 243141
# 9 7 8 6 5 4 8 9 7 124 0

# 15
# 0 22354 11235 12623 323534 235327 23390 2436 1228 23436 43533 235235 25221 2545 62624
# 112644 0 12648 71264 946 6246 8216 7152 5258 23536 31235 24624 3645 23723 46899 47454
# 35752 93575 0 35737 83257 357237 73275 83275 16326 8235 21235 235263 236235 35363 23653
# 137325 35754 57578 0 35731 23573 4357 732758 9575 4575 22357 262722 12612 19854 97456
# 92375 23578 235737 9237 0 23372 135735 357353 35754 35735 93575 89536 134734 35854 34643
# 93257 23578 3267 82357 3532 0 23225 33312 23532 23574 81247 27357 23735 135326 98776
# 72357 323579 32582 35736 123458 235639 0 23597 35776 235732 235712 236734 34735 2362 37355
# 78377 62357 35739 235736 235738 32735 237358 0 327523 23571 231242 23575 23573 235757 8986
# 63752 53739 237228 237359 357586 97658 134872 437243 34712 0 474781 12435 36366 326345 35633 236222
# 3486 53484 64868 4687 3488 3486 6865 4687 4688 0 243141 236533 375373 37352 258835
# 93468 76868 86684 64684 468645 468644 44668 2369 723565 124368 0 235753 23753 2362 97665
# 63274 123451 9234 76125 48715 48927 356498 123456 78236 54897 13564 0 12525 124624 12452
# 23498 12748 97239 473981 57182 35798 21759 821375 9651 21892 73461 97649 0 25789 422525
# 26784 1962 378562 79345 17623 54716 253461 23876 587126 598721 684758 27645 912736 49817 0 21342
# 12423 125245 61246 2461 12652 126512 4512 3579 821659 83264 24238 94782 94823794 85879 0



