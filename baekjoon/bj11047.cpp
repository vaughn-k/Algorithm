// 37m dp로 풀다가 메모리초과..

#include <iostream>

using namespace std;

int n,k;
int coin[11];
int dp[100000001];

int main(){
    cin >> n;
    cin >> k;
    for(int i=0;i<n;i++){
        cin >> coin[i];
    }
    int minimum = 200000000;
    for(int price=1; price<=k; price++){
        if(coin[0] > price){ // 제일 작은 액면가로도 못만드는 경우
            dp[price] = -1;
        }
        else{
            minimum = 200000000;
            for(int coin_loop=0;coin_loop<n;coin_loop++){
                if(coin[coin_loop] > price){ // 현재고른 액면가가 k보다 클 경우
                    dp[price] = minimum;
                    break;
                }
                else if(coin[coin_loop] == price){
                    minimum = 1;
                }
                else{
                    // 해당 액면가로 만들수 있을때
                    if(dp[price - coin[coin_loop]] > 0){
                        if(minimum > (dp[price - coin[coin_loop]] + 1)){
                            minimum = dp[price - coin[coin_loop]] + 1;
                        }
                    }
                }
            }
            if(minimum == 200000000){ // 해당 액면가를 만들수없을때
                dp[price] = -1;
            }
            else{
                dp[price] = minimum;
            }
        }
    }
    cout << dp[k];
}