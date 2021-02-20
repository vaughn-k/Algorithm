#include <stdio.h>

int arr[2001];
int dp[2001][2001] = {0};
int ans(int n);
int main(){
    int n,i,j,q,q1,q2;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    ans(n);
    scanf("%d",&q);
    for(i=0;i<q;i++){
        scanf("%d %d",&q1,&q2);
    }
}

int ans(int n){
    int i,j,k,s,e;
    for(i=0;i<n;i++){
        dp[i][i] = 1;
        s = i-1;
        e = i+1;
        while((s>=0) && (e<=n-1) && (arr[s] == arr[e])){
            dp[s][e] = 1;
            s--;
            e++;
        }
    }
    for(i=0;i<n-1;i++){
        if(arr[i]==arr[i+1]){
            dp[i][i+1] = 1;
            s = i-1;
            e = i+2;
            while((s>=0) && (e<=n-1) && (arr[s] == arr[e])){
                dp[s][e] = 1;
                s--;
                e++;
            }
        }
    }
}
