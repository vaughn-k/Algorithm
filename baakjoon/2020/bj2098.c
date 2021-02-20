#include <stdio.h>
#define INF 987654321;

int cost[17][17];
int n;
int st;
int dp[70000][17];
int minimum = INF;

int dev(int now, int count, int total, int before);
int min(int x, int y);

int main(){
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&cost[i][j]);
        }
    }

    printf("%d",dev((1<<0),1,0,0));

}

int dev(int now, int count, int total, int before){ 
    // now : 현재 도시 방문 상태 비트, count : 방문한 도시 개수, before : 이전에 방문한 위치
    int m = INF;
    int i,j;
    if(count >= n){
        if(cost[before][0] != 0){
            // total = total + cost[before][0];
            // if(minimum > total){
            //     minimum = total;
            // }
            return cost[before][0];
        }
        else{
            return INF;
        }
    }
    if(dp[now][before] != 0){
        // if(dp[now][before] + total < minimum){
        //     minimum = dp[now][before] + total;
        // }
        return dp[now][before];
    }
    // if(total > minimum){
    //     return INF;
    // }
    for(i=0;i<n;i++){
        if(((now & (1<<i)) == 0) && (cost[before][i] != 0)){ // 현재 도시 방문 안한상태 && 해당 경로 존재
            m =  min(m,dev(now +(1<<i),count+1,total+cost[before][i],i)+cost[before][i]);
        }
    }
    dp[now][before] = m;
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
