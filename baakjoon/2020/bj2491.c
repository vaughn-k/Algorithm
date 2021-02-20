#include <stdio.h>

int arr[100001] = {};
int rev[100001] = {};
int dp[100001] = {};
int dp2[100001] = {};

int lis(int n);
int lower_bound(int target, int len);
int lis_rev(int n);
int lower_bound_rev(int target, int len);

int main(){
    int i,j,n;
    scanf("%d",&n);

    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
        rev[n-1-i] = arr[i];
    }

    int ans,ans2;
    ans = lis(n);
    ans2 = lis_rev(n);
    if(ans > ans2){
        printf("%d",ans);
    }
    else{
        printf("%d",ans2);
    }
}

int lis(int n){
    int len,i;
    len = 1;
    dp[0] = arr[0];
    for(i=1;i<n;i++){
        len = len + lower_bound(arr[i],len);
    }
    return len;
}

int lower_bound(int target, int len){
    int s,e,m;
    s = 0;
    e = len-1;
    if(dp[e] <= target){
        dp[e+1] = target;
        return 1;
    }
    while(1){
        if(e-s <= 1){
            if(dp[s] < target){
                dp[e] = target;
            }
            else{
                dp[s] = target;
            }
            return 0;
        }
        m = (s+e)/2;
        if(dp[m] < target){
            s = m;
        }
        else{
            e = m;
        }
    }
}

int lis_rev(int n){
    int len,i;
    len = 1;
    dp2[0] = rev[0];
    for(i=1;i<n;i++){
        len = len + lower_bound(rev[i],len);
    }
    return len;
}

int lower_bound_rev(int target, int len){
    int s,e,m;
    s = 0;
    e = len-1;
    if(dp2[e] <= target){
        dp2[e+1] = target;
        return 1;
    }
    while(1){
        if(e-s <= 1){
            if(dp2[s] < target){
                dp2[e] = target;
            }
            else{
                dp2[s] = target;
            }
            return 0;
        }
        m = (s+e)/2;
        if(dp2[m] < target){
            s = m;
        }
        else{
            e = m;
        }
    }
}