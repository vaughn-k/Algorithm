#include <stdio.h>

int arr[50001] = {};
int train[50001] = {};
int dp[50001][4] = {};

int main(){
    int i,j,n,k;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    scanf("%d",&k);
    m_train(n,k);
    printf("train\n");
    for(i=0;i<n-k+1;i++){
        printf("%d ",train[i]);
    }
    for(i=0;i<50000;i++){
        for(j=0;j<50000;j++){
            train[0] = 10;
        }
    }
    dpp(n,k);
    printf("\ndp\n");
    for(i=0;i<n-k+1;i++){
        printf("%d ",dp[i][0]);
    }
}

int m_train(int n, int k){
    int i,j,total;
    j = 0;
    for(i=0;i<n;i++){
        if(i < k){
            total = total+arr[i];
            if(i == k-1){
                train[j] = total;
                j++;
            }
        }
        else{
            total = total+arr[i]-arr[i-k];
            train[j] = total;
            j++;
        }
    }
    return 0;
}

// dp[i][2] : 이들중 가장 큰 값이 답
// dp[i][1] : ?
// dp[i][0] : i를 포함해서 그 우측중 가장 큰 값

int dpp(int n, int k){ // dp[i][1] : i번째를 무조건 고르고 1개 더고를때 최대값
    int i;
    int e = n-k+1;
    int max = -1;
    for(i=n-k;i>=2*k;i--){
        if(max < train[i]){
            max = train[i];
        }
        dp[i][0] = max;
    }

    for(i=k;i<n-2*k;i++){

    }
}