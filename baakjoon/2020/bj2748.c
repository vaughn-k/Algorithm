#include <stdio.h>

long long dp[91] = {0};

int main(){
    int n,i;
    scanf("%d",&n);

    dp[0] = 0;
    dp[1] = 1;
    for(i=2;i<n+1;i++){
        dp[i] = dp[i-1]+dp[i-2];
    }
    printf("%lld",dp[n]);
}