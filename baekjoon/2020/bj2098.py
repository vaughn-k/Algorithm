import time

def tsp(store,min,n,stack,stack_not,total):
    # print("check")
    st_len = len(stack)
    stn_len = len(stack_not)
    if(st_len == n-1): # 마지막 조건
        start = stack[st_len-1]
        target = stack_not[0]
        tmp = store[start][target]
        
        start = target
        target = 0
        tmp2 = store[start][target]
        if(tmp == 0 or tmp2 == 0): # 마지막 지점으로 갈때 or 원점으로 갈때 경로가 없다
            return -1
        else:
            total = total + tmp + tmp2
            if(min[0] < 0 or min[0] > total):
                min[0] = total
            return 1

    now_min = -1
    for i in range(0,stn_len):
        target = stack_not.pop(0)
        stack.append(target)
        length = store[stack[st_len-1]][target] # 현재 고른경로 길이
        if(min[0] < 0): # 처음가는거니 끝까지 가봐야함
            tmp = tsp(store,min,n,stack,stack_not,total+length)
        else: # min값을 아니까 돌지말지 확인해야함
            if(length != 0 and find_bound(store,n,stack,stack_not) < min[0]):
                tmp = tsp(store,min,n,stack,stack_not,total+length)

        # if(length != 0):
        #     tmp = tsp(store,min,n,stack,stack_not,total+length)
        
        stack.pop(st_len)
        stack_not.append(target)
    return now_min



def find_bound(store,n,stack,stack_not):
    now = len(stack)
    bound = 0
    i = 0
    now_min = 1000001
    
    while(now > 1): # 지금까지 확정으로 온 길 합
        bound = bound + store[stack[i]][stack[i+1]]
        now = now -1
        
    # 앞으로 갈수있는 최소 bound(설령 실제로 그 길이 불가능할지라도)
    for i in range(0,len(stack_not)): # 1 : 현재까지 간 곳중 마지막에서 갈수있는 최소 bound
        tmp = store[stack[len(stack)-1]][stack_not[i]]
        if(tmp < now_min and tmp != 0):
            now_min = tmp
    if(now_min == 1000001):
        return -1 # 아무리 따져도 불가능, 길이없다
    else:
        bound = bound + now_min

    length_not = len(stack_not)
    for i in range(0,length_not): # 2 : 앞으로 안간곳중 최대로 갈수있는 최소 bound
        now_min = 1000001
        start = stack_not.pop(0)
        for j in range(0,length_not):
            if(j == (length_not-1)):
                tmp = store[start][0]
                if(tmp < now_min and tmp != 0):
                    now_min = tmp
            else:
                target = stack_not[j]
                tmp = store[start][target]
                if(tmp < now_min and tmp != 0):
                    now_min = tmp
        if(now_min == 1000001):
            return -1
        else:
            bound = bound + now_min
        stack_not.append(start)
        

    return bound



stack = [] # 현재까지 경로 표시위한 스택
stack_not = [] # 아직 안간 경로들

n = int(input(""))

store = [[0]*n for i in range(n)]
for i in range(0,n):
    store[i] = list(map(int, input().split()))
min = [] # 최소경로 저장값
min.append(-1)

stack.append(0)
for i in range(1,n):
    stack_not.append(i)

# print(stack)
# print(stack_not)

# print(find_bound(store,n,stack,stack_not))
now = time.time()
tsp(store,min,n,stack,stack_not,0)
print(min[0])
after = time.time()


print("time : ",after-now)