# 3h


def find_bound(n,store,ans):
    total = 0
    for j in range(0,10):
        for i in range(0,10):
            total = total + store[i][j]
            if(total > n):
                ans[0] = i
                ans[1] = j
                ans[2] = total # n이속한 구역의 다음 최솟값
                ans[3] = total-store[i][j] # n이속한 구역의 최솟값
                return 0
            else:
                now_i = i
                now_j = j
                
def find_final(bound_left,bound_right,store,a,b,n,ans):
    if(b != 0):
        first = 0
        for i in range(0,a):
            if(store[i][b-1] > 0):
                if(first == 0): # 첫 숫자
                    bound_right = bound_left + store[i][b-1]-1
                    if(n <= bound_right):
                        # print(i,"일때 bound : ",bound_left,bound_right)
                        ans = ans*10 + i
                        find_final(bound_left,bound_right,store,i,b-1,n,ans)
                        return 0
                    first = 1
                else:
                    bound_left = bound_right+1
                    bound_right = bound_left + store[i][b-1]-1
                    if(n <= bound_right):
                        # print(i,"일때 bound : ",bound_left,bound_right)
                        ans = ans*10 + i
                        find_final(bound_left,bound_right,store,i,b-1,n,ans)
                        return 0

    else:
        print(ans)
        return 0


store = [[0]*10 for i in range(10)]
ans = [1] * 4

for i in range(0,10):
    for j in range(0,i+1):
        if(i == 0 or j == 0):
            store[i][j] = 1
        else:
            store[i][j] = store[i-1][j-1] + store[i-1][j]

#max = 1023

n = int(input(""))
find_bound(n,store,ans)
a = ans[0]
b = ans[1] # 현재까지는 첫자리가 a이고 후에 b만큼 나올수 있다는것을 의미
bound_left = ans[3]
bound_right = ans[2]-1

if(n >= 1023):
    print("-1")
else:
    find_final(bound_left,bound_right,store,a,b,n,a)


