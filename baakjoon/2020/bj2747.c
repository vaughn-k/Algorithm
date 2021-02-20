#include <stdio.h>

int dp[46];
int fib(int n);
int main(){
    int n,i;
    scanf("%d",&n);
    printf("%d",fib(n));
}

int fib(int n){
    dp[1] = 0;
    dp[2] = 1;
    int i;
    for(i=3;i<n+2;i++){
        dp[i] = dp[i-1]+dp[i-2];
    }
    return dp[n+1];
}