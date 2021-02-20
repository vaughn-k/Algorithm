#include <stdio.h>

int dp[101] = {0};

int main(){
    int n,i,j;
    scanf("%d",&n);
    for(i=1;i<n+1;i++){
        if(i <= 6){
            dp[i] = i;
        }
        else{
            dp[i] = i;
            for(j=1;j<=i-3;j++){
                if(dp[i] < dp[j]*(i-j-1)){
                    dp[i] = dp[j]*(i-j-1);
                }
            }
        }
    }
    printf("%d",dp[n]);
}