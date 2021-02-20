#include <stdio.h>

int arr[100001] = {0};
int dp[100001][51] = {0};
int ddp(int n, int k);

int main(){
    int n,k,i,j;
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    ddp(n,k);
    // for(i=1;i<=k;i++){
    //     for(j=0;j<n;j++){
    //         printf("%d ",dp[j][i]);
    //     }
    //     printf("\n");
    // }

    int max = 1;
    for(i=0;i<n;i++){
        if(dp[i][k] > max){
            max = dp[i][k];
        }
    }
    printf("%d",max);

}

int ddp(int n, int k){
    int i,j,t;
    for(i=0;i<n;i++){
        for(j=1;j<=k;j++){
            if(j == 1){
                dp[i][j] = 1;
            }
            else if(i >= j-1){
                for(t=0;t<i;t++){
                    if(arr[t] < arr[i]){
                        dp[i][j] = dp[t][j-1] + dp[i][j];
                    }
                }
            }
        }
    }
}