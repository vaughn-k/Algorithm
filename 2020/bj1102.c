// 미친문제였다;
// 먼저 16개의 발전소들의 상태를 저장하기 위해서는 bitmask를 사용해야하고
// 이미 방문해본 발전소 상태(bitmask 현황)을 dp에 저장해서 중복 방문을 막고
// 현재까지 최소치를 저장해서 진입하다가 최소치보다 커지면 바로 재귀종료.

#include <stdio.h>
#include <string.h>
#define INF 987654321;

int cost[17][17];
int n,k;
char state[20];
int st;
int dp[70000];
int minimum = INF;

int dev(int now, int count, int total);
int min(int x, int y);

// 전부 N이 들어올때 p=0 -> 0
// 전부 N이 들어올때 p != 0 -> -1
// 처음에 Y개수보다 P가 작거나 같을때 -> 0

int main(){
    int i,j,count;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&cost[i][j]);
        }
    }
    scanf("%s",&state);
    scanf("%d",&k);
    i = strlen(state);
    j = 0;
    // printf("i : %d\n",i);
    st = 0;
    count = 0;
    while(i >= 0){
        if(state[i] == 'Y'){
            st = st + (1<<(j-1));
            count++;
        }
        i--;
        j++;
    }
    if(st == 0){
        if(k == 0){
            printf("0");
        }
        else{
            printf("-1");
        }
    }
    else{
        printf("%d",dev(st,count,0));
    }
    // printf("st : %d\n",st);


}

int dev(int now, int count, int total){ // now : 현재발전소 상태 비트, count : 켜져있는 개수
    // input : dev(st,count);
    int m = INF;
    int i,j;
    if(count >= k){
        if(minimum > total){
            minimum = total;
        }
        return 0;
    }
    if(dp[now] != 0){
        // printf("used");
        return dp[now];
    }
    if(total >= minimum){
        return INF;
    }
    for(i=0;i<n;i++){
        if((now & (1<<i)) > 0){ // 현재발전소 켜져있음
            for(j=0;j<n;j++){
                if((now & (1<<j)) == 0){ // 현재발전소 꺼져있음
                    m =  min(m,dev(now +(1<<j),count+1,total+cost[n-i-1][n-j-1])+cost[n-i-1][n-j-1]);
                }
            }
        }
    }
    dp[now] = m;
    return m;
}

int min(int x, int y){
    if(x < y){
        return x;
    }
    else{
        return y;
    }
}
