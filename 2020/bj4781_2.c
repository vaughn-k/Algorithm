#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 한달만에 해결한 문제이다. 배낭문제인데 각각의 상품에 개수제한이 없는 unbounded knapsack이다.
// 1. 일단 문제에서 실수가 들어오는데 바로 int로 타입변환을 해버리면 오류가 날수도 있어서 0.5를 더해준후 형변환을 해야했다.
// 2. 0/1 knapsack이랑 동일한데 다만 현재물건을 담고 now를 유지시키는 재귀가 하나 추가되었다.
// 3. 여기까지만 하면 시간초과기 때문에 최대 maximum값을 전역변수로 두고 아무리 최대로 채워도 불가능하면 바로 INF를 리턴하도록 설계했다.
// 4. 근데 이 과정에서 maximum값을 각 테스트마다 초기화해주지 않아서 한시간을 헤맸다;


#define INF -987654321

typedef struct CANDY{
    int c,p; // c : 사탕의 칼로리, p : 가격
}Candy;

int n,mp;
Candy cc[5001];
int dp[5001][10001] = {0};
int maximum = 0;

int ddp(int now, int price, int cal);
int max(int x, int y, int z);

int cmp(const void* a, const void* b){
    Candy* ptrA = (Candy*)a;
    Candy* ptrB = (Candy*)b;

    if (ptrA->c*ptrB->p > ptrB->c*ptrA->p) return -1;
    else if (ptrA->c*ptrB->p == ptrB->c*ptrA->p) return 0;
    else return 1;

}

int main(){
    int i,j;
    float tmp;
    int total = 0;
    n=1;
    mp=1;
    while(n != 0 && mp != 0){
        scanf("%d %f",&n,&tmp);
        mp = (int)(tmp*100+0.5);
        if(n != 0 && mp != 0){
            for(i=0;i<n;i++){
                scanf("%d %f",&cc[i].c,&tmp);
                cc[i].p = (int)(tmp*100 + 0.5);
            }
            qsort(cc,n,sizeof(Candy),cmp);
            memset(dp,0,sizeof(dp));
            maximum = 0;
            printf("%d\n",ddp(0,0,0));
        }
    }
}

int ddp(int now, int price, int cal){

    if(price > mp){
        return INF;
    }
    if(now == n){
        if(cal > maximum){
            maximum = cal;
        }
        return 0;
    }
    int tmp1,tmp2,tmp3;
    if(dp[now][price] != 0){
        return dp[now][price];
    }
    if(cal + ((cc[now].c)/(cc[now].p)+1) * (mp-price) <= maximum){
        return INF;
    }
    tmp1 = ddp(now,price+cc[now].p,cal+cc[now].c) + cc[now].c;
    tmp2 = ddp(now+1,price+cc[now].p,cal+cc[now].c) + cc[now].c;
    tmp3 = ddp(now+1,price,cal);
    int mm;
    mm = max(tmp1, tmp2, tmp3);
    dp[now][price] = mm;
    return mm;
}

int max(int x, int y, int z){
    int m;
    m = x > y ? x : y;
    return m > z ? m : z;
}