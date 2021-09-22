#include <iostream>

using namespace std;

int n,k;
int dp[1001][1001][2];
int visit[1002][1002];
int mod = 1000000003;
int result[2];

void dfs(int level, int color) {
    if (level == k) {
        if (color == n - 1) {
            result[0] = 0;
            result[1] = 1;
            return;
        }else{
            result[0] = 1;
            result[1] = 0;
            return;
        }
    }
    if(visit[level][color] == 1){
        result[0] = dp[level][color][0];
        result[1] = dp[level][color][1];
        return;
    } 
    int tmp1,tmp2;
    tmp1 = 0;
    tmp2 = 0;
    for (int i = color + 2; i <= n - 1; i++) {
        dfs(level + 1, i);
        // cout << "sub : " << sub[0] << " " << sub[1] << endl; 
        tmp1 += result[0];
        tmp2 += result[1];
        tmp1 %= mod;
        tmp2 %= mod;
    }
    result[0] = tmp1;
    result[1] = tmp2;
    visit[level][color] = 1;
    dp[level][color][0] = result[0];
    dp[level][color][1] = result[1];
    // if (result[0] < 0 || result[1]< 0) {
    //     // System.out.printf("result[0] : %d , result[1] :  %d\n", result[0],result[1]);
    // }
    return;
}

int main() {
    cin >> n >> k;
    if(k == 1){
        cout << n;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        dfs(1, i);
    }
    int sol = 0;
    for (int i = 0; i < n; i++) {
        if(i == 0){
            sol += dp[1][i][0] % mod;
        }else{
            sol += (dp[1][i][0] + dp[1][i][1])%mod;
        }
        sol %= mod;
    }
    int ans;
    ans = sol % mod;
    cout << ans;
}