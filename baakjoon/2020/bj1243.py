import sys
sys.setrecursionlimit(10000000) 

n = int(input(""))
m = int(input(""))

def pal(arr,now,n,m,exceed,acc): 
    # exceed 이번에 절반뒤에서 넘은 알파벳 개수
    # acc 누적 확인한 알파벳 개수
    if(len(now) > m):
        return 0
    if(len(now) >= m//2+1):
        if(not check(now,exceed,acc)):
            return 0
        acc = acc + exceed
    if(len(now) == m):
        if(now[0] != now[m-1]):
            return 0
        else:
            return 1
    total = 0
    for i in range(0,n):
        if(len(now+arr[i]) >= m//2 and m%2 == 1): # 길이가 절반을 넘었고 홀수
            if(acc == 0): # 처음으로 넘음
                exceed = len(now+arr[i]) - m//2 - 1
                total = total + pal(arr,now+arr[i],n,m,exceed,acc)
            else: # 이미 넘었었다.
                exceed = len(now+arr[i]) - m//2 - acc
                total = total + pal(arr,now+arr[i],n,m,exceed,acc)

        elif(len(now+arr[i]) >= (m//2)+1 and m%2 == 0): # 길이가 절반을 넘었고 짝수
            if(acc == 0): # 처음으로 넘음
                exceed = len(now+arr[i]) - m//2
                total = total + pal(arr,now+arr[i],n,m,exceed,acc)
            else: # 이미 넘었었다.
                exceed = len(now+arr[i]) - m//2 - acc
                total = total + pal(arr,now+arr[i],n,m,exceed,acc)
        else:
            total = total + pal(arr,now+arr[i],n,m,exceed,acc)
    return total

def check(st,exceed,acc):
    # exceed 이번에 절반뒤에서 넘은 알파벳 개수
    # acc 누적 확인한 알파벳 개수
    # print(st,exceed,acc)
    if(m//2 == 0):
        for i in range(m//2-exceed-acc,m//2-exceed-acc+exceed):
            # print(i,m-i-1)
            if(st[i] != st[m-i-1]):
                # print("f")
                # print("")
                return False
    else:
        for i in range(m//2-exceed-acc+1,m//2-exceed-acc+exceed+1):
            # print(i,m-i-1)
            if(st[i] != st[m-i-1]):
                # print("f")
                # print("")
                return False
    # print("t")
    # print("")
    return True
    

arr = [0] * n
for i in range(0,n):
    arr[i] = input("")

print(pal(arr,"",n,m,0,0))

# 5
# 30
# A
# AA
# BB
# BC
# CB