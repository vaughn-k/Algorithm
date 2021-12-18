/*/////////////////////////////////////////////////////////////////////////
소요시간 : 11m

문제명 - 백준 16562 - 친구비

알고리즘
    - 컴포넌트 분리
    - 컴포넌트별 순환

문제개요
    n명의 친구가 주어지고 각각 친구마다 친구를 맺을수있는 비용이주어지고 m개의 친구끼리의 관계가 주어진다.
    이때 k원을 가지고있을때 최소의 비용으로 모든친구를 갖고싶을때 그 비용 출력

*//////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <vector>

using namespace std;

int n,m,k;
int cost[10001];
int visited[10001];

vector<vector<int> > v;

int findMinimum(int root){
    visited[root] = 1;
    int mini = cost[root];
    int next;
    for(int i=0;i<v[root].size();i++){
        next = v[root][i];
        if(visited[next] == -1){
            mini = min(mini,findMinimum(v[root][i]));
        }
    }
    return mini;
}

int main(){
    cin >> n >> m >> k;
    int tmp,tmp2;
    for(int i=1;i<=n;i++){
        cin >> tmp;
        cost[i] = tmp;
        visited[i] = -1;
    }
    for(int i=0;i<=n;i++){
        v.push_back(vector<int>());
    }

    for(int i=0;i<m;i++){
        cin >> tmp >> tmp2;
        v[tmp].push_back(tmp2);
        v[tmp2].push_back(tmp);
    }

    int tot = 0;
    for(int i=1;i<=n;i++){
        if(visited[i] != 1){
            tot = tot + findMinimum(i);
        }
    }
    if(k < tot){
        cout << "Oh no";
    }
    else{
        cout << tot;
    }
}