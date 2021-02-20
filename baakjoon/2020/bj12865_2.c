#include <stdio.h>

#define INF 987654321;

typedef struct KNAPSACK{
    int w,v;
}Knapsack;

Knapsack ks[101];

int ddp(int now, int weight);
int maximum(int x, int y);

int dp[101][100001] = {0};
int n,k;

int main(){
    int i;
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++){
        scanf("%d %d",&ks[i].w,&ks[i].v);
    }
    printf("%d",ddp(0,0));

}

int ddp(int now, int weight){
    int tmp1,tmp2,ans;
    if(weight > k){
        return (-1) * INF;
    }
    if(now == n){
        return 0;
    }
    if(dp[now][weight] != 0){
        return dp[now][weight];
    }
    tmp1 = ks[now].v + ddp(now+1,weight+ks[now].w);
    tmp2 = ddp(now+1,weight);

    ans = maximum(tmp1, tmp2);
    dp[now][weight] = ans;
    return ans;
}

int maximum(int x, int y){
    return x > y ? x : y;
}