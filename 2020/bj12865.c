#include <stdio.h>

typedef struct KNAPSACK{
    int w,v;
}Knapsack;

Knapsack ks[101];
// Knapsack dp[101];

int dp[100001][101] = {0};

int main(){
    int n,k,i,j;
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++){
        scanf("%d %d",&ks[i].w,&ks[i].v);
    }
    int max = -1;
    for(i=0;i<n;i++){
        for(j=0;j<=k;j++){
            if(i == 0){
                if(ks[i].w <= j){
                    dp[i][j] = ks[i].v;
                }
            }
            else{
                if(ks[i].w <= j){
                    dp[i][j] = dp[i-1][k-j] + ks[i].v;
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
    }

    for(i=0;i<n;i++){
        for(j=0;j<=k;j++){
            printf("%d ",dp[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<k+1;i++){
        if(max < dp[n-1][i]){
            max = dp[n-1][i];
        }
    }
    printf("%d",max);


}