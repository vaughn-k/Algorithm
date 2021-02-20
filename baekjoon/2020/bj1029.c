#include <stdio.h>
// 비트마스킹을 이용하면 쉽게 풀리는 문제.
// 함수호출이 아닌 일반 배열 재귀로 가능한지도 해보면 좋을것같다

int n;

int pp[16][16];
int dp[15][32768] = {0};
int ddp(int state, int before, int price);
int max(int x, int y);


int main(){
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%1d",&pp[i][j]);
        }
    }    
    printf("%d",ddp(1,0,0)+1);

}

int ddp(int state, int before, int price){
    printf("state : %d\n",state);
    int i,j;
    int tmp1, tmp2;
    int maximum = 0;
    if(state == (1<<n)-1){
        return 0;
    }

    if(dp[before][state] != 0){
        return dp[before][state];
    }
    for(i=1;i<n;i++){
        if((state & (1<<i)) == 0 && pp[before][i] >= price){
            maximum = max(maximum,1+ddp(state+(1<<i),i,pp[before][i]));
        }
    }
    dp[before][state] = maximum;
    return maximum;
}

int max(int x, int y){
    return x > y ? x : y;
}