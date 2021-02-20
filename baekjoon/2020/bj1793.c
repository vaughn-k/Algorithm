#include <stdio.h>
#include <stdlib.h>

int ans[251] = {};

int main(){
    int n;
    while(1){
        scanf("%d",&n);
        printf("%d\n",dp(n));
    }

}

int dp(int now){
    if(now == 1){
        return 1;
    }
    if(now == 2){
        return 3;
    }
    if(ans[now] != 0){
        return ans[now];
    }
    int total;
    total = dp(now-1) + 2*dp(now-2);
    ans[now] = total;
    return total;
}