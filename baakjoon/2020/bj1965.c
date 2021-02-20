#include <stdio.h>

int box[1001] = {0};
int dp[1001] = {0};
int box_dp(int n);

int main(){
    int i,n;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&box[i]);
    }
    printf("%d",box_dp(n));
}

int box_dp(int n){
    int i,j,max;
    max = 1;
    for(i=0;i<n;i++){
        dp[i] = 1;
        for(j=0;j<i;j++){
            if(dp[i] < dp[j]+1 && box[j] < box[i]){
                dp[i] = dp[j]+1;
                if(max < dp[i]){
                    max = dp[i];
                }
            }
        }
    }
    return max;
}