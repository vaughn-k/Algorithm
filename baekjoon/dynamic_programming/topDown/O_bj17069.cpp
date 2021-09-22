/*/////////////////////////////////////////////////////////////////////////
날짜 : 2021.09.21

소요시간 : 15m

문제명 - 백준 17069 파이프 옮기기 2
   
알고리즘
    - dp(변수3개)
    - dfs

문제개요

    전형적인 dfs dp 이며 약간의 조건만 추가해주면 된다.

    주의할 점은 예제에서 출력값이 43억인 예제가 있는것으로 보아 변수타입을 int보다 크게 잡아야한다.

   
*//////////////////////////////////////////////////////////////////////////


#include <iostream>

using namespace std;

int n;
int map[33][33];
long long dp[33][33][3];

// before(0 = 우측, 1 = 대각선, 2 = 아래)
long long dfs(int ni, int nj, int before){
    long long tot = 0; 

    if(ni == (n-1) && nj == (n-1)){
        return 1;
    }

    if(dp[ni][nj][before] != -1){
        return dp[ni][nj][before];
    }

    // 우측으로 진행
    if((before == 0 || before == 1) && nj < (n-1)){
        if(map[ni][nj+1] != 1){
            tot += dfs(ni,nj+1,0);
        }
    }

    // 대각선으로 진행
    if(nj < (n-1) && ni < (n-1)){
        if(map[ni+1][nj+1] != 1 && map[ni+1][nj] != 1 && map[ni][nj+1] != 1){
            tot += dfs(ni+1,nj+1,1);
        }
    }

    // 아래로 진행
    if((before == 2 || before == 1) && ni < (n-1)){
        if(map[ni+1][nj] != 1){
            tot += dfs(ni+1,nj,2);
        }
    }

    dp[ni][nj][before] = tot;
    return tot;
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> map[i][j];
            for(int k=0;k<3;k++){
                dp[i][j][k] = -1;
            }
        }
    }
    cout << dfs(0,1,0);
}