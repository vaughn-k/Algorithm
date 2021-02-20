#include <stdio.h>

int arr[1001] = {0};
int rev[1001] = {0};
int dp[1001] = {0};
int re_dp[1001] = {0};
int dp_max[1001] = {0};
int re_dp_max[1001] = {0};
int max_n[1001] = {0};
int re_max_n[1001] = {0};

int lis(int n);

int main(){
    int i,n;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
        rev[n-i-1] = arr[i];
    }
    printf("%d",lis(n));

}

int lis(int n){
    int i,j;
    int now_max = 1;
    int rm = arr[0];
    for(i=0;i<n;i++){
        dp[i] = 1;
        for(j=0;j<i;j++){
            if(dp[i] < dp[j]+1 && arr[j] < arr[i]){
                dp[i] = dp[j]+1;
                if(now_max < dp[i]){
                    now_max = dp[i];
                    rm = arr[i];
                }
            }
        }
        dp_max[i] = now_max;
        max_n[i] = rm;
    }
    now_max = 1;
    rm = rev[0];
    for(i=0;i<n;i++){
        re_dp[i] = 1;
        for(j=0;j<i;j++){
            if(re_dp[i] < re_dp[j]+1 && rev[j] < rev[i]){
                re_dp[i] = re_dp[j]+1;
                if(now_max < re_dp[i]){
                    now_max = re_dp[i];
                    rm = rev[i];
                }
            }
        }
        re_dp_max[i] = now_max;
        re_max_n[i] = rm;

    }
    int max = 1;
    int tmp;
    for(i=0;i<n-1;i++){
        tmp = dp_max[i]+re_dp_max[n-2-i];
        if(max_n[i] == re_max_n[n-2-i]){
            tmp = tmp-1;
        }
        if(max < tmp){
            max = tmp;
        }
    }
    if(max < dp_max[n-1]){
        max = dp_max[n-1];
    }
    if(max < re_dp_max[n-1]){
        max = re_dp_max[n-1];
    }
    return max;
}