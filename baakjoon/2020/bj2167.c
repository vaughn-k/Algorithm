// 32m

#include <stdio.h>

int arr[302][302] = {0};
int dp[302][302] = {0};

int main(){
    int n,m,i,j;
    scanf("%d %d",&n,&m);
    for(i=1;i<n+1;i++){
        for(j=1;j<m+1;j++){
            scanf("%d",&arr[i][j]);
        }
    }

    for(i=0;i<n+1;i++){
        for(j=0;j<m+1;j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
            else if(i == 1){
                dp[i][j] = dp[i][j-1] + arr[i][j];
            }
            else if(j == 1){
                dp[i][j] = dp[i-1][j] + arr[i][j];
            }
            else{
                dp[i][j] = arr[i][j] + dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1];
            }
        }
    }

    int k,x,y,a,b;
    scanf("%d",&k);
    for(i=0;i<k;i++){
        scanf("%d %d %d %d",&x,&y,&a,&b);
        printf("%d\n",dp[a][b] - dp[x-1][b] - dp[a][y-1] + dp[x-1][y-1]);
    }
}