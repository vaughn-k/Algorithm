/*
30m

백준 11047 - 동전 0

알고리즘 : 그리디

문제개요 : 동전의 액면가가 주어지고 k원을 만들때 가장 최소의 동전으로 만들기


*/

#include <iostream>

using namespace std;

int n,k;
int coin[11];

int greedy(int now, int left){
    if(left == 0){
        return 1;
    }
    if(left < 0 || now == -1){
        return 0;
    }
    int maxi = left / coin[now];
    int ret;
    for(int i=maxi; i>=0; i--){
        ret = greedy(now-1,left - coin[now] * i);
        if(ret > 0){
            return ret + i;
        }
    }
    return 0;
}

int main(){
    cin >> n;
    cin >> k;
    for(int i=0;i<n;i++){
        cin >> coin[i];
    }
    int ans = greedy(n-1,k) - 1;
    cout << ans;
}