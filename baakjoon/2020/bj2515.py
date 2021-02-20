import sys
sys.setrecursionlimit(10000000)
import time


def double_sort(picture, start, end):
    if end-start<1: # 원소가 한 개면
        return # 종료

    low = start # 왼쪽 탐색 막대
    high = end # 오른쪽 탐색 막대
    pivot = picture[end][0] # 마지막 원소를 기준으로

    while low<high: # 왼쪽 막대가 오른쪽 막대보다 작은 동안 실행
        while low<high and picture[low][0]<=pivot:
            low+=1
        while low<high and picture[high][0]>=pivot:
            high-=1
        if low<high: # 왼쪽 막대가 오른쪽 막대보다 작으면
            picture[low][0], picture[high][0] = picture[high][0], picture[low][0] # 위치 교환
            picture[low][1], picture[high][1] = picture[high][1], picture[low][1] # 위치 교환
        else: # 왼쪽 막대가 오른쪽으로 넘어가면
            picture[end][0], picture[low][0] = picture[low][0], picture[end][0] # 기준과 a[low] 교환하고
            picture[end][1], picture[low][1] = picture[low][1], picture[end][1] # 기준과 a[low] 교환하고
            break # 반복문 탈출

    double_sort(picture, start, low-1) # 새로운 기준을 중심으로 왼쪽 리스트 부분 정렬
    double_sort(picture, low+1, end) # 새로운 기준을 중심으로 오른쪽 리스트 부분 정렬

def dp(picture,maximum,now,n,s,now_max,before,last_p):
    # before : 바로 직전 그림의 높이
    if(now == -1): # 그림의 맨 뒤까지 갔을때
        if(before >= s):
            now_max = now_max + last_p
        if(now_max > maximum[0]):
            maximum[0] = now_max
        return 0

    if()


    if(before-picture[now][0] >= s):
        dp(picture,maximum,now-1,n,s,now_max+last_p,picture[now][0],picture[now][1]) # 이번그림 선택
    # else:
    #     dp(picture,maximum,now-1,n,s,now_max,picture[now][0],picture[now][1]) # 이번그림 선택
    dp(picture,maximum,now-1,n,s,now_max,before,last_p) # 이번그림 패스

    # if(): # 더이상 S이상의 가치가 되는 그림이 없을때
    


n,s = input().split(" ")
n = int(n)
s = int(s)
picture = [[0] * (2) for i in range(n)]
maximum = []
maximum.append(0)
for i in range(n):
    picture[i] = list(map(int, sys.stdin.readline().split()))

now = time.time()
double_sort(picture,0,len(picture)-1)
dp(picture,maximum,n-2,n,s,0,picture[n-1][0],picture[n-1][1])
print(maximum[0])
after = time.time()
print(after-now)

# 33 4
# 15 80
# 8 230
# 10 100
# 17 200
# 20 75
# 26 80
# 40 199
# 34 200
# 79 1020
# 16 90
# 25 49
# 24 10
# 11 39
# 73 192
# 101 232
# 103 222
# 242 394
# 124 100
# 9 88
# 1121 23
# 322 14
# 38 14
# 45 389
# 56 890
# 67 483
# 99 341
# 530 134
# 1384 134
# 1341 123
# 3535 132
# 1436134 314
# 1343151 435

# 2578287 345
# 1115331 432
# 31413 647
# 31541 354 
# 87135 847 

# 16384 731 
# 95713 847
# 87628 153
# 26814 351
# 35 31

