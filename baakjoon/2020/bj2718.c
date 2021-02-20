#include <stdio.h>

dp[26] = {0};
ddp[26] = {0};
ddp2[26] = {0};

int main(){
    int n,i;
    ddp[0] = 0;
    ddp2[0] = 1;
    ddp2[1] = 1;
    scanf("%d",&n);
    for(i=1;i<26;i++){
        if(i == 1) dp[1] = 1;
        else if(i == 2) dp[2] = 5;
        else if(i == 3) dp[3] = 11;
        else{
            dp[i] = 2*ddp[i-3] + dp[i-2]*4 + dp[i-1] + ddp2[i-4]+2;
        }
        ddp[i] = ddp[i-1] + dp[i];
        if(i > 1){
            ddp2[i] = ddp2[i-2] + dp[i];
        }
    }
    int tmp;
    for(i=0;i<n;i++){
        scanf("%d",&tmp);
        printf("%d\n",dp[tmp]);
    }
}