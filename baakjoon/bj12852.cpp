// 12m

// bottom-up 으로 설계

#include <iostream>
#include <algorithm>

using namespace std;

int n;
int dp[1000001];
int dp_seq[1000001];
int main(){
    cin >> n;
    dp[0] = 0;
    dp[1] = 0;

    int tmp1, tmp2, tmp3;

    for(int i=2;i<=n;i++){
        tmp1 = dp[i-1] + 1;
        dp_seq[i] = 1;
        if((i%2) == 0){
            tmp2 = dp[i/2] + 1;
            if(tmp1 > tmp2){
                tmp1 = tmp2;
                dp_seq[i] = 2;
            }
        }
        if((i%3) == 0){
            tmp3 = dp[i/3] + 1;
            if(tmp1 > tmp3){
                tmp1 = tmp3;
                dp_seq[i] = 3;
            }
        }
        dp[i] = tmp1;
    }

    cout << dp[n] << endl;
    int now = n;
    while(now != 1){

        cout << now << " ";
        if(dp_seq[now] == 1){
            now = now - 1;
        }
        else if(dp_seq[now] == 2){
            now = now / 2;
        }
        else{
            now = now / 3;
        }

    }
    cout << 1;
}