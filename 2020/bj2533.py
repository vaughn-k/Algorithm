# 1h 10m - 해결x
# 너무 어렵다

# while len(alist) > 0 : alist.pop()

n = int(input(""))
friend = [[0]*2 for i in range(n)]

for i in range(0,n-1):
    a,b = input().split(" ")
    friend[i][0] = int(a)
    friend[i][1] = int(b)

store1 = 1 # check = 1일때
store2 = 0 # check = -1일때
check = False
arr = [] # 상위노드 번호 임시 저장용 리스트
next_arr = []
arr.append(1)
# for i in range(0,n):
#     if friend[i][0] in arr:
#         next_arr.append(friend[i][1])
#     else:
#         if(check):
#             store1 = store1 + len(next_arr) 
#         else:
#             store2 = store2 + len(next_arr)
#         check = not check
#         del arr[:] # 기존 리스트 삭제
#         arr = next_arr # 다음 리스트 앞으로 가져오기
#         del next_arr[:]
#         # while len(next_arr) > 0 : arr.append(next_arr.pop()) 
#         next_arr.append(friend[i][1])
# print(min(store1,store2))

right = friend[0][1]
for i in range(0,n-1):
    if friend[i][0] >= right: # 전환x
        check = not check
    if(check):
        store1 = store1 + 1
    else:
        store2 = store2 + 1
        
print(min(store1,store2))





