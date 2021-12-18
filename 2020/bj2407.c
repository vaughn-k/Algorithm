#include <stdio.h>

long long dp[101][101] = {0};

int main(){
    int n,m,i,j;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        for(j=1;j<=i;j++){
            if(j == 1){
                dp[i][j] = i;
            }
            else if(i == j){
                dp[i][j] = 1;
            }
            else{
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
        }
    }
    printf("%lld",dp[n][m]);
}