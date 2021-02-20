#include <stdio.h>
// n by m (0,0)->(n,m) 최대 비용문제

// 특별한 점은 위로는 못가고 아래,양옆만 갈수 있으며 갔던 곳은 갈수 없다.
// 갔던 곳은 못가므로 (a1,a2) 에서 (b1,b2)에 갔을때 (n,m) 까지의 최대값이 
// 그다음에 (a3,a4) (b1,b2)에 갔을때 (n,m) 까지의 최대값이 같지않을수 있다.
// 같은 지점이라도 온 경로가 다르기에 앞으로 갈 경로의 경우의 수가 달라질수도 있기때문이다.
// 다만 이문제에서는 위로는 갈수 없으므로 현재 내가 있는 위치가 위에서 내려온것인지, 왼쪽에서 또는 오르쪽에서 온것인지
// 에 따라 그 경우가 special해지기 때문에 3개의 변수로 해당위치 상태에서 최대값을 저장할수 있다.


#define INF 987654321

int n,m;
int state[1001][1001] = {0}; // 0 : 미방문, 1 : 방문
int map[1001][1001];
int dp[1001][1001][3] = {0};
int nasa(int ni, int nj,int st);
int max(int x, int y);

int main(){
    int i,j;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&map[i][j]);
        }
    }
    printf("%d",nasa(0,0,1)+map[0][0]);
}   

int nasa(int ni, int nj, int st){
    int i,j;
    int ans;
    int tmp1 = INF * (-1);
    int tmp2 = INF * (-1);
    int tmp3 = INF * (-1);
    if(ni == n-1 && nj == m-1){
        return 0;
    }
    if(dp[ni][nj][st] != 0){
        return dp[ni][nj][st];
    }
    state[ni][nj] = 1;
    if(ni != n-1 && state[ni+1][nj] == 0){
        tmp1 = map[ni+1][nj] + nasa(ni+1,nj,1); // 아래
    }
    if(nj != m-1 && state[ni][nj+1] == 0){
        tmp2 = map[ni][nj+1] + nasa(ni,nj+1,2); // 오른쪽
    } 
    if(nj != 0 && state[ni][nj-1] == 0){
        tmp3 = map[ni][nj-1] + nasa(ni,nj-1,3); // 왼쪽
    }
    ans = max(tmp1,max(tmp2,tmp3));
    state[ni][nj] = 0;
    dp[ni][nj][st] = ans;
    return ans;
}

int max(int x, int y){
    return x > y ? x : y;
}