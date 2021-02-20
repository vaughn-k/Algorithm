#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,k;
vector<int> coin;
int store[100][10000];

int find_coin(int now, int total){
    // now : 현재 동전 액면가를 나타내는 index
    // total : 현재까지 전체 금액(시작부터)
    int try_count = 0;
    int sub_total = 0;
    if(now == n){
        if(total == k){
            return 1;
        }
        else{
            return 0;
        }
    }
    if(total == k){
        return 1;
    }
    if(coin[now] > (k-total)){
        return 0;
    }
    if(store[now][total] != -1){
        return store[now][total];
    }
    while(coin[now] * try_count <= (k-total)){
        sub_total = sub_total + find_coin(now+1,total+coin[now] * try_count);
        try_count++;
    }
    store[now][total] = sub_total;
    return sub_total;
}

bool compare(int a, int b){
    if(a > b){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    int tmp;
    cin >> n;
    cin >> k;
    for(int i=0;i<n;i++){
        cin >> tmp;
        coin.push_back(tmp);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            store[i][j] = -1;
        }
    }
    // 내림차순 정렬
    sort(coin.begin(), coin.end(), compare);
    cout << find_coin(0,0);
}