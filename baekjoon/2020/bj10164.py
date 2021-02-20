# 1h 12m

# DP로 하는게 더 빠른줄알고 DP로 했더니 런타임에러가 난다.
# input n,m에 대해서만 구하는거보다 차라리 모든 15x15의 모든 쌍을 구해놓고
# 거기서 뽑아 쓰는게 더 빨랐다


store = []
store = [[0]*16 for i in range(16)]

a,b,c = input().split(" ")
n = int(a)
m = int(b)
k = int(c)

for i in range(1,16):
    for j in range(1,16):
        if(i == 1 or j == 1):
            store[i][j] = 1
        else:
            store[i][j] = store[i-1][j] + store[i][j-1] 
        # print("[",i,"][]",j,"] : ",store[i][j])

if(k == 0):
    print(store[n][m])
else:
    mid_n = k//m+1
    mid_m = k%m
    if(mid_m == 0):
        mid_n = mid_n-1
        mid_m = m
    if(n == 1 or m == 1):
        print(1)
    else:
        print(store[mid_n][mid_m] * store[n-mid_n+1][m-mid_m+1])


# def road(store,n,m):
#     if(n == 1):
#         return 1
#     if(m == 1):
#         return 1
#     if(store[n-1][m] != 0):
#         down = store[n-1][m]
#     else:
#         down = road(store,n-1,m)
    
#     if(store[n][m-1] != 0):
#         right = store[n][m-1]
#     else:
#         right = road(store,n,m-1)
#     ans = down + right
#     store[n][m] = ans
#     return ans



# print(mid_n," ",mid_m)
# if(k == 0):
#     print(road(store,n,m))
# else:
#     mid_n = k//m+1
#     mid_m = k%m
#     if(n == 1 or m == 1):
#         print(1)
#     else:
#         print(road(store,mid_n,mid_m) * road(store,n-mid_n+1,m-mid_m+1))
    