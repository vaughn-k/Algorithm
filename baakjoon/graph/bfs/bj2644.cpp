/*
25m

가족간 촌수를 계산하는 문제. 

그래프 - bfs

*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
int t1,t2;
int k;
int tmp1,tmp2;
vector<vector<int> > v;
int visited[102];
// v[3][4] : 3은 4의 부모이다.

queue<int> q1;
queue<int> q2;

int family(){
    q1 = q2;
    while(!q2.empty()){
        q2.pop();
    }

    int len = q1.size();
    int now;
    for(int i=0;i<len;i++){
        now = q1.front();
        q1.pop();
        for(int j=0;j<v[now].size();j++){
            if(v[now][j] == t2){
                return 1;
            }
            if(visited[v[now][j]] == 0){
                visited[v[now][j]] = 1;
                q2.push(v[now][j]);
            }
        }
    }
    if(q2.size() > 0){
        return family() + 1;
    }
    return 99999999;
}

int main(){
    cin >> n;
    cin >> t1;
    cin >> t2;
    cin >> k;
    for(int i=0;i<=n;i++){
        v.push_back(vector<int>());
        visited[i] = 0;
    }

    for(int i=0;i<k;i++){
        cin >> tmp1;
        cin >> tmp2;
        v[tmp1].push_back(tmp2);
        v[tmp2].push_back(tmp1);
    }

    q2.push(t1);
    visited[t1] = 1;
    int answer = family();
    if(answer >= 99999999){
        cout << -1;
    }
    else{
        cout << answer;
    }
}

/*

9
7 8
7
1 2
1 3
2 7
2 8
2 9
4 5
4 6

*/