#include <stdio.h>

// 20m

int dp[1001][10] = {};
int ddp(int n);

int main(){
    int i,j,n;
    scanf("%d",&n);
    ddp(n+1);
    printf("%d",sum(n,0)%10007);
}

int ddp(int n){
    int i,j;
    for(i=1;i<n;i++){
        for(j=0;j<10;j++){
            if(i==1){
                dp[1][j] = 1;
            }
            else if(i==2){
                dp[2][j] = 10-j;
            }
            else{
                dp[i][j] = sum(i-1,j)%10007;
            }
        }
    }
    return 0;
}

int sum(int n, int s){
    int i;
    int total = 0;
    for(i=s;i<10;i++){
        total = total + dp[n][i];
    }
    return total;
}