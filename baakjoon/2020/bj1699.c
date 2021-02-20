#include <stdio.h>
#include <math.h>

#define INF 987654321;


int sqrtarr[400] = {};
int dp[100001] = {};

int sq(int n);

int main(){
    int n,i;
    scanf("%d",&n);
    sq(n);

    printf("%d\n",dp[n]);
    

}

int sq(int n){
    int i,j,k,min;
    j=0;
    for(i=0;i<n+1;i++){
        dp[i] = INF;
        if(i == (j+1)*(j+1)){
            dp[i] = 1;
            j++;
        }
        else{
            for(k=0;k<j;k++){
                if(dp[i] > dp[i-k*k]+1){
                    dp[i] = dp[i-k*k]+1;
                }
            }
        }
    }
    return 0;
}