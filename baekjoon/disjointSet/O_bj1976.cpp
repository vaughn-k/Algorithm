/*
15m

백준 1976 - 여행 가자

알고리즘 : 상호 배타적 집합(분리집합)

문제 개요 : n개의 도시에 대해 2차원 배열로 연결상태가 주어지고 여행해야할 도시들이 주어졌을때

그 여행해야 할 도시들이 모두 연결되어있는지(같은 집합에 속해있는지) 판별
*/

#include <iostream>
#include <queue>

using namespace std;

int n,m;
int city[201][201];
int check[1002];
int d[201]; // 현재 자신의 부모

queue<int> q;

int findRoot(int x){
    q.push(x);
    while(d[x] != x){
        x = d[x];
        q.push(x);
    }
    while(q.size() > 0){
        d[q.front()] = x;
        q.pop();
    }
    return x;
}

void unionAB(int a, int b){
    int rootA,rootB;
    rootA = findRoot(a);
    rootB = findRoot(b);
    if(rootA != rootB){
        d[rootA] = rootB;
    }
}

int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        d[i] = i;
        for(int j=0;j<n;j++){
            cin >> city[i][j];
        }
    }
    for(int i=0;i<m;i++){
        cin >> check[i];
        check[i]--;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(city[i][j] == 1){
                unionAB(i,j);
            }
        }
    }
    int same = true;
    int root = findRoot(check[0]);
    for(int i=1;i<m;i++){
        if(root != findRoot(check[i])){
            cout << "NO";
            same = false;
            break;
        }
    }
    if(same){
        cout << "YES";
    }
}