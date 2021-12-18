#include <iostream>
#include <algorithm>

using namespace std;

int n,m,k;

unsigned long long store[101][101];

unsigned long long combination(int n, int m){
    if(m == 1){
        return n;
    }
    if(n == m){
        return 1;
    }
    if(store[n][m] != 0){
        return store[n][m];
    }
    unsigned long long answer = combination(n-1,m-1) + combination(n-1,m);
    store[n][m] = answer;
    return answer;
}

int main(){
    cin >> n;
    cin >> m;
    // cin >> k;

    for(int i=0;i<101;i++){
        for(int j=0;j<101;j++){
            store[i][j] = 0;
        }
    }

    if(combination(n,m) < 0){
        cout << "erorr : " << combination(n,m);
    }
    if(combination(n,m) > 0){
        cout << "right : " << combination(n,m);
    }
    // cout << combination(5,2);
    // cout << combination(6,3);
}