/*
n개의 액면가를 가진 동전들로 k원을 만들수 있는 경우의 수 출력

top-down 방식으로도 답을 도출할수는 있지만 메모리 제한으로 인해 nk 의 메모리 크기를 사용할수 없다.

따라서 bottom-up 방식을 통해 구현해야했다.
*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,k;
vector<int> coin;
int store[2][10001];
// store[k] = 합계 k를 만들수 있는 전체 경우의 수

int main(){
    int tmp;
    cin >> n;
    cin >> k;
    for(int i=0;i<n;i++){
        cin >> tmp;
        coin.push_back(tmp);
    }

    store[0][0] = 1;
    store[1][0] = 1;
    for(int i=1;i<=k;i++){
        store[0][i] = 0;
        store[1][i] = 0;
    }

    // 내림차순 정렬
    // sort(coin.begin(), coin.end()); 정렬 안해도 상관없다.
    for(int now=0;now<n;now++){ // 현재 동전 액면가
        for(int target=1; target<=k; target++){ // 만들어야하는 타겟  
            if(target < coin[now]){
                store[1][target] = store[0][target];
            }
            else{
                store[1][target] = store[0][target] + store[1][target-coin[now]];
            }
        }
        for(int tmp=1;tmp<=k;tmp++){
            store[0][tmp] = store[1][tmp];
        }
    }

    cout << store[0][k];
}