#include <stdio.h>

// 13m 전형적인 쉬운 dp 유형

#define INF 987654321

int arr[1001] = {0};
int dp[1001] = {0};
int n;

int jump(int now);
int min(int x, int y);

int main(){
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int ans;
    ans = jump(0);
    if(ans >= INF){
        printf("%d",-1);
    }
    else{
        printf("%d",jump(0));
    }
}

int jump(int now){
    int i;
    int bound;
    if(now == n-1){
        return 0;
    }
    int minimum = INF;
    if(dp[now] != 0){
        return dp[now];
    }
    bound = min(now+arr[now], n-1);
    for(i=now+1;i<=bound;i++){
        minimum = min(minimum,jump(i)+1);
    }
    dp[now] = minimum;
    return minimum;
}

int min(int x, int y){
    return x < y ? x : y;
}