
# 40m
# brute-force를 이용 : why? DP를 쓰기에는 같은상황
# (5,6을 선택하고 7을 선택할때, 4,5를 선택하고 7을 선택할때
# 둘다 7을 선택하지만 전체 합이 target보다 작아야하고 최대한 비슷해야하기에 7을 선택하는 기준이 달라져
# 앞뒤가 독립적이지 못하다. 따라서 모든 경우를 다 해보는수밖에 없다.




def blackjack(card,n,start,total,target,maxn,count):
    if(count == 3): # 마지막 카드 확인
        if(total > maxn[0]): # 현재까지 합이 max보다 크면 동기화
            maxn[0] = total
        return 0
    if(start == n-1):
        return 0
    else:
        if(total+card[start+1] <= target):
            blackjack(card,n,start+1,total+card[start+1],target,maxn,count+1) # 해당카드 선택
        blackjack(card,n,start+1,total,target,maxn,count) # 해당카드 선택x



a,b = input("").split()
n = int(a)
m = int(b)
card = list(map(int, input().split()))
maxn = []
maxn.append(-1)

blackjack(card,n,-1,0,m,maxn,0)
print(maxn[0])
# card : 카드들 숫자
# n : 확인해야할 카드 수
# start : 몇번째부터 확인하면되는지
# total : 현재까지 합계
# target : 최대목표치
# maxn : 현재까지 최고점d


