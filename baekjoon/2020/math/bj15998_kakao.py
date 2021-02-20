
def find_limit(remain, change, now):
    return now-remain

def find_max(remain, change, now):
    return now - change - remain

def gcd(m,n):
    while n != 0:
       t = m%n
       (m,n) = (n,t)
    return abs(m)

M_list = []
sub_list = []

n = int(input(""))

store = [[0]*2 for i in range(n)]


# for i in range(0,n):
#     a,b = input("").split()
#     store[i][0] = int(a)
#     store[i][1] = int(b)

########
first_minus = 0
end = 0
for i in range(0,n):
    a,b = input("").split()
    store[i][0] = int(a)
    store[i][1] = int(b)
    if(store[i][0] < 0):
        if(i == 0): # 맨첫거래가 출금거래(잔액이 0원)
            remain = 0
        else:
            remain = store[i-1][1]
        
        if(first_minus == 0): # 첫 출금거래
            now_gcd = find_max(remain,store[i][0],store[i][1])
            now_limit = find_limit(remain,store[i][0],store[i][1])

            first_minus = 1
        else: # 두번째 이상 출금거래 (최소출금금액 확인용)
            new_gcd = find_max(remain,store[i][0],store[i][1])
            new_limit = find_limit(remain,store[i][0],store[i][1])
            # 최대공약수 확인
            now_gcd = gcd(now_gcd,new_gcd)
            # 최소치 확인
            if(new_limit > now_limit):
                now_limit = new_limit
            if(now_gcd <= new_limit):
                print("-1")
                end = 1
                break

if(end == 0):
    i = 2
    final_gcd = now_gcd
    while(final_gcd > 9000000000000000000):
        if(now_gcd%i == 0):
            final_gcd = now_gcd//i
        i = i+1
    print(now_gcd)
        



# for i in range(0,n):
#     if(store[0][0] < 0):
#         limit = find_limit(0,store[0][0],store[0][1])
#         mmax = find_max(0,store[0][0],store[0][1])
#         find_M(limit,mmax,M_list)
#         break
#     if(store[i+1][0] < 0):
#         limit = find_limit(store[i][1],store[i+1][0],store[i+1][1])
#         mmax = find_max(store[i][1],store[i+1][0],store[i+1][1])
#         find_M(limit,mmax,M_list)
#         break


# # for i in range(0,len(M_list)):
# #     print(M_list[i])

# check = 0
# for i in range(0,n):
#     check = 0
#     if(store[i][0] < 0 and i != 0): # 출금 되었을때만 본다
#         limit = find_limit(store[i-1][1],store[i][0],store[i][1])
#         mmax = find_max(store[i-1][1],store[i][0],store[i][1])
#         for j in range(0,len(M_list)):
#             if(M_list[j] > limit and mmax%M_list[j] == 0):
#                 check = 1
#             else:
#                 sub_list.append(M_list[j])
#         fix = len(sub_list)
#         for k in range(0,fix):
#             M_list.remove(sub_list.pop())
#         if(check == 0): # 불가능하다
#             print("-1")

# for i in range(0,len(M_list)):
#     print(min(M_list))

# print(len(M_list))

# def find_M(limit,max,M_list):
#     count = 0
#     for i in range(limit+1,max+1):
#         if(max%i == 0):
#             if(i in M_list):
#                 return 0
#             M_list.append(i)
#             if(max//i > limit):
#                 M_list.append(max//i)
#             if(i == max//i):
#                 return 0
#     return 0

