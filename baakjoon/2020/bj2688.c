#include <stdio.h>

long long dp[65][10] = {0};

int ddp(int n);

int main(){
    int t,i,j,n;
    long long total;
    scanf("%d",&t);

    ddp(64);
    for(i=0;i<t;i++){
        total = 0;
        scanf("%d",&n);
        for(j=0;j<10;j++){
            total = total + dp[n-1][j];
        }
        printf("%lld\n",total);
    }   
}

int ddp(int n){
    int i,j,k;
    for(i=0;i<n+1;i++){
        for(j=0;j<10;j++){
            if(i == 0){
                dp[i][j] = 1;
            }
            else if(i == 1){
                dp[i][j] = 10-j;
            }
            else{
                for(k=j;k<10;k++){
                    dp[i][j] = dp[i][j] + dp[i-1][k];
                }
            }
        }
    }
}