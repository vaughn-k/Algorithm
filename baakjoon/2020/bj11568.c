#include <stdio.h>

int arr[1001] = {};
int dp[1001] = {};

int main(){
    int i,j,n;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    printf("%d",lis(n));

}

int lis(int n){
    int i,j;
    int max=1;
    for(i=0;i<n;i++){
        dp[i] = 1;
        for(j=0;j<i;j++){
            if(dp[j]+1 > dp[i] && arr[j] < arr[i]){
                dp[i] = dp[j]+1;
                if(max < dp[i]){
                    max = dp[i];
                }
            }
        }
    }
    return max;
}