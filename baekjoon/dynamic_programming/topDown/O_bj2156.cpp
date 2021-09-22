/*/////////////////////////////////////////////////////////////////////////
날짜 : 2021.07.17

소요시간 : 15m

문제명 - 백준 2156 - 포도주 시식
   
알고리즘
    - dp

문제개요
    

*//////////////////////////////////////////////////////////////////////////


#include <iostream>

using namespace std;

int n;
int grape[10001];
int dp[10001][3];

int dfs(int now, bool eat, int seq){
    if(now == n){
        return 0;
    }
    if(dp[now][seq] != -1){
        return dp[now][seq];
    }

    int case1,case2,ans;
    if(seq == 2){
        case1 = 0;
    }
    else{
        case1 = dfs(now+1,true,seq+1);
    }
    case2 = dfs(now+1,false,0);
    ans = max(case1,case2);
    if(eat){
        ans = ans + grape[now];
    }
    dp[now][seq] = ans;
    return ans;
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> grape[i];
        for(int j=0;j<3;j++){
            dp[i][j] = -1;
        }
    }
    int answer;
    answer = max(dfs(0,true,1),dfs(0,false,0));
    cout << answer;
}