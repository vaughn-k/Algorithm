// 6m
/*
피보나치 응용
*/

#include <iostream>

using namespace std;

int n;
long long pv[85];

int main(){
    pv[0] = 1ll;
    pv[1] = 1ll;
    for(int i=2;i<85;i++){
        pv[i] = pv[i-1] + pv[i-2];
    }

    cin >> n;

    cout << pv[n+1] * 2;
}
