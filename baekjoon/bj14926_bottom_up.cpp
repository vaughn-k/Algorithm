/*
23m

처음에는 bfs문제인줄알고 풀었지만 메모리초과로인해 bottom up으로 재구현하였다.

*/

#include <iostream>
#include <algorithm>

using namespace std;

int n;
int store[100001];

int main(){
    cin >> n;
    store[1] = 99999999;
    store[2] = 1;
    store[3] = 99999999;
    store[4] = 2;
    store[5] = 1;
    if(n > 5){
        for(int i=6;i<=n;i++){
            store[i] = min(store[i-2],store[i-5]) + 1;
        }
    }
    if(store[n] == 99999999){
        cout << -1;
    }
    else{
        cout << store[n];
    }
}