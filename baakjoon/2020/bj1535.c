#include <stdio.h>

#define INF -987654321

typedef struct PEOPLE{
    int up,down;
}People;

int n,k;
People pp[21];
int dp[21][101] = {0};

int ddp(int now, int hp);
int max(int x, int y);

int main(){
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&pp[i].down);
    }
    for(i=0;i<n;i++){
        scanf("%d",&pp[i].up);
    }
    printf("%d",ddp(0,100));
}

int ddp(int now, int hp){

    if(hp <= 0){
        return INF;
    }
    if(now == n){
        return 0;
    }
    int tmp1,tmp2;
    if(dp[now][hp] != 0){
        return dp[now][hp];
    }
    tmp1 = ddp(now+1,hp-pp[now].down) + pp[now].up;
    tmp2 = ddp(now+1,hp);
    int mm;
    mm = max(tmp1, tmp2);
    dp[now][hp] = mm;
    return mm;
}

int max(int x, int y){
    return x > y ? x : y;
}