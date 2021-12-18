#include <iostream>

using namespace std;

int t,n;

int stc[100001][2];
int dp[100001][3];
int dfs(int now, int before){
    int maxi = -1;
    int tmp0,tmp1,tmp2;

    if(now == n){
        return 0;
    }
    if(dp[now][before] != -1){
        return dp[now][before];
    }

    tmp0 = dfs(now+1,0);
    if(before == 0){
        tmp1 = dfs(now+1,1) + stc[now][0];
        tmp2 = dfs(now+1,2) + stc[now][1];
        maxi = max(tmp1,tmp2);
        maxi = max(maxi,tmp0);
    }
    else if(before == 1){
        tmp2 = dfs(now+1,2) + stc[now][1];
        maxi = max(tmp0,tmp2);
    }
    else if(before == 2){
        tmp1 = dfs(now+1,1) + stc[now][0];
        maxi = max(tmp0,tmp1);
    }

    dp[now][before] = maxi;
    return maxi;
}

int main(){
    int ans;
    cin >> t;
    for(int i=0;i<t;i++){
        cin >> n;
        for(int j=0;j<n;j++){
            dp[j][0] = -1;
            dp[j][1] = -1;
            dp[j][2] = -1;
            cin >> stc[j][0];
        }
        for(int j=0;j<n;j++){
            cin >> stc[j][1];
        }
        ans = dfs(0,0);
        // cout << dp[0][0] << " " << dp[0][1] << " " << dp[0][2] << endl;
        cout << ans << '\n';
    }
}