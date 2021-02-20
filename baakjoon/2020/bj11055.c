#include <stdio.h>

int arr[1001] = {0};
int dp[1001] = {0};

int lis(int n);

int main(){
    int i,n;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("%d",lis(n));
}

int lis(int n){
    int i,j;
    int max = -1;
    for(i=0;i<n;i++){
        dp[i] = arr[i];
        for(j=0;j<i;j++){
            if(dp[i] <dp[j]+arr[i] && arr[j] < arr[i]){
                dp[i] = dp[j]+arr[i];
            }
        }
    }
    for(i=0;i<n;i++){
        if(max < dp[i]){
            max = dp[i];
        }
    }
    return max;
}