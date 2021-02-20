#include <stdio.h>
#include <stdlib.h>

int scv[3] = {0};
int dp[61][61][61] = {0};
int mut(int scv1, int scv2, int scv3);


int main(){
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&scv[i]);
    }

    printf("%d",mut(scv[0],scv[1],scv[2]));
}

int mut(int scv1, int scv2, int scv3){
    if(scv1 <= 0 && scv2 <= 0 && scv3 <= 0){
        return 0;
    }
    if(scv1 < 0){
        scv1 = 0;
    }
    if(scv2 < 0){
        scv2 = 0;
    }
    if(scv3 < 0){
        scv3 = 0;
    }
    if(dp[scv1][scv2][scv3] != 0){
        return dp[scv1][scv2][scv3];
    }
    int tmp[6] = {};
    tmp[0] = 1 + mut(scv1-9,scv2-3,scv3-1);
    tmp[1] = 1 + mut(scv1-9,scv2-1,scv3-3);
    tmp[2] = 1 + mut(scv1-3,scv2-9,scv3-1);
    tmp[3] = 1 + mut(scv1-3,scv2-1,scv3-9);
    tmp[4] = 1 + mut(scv1-1,scv2-9,scv3-3);
    tmp[5] = 1 + mut(scv1-1,scv2-3,scv3-9);
    int i,min;
    min = 987654321;
    for(i=0;i<6;i++){
        if(min > tmp[i]){
            min = tmp[i];
        }
    }
    dp[scv1][scv2][scv3] = min;
    return min;
}