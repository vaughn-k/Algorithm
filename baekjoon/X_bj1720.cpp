#include <iostream>

using namespace std;

int n;
int dp[31]; // 3가지 블록 모두 이용
int dp2[31];

int main(){
    cin >> n;
    dp[1] = 1;
    dp[2] = 3;
    dp2[1] = 1;
    dp2[2] = 3;
    dp2[3] = 3;
    dp2[4] = 8;
    int ans;
    if(n > 4){
        for(int i=3;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2] * 2;
        }
        for(int i=5;i<=n;i++){
            dp2[i] = dp2[i-4]*2 + dp[i-4] + dp[i-3]*2 + dp2[i-2];
        }
    }
    cout << dp2[n];
    return 0;
}