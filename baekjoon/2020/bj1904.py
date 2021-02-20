import sys
sys.setrecursionlimit(1000000000) 

# 왜 binary 함수로 호출하면 n이 70000이 넘어갈때 sigsegv 에러가 뜨는가...?
# 일단 재귀 또는 반복문을 통해 점화식을 풀어나갈때 숫자가 매우 커지게 되면 연산속도도 그에 상응하여
# 커지므로 모듈러 연산(k로 나눈 나머지를 구하여라)일때 중간중간마다 모듈러값을 계속 구해서 수를 작게유지하면 시간이 단축된다.
# 재귀로 해서 sigsegv 에러가 뜬다면 반복문으로 해결하는것도 방법이다.

# def binary(now,answer):
#     if(now == 1):
#         return 1
#     if(now == 2):
#         return 2
#     if(now == 3):
#         return 3
#     if(answer[now] != -1):
#         return answer[now]
#     tmp1 = 2 * binary(now-2,answer)
#     tmp2 = binary(now-3,answer)
#     total = (tmp1 + tmp2)%15746
#     answer[now] = total
#     return total

# n = int(input(""))
# answer = [-1] * 10000001
# print(binary(n,answer))



n = int(input(""))

answer = [0] * 3
answer[0] = 1
answer[1] = 2
answer[2] = 3
now = n

if(now == 1):
    print(1)
elif(now == 2):
    print(2)
elif(now == 3):
    print(3)
else:
    while(now != 3):
        # new = (answer[1]*2 + answer[0])%15746
        new = (answer[1]*2 + answer[0])
        answer[0] = answer[1]
        answer[1] = answer[2]
        answer[2] = new
        now = now-1
    print(new%15746)