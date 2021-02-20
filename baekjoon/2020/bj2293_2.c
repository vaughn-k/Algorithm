#include <stdio.h>


int coin[101];
int tot = 0;
int cdp(int now, int total);
int dp[101][10001] = {0};

int n,k;
int main(){
    int i,j;

    scanf("%d %d",&n, &k);
    for(i=0;i<n;i++){
        scanf("%d",&coin[i]);
    }   
    cdp(0,0);
    printf("%d",tot);
}

int cdp(int now, int total){
    int t = 0;
    if(total == k){
        tot++;
        return 1;
    }

    if(total > k || now == n){
        return 0;
    }
    int i,j;
    int count = 0;
    // if(dp[now][total] != 0){
    //     return dp[now][total];
    // }
    while(total+coin[now]*count  <= k){
        t = t + cdp(now+1,total+coin[now]*count);
        count++;
    }
    dp[now][total] = t;
    return t;
}

