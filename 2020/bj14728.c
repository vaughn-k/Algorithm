#include <stdio.h>
// 일반적인 knapsack문제
#define INF -987654321

typedef struct EXAM{
    int t,s; // t : 투자해야하는 시간, s : 배점
}Exam;

int n,mt;
Exam ex[101];
int dp[101][10001] = {0};

int ddp(int now, int hp);
int max(int x, int y);

int main(){
    int i,j;
    scanf("%d %d",&n,&mt);
    for(i=0;i<n;i++){
        scanf("%d %d",&ex[i].t,&ex[i].s);
    }
    printf("%d",ddp(0,0));
}

int ddp(int now, int time){

    if(time > mt){
        return INF;
    }
    if(now == n){
        return 0;
    }
    int tmp1,tmp2;
    if(dp[now][time] != 0){
        return dp[now][time];
    }
    tmp1 = ddp(now+1,time+ex[now].t) + ex[now].s;
    tmp2 = ddp(now+1,time);
    int mm;
    mm = max(tmp1, tmp2);
    dp[now][time] = mm;
    return mm;
}

int max(int x, int y){
    return x > y ? x : y;
}