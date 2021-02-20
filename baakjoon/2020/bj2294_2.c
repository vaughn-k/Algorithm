#include <stdio.h>

// 전체를 가능한 두구간으로 나누어 쪼개서 생각하는 방식으로 해결

int coin[100001] = {};
int dp[10001] = {};

int coin_dp(int n, int now);

int main(){
    int n,k,i;
    int tmp;
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++){
        scanf("%d",&tmp);
        coin[tmp] = 1;
    }
    int ans;
    ans = coin_dp(n,k);
    printf("%d",ans);
}


int coin_dp(int n, int now){
    int i;
    int tmp1, tmp2;
    int minimum = -1;
    int first = 1;
    if(dp[now] != 0){
        return dp[now];
    }
    if(coin[now] == 1){
        return 1;
    }
    if(now == 1){
        return -1;
    }
    for(i=1;i<=now/2;i++){
        tmp1 = coin_dp(n,i);
        tmp2 = coin_dp(n,now-i);
        if(tmp1 != -1 && tmp2 != -1){
            if(first){
                minimum = tmp1+tmp2;
                first = 0;
            }
            else{
                if(minimum > tmp1+tmp2){
                    minimum = tmp1+tmp2;
                }
            }

        }
    }
    dp[now] = minimum;
    return minimum;
}